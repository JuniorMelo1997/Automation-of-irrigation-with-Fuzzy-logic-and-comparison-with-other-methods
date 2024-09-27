const int pinoSensor = A0;
const int pinoValvula = 9;
const int tempoRega = 15;
int umidadeSolo = 0;

void setup() {  
  pinMode(pinoValvula, OUTPUT);
  digitalWrite(pinoValvula, HIGH);

  Serial.begin(9600);
}

void loop() {
  /* O loop for abaixo serve para a passagem de tempo de 1800 segundos, isto é, 30 minutos */
  for(int i=0; i < 1800; i++) 
    {if(i == 1500){
      /* Neste código o valor da umidade do solo não determina o acionamento ou não da válvula, apenas serve para a leitura via serial do valor de umidade */
        // Leitura da tensão do sensor
      umidadeSolo = analogRead(pinoSensor);
      // Conversão do valor de tensão em valor de umidade
      umidadeSolo = map(umidadeSolo, 1023, 0, 0, 100);
          
        // Mostra o valor através da conexão serial
        Serial.println(umidadeSolo);
        Serial.println(" %    ");
      }
      delay(1000);
  }
  
    digitalWrite(pinoValvula, 0);
    // Espera o tempo estipulado
    delay(tempoRega*1000);
    digitalWrite(pinoValvula, 1);
}