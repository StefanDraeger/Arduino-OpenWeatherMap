#include <ArduinoJson.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>

#include <Wire.h> //Bibliothek für die Arduino IDE <= 1.6.5
#include "SSD1306Wire.h" //Display Bibliothek
#include "OLEDDisplayUi.h" //Display Bibliothek

#include <SPI.h>
#include <Wire.h>

ESP8266WiFiMulti WiFiMulti;

SSD1306Wire  display(0x3c, D1, D2);
OLEDDisplayUi ui ( &display );

const char* SSID = "FRITZ!Box 7590 KV";
const char* PW = "32180948830109488626";

#define SONNE 0
#define WOLKE_SONNE 85
#define WOLKE 192
#define WOLKE_DUNKEL 329
#define REGEN 429
#define SONNE_REGEN 522
#define GEWITTER 608
#define SCHNEE 658
#define REGEN_MOND 713
#define WOLKE_MOND 780
#define MOND 838

const String url ="http://api.openweathermap.org/data/2.5/weather?q=Braunschweig,DE&appid=3ee177bfa6d11e51f870552aab5150be";

class Coord {
  double longitude;
  double latitude;
      
  public:
    double getLongitude(){ return longitude; }
    double getLatidute(){ return latitude; }
      
    void setLongitude(double inLongitude){ longitude = inLongitude; }
    void setLatitude(double inLatitude){ latitude = inLatitude; }
};

class Weather {
  int id;
  String main;
  String description;
  String icon; 
  
  public:
    int getId(){ return id; }
    String getMain(){ return main; }
    String getDescription(){ return description; }
    String getIcon(){ return icon; }
        
    void setId(int inId){ id = inId;  }
    void setMain(String inMain){ main = inMain; } 
    void setDescription(String inDescription){ description = inDescription; }
    void setIcon(String inIcon){ icon = inIcon; }   
};

class Main {
  double temp;
  double tempMin;
  double tempMax;
  int pressure;
  int humidity;
  
  public:
    double getTemp(){ return temp; }
    double getTempMin(){ return tempMin; }
    double getTempMax(){ return tempMax; }
    int getPressure(){ return pressure; }
    int getHumidity(){ return humidity; }
    
    void setTemp(double inTemp){ temp = inTemp; }
    void setTempMin(double inTempMin){ tempMin = inTempMin; }
    void setTempMax(double inTempMax){ tempMax = inTempMax; }
    void setPressure( int inPressure){ pressure = inPressure; }
    void setHumidity( int inHumidity){ humidity = inHumidity; }
};

class Wind {
  double speed;
  int degree;
  
  public:
    double getSpeed(){ return speed; }
    int getDegree(){ return degree; }
    
    void setSpeed(double inSpeed) { speed = inSpeed; }
    void setDegree( int inDegree){ degree = inDegree; }
};

class Clouds {
  int all;
  
  public:
    int getAll(){ return all; }
    void setAll( int inAll){ all = inAll; }
};

class Sys{
  int type;
  int id;
  double message;
  String country;
  long sunrise;
  long sunset;
  
  public:
    int getType(){ return type; }
    int getId(){ return id; }
    double getMessage(){ return message; }
    String getCountry(){ return country; }
    long getSunrise(){ return sunrise; }
    long getSunset(){ return sunset; }
    
    void setType(int inType){ type = inType; }
    void setId(int inId){ id = inId; }
    void setMessage(double inMessage){ message = inMessage; }
    void setCountry(String inCountry){ country = inCountry; }
    void setSunrise(long inSunrise){ sunrise = inSunrise; }
    void setSunset(long inSunset){ sunset = inSunset; }
};

class OpenWeatherMap {    
  int id;
  String name;
  int code;
  String httpResponse; 
  String base;
  int visibility;
  long dateTime;
  
  Coord coord;
  Weather weather;
  Main main;  
  Wind wind;
  Clouds clouds;
  Sys sys;
  
  public: 
    String getHttpResponse(){ return httpResponse; }    
    void setHttpResponse(String inHttpResponse){ httpResponse = inHttpResponse; } 
  
    int getId(){ return id; }
    void setId(int inId){ id = inId; }
    
    String getName(){ return name; }
    void setName(String inName){ name = inName; }
    
    int getCode(){ return code; }
    void setCode(int inCode){ code = inCode; }
    
    String getBase(){ return base; }
    void setBase(String inBase){ base = inBase; }
    
