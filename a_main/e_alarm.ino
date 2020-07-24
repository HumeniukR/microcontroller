void okTone(int times) {
  for(int i=0; i < times; i++) {
    tone(buzzer,329);      
    delay(200);     
    tone(buzzer,349);    
    delay(200);     
    tone(buzzer,392);            
    delay(200);
    noTone(buzzer);
  }
}

void doneTone(int times) {
  for(int i=0; i < times; i++) {
    tone(buzzer,10);      
    delay(100);     
    tone(buzzer,500);    
    delay(100);     
    noTone(buzzer);
  }
}

void alarmTone(int times) {
  for(int i=0; i < times; i++) {
    tone(buzzer, 4000);
    delay(250);
    tone(buzzer, 800);
    delay(250);
    noTone(buzzer);
  }
}

bool armed = false;
bool alarm = false;

void activate() {
  okTone(2);
  armed = true;
}

void disactivate(int code) {
  if(alarmPinCode == code) {
    armed = false;
    alarm = false;
    doneTone(2);
    resetCommand();
    Serial.println("OK:disarmed");
  } else {
    Serial.println("ERR:wrong_alarm_code");
  }
}

void handleAlarm(int sensorVal) {
  if(sensorVal == HIGH){
    alarm = true;
  }
  if(alarm && armed){
    alarmTone(1);
  }
  sendAlarmNotification(sensorVal);
}

void setCode(int code) {
  if(armed) {
    disactivate(code);
  } else {
    alarm = false;
    activate();
    Serial.println("OK:armed");
  }
}

bool alarmTrigger = false;
int doorOldState = old_val;
void sendAlarmNotification(int sensorVal) {
  alarmTrigger = doorOldState != sensorVal && sensorVal == HIGH && armed;
  doorOldState = sensorVal;
  if(alarmTrigger) {
    Serial.println("INFO:alarm");
    alarmTrigger = false;
  }
}
