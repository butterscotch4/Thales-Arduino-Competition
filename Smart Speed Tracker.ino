#include "pitches.h"
int sensorPin = 0;
int i=2;

int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(sensorPin, INPUT);
}

void withoutObj(){
  int i=2;
  analogWrite(10, 255/2);
  analogWrite(11, 255/2);
  analogWrite(9, 0);
  
}

void withObj(){
  int thisNote = 0;
  
    analogWrite(9, 250);
    if(thisNote<8){
      thisNote++;
    }
    else{
      thisNote = thisNote;
    }

    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
    analogWrite(10, 255/i);
    analogWrite(11, 255/i);
    i=i+2;

  }
  
  void loop(){
  float dist = 12343.85 * pow(analogRead(sensorPin), -1.15);
  Serial.println(dist);
  if(dist<10
  ){
    withObj();
  }
  else{
    withoutObj();
  }
  }
    

