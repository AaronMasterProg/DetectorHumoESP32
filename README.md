# MANUAL DE USUARIO  
## Sistema de Detección de Humo con ESP32 y Bot de Telegram
##En esta sección son libres de adecuar a su estilo de trabajo, ocupar distintas herramientas y usar su creatividad para lo que requieran agregar.

## 1. Presentación del sistema

Este manual describe el uso y operación del **Sistema de Detección de Humo con ESP32**, el cual integra un sensor de gas/humo y un bot de Telegram para la notificación y control remoto del sistema.

El proyecto fue desarrollado con fines educativos, aplicando conceptos de electrónica, redes, IoT y programación, permitiendo a los usuarios interactuar con el sistema desde la aplicación de Telegram.

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

## 4. Usuarios del sistema

El sistema está diseñado para múltiples usuarios mediante un mecanismo de suscripción.

- Para recibir alertas, el usuario debe enviar el comando `/start` al bot.
- El sistema registra automáticamente al usuario.
- Solo los usuarios registrados reciben notificaciones.

Pegar aquí la captura del bot creado en Telegram, y después del bot ya recibiendo alertas de la ESP32.

<img width="180" height="400" alt="image" src="https://github.com/user-attachments/assets/8cb630c9-59ef-4d6d-aed6-4794accfff32" />

## 5. Requisitos para el uso del sistema

### 5.1 Requisitos de hardware

Agregar aquí el material y las fotos de los materiales.
Agregar el diagrama de bloques del proyecto.

### 5.2 Requisitos de software

Agregar aquí la lista del software empleado.

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

En esta sección el alumno debe documentar las pruebas realizadas.

### 9.1 Prueba de conexión WiFi  
Evidencia:

### 9.2 Prueba del sensor de humo  
Evidencia:

### 9.3 Prueba de envío de alertas  
Evidencia:

### 9.4 Prueba de comandos remotos  
Evidencia:

## 10. Resultados obtenidos

Describir el comportamiento del sistema durante las pruebas, tiempos de respuesta, confiabilidad y funcionamiento general.

## 11. Problemas presentados y soluciones

Problema que detecta.

Problema que resuelve.

Donde se implementa.

## 12. Recomendaciones de uso

- Mantener el ESP32 conectado a una red WiFi estable.
- Ajustar el umbral del sensor para evitar falsas alarmas.
- Realizar pruebas periódicas del sistema.
- No utilizar el sistema como único medio de seguridad.

## 13. Conclusiones

Redactar las conclusiones del proyecto, describiendo:
- Qué se aprendió
- Qué funcionó correctamente
- Qué podría mejorarse
- La importancia del uso de IoT en sistemas de monitoreo, así como su aplicación en áreas de mantenimiento industrial y Soporte Técnico.

## 14. Trabajo futuro

- Integración con otros sensores
- Registro de eventos
- Interfaz web
- Control de actuadores adicionales

## 15. Referencias

- Documentación ESP32
- Telegram Bot API
- Manuales del sensor utilizado

## 16. Material.

Agregar aquí el material y fotografías de todo el material.
Al final de esta sección agregar una fotografía del proyecto ya completamente ensamblado.

## 17. Créditos

Proyecto desarrollado con fines académicos para práctica de Soporte Técnico.
ESNE (2026)
