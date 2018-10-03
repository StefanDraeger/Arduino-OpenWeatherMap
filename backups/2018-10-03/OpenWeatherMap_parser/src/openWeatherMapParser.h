#include <iostream>
#include <cstdlib>
#include <string>
#include "../ArduinoJson/ArduinoJson.h"
#include "OpenWeatherMap.h"

using namespace std;

OpenWeatherMap parseCurrentJson(char* httpResponse){ 
	OpenWeatherMap openWeatherMap; 
	openWeatherMap.setHttpResponse(httpResponse); 
	
	//Die länge des JSONs muss hier ggf. angepasst werden
 	StaticJsonBuffer<2000> jsonBuffer;
 	JsonObject& root = jsonBuffer.parseObject(httpResponse);
 	//prüfen ob das JSON Objekt erfolgreich geparst wurde
 	if (!root.success()) {
    	cout << "parseObject() failed" << endl;
    	return openWeatherMap; 
  	} else {
  		cout << "parseObject() successfull" << endl;
  	}
	
	string base = root["base"];
	openWeatherMap.setBase(base);
	
	int visibility = root["visibility"];
	openWeatherMap.setVisibility(visibility);
	
	long dateTime = root["dt"];
	openWeatherMap.setDateTime(dateTime);
	
	int id = root["id"];
	openWeatherMap.setId(id);
	
	string name = root["name"];
	openWeatherMap.setName(name);
	
	double longitude = root["coord"]["lon"];
	double latidude = root["coord"]["lat"];
	Coord coord;
	coord.setLongitude(longitude);
	coord.setLatitude(latidude);
    openWeatherMap.setCoord(coord);
    	
	int weatherId = root["weather"][0]["id"];
	string weatherMain = root["weather"][0]["main"];
	string weatherDescription = root["weather"][0]["description"];
	string weatherIcon = root["weather"][0]["icon"];
	
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
	string sysCountry = root["sys"]["country"];
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
