This simply prints out a grid of colours to the serial terminl.
As the Arduino built in one don't suport colour you need to use one that suports VT100.

On my computer:
```
stty -F /dev/ttyUSB0 38400 raw
cat /dev/ttyUSB0
```
works
