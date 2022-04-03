#include "ui_io.h"
#include <Arduino.h> 
//#include <wire.h> 
byte indent = 0;
boolean lastLn = false;
bool quiteMode = false;

void pDet( boolean b, boolean c ) {//Print indent void pDet(boolean b = false, boolean c = false)
  byte x;
  if ( c ) indent++;
  if ( lastLn ) {
    for ( x = 0; x < indent; x++ ) Serial.print( "\t" );
  }
  lastLn = b;
}

void io_printPrePad_n( byte x, bool coma ) {
  Serial.print(x);
  if(coma) Serial.print(',');
  if ( x < 10 )Serial.print( ' ' );
  if ( x < 100 )Serial.print( ' ' );
}

void io_printHeading_side() {
  Serial.print( F( "===========" ) );
}
void io_printStart_Pre() {
  Serial.print( F( "Starting Function " ) );
}
void io_printStart_side() {
  Serial.print( F( "+++++++++++" ) );
}
void io_printStop_Pre() {
  Serial.print( F( "Stop Function " ) );
  indent--;
}
void io_printStop_side() {
  Serial.print( F( "-----------" ) );
}
unsigned long previousM;

void io_printTimeElapsed() {
  word m;
  byte s;
  word ms;
  word us;
  unsigned long t = micros() - previousM;
  us = t % 1000;
  t = t / 1000;
  ms = t % 1000;
  t = t / 1000;
  s = t % 60;
  t = t / 60;
  m = t;
  io_print( "format = m:s.ms,us " );
  Serial.print( m );
  Serial.print( ':' );
  Serial.print( s );
  Serial.print( '.' );
  if ( ms < 10 ) Serial.print( '0' );
  if ( ms < 100 ) Serial.print( '0' );
  Serial.print( ms );
  Serial.print( ',' );
  if ( us < 10 ) Serial.print( '0' );
  if ( us < 100 ) Serial.print( '0' );
  io_println_n( us );
  previousM = micros();
}
