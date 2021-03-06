#include             <ESP8266WiFi.h>
#include            <WiFiClient.h>

WiFiClient client;
char s[100];

void setup() {
int i;
char ssid[] = "********";
char pass[] = "********";

int   status;

Serial.begin(115200);
Serial.println("");
Serial.print("Tryingonnect to ");
Serial.println(ssid);

// attempt to connect to Wifi network:
status = WiFi.begin(ssid, pass);

status = WiFi.waitForConnectResult();
if (status != WL_CONNECTED) {
    Serial.println("Connection Failed");
    while (true) {}
}
Serial.println("wifi OK!!");
if (!client.connect("192.168.100.199", 1234)) {
    Serial.println("Connection to echo server failed");
    while (true) {}
    }

client.println("connect!!");
// client.available()
// client.read()
} // setup

void loop() {
    if(client.available()){
        wifi_read(&s[0]);
        Serial.println(s);
    }
}

void wifi_read(char str[]){
    int i = 0;
    while (true) {
        while (client.available() == 0) {}
        str[i] = client.read();
        if (str[i] == '@') {
            str[i] = '\0';
            break; // while
        }
        i = i + 1;
    } // while
}
