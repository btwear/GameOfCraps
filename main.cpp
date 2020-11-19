#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

double winRate;
double avgLength;

// 宣告為 int 有需要再轉 double
int totalWin = 0;
int totalLength = 0;
int iterations = 10000;

int rollDice();
void game();

int main() {
  srand(time(NULL)); // random seed initialization

  // play many times
  for (int i = 0; i < iterations; i++) {
    // 一般情況game()最好可以回傳值再搜集
    game();
  }

  winRate = (double)totalWin / (double)iterations;
  avgLength = (double)totalLength / (double)iterations;
  cout << "answer1 = " << winRate << endl << "answer2 = " << avgLength << endl;
  return 0;
}

void game() {
  int len = 1;
  int number = rollDice();

  if (number == 7 || number == 11) {
    totalWin++;
  } else if (number == 2 || number == 3 || number == 11) {
    // lose
  } else {
    int point = number;
    while (true) {
      len++;
      number = rollDice();
      if (number == point) {
        totalWin++;
        break; // game over
      } else if (number == 7) {
        break; // game over
      }
    }
  }

  totalLength += len;
}

int rollDice() {
  int number = 0;
  number += (rand() % 6) + 1; // First roll
  number += (rand() % 6) + 1; // Second roll
  return number;
}
