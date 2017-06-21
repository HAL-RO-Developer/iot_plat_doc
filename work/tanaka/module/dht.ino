#include "DHT.h"

#define DHTPIN 5 
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);

void setup() 
{
    Serial.begin(115200); 
    Serial.println("DHTxx test!");

    dht.begin();
}

void loop() 
{
	//およそ250msごとに取得
    float h = dht.readHumidity();		//湿度取得
    float t = dht.readTemperature();	//温度取得

  
    if (isnan(t) || isnan(h)){
        Serial.println("Failed to read from DHT");
    }else {
        Serial.print("Humidity: "); 
        Serial.print(h);
        Serial.print(" %\t");
        Serial.print("Temperature: "); 
        Serial.print(t);
        Serial.println(" *C");
    }
}