#ifndef _ui_ha_h //User Interface for Home Auto
#define _ui_ha_h
#include <Arduino.h>
#include "colours.h"
//#include <Serial.h>

//byte indent = 0;
//boolean lastLn = false;
extern boolean lastLn;// = false;
extern unsigned long previousM;
extern bool quiteMode;

#define io_l io_print( "file:" ); Serial.print( __FILE__ ); io_print( ", Line:" ); Serial.println( __LINE__ );

#define io_println(S) pDet(true); Serial.println(F(S) ) // print a string stored in program flash instead of ram.
#define io_ln lastLn = true; Serial.println() // print a string stored in program flash instead of ram.
#define io_print(S) pDet(); Serial.print(F(S) );
#define io_println_n(N) pDet(true); Serial.println(N) //output a number
#define io_print_n(N) pDet(); Serial.print(N) //output a number
#define io_print_nb(N) pDet(); Serial.print(N, BIN) //output a number
#define io_println_nb(N) pDet(); Serial.println(N, BIN) //output a number
#define io_print_nh(N) pDet(); Serial.print("0x"); if(N <16){Serial.print("0");} Serial.print(N, HEX) //output a number
#define io_print_nh2(N) pDet(); if(N <16){Serial.print("0");} Serial.print(N, HEX) //output a number
#define io_println_nh(N) pDet(); Serial.print("0x"); if(N <16){Serial.print("0");} Serial.println(N, HEX) //output a number
#define io_printlnMenuOpt(N) lastLn = true; Serial.print(F("Menu option selected:") ); Serial.println(N);  //output a number
#define io_printHeading(S) io_ln; pDet(); io_printHeading_side(); Serial.print(F(S) ); io_printHeading_side(); io_l; Serial.println();
#define io_printHeadingW(S) io_ln; pDet(); io_printHeading_side(); io_printHeading_side();Serial.print(F(S) ); io_printHeading_side(); io_printHeading_side(); io_l; Serial.println();
#define io_printStartFunc(S) io_ln; pDet(false,true); io_printStart_side(); io_printStart_Pre(); Serial.print(F(S) ); io_printStart_side();io_ln;
#define io_printEndFunc(S) pDet(); io_printStop_side(); io_printStop_Pre(); Serial.print(F(S) ); io_printStop_side();    io_ln; io_ln;

// 30-37: foreground colour, 40-47:background. 90-97: bright foreground, 100-107: bright background
// 0:black, 1:red, 2:green, 3:yellow, 4:blue, 5:magenta, 6:cyan, 7:white
// effects: 0=reset, 1=bold, 2=faint, 3=Italic, 4=underlined, 5=flash, 7=Reverse(swap foreground with background), 8=Hidden(passwords), 9=Strikethrough
#define maxFGColour 7
#define termResetColour "\e[37;48m"
#define termReset "\e[37;48m\e[0m\r\n"

#define vt100_red  "\e[31m"
#define vt100_redB  "\e[91m"
#define vt100_green  "\e[32;48m"
#define vt100_yellow  "\e[33m"

#define vtRed io_print(vt100_red);
#define vtRedB io_print(vt100_redB);
#define vtGreen io_print(vt100_green) 
#define vtYellow io_print(vt100_yellow);

#define vtResetColour io_print(termResetColour)
//Rule
//If the function has a forward declaration, put the default argument there. Otherwise, put them in the function definition. This is good practice and not a c rule I think
//eg. add "#include UI_IO.h" to top of UI_IO.cpp when puting a forward in function UI_IO.h to a function in UI_IO.cpp

void pDet(boolean b = false, boolean c = false);

void io_printHeading_side();
void io_printStart_Pre();
void io_printStart_side();
void io_printStop_Pre();
void io_printStop_side();

void io_printTimeElapsed();

void io_printPrePad_n(byte x, bool = false);
void io_print_nb_f(byte x, bool coma);


#endif
