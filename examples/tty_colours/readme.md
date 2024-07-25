This example simply prints out a grid of colours to the serial terminal.
As the Arduino built in one don't support colour you need to use one that supports VT100.

On my computer using the standard bash console works.

I am using Linux with a KDE desktop and using Konsole as the terminal.

As an example with my Nano board plugged in on /dev/ttyUSB0 and the serial speed set to 38400 the following bash commands work:
```
stty -F /dev/ttyUSB0 38400 raw
cat /dev/ttyUSB0
```

cat returned after each line when I had 2 arduinos 1 each on /dev/ttyUSB0 and /dev/ttyUSB1 buf tail still worked.
```
tail -f /dev/
```
I can also use the cat command in another bash terminal to type to the Nano.
