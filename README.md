# MANUAL DE USUARIO  
## Sistema de Detección de Humo con ESP32 y Bot de Telegram


## 1. Presentación del sistema

Este manual describe el uso y operación del **Sistema de Detección de Humo con ESP32**, el cual integra un sensor de gas/humo y un bot de Telegram para la notificación y control remoto del sistema.

El proyecto fue desarrollado con fines educativos, aplicando conceptos de electrónica, redes, IoT y programación, permitiendo a los usuarios interactuar con el sistema desde la aplicación de Telegram.

El presente manual de usuario describe el funcionamiento, operación y uso correcto del Sistema de Detección de Humo basado en ESP32, el cual integra un sensor gas/humo, actuador acústico (buzzer) y un Bot de telegram para la notificación y el control remoto del sistema.
Este proyecto fue desarrollado con fines educativos de electrónica digital, redes inalámbricas, internet de las cosas (loT) y programación, permitiendo la supervisión remota de un ambiente mediante una aplicación de mensajería ampliamente utilizada como telegram.
El sistema esta orientado a demostrar como los dispositivos lot pueden emplearse en aplicaciones de monitoreo preventivo, simulando un sistema básico de seguridad contra incendios.


## 2. Objetivo del manual

El objetivo de este manual es guiar al usuario en:

- La correcta operación del sistema
- El uso de los comandos disponibles en Telegram
- La interpretación de alertas y estados
- La documentación de pruebas, resultados y conclusiones

## 3. Descripción general del funcionamiento

El sistema opera de manera continua realizando las siguientes acciones:

1. El ESP32 se conecta a una red WiFi.
2. El sensor de humo monitorea el ambiente.
3. Al detectar un nivel de humo superior al umbral configurado:
   - Se activa una alarma sonora (buzzer).
   - Se envía una notificación mediante Telegram.
4. Durante la ejecucion:
	- El ESP32 establece conexion a una red WiFi utilizando las credenciales definidas en las variables ssid y password
	- Se inicializa un cliente seguro (WiFiClienteSecure) para permitir la comunicacion cifrada en los servidores de telegram.
	- Se  crea una instancia del bot mediante la libreria UniversalTelegramBot, empleando el token del bot y el ID de chat autorizado.
	- El sensor de humo, conectado al pin analogico GPIO 34, realiza lecturas constantes del nivel de gases presentes en el ambiente.
	- Cuando el valor leido supera al umbral definido en la variable umbral, el sistema activa una alarma sonora y envia una notificacion inmediata a los usuarios registrados.
	- Paralelamente, el sistema revisa periodicamente si existen comandos enviados desde telegram para permitir el control remoto del sistema.

## 4. Usuarios del sistema

El sistema está diseñado para múltiples usuarios mediante un mecanismo de suscripción.

- Para recibir alertas, el usuario debe enviar el comando `/start` al bot.
- El sistema registra automáticamente al usuario.
- Solo los usuarios registrados reciben notificaciones.
- El sistema implementa un control basico de acceso, perimitiendo que solo los usuarios autorizadis interactuen con el sistema.
Esto se logra mediante:
	- La variable Chat_ID, la cual almacena el identificador unico del usuario autorizado.
	- Cada mensaje recibido por el bot es valido comparando el chat_id del remitiente con el valor almacenado.
	- Si el usuario no coincide con el ID autorizado, el sistema responde ccon un mensaje de rechazo

<img width="180" height="400" alt="image" src="https://github.com/user-attachments/assets/8cb630c9-59ef-4d6d-aed6-4794accfff32" />

## 5. Requisitos para el uso del sistema

### 5.1 Requisitos de hardware

Agregar aquí el material y las fotos de los materiales.
Agregar el diagrama de bloques del proyecto.

### 5.2 Requisitos de software

El sistema fue desarrollado utilizando el siguiente software y librerías:
-	Arduino IDE (Entorno para el desarrollo)
-	Librería WiFi.h para la conexión a redes inalámbricas
-	WiFiClientSecure.h para la comunicación segura HTTPS
-	UniversalTelegramBot.h para la interacción con la API de Telegram
-	Arduino.Json.h para el manejo interno de mensajes JSON
Estas herramientas permiten la comunicación en tiempo real entre ESP32 y los servidores de Telegram, así como la correcta interpretación de comandos enviados por el usuario. 


