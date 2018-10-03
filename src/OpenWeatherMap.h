#include <string>
using namespace std;

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
	string main;
	string description;
	string icon; 
	
	public:
		int getId(){ return id; }
		string getMain(){ return main; }
		string getDescription(){ return description; }
		string getIcon(){ return icon; }
				
		void setId(int inId){ id = inId;	}
		void setMain(string inMain){ main = inMain; }	
		void setDescription(string inDescription){ description = inDescription; }
		void setIcon(string inIcon){ icon = inIcon; }		
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
		
		void setTemp(double inTemp){ temp = inTemp;	}
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
	string country;
	long sunrise;
	long sunset;
	
	public:
		int getType(){ return type; }
		int getId(){ return id; }
		double getMessage(){ return message; }
		string getCountry(){ return country; }
		long getSunrise(){ return sunrise; }
		long getSunset(){ return sunset; }
		
		void setType(int inType){ type = inType; }
		void setId(int inId){ id = inId; }
		void setMessage(double inMessage){ message = inMessage; }
		void setCountry(string inCountry){ country = inCountry; }
		void setSunrise(long inSunrise){ sunrise = inSunrise; }
		void setSunset(long inSunset){ sunset = inSunset; }
};

class OpenWeatherMap { 		
	int id;
	string name;
	int code;
	char* httpResponse; 
	string base;
	int visibility;
	long dateTime;
	
	Coord coord;
	Weather weather;
	Main main;	
	Wind wind;
	Clouds clouds;
	Sys sys;
	
	public: 
		char* getHttpResponse(){ return httpResponse; } 		
		void setHttpResponse(char* inHttpResponse){ httpResponse = inHttpResponse; } 
	
		int getId(){ return id; }
		void setId(int inId){ id = inId; }
		
		string getName(){ return name; }
		void setName(string inName){ name = inName;	}
		
		int getCode(){ return code; }
		void setCode(int inCode){ code = inCode; }
		
		string getBase(){ return base; }
		void setBase(string inBase){ base = inBase; }
		
		int getVisibility(){ return visibility; }
		void setVisibility( int inVisibiity){ visibility = inVisibiity;	}
		
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
		void setClouds(Clouds inClouds){ clouds = inClouds;	}
		
		Sys getSys(){ return sys; }
		void setSys(Sys inSys){ sys = inSys; }
};
