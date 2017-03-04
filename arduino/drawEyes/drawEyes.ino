#include "U8glib.h"
#include "math.h"

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NO_ACK);  // Display which does not send AC

void u8g_prepare(void) {
  u8g.setFont(u8g_font_6x10);
  u8g.setFontRefHeightExtendedText();
  u8g.setDefaultForegroundColor();
  u8g.setFontPosTop();
}


void u8g_disc_circle(double a) {
//  u8g.drawStr(30,31, String(sin(a)));
//  String thisString = String(sin(a)*20);
//  char charBuf[50];
//  thisString.toCharArray(charBuf, 50);
  int x = sin(a)*20;
  int y = cos(a)*20;
//  u8g.drawStr( 0, 0, charBuf);
  u8g.drawDisc(20+x,31+y,9);
  u8g.drawCircle(20,40,20);
  u8g.drawDisc(80+x,31+y,9);
  u8g.drawCircle(80,40,20);
}

uint8_t draw_state = 0;
double theta = 0.0d;

void draw(void) {
  u8g_prepare();
  u8g_disc_circle(theta);
}

void setup(void) {

  // flip screen, if required
  //u8g.setRot180();

#if defined(ARDUINO)
  pinMode(13, OUTPUT);           
  digitalWrite(13, HIGH);  
#endif
}
double adder = 0.1d;
void loop(void) {
  
  // picture loop  
  u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );
  
  theta = theta + adder;
  if ( theta > 0.5d )
    adder = -0.1d;
  if( theta < -0.5d)
    adder = 0.1d;
  
  // rebuild the picture after some delay
//  delay(10);

}


