/**
   Jogo de memória (GENIUS)
   @author Professor José de Assis
   @version 2.0
   @link https://roboticapratica.com.br/
*/

/*
  Vetor usado para armazenar a sequência da rodada.
  "16" é o número máximo de rodadas (0 a 15).
  Você pode aumentar este valor para deixar o jogo
  mais difícil, neste caso alterar também a linha 82.
*/
int sequencia[16] = {};

/*
  Vetores uados para associar o botão com a cor do LED
  e nota musical correspondente:
  ------------------------------------------------
  | Índice | Botão     | LED              | Nota |
  ------------------------------------------------
  |  [0]   | botão 8   | led 5 (vermelho) | DÓ   |
  ------------------------------------------------
  |  [1]   | botão 9   | led 4 (amarelo)  | RÉ   |
  ------------------------------------------------
  |  [2]   | botão 10  | led 3 (verde)    | MI   |
  ------------------------------------------------
  |  [3]   | botão 11  | led 5 (azul)     | FÁ   |
  ------------------------------------------------
*/
int botoes[4] = {5, 4, 3, 2};
int leds[4] = {8, 9, 10, 11};
int tons[4] = {262, 294, 330, 349};
int buzzer = 1;

// variáveis usadas para determinar a dificuldade do jogo
int tempoRodada = 1000; // tempo de espera da rodada
int tempoAceso = 300;   // tempo em que o led fica aceso quando reproduz a sequência
int tempoApagado = 200; // tempo de espera até acender o próximo led

// variáveis usadas no apoio a lógica do jogo
int rodada = 0;
int passo = 0;
int botaoPressionado = 0;
bool gameOver = false;

void setup() {
  // Buzzer
  pinMode(buzzer, OUTPUT);
  //Leds
  for(int i = 0; i < 4; i++){
    pinMode(leds[i], OUTPUT);
  }
  //Botões
  for(int i = 0; i < 4; i++){
    pinMode(botoes[i], INPUT_PULLUP);
  }
  // referência a inicialização da função random()
  randomSeed(analogRead(A0));
}

void loop() {
  // validação GAME OVER
  if (gameOver == true) {
    efeitoGameOver();
  } else {
    // lógica principal
    proximaRodada();
    reproduzirSequencia();
    aguardarJogador();
    delay(tempoRodada);

    // aumentar a dificuldade à partir da 8ª rodada
    if (rodada > 7) {
      tempoRodada = 500;
      tempoAceso = 150;
      tempoApagado = 100;
    }

    // vencedor (jogador chegou até a última rodada)
    if (rodada == 15) {
      efeitoVitoria();
      gameOver = true;
    }
  }
}

/* Função que sorteia a sequência da próxima rodada */
void proximaRodada() {
  sequencia[rodada] = random(4);
  rodada = rodada + 1;
}

/* Função que reproduz a sequência da rodada */
void reproduzirSequencia() {
  for (int i = 0; i < rodada; i++) {
    tone(buzzer, tons[sequencia[i]]);
    digitalWrite(leds[sequencia[i]], HIGH);
    delay(tempoAceso); 
    noTone(buzzer);
    digitalWrite(leds[sequencia[i]], LOW);
    delay(tempoApagado); 
  }
}

/* Função que aguarda o jogador */
void aguardarJogador() {
  for (int i = 0; i < rodada; i++) {
    bool jogadaEfetuada = false;
    while (!jogadaEfetuada) {
      for (int i = 0; i <= 3; i++) {
        if (digitalRead(botoes[i]) == 0) {
          botaoPressionado = i;
          tone(buzzer, tons[i]);
          digitalWrite(leds[i], HIGH);
          delay(300);
          digitalWrite(leds[i], LOW);
          noTone(buzzer);
          jogadaEfetuada = true;
        }
      }
    }
    //verificar a jogada
    if (sequencia[passo] != botaoPressionado) {
      efeitoErrou();
      gameOver = true;
      break;
    }
    passo++;
  }
  passo = 0;
}

