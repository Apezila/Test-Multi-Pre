#include <Arduino.h>
#include <Wire.h>
#include <I2CEEPROM.h>
#include <OneButton.h>
#include "TFT_22_ILI9225.h"
#include "Adafruit_MCP23017.h"

#include <Rotary.h>
#include <RotaryEncOverMCP.h>
#define TFT_RST PA2
#define TFT_RS  PA4
#define TFT_CS  PA3  // SS
#define TFT_SDI PA7  // MOSI
#define TFT_CLK PA5  // SCK
#define TFT_LED 0   // 0 if wired to +5V directly
#define TFT_BRIGHTNESS 200 // Initial brightness of TFT backlight (optional)
TFT_22_ILI9225 tft = TFT_22_ILI9225(TFT_RST, TFT_RS, TFT_CS, TFT_LED, TFT_BRIGHTNESS);

Adafruit_MCP23017 mcp;
Adafruit_MCP23017 mcpx;

I2CEEPROM eep(0x50);
int preset;
int Fxset;
int Ampset=0;
OneButton Up(PB10, true);
OneButton Down(PB1, true);
OneButton Set(PB8, true);
OneButton Bypass(PB0, true);

const int LED_UP = 8;
const int LED_BYPASS = 9;
const int LED_PRE = 10;
const int LED_Pedal = 11;
const int LED_DOWN = 12;
int FV_S0 = PB9;
int FV_S1 = PA0;
int FV_S2 = PA1;
//const int Bypass_Button = PB0;

byte amptype;
byte Outtype;
byte Fxtype;
byte Simtype;
byte Revtype;
byte Looptype;
byte Deptype;

int Bypasstype;
int BypassButtonState=1;         
int lastBypassButtonState=1;

int ledPedalState;
int ledPreState=LOW;

int GaPresetValue=50;
int BaPresetValue=50;
int MiPresetValue=50;
int TrePresetValue=50;
int LevPresetValue=50;
int RevPresetValue=50;
int DepPresetValue=50;
int RatPresetValue=50;

int v1Amt=0;
int v1OldA = HIGH;
int v1OldB = HIGH;
const int v1CC=1;
const int v1Clk=4;
const int v1Dta=5;

int v2Amt;
int v2OldA = HIGH;
int v2OldB = HIGH;
const int v2CC=2;
const int v2Clk=6;
const int v2Dta=7;

int v3Amt;
int v3OldA = HIGH;
int v3OldB = HIGH;
const int v3CC=3;
const int v3Clk=8;
const int v3Dta=9;

int v4Amt;
int v4OldA = HIGH;
int v4OldB = HIGH;
const int v4CC=4;
const int v4Clk=10;
const int v4Dta=11;

int v5Amt;
int v5OldA = HIGH;
int v5OldB = HIGH;
const int v5CC=5;
const int v5Clk=0;
const int v5Dta=1;

int v6Amt;
int v6OldA = HIGH;
int v6OldB = HIGH;
const int v6CC=6;
const int v6Clk=2;
const int v6Dta=3;

int v7Amt;
int v7OldA = HIGH;
int v7OldB = HIGH;
const int v7CC=7;
const int v7Clk=12;
const int v7Dta=13;

int v8Amt;
int v8OldA = HIGH;
int v8OldB = HIGH;
const int v8CC=8;
const int v8Clk=14;
const int v8Dta=15;


int REV_button=0;
const int REV_buttonPin = 0;
int REVState =0;
int lastREVState =0;

int AMP_button=0;
const int AMP_buttonPin = 1;
int AMPState =0;
int lastAMPState =0;

int OUT_button=0;
const int OUT_buttonPin = 2;
int OUTState =0;
int lastOUTState =0;

int LOOP_button=0;
const int LOOP_buttonPin = 4;
int LOOPState =0;
int lastLOOPState =0;

int SIM_button=0;
const int SIM_buttonPin = 3;
int SIMState =0;
int lastSIMState =0;

int FX_button=0;
const int FX_buttonPin = 5;
int FXState =0;
int lastFXState =0;

int DEP_button=0;
const int DEP_buttonPin = 6;
int DEPState =0;
int lastDEPState =0;


