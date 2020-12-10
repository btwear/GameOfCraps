#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

// High is the high of the 20×20 world plus the two rows above and below
// the array to prevent bug when the place is on the border
#define High 22
// Width is the width of the 20×20 world  plus the two column at the left
// and right side the array to prevent bug when the place is on the border
#define Width 22
int answer1;            // total number of live cells of the first generation
int answer2;            // total number of live cells of the second generation
int answer3;            // total number of live cells of the third generation
int cells[High][Width]; // The 20×20 world
int currentCellsCount = 0;

// the startup function is used to state the place of the first generation
void startup() {
  cells[9][9] = 1;
  cells[9][11] = 1;
  cells[10][10] = 1;
  cells[11][10] = 1;
  cells[12][9] = 1;
  cells[12][11] = 1;
  currentCellsCount = 6;
}

void show() {
  // i is the row of the array cells[20][20],and j is the column of the array
  // cells[20][20]
  int i, j;
  for (i = 0; i < High; i++) {
    for (j = 0; j < Width; j++) {
      if (cells[i][j] == 1) {
        // the place stated before will cout to the screen;
        cout << "|██";
      } else {
        // the place not stated before will not cout to the screen;
        cout << "|░░";
      }
    }
    cout << endl;
  }

  for (int i = 0; i <= Width; i++) {
    cout << "---";
  }
  cout << endl;
}

void UpdateWithoutInput() {
  int newcells[High][Width]; // it will be the next 20×20 world
  int neighbornumber;        // neighbornumber is the 8 neighbor of a place
  int i, j;                  // i, j used for iterate through newcells[][]
  for (i = 1; i <= High - 1; i++) {
    for (j = 1; j <= Width - 1; j++) {
      neighbornumber = cells[i - 1][j - 1] + cells[i - 1][j] +
                       cells[i - 1][j + 1] + cells[i][j - 1] + cells[i][j + 1] +
                       cells[i + 1][j - 1] + cells[i + 1][j] +
                       cells[i + 1][j + 1];
      if (neighbornumber == 3) {
        newcells[i][j] = 1; // the cell in this place will live
      } else if (neighbornumber == 2) {
        // the cell in this place will be the same as the last generation
        newcells[i][j] = cells[i][j];
      } else
        newcells[i][j] = 0; // the cell dies
    }
  }

  currentCellsCount = 0;
  for (i = 1; i <= High - 1; i++) {
    for (j = 1; j <= Width - 1; j++) {
      // in each place,the new cell will replace
      // the original cell;
      cells[i][j] = newcells[i][j];
      currentCellsCount += cells[i][j];
    }
  }
}

int main() {
  startup();
  {
    show();
    answer1 = currentCellsCount;
    UpdateWithoutInput();
    show();
    answer2 = currentCellsCount;
    UpdateWithoutInput();
    show();
    answer3 = currentCellsCount;
    cout << answer1 << endl << answer2 << endl << answer3 << endl;
  }
  return 0;
}