/***** Efeitos luminosos / sonoros *****/

/* Game over */
void efeitoGameOver() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  delay(1000);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  delay(1000);
}

/* Errou a sequência */
void efeitoErrou() {
  for (int i = 0; i <= 3; i++) {
    tone (buzzer, 70);
    digitalWrite(leds[i], HIGH);
    delay(100);
    digitalWrite(leds[i], LOW);
    noTone(buzzer);
  }
}

/* Campeão !!! */
void efeitoVitoria() {
  // melodia (notas musicais)
  int nota[] = {660, 660, 660, 510, 660, 770, 380, 510, 380, 320, 440, 480, 450, 430, 380, 660, 760, 860, 700, 760, 660, 520, 580, 480, 510, 380, 320, 440, 480, 450, 430, 380, 660, 760, 860, 700, 760, 660, 520, 580, 480, 500, 760, 720, 680, 620, 650, 380, 430, 500, 430, 500, 570, 500, 760, 720, 680, 620, 650, 1020, 1020, 1020, 380, 500, 760, 720, 680, 620, 650, 380, 430, 500, 430, 500, 570, 585, 550, 500, 380, 500, 500, 500, 500, 760, 720, 680, 620, 650, 380, 430, 500, 430, 500, 570, 500, 760, 720, 680, 620, 650, 1020, 1020, 1020, 380, 500, 760, 720, 680, 620, 650, 380, 430, 500, 430, 500, 570, 585, 550, 500, 380, 500, 500, 500, 500, 500, 500, 500, 580, 660, 500, 430, 380, 500, 500, 500, 500, 580, 660, 870, 760, 500, 500, 500, 500, 580, 660, 500, 430, 380, 660, 660, 660, 510, 660, 770, 380};
  // duraçao de cada nota da melodia
  int duracaoNota[] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 80, 100, 100, 100, 80, 50, 100, 80, 50, 80, 80, 80, 80, 100, 100, 100, 100, 80, 100, 100, 100, 80, 50, 100, 80, 50, 80, 80, 80, 80, 100, 100, 100, 100, 150, 150, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 150, 200, 80, 80, 80, 100, 100, 100, 100, 100, 150, 150, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 150, 150, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 150, 200, 80, 80, 80, 100, 100, 100, 100, 100, 150, 150, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 60, 80, 60, 80, 80, 80, 80, 80, 80, 60, 80, 60, 80, 80, 80, 80, 80, 60, 80, 60, 80, 80, 80, 80, 80, 80, 100, 100, 100, 100, 100, 100, 100};
  // pausa depois que cada nota da melodia é reproduzida
  int pausaNota[] = {150, 300, 300, 100, 300, 550, 575, 450, 400, 500, 300, 330, 150, 300, 200, 200, 150, 300, 150, 350, 300, 150, 150, 500, 450, 400, 500, 300, 330, 150, 300, 200, 200, 150, 300, 150, 350, 300, 150, 150, 500, 300, 100, 150, 150, 300, 300, 150, 150, 300, 150, 100, 220, 300, 100, 150, 150, 300, 300, 300, 150, 300, 300, 300, 100, 150, 150, 300, 300, 150, 150, 300, 150, 100, 420, 450, 420, 360, 300, 300, 150, 300, 300, 100, 150, 150, 300, 300, 150, 150, 300, 150, 100, 220, 300, 100, 150, 150, 300, 300, 300, 150, 300, 300, 300, 100, 150, 150, 300, 300, 150, 150, 300, 150, 100, 420, 450, 420, 360, 300, 300, 150, 300, 150, 300, 350, 150, 350, 150, 300, 150, 600, 150, 300, 350, 150, 150, 550, 325, 600, 150, 300, 350, 150, 350, 150, 300, 150, 600, 150, 300, 300, 100, 300, 550, 575};
  for (int i = 0; i < 156; i++) {
    tone(buzzer, nota[i], duracaoNota[i]);
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    delay(15);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    delay(pausaNota[i]);
    noTone(buzzer);
  }
}
