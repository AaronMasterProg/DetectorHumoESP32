#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

const char* ssid = "WIFI"; /* Cambiar con la red Wifi de la Escuela */
const char* password = "CONTRASEÑA"; /*Introducir clave de la red */

const String BOT_TOKEN = "8371451527:AAG4Cje1w1XvzLfVD2F9J7b0WyvB6M25d7I"; /* Ejercicio: guardar dentro de una variable y llamarla en esta sección.*/
const String CHAT_ID = "5155878614"; /* Valor que deben obtener para vincular su teléfono al chatbot, hacer lo mismo que la variable anterior.*/

WiFiClientSecure client;
UniversalTelegramBot bot(BOT_TOKEN, client);

const int PIN_SENSOR = 34;
const int PIN_BUZZER = 25;
int umbral = 2000;         /* Valor a modificar si no se realiza una correcta detección */
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
  
  bot.sendMessage(CHAT_ID,"MENSAJE DE BIENVENIDA", ""); /* Editar este mensaje*/
}

void manejarComando(String text) {
  if (text == "/mute") {
    digitalWrite(PIN_BUZZER, LOW);
    alarma_activa = false;
    bot.sendMessage(CHAT_ID, "SILENCIO", ""); /* Editar la alerta de silencio */
  } else if (text == "/status") {
    int valor = analogRead(PIN_SENSOR);
    bot.sendMessage(CHAT_ID, "HUMO " + String(valor), ""); /* Cambiar mensaje de nivel de humo */
  } else if (text == "/reset") {
    alarma_activa = false;
    digitalWrite(PIN_BUZZER, LOW);
    bot.sendMessage(CHAT_ID, "RESET", ""); /*Cambiar alerta de reseteo físico*/
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
        bot.sendMessage(bot.messages[i].chat_id, "RECHAZO", ""); /* Rechazar si no es usuario autorizado cambiar mensaje*/
      }
    }
    numNewMessages = bot.getUpdates(bot.last_message_received + 1);
  }
}

void loop() {
  int valor = analogRead(PIN_SENSOR);
  // Serial.println(valor); /* En caso de problemas ajustar descomentando y viendo la lectura que nos da a través de la interfaz de Arduino */

  if (valor > umbral && !alarma_activa) {
    alarma_activa = true;
    digitalWrite(PIN_BUZZER, HIGH);
    bot.sendMessage(CHAT_ID, "HUMO DETECTADO Nivel: " + String(valor), ""); /*Cambiar mensaje de humo detectado*/
  }

  if (millis() - lastBotCheck > 1000) {
    lastBotCheck = millis();
    revisarTelegram();
  }
  
  delay(100);
}

//Al finalizar tienen que compilar, compañeros de evidencia obtener foto del software Arduino con la compilación y comenzar a realizar la documentación
//BORRAR ESTAS ULTIMAS LINEAS DE COMENTARIOS, Y LAS QUE CONSIDEREN NECESARIAS, O AGREGAR MÁS