#define led 3
const int DELAY = 4;

void setup(){
  pinMode(led, OUTPUT);
}

void loop(){
  turnOn(led);
  turnOff(led);
}

void turnOn(int x){
  for(int i = 0; i < 255; i++){
    analogWrite(x, i);
    delay(DELAY);
  }
}

void turnOff(int x){
  for(int i = 255; i > 0; i--){
    analogWrite(x, i);
    delay(DELAY);
  }
}