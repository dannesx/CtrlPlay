// Importante seguir a mesma ordem
// Vermelho[0], Amarelo[1] e Verde[2]
int semaforo1[] = {2,3,4};
int semaforo2[] = {8,9,10};

const long LENTO = 5000;
const long RAPIDO = 1000;

void setup(){
  for(int i = 0; i < 3; i++){
    pinMode(semaforo1[i], OUTPUT);
    pinMode(semaforo2[i], OUTPUT);
  }
  
  acendeVm(semaforo1);
  acendeVm(semaforo2);
}

void loop(){
  acendeVd(semaforo1);
  delay(LENTO);
  
  acendeAm(semaforo1);
  delay(RAPIDO);
  
  acendeVm(semaforo1);
  delay(RAPIDO);
  
  acendeVd(semaforo2);
  delay(LENTO);
  
  acendeAm(semaforo2);
  delay(RAPIDO);
  
  acendeVm(semaforo2);
  delay(RAPIDO);
}

void acendeVm(int s[]){
  digitalWrite(s[0], HIGH);
  digitalWrite(s[1], LOW);
  digitalWrite(s[2], LOW);
}

void acendeAm(int s[]){
  digitalWrite(s[0], LOW);
  digitalWrite(s[1], HIGH);
  digitalWrite(s[2], LOW);
}

void acendeVd(int s[]){
  digitalWrite(s[0], LOW);
  digitalWrite(s[1], LOW);
  digitalWrite(s[2], HIGH);
}