    int getVisibility(){ return visibility; }
    void setVisibility( int inVisibiity){ visibility = inVisibiity; }
    
    long getDateTime(){ return dateTime; }
    void setDateTime(long inDateTime){ dateTime = inDateTime; }
    
    Coord getCoord(){ return coord; }
    void setCoord(Coord inCoord){ coord = inCoord; }
    
    Weather getWeather(){ return weather; }
    void setWeather(Weather inWeather){ weather = inWeather; }
    
    Main getMain(){ return main; }
    void setMain(Main inMain){ main = inMain; }
    
    Wind getWind(){ return wind; }
    void setWind(Wind inWind){ wind = inWind; }
    
    Clouds getClouds(){ return clouds; }
    void setClouds(Clouds inClouds){ clouds = inClouds; }
    
    Sys getSys(){ return sys; }
    void setSys(Sys inSys){ sys = inSys; }
};

OpenWeatherMap parseCurrentJson(String httpResponse){ 
  OpenWeatherMap openWeatherMap; 
  openWeatherMap.setHttpResponse(httpResponse); 
  
  StaticJsonBuffer<2000> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(httpResponse);
  if (!root.success()) {
      return openWeatherMap; 
  }
  
  String base = root["base"];
  openWeatherMap.setBase(base);
  
  int visibility = root["visibility"];
  openWeatherMap.setVisibility(visibility);
  
  long dateTime = root["dt"];
  openWeatherMap.setDateTime(dateTime);
  
  int id = root["id"];
  openWeatherMap.setId(id);
  
  String name = root["name"];
  openWeatherMap.setName(name);
  
  int code = root["cod"];
  openWeatherMap.setCode(code);
  
  double longitude = root["coord"]["lon"];
  double latidude = root["coord"]["lat"];
  Coord coord;
  coord.setLongitude(longitude);
  coord.setLatitude(latidude);
    openWeatherMap.setCoord(coord);
      
  int weatherId = root["weather"][0]["id"];
  String weatherMain = root["weather"][0]["main"];
  String weatherDescription = root["weather"][0]["description"];
  String weatherIcon = root["weather"][0]["icon"];
  
  Weather weather;
  weather.setId(weatherId);
  weather.setMain(weatherMain);
  weather.setDescription(weatherDescription); 
  weather.setIcon(weatherIcon);
    openWeatherMap.setWeather(weather);
        
    double temp = root["main"]["temp"];
    double tempMin = root["main"]["temp_min"];
    double tempMax = root["main"]["temp_max"];
    int tempPressure = root["main"]["pressure"];
    int tempHumidity = root["main"]["humidity"];
    
  Main main;
  main.setTemp(temp);
  main.setTempMin(tempMin);
  main.setTempMax(tempMax);
  main.setPressure(tempPressure);
  main.setHumidity(tempHumidity);
  openWeatherMap.setMain(main);
  
  double windSpeed = root["wind"]["speed"];
  double windDegree = root["wind"]["deg"];
  
  Wind wind;
  wind.setSpeed(windSpeed);
  wind.setDegree(windDegree);
  openWeatherMap.setWind(wind);
  
  int cloudsAll = root["clouds"]["all"];
  
  Clouds clouds;
  clouds.setAll(cloudsAll);
  openWeatherMap.setClouds(clouds);
  
  int sysType = root["sys"]["type"];
  int sysId = root["sys"]["id"];
  double sysMessage = root["sys"]["message"];
  String sysCountry = root["sys"]["country"];
  long sysSunrise = root["sys"]["sunrise"];
  long sysSunset =  root["sys"]["sunset"];
  
  Sys sys;
  sys.setType(sysType);
  sys.setId(sysId);
  sys.setMessage(sysMessage);
  sys.setCountry(sysCountry);
  sys.setSunrise(sysSunrise);
  sys.setSunset(sysSunset);
  openWeatherMap.setSys(sys);
  
  return openWeatherMap; 
}

OpenWeatherMap openWeatherMap;

void mainData(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_16);
  display->drawString(0, 0, openWeatherMap.getName());
  Serial.println("1");
}

void windData(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
Serial.println("2a");
  Wind wind = openWeatherMap.getWind();
  Serial.println("2b");
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_16);
  display->drawString(0, 0, "Wind");
  display->setFont(ArialMT_Plain_10);  
  display->drawString(0, 16, "Speed:");
  String windSpeed = String(wind.getSpeed());
  windSpeed += " m/sec";
  display->drawString(55, 16, windSpeed);
  
  display->drawString(0, 30, "Degree:");
  String windDegree = String(wind.getDegree());
  windDegree += "°"; 
  display->drawString(55, 30, windDegree);  
  Serial.println("2");
}

