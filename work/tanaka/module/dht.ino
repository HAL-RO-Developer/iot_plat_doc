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
	//���悻250ms���ƂɎ擾
    float h = dht.readHumidity();		//���x�擾
    float t = dht.readTemperature();	//���x�擾

  
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