## 6. Puesta en marcha del sistema

### 6.1 Encendido
1. Conectar el ESP32 a la fuente de alimentación.
2. Verificar que el dispositivo se conecte a la red WiFi.
3. Confirmar el mensaje de inicio enviado por el bot.

Idealmente capturas del proceso una vez que se desplego, así como de su operación.

## 7. Procedimiento de uso

### 7.1 Suscripción al sistema
1. Abrir la aplicación Telegram.
2. Buscar el bot configurado.
3. Enviar el comando `/start`.
4. Esperar confirmación de suscripción.

### 7.2 Detección de humo
1. El sistema monitorea continuamente el sensor.
2. Al detectar humo:
   - Se activa el buzzer.
   - Se envía una alerta a todos los usuarios suscritos.

### 7.3 Comandos disponibles de Telegram:
El sistema permite el control remoto mediante los siguientes comandos, definidos en la función manejarComando():

-	/status: Permite consultar el nivel actual de humo detectado por el sensor. El sistema responde enviando el valor leído directamente desde el pin analógico.

-	/mute: Desactiva la alarma sonora (buzzer) y cambia el estado del sistema a alarma silenciada.

-	/reset: Reinicia el estado de la alarma, apagando el buzzer y dejando el sistema listo para una nueva detección.


**Evidencia requerida:**  
- Captura del mensaje de alerta.
- Fotografía o video del buzzer activado.

## 8. Estados del sistema

El sistema puede encontrarse en los siguientes estados:

- **Armado:** El sistema monitorea y genera alertas.
- **Desarmado:** El sistema no genera alarmas.
- **Alarma activa:** Se detectó humo y el buzzer está encendido.
- **Alarma silenciada:** El buzzer fue apagado mediante comando.

## 9. Pruebas de funcionamiento

En esta sección se añadiran las evidencias de las pruebas del desarrollo

### 9.1 Prueba de conexión WiFi  
Evidencia:

### 9.2 Prueba del sensor de humo  
Evidencia:

### 9.3 Prueba de envío de alertas  
Evidencia:

### 9.4 Prueba de comandos remotos  
Evidencia:

## 10. Resultados obtenidos

<img width="1919" height="1079" alt="Captura de pantalla 2026-01-31 095502" src="https://github.com/user-attachments/assets/d895bfba-1533-43fd-a0ac-97de5af20498" />


## 11. Problemas presentados y soluciones
Problema Detectado:
Falsas alarmas por sensibilidad del sensor.

Solucion presentada:
Ajuste del umbral de deteccion y filtrado de lecturas.

Ubicacion de la solucion:
Codigo del ESP32, seccion de lectura del sensor.


## 12. Recomendaciones de uso

- No utilizar el sistema como unico medio de seguridad
- Mantener el ESP32 conectado a una red WiFi estable
-Realizar pruebas periodicas del sistema.
-Ajustar el umbral del sensor adecuadamente


## 13. Conclusiones

    Durante el desarrollo del proyecto se aprendio:
	-Integracion del hardware y software  en el sistema loT.
	-Comunicacion entre dispositivos y servicios en la nube.
    -Uso de bots como telegram para el control remoto.


## 14. Trabajo futuro

- Integración de sensores adicionales
- Registro histórico de eventos.
- Desarrollo de interfaz web
- Control de actuadores adicionales

## 15. Referencias

•	Documentación oficial ESP32
•	Telegram Bot API
•	Manual del sensor de gas utilizado.

## 16. Material.

Agregar aquí el material y fotografías de todo el material.
Al final de esta sección agregar una fotografía del proyecto ya completamente ensamblado.
- ESP32 Dev Module
- Buzzer activo
- Cables Dupont
- Sensor de humo/Gas
- Protoboard
- Fuente de alimentacion
- Telegram Instalado
## 17. Créditos

Proyecto desarrollado con fines académicos para practica Soporte Técnico. ESNE (2026).
- ##Editado por
- Mereles Arellano Luis Antonio.
- Eugenio Emmanuel Badillo Perez.

