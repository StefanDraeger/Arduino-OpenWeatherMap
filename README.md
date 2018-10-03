# Arduino-OpenWeatherMap
<h2>Einleitung</h2>
Laden & verarbeiten eines HTTP JSON Response von <a href="https://openweathermap.org/" target="_blank">OpenWeaterMap.org</a>

Diese Bibliotek dient dazu ein HTTP JSON Response von <a href="https://openweathermap.org/" target="_blank">OpenWeaterMap.org</a> mit hilfe von <a href="https://github.com/bblanchon/ArduinoJson" target="_blank">ArduinoJson V5.13.2</a> zu parsen.
Als Ergebnis dieses Vorgangs erhält man ein Objekt vom Typ "OpenWeatherMap".

<h2>Verzeichnisse</h2>
In diesem Github Repository findest du folgende Verzeichnisse:
<ol>
<li>ArduinoJson</li>
<li>backups</li>
<li>examples</li>
<li>src</li>
<li>test</li>
</ol>

Die Funktion des parsens wurde mit der Version 5.13.2 von ArduinoJson entwickelt und getestet, diese Version habe ich im Verzeichnis "ArduinoJson" abgelegt.
Unter dem Verzeichnis "backups" lege ich gepackte zwischenstände im *.zip Format ab. Diese Versionen haben kein Anrecht auf funktionalität!

Beispiele findest du unter dem Verzeichnis "examples" hier möchte ich dann zu jeder Funktion des parsers ein Beispiel einfügen.

Die Verzeichnisse "src" & "test" enthalten den Quellcode sowie die Testfälle. 
Der Parser wurde mit der portablen Entwicklungsumgebung <a href="https://sourceforge.net/projects/orwelldevcpp/files/latest/download">Dev-C++</a> entwickelt und getestet.
Da die Arduino IDE nicht wirklich mit C++ Code arbeitet, kann der Code nicht 1:1 verwendet werden, ich empfehle hier einen Blick in das Verzeichnis "examples".

<h2>Beispiele</h2>
Nun möchte ich auf dei Beispiele eingehen.
Für alle Beispiele wird die Datei "openWeatherMapParser.h" benötigt welche parallel zum Arduino Sketch abgelegt wird.

<h3>01_parse_current</h3>
Der Funktion "OpenWeatherMap parseCurrentJson(char* httpResponse)" wird das Ergebnis einer Abfrage für das aktuelle Wetter im JSON Format übergeben.
Als Ergebnis erhält man ein Objekt vom Typ "OpenWeaterMap" mit den geparsten Werten.




