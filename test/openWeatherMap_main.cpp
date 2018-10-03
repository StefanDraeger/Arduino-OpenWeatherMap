#include "openWeatherMapTest.h"

char weatherJson[] = "{\"coord\": { \"lon\": 10.53, \"lat\": 52.26 }, \"weather\": [ { \"id\": 800, \"main\": \"Clear\", \"description\": \"clear sky\", \"icon\": \"01d\" } ], \"base\": \"stations\", \"main\": { \"temp\": 284.81, \"pressure\": 1019, \"humidity\": 58, \"temp_min\": 284.15, \"temp_max\": 285.15 }, \"visibility\": 10000, \"wind\": { \"speed\": 2.6, \"deg\": 210 }, \"clouds\": { \"all\": 0 }, \"dt\": 1538295600, \"sys\": { \"type\": 1, \"id\": 4925, \"message\": 0.0088, \"country\": \"DE\", \"sunrise\": 1538284651, \"sunset\": 1538326624 }, \"id\": 3221017, \"name\": \"Brunswick\", \"cod\": 200 }";

int main(){	
 OpenWeatherMap openWeatherMap = parseCurrentJson(weatherJson); 
 testCurrentOpenWeatherMapObject(openWeatherMap); 
 return 0; 
}
