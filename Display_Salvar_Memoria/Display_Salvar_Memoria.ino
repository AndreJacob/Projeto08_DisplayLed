
/*
 = ** ======================== ** ======================= // ================================== ** =====================================
|   --   -----  -----------     --   -   --    ---      --   --   ------  ----------   -------   --   --------      --   --     -----   |
|  |  | |  -  | ----   ----    |  | |  \|  | |   -  \  |  | |  | |  ====  ----  ----  |   --  | |  | |   --   |    |  | |  |   |  -  |  |
|  |  | | | | |    |  |        |  | |      | |  | |  | |  | |  | |      |    |  |     |  |_  <  |  | |  |__|  |    |   -   |   | | |    |
|  |  | |  -  |    |  |        |  | |  |\  | |   -  /  |   -   |  ====       |  |     |  | |  | |  | |  |  |  |     --- |  |   |  -  |  |
|   --   -----      --          --   --  --    ---      -------   ------      --       --   --   --   --    --           --  O  -----   |
 ========================================================================================================================================   
|PROJECT TO INDUSTRIA 4.0 THIS EXAMPLE DEMONSTRATION INTERFACE IN ESP8266 AND MQTT WITH CONSTRUCT 2.                                    |
|WITH THIS DESIGN WE CAN OPERATE DEVICES MONITOR TEMPERATURE, CURRENT, VIBRATION,                                                       | 
|AUTHOR: ALVARO RAMOS                                                                                                                   |
|                                                                                                                                       |
| COM ESTE PROJETO PODEMOS ACIONAR DISPOSITIVOS MONITORAR SENSORES DE TEMPERATURA, CORRENTE , VIBRAÇÃO,                                 |
| AUTOR: ALVARO RAMOS                                                                                                                   |
| DATA: 11/12/2019                                                                                                                      | 
|                                                                                                                                       |
| SOFTWARE DETAILS IN DOCUMENTATION.                                                                                                    |
| DETALHES DO SOFTWARE NA DOCUMENTAÇÃO. 

// LED Matrix Pin -> ESP8266 Pin
// Vcc            -> 3v  (3V on NodeMCU 3V3 on WEMOS)
// Gnd            -> Gnd (G on NodeMCU)
// DIN            -> D7  (Same Pin for WEMOS)
// CS             -> D4  (Same Pin for WEMOS)
// CLK            -> D5  (Same Pin for WEMOS)|
 ========================================================================================================================================                              
*/
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>
#include <FS.h>

#include <Arduino.h>
#ifdef ESP32
#include <WiFi.h>
#include <AsyncTCP.h>
#else
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#endif
#include <ESPAsyncWebServer.h>

AsyncWebServer server(80);
//============================================================================================================

int pinCS = D4; // Attach CS to this pin, DIN to MOSI and CLK to SCK (cf http://arduino.cc/en/Reference/SPI )
int numberOfHorizontalDisplays = 4;
int numberOfVerticalDisplays   = 1;
char time_value[30];
String message;
int conf;
String configurar;

String version = "v1.0";       // Version of this program
Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays);
int wait   = 90; // In milliseconds between scroll movements
int spacer = 1;
int width  = 5 + spacer; // The font width is 5 pixels

// parametros Servidor
// REPLACE WITH YOUR NETWORK CREDENTIALS
const char* ssid = "Coloque aqui o nome da sua rede Wifi";
const char* password = "Coloque aqui a senha do seu wifi";
const char* PARAM_INPUT_1 = "input1";

//====================================================================================================
void writeFile(String state, String path);
void openFS(void);
String readFile(String path);
void display_message(String message);
void Initialize();
void DisplayMensage();
void InitHtml();
void notFound(AsyncWebServerRequest *request);
//====================================================================================================

void setup(){
Initialize();
InitHtml();
}

void loop() {    
DisplayMensage();

}




  