void weather1Data(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  Main main = openWeatherMap.getMain();
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_16);
  display->drawString(0, 0, "Weather");
  display->setFont(ArialMT_Plain_10);  
  display->drawString(0, 16, "Temp.:");
  String weatherTemp = String(main.getTemp()-273.15,2);
  weatherTemp += "°C";
  display->drawString(63, 16, weatherTemp);
  String weatherTempMin = String(main.getTempMin()-273.15,2);
  weatherTempMin += "°C";
  display->drawString(0, 30, "min. Temp.:");
  display->drawString(63, 30, weatherTempMin);  
  String weatherTempMax = String(main.getTempMax()-273.15,2);
  weatherTempMax += "°C";
  display->drawString(0, 43, "max. Temp.:");
  display->drawString(63, 43, weatherTempMax);  
  Serial.println("3");
}

void weather2Data(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  Main main = openWeatherMap.getMain();
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_16);
  display->drawString(0, 0, "Weather");
  display->setFont(ArialMT_Plain_10);  
  
  display->drawString(0, 16, "Pressure:");
  String weatherPressure = String(main.getPressure());
  weatherPressure += " hPa";
  display->drawString(55, 16, weatherPressure);
   
  display->drawString(0, 30, "Humidity:");
  String weatherHumidity = String(main.getHumidity());
  weatherHumidity += " %";
  display->drawString(55, 30, weatherHumidity);  
  Serial.println("4");
}

FrameCallback frames[] = {mainData, windData, weather1Data, weather2Data};

void setup() {
  Serial.begin(115200);
  
  Serial.println();
  WiFiMulti.addAP(SSID, PW);

  const int frameCount = 4;
  ui.setTargetFPS(60);
  ui.setFrames(frames, frameCount);
  ui.init();
}

void showData(){
  Weather weather = openWeatherMap.getWeather();
  String icon = weather.getIcon();
  setWeatherIcon(icon);   
}

void setWeatherIcon(String icon){
  int pwmValue = WOLKE;
  if(icon == "01d"){ pwmValue = SONNE; } 
  else if(icon == "02d"){ pwmValue = WOLKE_SONNE; } 
  else if(icon == "03d"){ pwmValue = WOLKE; } 
  else if(icon == "04d"){ pwmValue = WOLKE_DUNKEL; } 
  else if(icon == "09d"){ pwmValue = REGEN; } 
  else if(icon == "10d"){ pwmValue = SONNE_REGEN; } 
  else if(icon == "11d"){ pwmValue = GEWITTER; } 
  else if(icon == "13d"){ pwmValue = SCHNEE; } 
  else if(icon == "50d"){ pwmValue = WOLKE; } 
  else if(icon == "01n"){ pwmValue = MOND; } 
  else if(icon == "02n"){ pwmValue = WOLKE_MOND; } 
  else if(icon == "03n"){ pwmValue = WOLKE; } 
  else if(icon == "04n"){ pwmValue = WOLKE_DUNKEL; } 
  else if(icon == "09n"){ pwmValue = REGEN; } 
  else if(icon == "10n"){ pwmValue = REGEN_MOND; } 
  else if(icon == "11n"){ pwmValue = GEWITTER; } 
  else if(icon == "13n"){ pwmValue = SCHNEE; } 
  analogWrite(D5,pwmValue);
}   

long lastUpdate = -1L;
long updateIntervall = 5000;

void loop() {
    if((WiFiMulti.run() == WL_CONNECTED) && ((lastUpdate+updateIntervall) < millis())) {
        lastUpdate = millis();
        HTTPClient http;
        Serial.println("[HTTP] begin...");
        http.begin(url);
        Serial.println("[HTTP] GET...");
        int httpCode = http.GET();
        if(httpCode > 0) {
            Serial.printf("[HTTP] GET... code: %d\n", httpCode);
            if(httpCode == HTTP_CODE_OK) {
                String response = http.getString();
                Serial.println(response);
                openWeatherMap = parseCurrentJson(response);
                showData();
            }
        } else {
            Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }
        http.end();
    }
    int remainingTimeBudget = ui.update();
}
