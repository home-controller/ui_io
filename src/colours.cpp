/**
 * @file colours.cpp
 * @author jmnc2 (you@domain.com)
 * @brief Print out a grid of colours on the tty.
 * @version 0.1
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 * Note, the Arduino IDE term doesn't support colour Esc codes etc.
 * 
 */


#include <Arduino.h>

void setString(char r[], const char s[])
{
  byte i = 0;
  while (s[i] != 0 and (i < 15))
  {
    r[i] = s[i];
    i++;
  }
  r[i] = 0;
}

void printColourGrid(){
// 30-37: foreground colour, 40-47:background. 90-97: bright foreground, 100-107: bright background
// 0:black, 1:red, 2:green, 3:yellow, 4:blue, 5:magenta, 6:cyan, 7:white
// effects: 0=reset, 1=bold, 2=faint, 3=Italic, 4=underlined, 5=flash, 7=Reverse(swap foreground with background), 8=Hidden(passwords), 9=Strikethrough
#define maxFGColour 7
#define termResetColour "\e[37;48m"
#define termReset "\e[37;48m\e[0m\r\n"
  byte x, y, i;
  char a[15];
  //           01234567890123456789
  // char ra[] = "\e[0m\r\n";
  for (i = 0; i <= 8; i++) // back ground colour
  {
    //Serial.print(termResetColour);
    for (y = 0; y <= 9; y++)
    {
      // ra[3] = '0' + y;
      Serial.print(termReset);
      for (x = 0; x <= maxFGColour; x++)
      { //            0123456789
        setString(a, "[0;30;40m");
        a[4] = '0' + x;
        a[7] = '0' + i;
        a[1] = '0' + y;
        Serial.print("\e");
        Serial.print(a);
        Serial.print(a);
        Serial.print(' ');
      }
    }
    Serial.print(termReset); // 0b00010000
    for (x = 0; x <= maxFGColour; x++)
    {
      setString(a, "[0;90;40m");
      a[4] = '0' + x;
      a[7] = '0' + i;
      Serial.print("\e");
      Serial.print(a);
      Serial.print(a);
      Serial.print(' ');
    }
    Serial.print(termReset);

    for (x = 0; x <= maxFGColour; x++)
    {
      setString(a, "[0;30;100m");
      a[4] = '0' + x;
      a[8] = '0' + i;
      Serial.print("\e");
      Serial.print(a);
      Serial.print(a);
    }
    Serial.print(termReset);

    for (x = 0; x <= maxFGColour; x++)
    {
      setString(a, "[0;90;100m");
      a[4] = '0' + x;
      a[8] = '0' + i;
      Serial.print("\e");
      Serial.print(a);
      Serial.print(a);
    }
    Serial.print(termReset);
  }

}
