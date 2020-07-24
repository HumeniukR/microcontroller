String superSecretNumber = "4785";
int alarmPinCode = 1234;
int ledPins[6] = {8,9,10,11,12,13};
int buzzer = 5;
int button = 7;
/*stepper pins*/
int PUL=2;
int DIR=3;
int ENA=4;
int del=50;

int btnVal;
struct command
{
  String name;
  int value;
};
command curCmd;


void setup() {
  Serial.begin(9600);
  for(int i = 0; i < 6; i ++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode (PUL, OUTPUT);
  pinMode (DIR, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  if (Serial.available() > 0) {
    curCmd = readCommand();
  }
  handleCommand(curCmd);
  btnVal = !digitalRead(button);
  handleDoor(btnVal);
  handleAlarm(btnVal);
}

struct command readCommand() {
  String secret = Serial.readStringUntil('>');
  command cmd;
  if (secret == superSecretNumber) {
    cmd.name = Serial.readStringUntil(':');
    cmd.value = Serial.readStringUntil('|').toInt();
  } else {
    resetCommand();
  }
  return cmd;
}

void handleCommand(command cmd) {
  if (cmd.name == "led-on") { // "4785>led-on:8|" : on - "4785>led-off:8|" : off
    ledOn(cmd.value);
  } else if (cmd.name == "led-off") {
    ledOff(cmd.value);
  } else if (cmd.name == "win-set"){ // "4785>win-set:50|" - set window to 50%
    setJalousiePos((int)cmd.value);
    resetCommand();  
  } else if(cmd.name == "tone-set") {
    alarmTone((int)cmd.value);
    Serial.println("OK:tone_set");
    resetCommand();
  } else if(cmd.name == "pin-code") {
    setCode((int)cmd.value);
    resetCommand();
  } else {
    //Serial.println("ERR");
    resetCommand(); 
  }
}

void resetCommand() {
  curCmd = (command) {
    "", 0
  };
}
