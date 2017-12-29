#include <IRremote.h>
#include <Adafruit_NeoPixel.h>
#define PIN 6
#define PIN_NUM 2
#include <U8glib.h>//使用OLED需要包含这个头文件
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIN_NUM, PIN, NEO_GRB + NEO_KHZ800);
int RECV_PIN = 10;
int ledPin=8;
IRrecv irrecv(RECV_PIN);
decode_results results;
#define INTERVAL_LCD 0 //定义OLED刷新时间间隔 
unsigned long lcd_time = millis(); //OLED刷新时间计时器
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE); //设置OLED型号 
//-------字体设置，大、中、小
#define setFont_L u8g.setFont(u8g_font_7x13)
#define setFont_M u8g.setFont(u8g_font_fixed_v0r)
#define setFont_S u8g.setFont(u8g_font_fixed_v0r)
#define setFont_SS u8g.setFont(u8g_font_fub25n)
void setup() {
 Serial.begin(9600);
 Serial.println("Initialisation complete.");
 irrecv.enableIRIn();
 pinMode(ledPin,OUTPUT);
 strip.begin();
}
void loop(){
  if (irrecv.decode(&results)) {
Serial.println(results.value);
switch(results.value){
 case 33456255:
 tone(ledPin,262,100);
 strip.setPixelColor(0, strip.Color(255, 0, 0));delay(100);strip.setPixelColor(1, strip.Color(255, 255, 0));
  strip.show();
 u8g.firstPage();
do{
 u8g.drawFrame(0,1,127,62);
 u8g.drawFrame(0,0,127,64);
 u8g.drawLine(32,0,32,62);
 u8g.drawLine(64,0,64,62);
 u8g.drawLine(96,0,96,62);
 u8g.drawBox(1,0,32,62);
delay(0);

 }while(u8g.nextPage());
break;
case 33439935:
  tone(ledPin,294,100);
  strip.setPixelColor(0, strip.Color(255, 0, 255));delay(100);strip.setPixelColor(1, strip.Color(255, 255, 255));
  strip.show();
 u8g.firstPage();
do{
 u8g.drawFrame(0,1,127,62);
 u8g.drawFrame(0,0,127,64);
 u8g.drawLine(32,0,32,62);
 u8g.drawLine(64,0,64,62);
 u8g.drawLine(96,0,96,62);
 u8g.drawBox(32,0,32,62);
  delay(0);

}while(u8g.nextPage());
 break;

  case 33472575:tone(ledPin,330,100);strip.setPixelColor(0, strip.Color(0, 255, 0));delay(100);strip.setPixelColor(1, strip.Color(0, 255, 255));
  strip.show(); 
  u8g.firstPage();
  do{
 u8g.drawFrame(0,1,127,62);
 u8g.drawFrame(0,0,127,64);
 u8g.drawLine(32,0,32,62);
 u8g.drawLine(64,0,64,62);
 u8g.drawLine(96,0,96,62);
 u8g.drawBox(64,0,32,62);
  delay(0);

}while(u8g.nextPage());
  break;
  case 33431775:tone(ledPin,350,100);strip.setPixelColor(0, strip.Color(255, 255, 255));delay(100);strip.setPixelColor(1, strip.Color(255, 255, 0));
  strip.show(); 
   u8g.firstPage();
do{
 u8g.drawFrame(0,1,127,62);
 u8g.drawFrame(0,0,127,64);
 u8g.drawLine(32,0,32,62);
 u8g.drawLine(64,0,64,62);
 u8g.drawLine(96,0,96,62);
 u8g.drawBox(96,0,32,62);
  delay(0);

}while(u8g.nextPage());
  break;
 default:break;
}
 delay(100);
 ((void(*)())0)();
  }
}
