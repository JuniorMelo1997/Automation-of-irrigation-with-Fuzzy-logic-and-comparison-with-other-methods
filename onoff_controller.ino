// variáveis do programa
const int pinoSensor = A0;
const int pinoValvula = 9;
const int limiarSeco = 70;
const int tempoRega = 15; // Tempo de rega em segundos
int umidadeSolo = 0;

void setup() {  
  pinMode(pinoValvula, OUTPUT);
  // Desliga a válvula
  digitalWrite(pinoValvula, HIGH);

  Serial.begin(9600);
}

void loop() {
  // Mede a umidade a cada segundo. Faz isso durante uma hora (3600 segundos).
  for(int i=0; i < 1800; i++) {
    // Faz a leitura do sensor de umidade do solo
    umidadeSolo = analogRead(pinoSensor);
    // Converte a variação do sensor de 0 a 1023 para 0 a 100
    umidadeSolo = map(umidadeSolo, 1023, 0, 0, 100);
    if(i == 900){      
      // Exibe a mensagem via serial:
      Serial.println(umidadeSolo);
      Serial.println(" %    ");
    }
    // Espera um segundo
    delay(1000);
  }
  
  if(umidadeSolo < limiarSeco) {
    digitalWrite(pinoValvula, 0);
    // Espera o tempo estipulado
    delay(tempoRega*1000);
    digitalWrite(pinoValvula, 1);
  }
  else {
    // Espera o tempo estipulado
    delay(3000);
  }
}