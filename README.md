# nodered-sample-project
a simple sample project to showcase Node-RED`s IoT capabilities
## Einführung
Das Programm misst mithilfe eines Microcontrollers und eines DHT11 Temparatur-Sensors die Luftfeuchtigkeit und die Temperatur auf Knopfdruck. Die Daten werden über das Nachrichtenprotokoll MQTT durchs Netzwerk an einen Node-RED Flow geschickt.

## Installation 
Die Installation besteht aus einem Hardware- und einem Softwareteil. Für den korrekten Programmablauf wird ein MQTT-Broker im Netzwerk vorrausgesetzt. Es gibt viele verschiedene Broker-Softwares - Installation hierzu können im Internet gefunden werden.

### Hardware


### Software
1. Laden Sie den Quellcode aus diesem github-repository herunter und öffnen sie die .ino-Datei in der Arduino IDE.
2. Fügen Sie den untenstehenden Link unter "Datei" -> "Voreinstellungen" bei "Zusätzliche Boardverwalter-URLs" ein.
  http://arduino.esp8266.com/stable/package_esp8266com_index.json
3. Suchen Sie unter "Werkzeuge" -> "Board" und "Boardverwalter" die Verwaltersoftware "ESP8266 by Esp8266 Community" und installieren Sie eine aktuelle Version. 
4. Suchen Sie unter "Werkzeuge" -> "Board" den von Ihnen genutzten Microcontroller aus.
5. Geben Sie Ihre SSID, Ihren WPA und Ihre MQTT-Server-IP in die dafür vorgesehenen Zeilen im Programmquellcode ein.
6. Laden Sie das Programm auf ihren Microcontroller hoch und warten Sie ein paar Momente, bis der Microcontroller mit dem Internet verbunden ist.

Wichtig: Achten Sie auf die benötigten Bibliotheken!