byte rgbtable[100][3]{
  {0,0,0},
  {255,255,255},
  {255,255,255},
  {224,255,255},
  {224,255,255},
  {192,255,255},
  {192,255,255},
  {160,255,255},
  {160,255,255},
  {128,255,255},
  {128,255,255},
  {96,255,255},
  {64,255,255},
  {32,255,255},
  {0,255,255},
  {0,255,255},
  {0,255,240},
  {0,255,240},
  {0,255,224},
  {0,255,224},
  {0,255,209},
  {0,255,209},
  {0,255,192},
  {0,255,192},
  {0,255,177},
  {0,255,177},
  {0,255,160},
  {0,255,160},
  {0,255,145},
  {0,255,145},
  {0,255,128},
  {0,255,128},
  {0,255,96},
  {0,255,96},
  {0,255,64},
  {0,255,64},
  {0,255,32},
  {0,255,32},
  {0,255,0},
  {0,255,0},
  {32,255,0},
  {32,255,0},
  {47,255,0},
  {47,255,0},
  {64,255,0},
  {64,255,0},
  {79,255,0},
  {79,255,0},
  {96,255,0},
  {96,255,0},
  {111,255,0},
  {111,255,0},
  {128,255,0},
  {128,255,0},
  {143,255,0},
  {143,255,0},
  {160,255,0},
  {160,255,0},
  {175,255,0},
  {175,255,0},
  {192,255,0},
  {192,255,0},
  {207,255,0},
  {207,255,0},
  {224,255,0},
  {224,255,0},
  {239,255,0},
  {239,255,0},
  {255,255,0},
  {255,255,0},
  {255,240,0},
  {255,240,0},
  {255,224,0},
  {255,224,0},
  {255,209,0},
  {255,209,0},
  {255,192,0},
  {255,192,0},
  {255,177,0},
  {255,177,0},
  {255,160,0},
  {255,160,0},
  {255,145,0},
  {255,145,0},
  {255,128,0},
  {255,128,0},
  {255,113,0},
  {255,113,0},
  {255,96,0},
  {255,96,0},
  {255,81,0},
  {255,81,0},
  {255,64,0},
  {255,64,0},
  {255,49,0},
  {255,49,0},
  {255,32,0},
  {255,32,0},
  {255,17,0}, 
  {255,0,0},
  };


void setup() {
  Wire.begin();
  eep.begin(); 
  tft.begin();
  tft.setOrientation(3);
  tft.setFont(Terminal12x16);
  tft.drawText(40, 30, "A P E Z I L A", COLOR_WHITE);
  tft.drawText(48, 60, "C O R A N A", COLOR_WHITE);
  delay(2000);
  tft.clear();
  Serial.begin(115200);

  pinMode(FV_S0,OUTPUT);
  pinMode(FV_S1,OUTPUT);
  pinMode(FV_S2,OUTPUT);
  pinMode(PA6,OUTPUT);
  pinMode(PC13,OUTPUT);
  pinMode(PB11,OUTPUT);
  //pinMode(Bypass_Button,INPUT);
  //pinMode(Bypass_Button,INPUT_PULLUP);
  preset=eep.read(0);
  
  Up.attachClick(UpClick);
  Down.attachClick(DownClick);
  Set.attachDuringLongPress(SetPress);
  Bypass.attachClick(BypassClick);
   
  mcp.begin(0);
  mcp.pinMode(0, INPUT);
  mcp.pinMode(1, INPUT);
  mcp.pinMode(2, INPUT);
  mcp.pinMode(3, INPUT);
  mcp.pinMode(4, INPUT);
  mcp.pinMode(5, INPUT);
  mcp.pinMode(6, INPUT);
  mcp.pinMode(7, INPUT);
  mcp.pinMode(8, INPUT);
  mcp.pinMode(9, INPUT);
  mcp.pinMode(10, INPUT);
  mcp.pinMode(11, INPUT);
  mcp.pinMode(12, INPUT);
  mcp.pinMode(13, INPUT);
  mcp.pinMode(14, INPUT);
  mcp.pinMode(15, INPUT);
  
  mcpx.begin(1);
  mcpx.pinMode(REV_buttonPin, INPUT);
  mcpx.pullUp(REV_buttonPin, HIGH);

  mcpx.pinMode(AMP_buttonPin, INPUT);
  mcpx.pullUp(AMP_buttonPin, HIGH);

  mcpx.pinMode(OUT_buttonPin, INPUT);
  mcpx.pullUp(OUT_buttonPin, HIGH);

  mcpx.pinMode(LOOP_buttonPin, INPUT);
  mcpx.pullUp(LOOP_buttonPin, HIGH);

  mcpx.pinMode(SIM_buttonPin, INPUT);
  mcpx.pullUp(SIM_buttonPin, HIGH);

  mcpx.pinMode(FX_buttonPin, INPUT);
  mcpx.pullUp(FX_buttonPin, HIGH);

  mcpx.pinMode(DEP_buttonPin, INPUT);
  mcpx.pullUp(DEP_buttonPin, HIGH);
  //attachInterrupt(1,BUTTON,CHANGE);
  
  
  mcpx.pinMode(LED_UP, OUTPUT);
  mcpx.pinMode(LED_BYPASS, OUTPUT);
  mcpx.pinMode(LED_PRE, OUTPUT);
  mcpx.pinMode(LED_Pedal, OUTPUT);
  mcpx.pinMode(LED_DOWN, OUTPUT);

  MainDisplay();
}

