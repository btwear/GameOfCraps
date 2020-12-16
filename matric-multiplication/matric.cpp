#include <stdio.h>
#include <stdlib.h>
/* Main Function */
int main() {
  /* Declaring pointer for matrix multiplication.*/
  int **M1, **M2, **M3;
  /* Declaring integer variables for row and columns of two matrices.*/
  int row1, col1, row2, col2;
  /* Declaring indexes. */
  int i, j, k;

  // /* Request the user to input number of columns of the matrices.*/
  // printf("\nEnter number of rows for first matrix : ");
  // scanf("%d", &row1);
  // printf("\nEnter number of columns for first matrix : ");
  // scanf("%d", &col1);
  // printf("\nEnter number of rows for second matrix : ");
  // scanf("%d", &row2);
  // printf("\nEnter number of columns for second matrix : ");
  // scanf("%d", &col2);

  row1 = 2;
  col1 = 3;
  row2 = 3;
  col2 = 2;

  if (col1 != row2) {
    printf("\nCannot multiply two matrices.");
    return (0);
  }
  /* Allocating memory for three matrix rows. */
  M1 = (int **)malloc(sizeof(int *) * row1);
  M2 = (int **)malloc(sizeof(int *) * row2);
  M3 = (int **)malloc(sizeof(int *) * col1);
  /* Allocating memory for the col of three matrices. */
  for (i = 0; i < row1; i++)
    M1[i] = (int *)malloc(sizeof(int) * col1);
  for (i = 0; i < row2; i++)
    M2[i] = (int *)malloc(sizeof(int) * col2);
  for (i = 0; i < col1; i++)
    M3[i] = (int *)malloc(sizeof(int) * row2);

  M1[0][0] = 1;
  M1[0][1] = 2;
  M1[0][2] = 3;
  M1[1][0] = 4;
  M1[1][1] = 5;
  M1[1][2] = 6;

  M2[0][0] = 7;
  M2[0][1] = 8;
  M2[1][0] = 9;
  M2[1][1] = 10;
  M2[2][0] = 11;
  M2[2][1] = 12;

  // /* Request the user to input members of first matrix. */
  // printf("\nEnter elements of first matrix :\n");
  // for (i = 0; i < row1; i++) {
  //   for (j = 0; j < col1; j++) {
  //     printf("\tA[%d][%d] = ", i, j);
  //     scanf("%d", &M1[i][j]);
  //   }
  // }
  // /* request to user to input members of second matrix. */
  // printf("\nEnter elements of second matrix :\n");
  // for (i = 0; i < row2; i++) {
  //   for (j = 0; j < col2; j++) {
  //     printf("\tB[%d][%d] = ", i, j);
  //     scanf("%d", &M2[i][j]);
  //   }
  // }
  /* Calculation begins for the resultant matrix. */
  for (i = 0; i < row1; i++) {
    for (j = 0; j < col1; j++) {
      for (k = 0, M3[i][k] = 0; k < col2; k++)
        M3[i][k] += M1[i][j] * M2[j][k];
    }
  }
  /* Printing the contents of third matrix. */
  printf("\n\nResultant matrix :");
  for (i = 0; i < row1; i++) {
    printf("\n");
    for (j = 0; j < col2; j++)
      printf("%d ", M3[i][j]);
  }
  printf("\n");
  return 0;
}
