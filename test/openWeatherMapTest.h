#include "../src/openWeatherMapParser.h"

void printMsg(string str1, string str2, double expectedValue, double currentValue){ cout << str1 << str2 << " ["<< currentValue <<"] not equals "<< expectedValue << endl; }
void printMsg(string str1, string str2, int expectedValue, int currentValue){ cout << str1 << str2 << " ["<< currentValue <<"] not equals "<< expectedValue << endl; }
void printMsg(string str1, string str2, string expectedValue, string currentValue){	cout << str1 << str2 << " ["<< currentValue <<"] not equals "<< expectedValue << endl; }

void testCurrentOpenWeatherMapObject(OpenWeatherMap openWeatherMap){
	if(openWeatherMap.getBase() != "stations"){printMsg("", "base", "stations",openWeatherMap.getBase());}
	if(openWeatherMap.getVisibility() != 10000){printMsg("", "visibility", 10000, openWeatherMap.getVisibility());}
	if(openWeatherMap.getDateTime() != 1538295600){printMsg("","dt", 1538295600 ,openWeatherMap.getDateTime());}
	if(openWeatherMap.getId() != 3221017){printMsg("","id",3221017,openWeatherMap.getId());}
	if(openWeatherMap.getName() != "Brunswick"){printMsg("","name","Brunswick", openWeatherMap.getName());}
	if(openWeatherMap.getCode() != 200){printMsg("","code",200,openWeatherMap.getCode());;}
			
	if(openWeatherMap.getCoord().getLongitude() != 10.53){printMsg("coord", "longitude", 10.53, openWeatherMap.getCoord().getLongitude());}
	if(openWeatherMap.getCoord().getLatidute() != 52.26){printMsg("coord", "latidude",52.26,openWeatherMap.getCoord().getLatidute());}
	
	if(openWeatherMap.getWeather().getId() != 800){printMsg("weather","id",800,openWeatherMap.getWeather().getId());}	
	if(openWeatherMap.getWeather().getMain() != "Clear"){printMsg("weather","main","Clear",openWeatherMap.getWeather().getMain());}
	if(openWeatherMap.getWeather().getDescription() != "clear sky"){printMsg("weather","description","clear sky",openWeatherMap.getWeather().getDescription());}	
	
	if(openWeatherMap.getMain().getTemp() != 284.81){printMsg("main","temp",284.81,openWeatherMap.getMain().getTemp());}	
	if(openWeatherMap.getMain().getTempMin() != 284.15){printMsg("main","temp_min",284.15,openWeatherMap.getMain().getTempMin());}	
	if(openWeatherMap.getMain().getTempMax() != 285.15){printMsg("main","temp_max",285.15,openWeatherMap.getMain().getTempMax());}	
	if(openWeatherMap.getMain().getPressure() != 1019){printMsg("main","pressure",1019,openWeatherMap.getMain().getPressure());}	
	if(openWeatherMap.getMain().getHumidity() != 58){printMsg("main","humidity",58,openWeatherMap.getMain().getHumidity());}	
	
	if(openWeatherMap.getWind().getSpeed() != 2.6){printMsg("wind","speed",2.6,openWeatherMap.getWind().getSpeed());}	
	if(openWeatherMap.getWind().getDegree() != 210){printMsg("wind","deg",210,openWeatherMap.getWind().getDegree());}	
	
	if(openWeatherMap.getClouds().getAll() != 0){printMsg("clouds","all",0,openWeatherMap.getClouds().getAll());}	
	
	if(openWeatherMap.getSys().getId() != 4925){printMsg("sys","id",4925,openWeatherMap.getSys().getId());}	
	if(openWeatherMap.getSys().getType() != 1){printMsg("sys","type",1,openWeatherMap.getSys().getType());}	
	if(openWeatherMap.getSys().getMessage() != 0.0088){printMsg("sys","message", 0.0088,openWeatherMap.getSys().getMessage());}	
	if(openWeatherMap.getSys().getCountry() != "DE"){printMsg("sys","country","DE",openWeatherMap.getSys().getCountry());}	
	if(openWeatherMap.getSys().getSunrise() != 1538284651){printMsg("sys","sunrise",1538284651,openWeatherMap.getSys().getSunrise());}	
	if(openWeatherMap.getSys().getSunset() != 1538326624){printMsg("sys","sunset",1538326624,openWeatherMap.getSys().getSunset());}	
}