void MainDisplay () {
  
  Ampset = eep.read(preset +100 );
  delay(3);
  GaPresetValue = eep.read(preset + 200);
  delay(3);
  BaPresetValue = eep.read(preset + 300);
  delay(3);
  MiPresetValue = eep.read(preset + 400);
  delay(3);
  TrePresetValue = eep.read(preset + 500);
  delay(3);
  LevPresetValue = eep.read(preset + 600);
  delay(3);
  RevPresetValue = eep.read(preset + 700);
  delay(3);
  DepPresetValue = eep.read(preset + 800);
  delay(3);
  RatPresetValue = eep.read(preset + 900);
  delay(3);
  Fxset = eep.read(preset + 1000);
  delay(3);
  LOOP_button = eep.read(preset + 1050);
  delay(3);
  SIM_button = eep.read(preset + 1060);

  tft.clear();
  tft.setFont(Terminal12x16);
  tft.drawText(0, 2, "PRESET : ", COLOR_WHITE);
  tft.drawText(105, 2, String(preset)+"         ", COLOR_WHITE);
  tft.drawText(0, 22, "AMP: ", COLOR_WHITE);
  AmpTypePrint(Ampset);
  
  tft.setFont(Terminal6x8);
  
  tft.drawText(0, 45, "Gain", COLOR_WHITE);
  tft.drawRectangle(50, 44, 154, 52, COLOR_WHITE);
  byte iGP = GaPresetValue;
  int ColorGaP = tft.setColor(rgbtable[iGP][0],rgbtable[iGP][1],rgbtable[iGP][2]);
  tft.fillRectangle(52,46,(GaPresetValue+55),50, ColorGaP);
  
  tft.drawText(0, 57, "Bass", COLOR_WHITE);
  tft.drawRectangle(50, 56, 154, 64, COLOR_WHITE);
  byte iBP = BaPresetValue;
  int ColorBaP = tft.setColor(rgbtable[iBP][0],rgbtable[iBP][1],rgbtable[iBP][2]);
  tft.fillRectangle(52,58,(BaPresetValue+55),62, ColorBaP);
  
  tft.drawText(0, 69, "Middle", COLOR_WHITE);
  tft.drawRectangle(50, 68, 154, 76, COLOR_WHITE);
  byte iMP = MiPresetValue;
  int ColorMiP = tft.setColor(rgbtable[iMP][0],rgbtable[iMP][1],rgbtable[iMP][2]);
  tft.fillRectangle(52,70,(MiPresetValue+55),74, ColorMiP);
  
  tft.drawText(0, 81, "Treble", COLOR_WHITE);
  tft.drawRectangle(50, 80, 154, 88, COLOR_WHITE);
  byte iTP = TrePresetValue;
  int ColorTrP = tft.setColor(rgbtable[iTP][0],rgbtable[iTP][1],rgbtable[iTP][2]);
  tft.fillRectangle(52,82,(TrePresetValue+55),86, ColorTrP);
 
  tft.drawText(0, 93, "Level", COLOR_WHITE);
  tft.drawRectangle(50, 92, 154, 100, COLOR_WHITE);
  byte iLP = LevPresetValue;
  int ColorLeP = tft.setColor(rgbtable[iLP][0],rgbtable[iLP][1],rgbtable[iLP][2]);
  tft.fillRectangle(52,94,(LevPresetValue+55),98, ColorLeP);
  
  FxTypePrint(Fxset);
  
  tft.drawText(0, 123, "Reverb", COLOR_WHITE);
  tft.drawRectangle(50, 122, 154, 130, COLOR_WHITE);
  byte iReP = RevPresetValue;
  int ColorReP = tft.setColor(rgbtable[iReP][0],rgbtable[iReP][1],rgbtable[iReP][2]);
  tft.fillRectangle(52,124,(RevPresetValue+55),128, ColorReP);
  int FV1_S0 = RevPresetValue;
  FV1_S0 = map(FV1_S0, 0, 99, 0, 255);
  analogWrite(FV_S0, FV1_S0);

  tft.drawText(0, 135, "Rate", COLOR_WHITE);
  tft.drawRectangle(50, 134, 154, 142, COLOR_WHITE);
  byte iRaP = RatPresetValue;
  int ColorRaP = tft.setColor(rgbtable[iRaP][0],rgbtable[iRaP][1],rgbtable[iRaP][2]);
  tft.fillRectangle(52,136,(RatPresetValue+55),140, ColorRaP);
  int FV1_S1 = RatPresetValue;
  FV1_S1 = map(FV1_S1, 0, 99, 0, 255);
  analogWrite(FV_S1, FV1_S1);

  tft.drawText(0, 147, "Depth", COLOR_WHITE);
  tft.drawRectangle(50, 146, 154, 154, COLOR_WHITE);
  byte iDeP = DepPresetValue;
  int ColorDeP = tft.setColor(rgbtable[iDeP][0],rgbtable[iDeP][1],rgbtable[iDeP][2]);
  tft.fillRectangle(52,148,(DepPresetValue+55),152, ColorDeP);
  int FV1_S2 = DepPresetValue;
  FV1_S2 = map(FV1_S2, 0, 99, 0, 255);
  analogWrite(FV_S2, FV1_S2);

  tft.drawText(0, 164, "Mode:", COLOR_WHITE);
  tft.drawText(87, 164, "CabSim:", COLOR_WHITE); 
  //tft.drawText(134, 164, String(Simtype), COLOR_WHITE);
  tft.drawText(165, 164, "Loop:", COLOR_WHITE);
  //tft.drawText(200, 164, String(Looptype), COLOR_WHITE);
  //delay(1);
  
  //eep.write(0, preset); 
  v1Amt = GaPresetValue;
  v2Amt = BaPresetValue;
  v3Amt = MiPresetValue;
  v4Amt = TrePresetValue;
  v5Amt = LevPresetValue;
  v6Amt = RevPresetValue;
  v7Amt = RatPresetValue;
  v8Amt = DepPresetValue;
  AMP_button = Ampset;
  FX_button = Fxset;

}

