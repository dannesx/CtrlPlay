#define red 9
#define green 11
#define blue 10

const int DELAY = 4;

void setup(){
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  
  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
}

void loop(){
  //RED = RED
  turnOff(blue);
  //RED + GREEN = YELLOW
  turnOn(green);
  //GREEN = GREEN
  turnOff(red);
  //GREEN + BLUE = CYAN
  turnOn(blue);
  //BLUE = BLUE
  turnOff(green);
  //BLUE + RED = MAGENTA
  turnOn(red);
}

void turnOn(int pin){
  for(int i = 0; i < 255; i++){
    analogWrite(pin, i);
    delay(DELAY);
  }
}

void turnOff(int pin){
  for(int i = 255; i > 0; i--){
    analogWrite(pin, i);
    delay(DELAY);
  }
}