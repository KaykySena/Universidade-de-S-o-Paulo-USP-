//Informações dadas pelo Blynk para se conectar ao projeto
#define BLYNK_TEMPLATE_ID "XXXXXXXXXX"
#define BLYNK_DEVICE_NAME "XXXXXXXXXXXXXX"
#define BLYNK_AUTH_TOKEN  "XXXXXXXXXXXXXXXXXXXXXX"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <string.h>

char auth[] = BLYNK_AUTH_TOKEN;

// SSID (nome) e senha da rede Wi-Fi.

char ssid[] = "nome";
char pass[] = "senha";

// Inicialização das variaveis das leituras

int umidade_solo = 0;
int umidade_ar = 0;
int temperatura = 0;

// Lê o serial e separa as informaçãos em 3 variáveis.

void ler_serial(int * umidade_solo, int * umidade_ar, int * temperatura)
{
  String IncomingString = "";
  int posicao_na_string_recebida = 0;
  int posicao_na_string = 0;

  // Inicialização das strings com as informações enviadas pelo Arduino Uno R3.

  char entrada_umidade_solo[10];
  char entrada_umidade_ar[10];
  char entrada_temperatura[10];
  
  while(1)
  {
    int input = IncomingString[posicao_na_string_recebida];

    if(input == '\n')
    {
      entrada_umidade_ar[posicao_na_string] = '\0';
      posicao_na_string_recebida++;
      posicao_na_string = 0;

      break;
    }

    entrada_umidade_ar[posicao_na_string] = input;
    posicao_na_string_recebida++;
    posicao_na_string++;
  }
  while(1)
  {
    int input = IncomingString[posicao_na_string_recebida];

    if(input == '\n')
    {
      entrada_temperatura[posicao_na_string] = '\0';
      posicao_na_string_recebida++;
      posicao_na_string = 0;

      break;
    }

    entrada_temperatura[posicao_na_string] = input;
    posicao_na_string_recebida++;
    posicao_na_string++;
  }
  while(1)
  {
    int input = IncomingString[posicao_na_string_recebida];

    if(input == '\n')
    {
      entrada_umidade_solo[posicao_na_string] = '\0';
      posicao_na_string_recebida++;
      posicao_na_string = 0;

      break;
    }

    entrada_umidade_solo[posicao_na_string] = input;
    posicao_na_string_recebida++;
    posicao_na_string++;
  }
  
  // Converte as strings em inteiros.

  *umidade_solo = atoi(entrada_umidade_solo);
  *temperatura = atoi(entrada_temperatura);
  *umidade_ar = atoi(entrada_umidade_ar);
}

void setup()
{
  Serial.begin(9600);

  // Conecta a rede ao projeto no Blynk.

  Blynk.begin(auth, ssid, pass);
}


void loop()
{
  Blynk.run();
  
  boolean StringReady = false;

  while(Serial.available())
  {
    IncomingString = Serial.readString();
    StringReady = true;
  }

  if(StringReady)
  {
    ler_serial(&umidade_solo, &umidade_ar, &temperatura);
    
    // Envia os valores lidos pelos sensores para o Blynk.

    Blynk.virtualWrite(V0, temperatura);
    Blynk.virtualWrite(V1, umidade_solo);
    Blynk.virtualWrite(V2, umidade_ar);
    
    delay(800);
  }
}