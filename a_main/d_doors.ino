int old_val = btnVal;
void handleDoor(int val) {
  if(old_val != val) {
    old_val = val;
    if(val == HIGH){
      Serial.println("INFO:door-close");
    } else {
      Serial.println("INFO:door-open");
    }
  }
} 
