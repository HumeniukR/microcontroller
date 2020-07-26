# microcontroller
Arduino sketch for smart home 

### Instalation
Connect your Arduino to the PC, set up drivers if needed.
Download [Arduino IDE](https://www.arduino.cc/en/main/software).
Clone microcontroller repo on your PC.
Arduino IDE contains the bootloader which you should use.
Here you find a [Tutorial](https://www.arduino.cc/en/Tutorial/HomePage).

### Deatails
Using this code we can manage devices connected to the Arduino via Serial port.
Also, we can receive info from buttons. In my case buzzer simulate alarm, button simulate door open/close, stepper motor open/close window

### Serial commands

```sh
 1234>led-on:2|        // enable light in room #2 (1234 - secret)
 1234>led-Off:4|       // disable light in room #4
 1234>win-set:50|      // open window on 50 percent
 1234>pin-code:5678|   // enable or diable alarm (5678 - alarm pin code)
```

### Schema
![alt text](https://github.com/HumeniukR/microcontroller/blob/master/Detailed_schema.PNG?raw=true)

### TODO
- add comments in the microcontroller codebasse
- improve error handing
