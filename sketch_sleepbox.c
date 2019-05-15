/*
A Mark Zuckerberg Sleep Box
*/

int newPress = 0;
int pressCount = 0;
int pressCountFinal = 0;
int counter = 0;
int counterAlarm = 0;
int minsLeft = 0;
int alarmActive = 0;
int activeCounter = 0;
int minsLeftActive = 0;
int outPinLEDs = 5; // use pin #5 for LEDs

void flash(int n, int m) {
  /* flash LEDs n times pausing for m milliseconds between flashes */ 
  for (int i=0; i<n; i++) {
    analogWrite(outPinLEDs, 0);
    delay(m);
    analogWrite(outPinLEDs, 70);
    delay(m);
  }
  analogWrite(outPinLEDs, 0);
  delay(m); 
}

void doDemo() {  
  /* light the box on/off 10 times with fade effect */
  for (int demo=0; demo<10; demo++) {
    for (int power = 0; power<50; power++) {
      analogWrite(outPinLEDs, power);
      int sensorVal = digitalRead(2);
      if (sensorVal==LOW) { // button pressed
        goto end;
      }
      delay(50);
    }
    for (int power=50; power>=0; power--) {
      analogWrite(outPinLEDs, power);
      int sensorVal = digitalRead(2);
      if (sensorVal==LOW) { // button pressed
        goto end;
      }
      delay(50);
    }
    for (int i=0; i<10; i++) {
      int sensorVal = digitalRead(2);
      if (sensorVal==LOW) { // button pressed
        goto end;
      }
      delay(100);
    }
  }
  end:
    analogWrite(outPinLEDs, 0);
    delay(50);
}

void setup() { 
  // start serial connection for debugging (comment out when in live mode)
  // Serial.begin(9600);
  pinMode(2, INPUT_PULLUP); // pin #2 as input with internal pull-up resistor
  pinMode(13, OUTPUT); // pin #13 for pushbutton press 
  pinMode(outPinLEDs, OUTPUT); // pin for LEDs (defined earlier)
  flash(1, 700); // flash once to indicate successful power-up
}

void loop() {  
  // read pushbutton value into variable
  int sensorVal = digitalRead(2);
  // Keep in mind the pull-up means the pushbutton's logic is inverted. It goes
  // HIGH when it's open, and LOW when it's pressed. Turn on pin #13 when the
  // button's pressed, and off when it's not:
  if (sensorVal==HIGH) { // button unpressed
    digitalWrite(13, LOW);
    newPress = 0;
  } else { // button pressed
    digitalWrite(13, HIGH);  
    if (newPress==0) {
      newPress = 1;
      analogWrite(outPinLEDs, 0);
      alarmActive = 0;
      activeCounter = 0;
      minsLeftActive = 0;
      // if hasn't been long since last press (about 4s or less), 
      // then increment pressCount
      if (counter<=50) {
        pressCount++;
        counter = 1;
      }
    }
  }
  if (counter>0 && counter<=50) { // not done pressing, keep listening
    counter++;
  } else if (counter>50) { // done pressing, start alarm clock at next loop
    // Serial.println(pressCount);
    newPress = 0;
    pressCountFinal = pressCount;
    minsLeft = pressCountFinal * 60;
    counterAlarm = 0;
    counter = 0;
    pressCount = 0;
    // flash as many times as number of button presses to confirm input
    flash(pressCountFinal, 300);
  } else if (pressCountFinal==1) { // only 1 press, so demo mode
    pressCountFinal = 0;
    doDemo();
  } else if (pressCountFinal>1) { // more than 1 press, so alarm clock mode
    counterAlarm++;
    if (counterAlarm==600) {
      counterAlarm = 0;
      minsLeft--;
      if (minsLeft==0) {
        // activate alarm for 60 mins, i.e. light the box
        minsLeft=24*60; // reset to 24 hours
        alarmActive = 1;
        minsLeftActive = 60;
        analogWrite(outPinLEDs, 5); // light with tiny power
      }
    }
  }
  if (alarmActive==1) { // alarm is active, i.e. box should be lit
    if (minsLeftActive>0) {
      if (activeCounter==600) {
        activeCounter = 0;
        minsLeftActive--;
        if (minsLeftActive==59) {
          analogWrite(outPinLEDs, 10); // send more power
        } else if (minsLeftActive==58) {
          analogWrite(outPinLEDs, 15); // send more power
        } else if (minsLeftActive==57) {
          analogWrite(outPinLEDs, 20); // send more power
        } else {
          analogWrite(outPinLEDs, 50); // full power (set to smaller value if too bright)
        }
      } else {
        activeCounter++;
      }
    } else {
      alarmActive = 0;
      activeCounter = 0;
      minsLeftActive = 0;
      analogWrite(outPinLEDs, 0);
    }
  }
  // delay each loop by 100 ms, so 10 loops = 1 sec
  delay(100);
}
