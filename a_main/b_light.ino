void ledOn(int ledPin) {
  digitalWrite(ledPin, HIGH);
  resetCommand();
  Serial.print("OK:led_on-");
  Serial.println(ledPin);
}

void ledOff(int ledPin) {
  digitalWrite(ledPin, LOW);
  resetCommand();
  Serial.print("OK:led_off-");
  Serial.println(ledPin);
}
