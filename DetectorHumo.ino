#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

const char* ssid = "ESNE"; 
const char* password = "ESNE2023"; 

const String BOT_TOKEN = "8371451527:AAG4Cje1w1XvzLfVD2F9J7b0WyvB6M25d7I"; 
const String CHAT_ID = "5155878614"; 

WiFiClientSecure client;
UniversalTelegramBot bot(BOT_TOKEN, client);

const int PIN_SENSOR = 34;
const int PIN_BUZZER = 25;
int umbral = 2000;         
bool alarma_activa = false;
unsigned long lastBotCheck = 0;

void setup() {
  Serial.begin(115200);
  pinMode(PIN_BUZZER, OUTPUT);
  digitalWrite(PIN_BUZZER, LOW);

  Serial.print("Conectando a WiFi ");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConectado a WiFi");

  client.setInsecure();
  
  bot.sendMessage(CHAT_ID,"DETECTOR DE HUMO EN LINEA", ""); 
}

void manejarComando(String text) {
  if (text == "/mute") {
    digitalWrite(PIN_BUZZER, LOW);
    alarma_activa = false;
    bot.sendMessage(CHAT_ID, "ALARMA SILENCIADA", ""); 
  } else if (text == "/status") {
    int valor = analogRead(PIN_SENSOR);
    bot.sendMessage(CHAT_ID, "HUMO NO DETECTADO" + String(valor), ""); 
  } else if (text == "/reset") {
    alarma_activa = false;
    digitalWrite(PIN_BUZZER, LOW);
    bot.sendMessage(CHAT_ID, "ALARMA REINICIADA", ""); 
  } else {
    bot.sendMessage(CHAT_ID, "Comandos disponibles:\n/status - Ver nivel actual\n/mute - Apagar ruido\n/reset - Reiniciar alarma", "");
  }
}

void revisarTelegram() {
  int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
  while (numNewMessages) {
    for (int i = 0; i < numNewMessages; i++) {
      if (bot.messages[i].chat_id == CHAT_ID) {
        manejarComando(bot.messages[i].text);
      } else {
        bot.sendMessage(bot.messages[i].chat_id, "Usuario no autorizado", ""); 
      }
    }
    numNewMessages = bot.getUpdates(bot.last_message_received + 1);
  }
}

void loop() {
  int valor = analogRead(PIN_SENSOR);
  // Serial.println(valor); 
  if (valor > umbral && !alarma_activa) {
    alarma_activa = true;
    digitalWrite(PIN_BUZZER, HIGH);
    bot.sendMessage(CHAT_ID, "HUMO DETECTADO.POSIBLE RIESGO./nNivel: " + String(valor), ""); 
  }

  if (millis() - lastBotCheck > 1000) {
    lastBotCheck = millis();
    revisarTelegram();
  }
  
  delay(100);
}

/*Editado por Tianny Lopez 

