//Código-fonte do "sketch" do Arduino UNO R3.

#include <dht.h>
#include <time.h>

const int pino_sensor_umidade_solo = A0;
const int pino_DHT11 = A1;
const int pino_valvula = 10;
const int tempo_rega = 15;
const int limiar_umidade = 20;

dht DHT;

int umidade_ar = 0;
int temperatura = 0;
int umidade_solo = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(pino_valvula, OUTPUT);
}

// Rega a planta por um período de "tempo_rega" segundos.

void regar()
{
  digitalWrite(pino_valvula, HIGH);
  delay(tempo_rega * 1000);
  digitalWrite(pino_valvula, LOW);
}

void loop()
{
  // A verificação do nível de umidade do solo é feita em intervalos de uma hora.
  
  for(int i = 0; i < 3600; i++){

    // O sensor DHT11 lê a umidade relativa do ar e a temperatura ambiente.

    DHT.read11(pino_DHT11);
    umidade_ar = DHT.humidity;
    temperatura = DHT.temperature;

    // Converte o valor da umidade do solo, antes em um intervalo de 0 a 1023, para um de 0 a 100.

    umidade_solo = analogRead(pino_sensor_umidade_solo);
    umidade_solo = map(umidade_solo, 1023, 0, 0, 100);

    // Envia, por meio da porta serial, os valores extraídos pelos sensores, para a ESP8266.

    Serial.println(umidade_ar);
    Serial.println(temperatura);
    Serial.println(umidade_solo);
  
    delay(1000);
  }

  // Se o nível de umidade estivar abaixo do limiar, a válvula se abre e a rega é feita.

  if(umidade_solo < limiar_umidade)
    regar();
}