void loop() {    
     ENC();
     Up.tick();
     Down.tick();
     Bypass.tick();
     Set.tick();
     BUTTON();    

    
    }

void AmpTypePrint(int index) {
amptype = index; //global
  switch (index) {    
    case 0:
      tft.setFont(Terminal12x16);
      tft.drawText(65, 22, "CLEAN        ", COLOR_CYAN);
      digitalWrite(PB15,HIGH);
      digitalWrite(PA8,LOW);
      digitalWrite(PA9,LOW);  
      break;
    case 1:
      tft.setFont(Terminal12x16);
      tft.drawText(65, 22, "OVERDRIVE ", COLOR_YELLOW);
      digitalWrite(PB15,LOW);
      digitalWrite(PA8,HIGH);
      digitalWrite(PA9,LOW);    
      break;
    case 2:
      tft.setFont(Terminal12x16);
      tft.drawText(65, 22, "DISTORTION", COLOR_TOMATO); 
      digitalWrite(PB15,LOW);
      digitalWrite(PA8,LOW);
      digitalWrite(PA9,HIGH);    
      break;
  }
}

void UpClick (){
   preset++;
  
  if(preset > 50){
      preset = 0;
    }
   mcpx.digitalWrite(LED_UP,HIGH);
   delay(20);
   mcpx.digitalWrite(LED_UP,LOW);
   MainDisplay();
}

void DownClick (){
  preset--;
  
  if(preset < 0){
      preset = 50;
    }   
  mcpx.digitalWrite(LED_DOWN,HIGH);
  delay(20);
  mcpx.digitalWrite(LED_DOWN,LOW);
  MainDisplay();
}



 
