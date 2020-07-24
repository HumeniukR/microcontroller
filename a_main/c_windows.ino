long currentJalousiePos = 0;
int windowHeight = 15;

void rotate(int dir, int del, long turns) {
  for (long i = 0; i < turns; i++)
    {
      digitalWrite(DIR,dir);
      digitalWrite(ENA,HIGH);
      digitalWrite(PUL,HIGH);
      delayMicroseconds(del);
      digitalWrite(PUL,LOW);
      delayMicroseconds(del);
    }
    digitalWrite(ENA,LOW);
}

void setJalousiePos(int precent) { // 100 - fully opened, 0 - closed
  long pos = 64L * windowHeight * precent; // 6400 / 100 = 64
  if(pos < currentJalousiePos) {
    rotate(1, 10, currentJalousiePos - pos);
  } else {
    rotate(0, 10, pos - currentJalousiePos);
  }
  currentJalousiePos = pos;
  Serial.print("OK:window-");
  Serial.println(precent);
}
