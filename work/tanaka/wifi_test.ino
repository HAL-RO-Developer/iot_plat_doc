#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <FS.h>
#include <Wire.h>

#ifndef _TYPEDEF
#define _TYPEDEF
typedef          char   SCHR;
typedef unsigned char   UCHR;
typedef          short  SSHT;
typedef unsigned short  USHT;
typedef          long   SLNG;
typedef unsigned long   ULNG;
typedef          int    SINT;
typedef unsigned int    UINT;
typedef          double DBLE;
#endif

#define NUNCHACK_ADDR  ( 0x52 )
#define decode(data)  ( ( data ^ 0x17 ) + 0x17 )

#define MODE_PIN    ( 0 ) 
#define SDA_PIN     ( 4 )
#define SCL_PIN     ( 5 )
                     
#define PRESSED     ( 0 )
#define RELEASED    ( 1 )

const   SCHR*   settings    = "/settings.txt";
const   SCHR*   ap_ssid     = "ESP8266";
const   SCHR*   ap_pass     = "password";

typedef struct{
    String ssid;
    String pass;
    String host;
    String port;
}WIFICONFIG;

WIFICONFIG config;

ESP8266WebServer server( 80 );

/* WiFi Settings */
void handleRootGet()
{
    String html = "";
    html += "<h1>WiFi Settings</h1>";
    html += "<form method='post'>";
    html += "  <input type='text' name='ssid' placeholder='SSID'><br>";
    html += "  <input type='password' name='pass' placeholder='PASS'><br>";
    html += "  <input type='text' name='host' placeholder='HOST'><br>";
    html += "  <input type='text' name='port' placeholder='PORT'><br>";
    html += "  <input type='submit'><br>";
    html += "</form>";
    server.send( 200, "text/html", html );
}

void handleRootPost()
{
    String  ssid = server.arg("ssid");
    String  pass = server.arg("pass");
    String  host = server.arg("host");
    String  port = server.arg("port");
    
    File    file = SPIFFS.open( settings, "w" );
    file.println( ssid );
    file.println( pass );
    file.println( host );
    file.println( port );
    file.close();
    
    String html = "";
    html += "<h1>WiFi Settings</h1>";
	/*
	html += ssid + "<br>";
    html += pass + "<br>";
    html += host + "<br>";
    html += port + "<br>";
    */
	html += "<p>Settings changed</p>";
	server.send( 200, "text/html", html );
}

void getWiFiConfig()
{
    File   file = SPIFFS.open( settings, "r" );
    config.ssid = file.readStringUntil( '\n' );
    config.pass = file.readStringUntil( '\n' );
    config.host = file.readStringUntil( '\n' );
    config.port = file.readStringUntil( '\n' );
    file.close();
    
    config.ssid.trim();
    config.pass.trim();
    config.host.trim();
    config.port.trim();
    
	Serial.println();
    Serial.println( "SSID: " + config.ssid );
    Serial.println( "PASS: " + config.pass );
    Serial.println( "HOST: " + config.host );
    Serial.println( "PORT: " + config.port );
}

/* [SETUP] Client Mode */
void setup_client()
{
    getWiFiConfig();

    WiFi.begin( config.ssid.c_str(), config.pass.c_str() );
    WiFi.mode( WIFI_STA );
	
    while( WiFi.status() != WL_CONNECTED ){
        delay( 500 );
    }

    Serial.print( "IP address: " );
    Serial.println( WiFi.localIP() );
    Serial.println( "WiFi connected!" );
   
    
    /* Nunchack Setup ( I2C ) */
    Wire.begin( SDA_PIN, SCL_PIN );
    initNunchack();

}

/* [SETUP] Server Mode */
void setup_server()
{
	digitalWrite( 12, HIGH );
    Serial.println();
    Serial.print( "SSID: " );
    Serial.println( ap_ssid );
    Serial.print( "PASS: " );
    Serial.println( ap_pass );
	Serial.print("AP IP address: ");
	Serial.println( WiFi.softAPIP() );
    
    WiFi.softAP( ap_ssid, ap_pass );
    
    server.on( "/", HTTP_GET, handleRootGet );
    server.on( "/", HTTP_POST, handleRootPost );
    server.begin();
    Serial.println( "HTTP server started" );
}

void setup()
{
	pinMode( MODE_PIN, INPUT );
    pinMode( 12, OUTPUT );
	digitalWrite( 12, LOW );
   
    Serial.begin( 115200 );
    delay( 1000 );
    
    SPIFFS.begin();
    
    digitalRead( MODE_PIN ) ? setup_client() : setup_server();
	    
}

void initNunchack()
{
    Wire.beginTransmission( NUNCHACK_ADDR );
    Wire.write( 0x40 );
    Wire.write( 0x00 );
    Wire.endTransmission();
}

void writeZero()
{
    Wire.beginTransmission( NUNCHACK_ADDR );
    Wire.write( 0x00 );
    Wire.endTransmission();
}

void loop()
{	
    SINT    idx     = 0;
    SINT    data    = 0;
    
    SINT    nunchack[6];
    SINT    z_state = RELEASED;
    SINT    c_state = RELEASED;
    
	server.handleClient();
	
    Wire.requestFrom( NUNCHACK_ADDR, 6 );
    while( Wire.available() ){
        nunchack[idx] = decode( Wire.read() );
        idx++;
    }
    
    idx = 0;
    writeZero();
    
    z_state = ( nunchack[5] >> 0 ) & 0x01;
    c_state = ( nunchack[5] >> 1 ) & 0x01;
   
    data = z_state | ( c_state << 1 );
	
	sendMessage( data );

    delay( 50 );

}

void sendMessage( SINT data )
{
    WiFiClient  client;
    if( !client.connect( config.host.c_str(), config.port.toInt() ) ){
        return;
    }

    client.print( String(data) );
  
    while( client.available() ){
        String line = client.readStringUntil('\r');
    }
}

