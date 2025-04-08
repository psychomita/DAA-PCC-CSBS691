#include <stdbool.h>
#include <stdio.h>

#define N 8

// Function to display the chessboard
void display(int board[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i][j] == 0)
        printf(". ");
      else
        printf("Q ");
    }
    printf("\n");
  }
  printf("\n");
}

// Function to check if placing a queen at board[row][col] is safe
bool isSafe(int board[N][N], int row, int col) {
  for (int i = 0; i < col; i++)
    if (board[row][i]) return false;

  for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    if (board[i][j]) return false;

  for (int i = row, j = col; i < N && j >= 0; i++, j--)
    if (board[i][j]) return false;

  return true;
}

// Recursive function to solve N-Queens
bool solveNQueensUtil(int board[N][N], int col, int startRow, int startCol) {
  if (col == N) {
    display(board);
    return true;
  }

  // Skip the user-placed queen column
  if (col == startCol) return solveNQueensUtil(board, col + 1, startRow, startCol);

  bool res = false;
  for (int i = 0; i < N; i++) {
    if (isSafe(board, i, col)) {
      board[i][col] = 1;
      res = solveNQueensUtil(board, col + 1, startRow, startCol) || res;
      board[i][col] = 0;
    }
  }
  return res;
}

int main() {
  int board[N][N] = {0};
  int startRow, startCol;

  printf("Enter initial queen position (row and column from 0 to 7): ");
  scanf("%d %d", &startRow, &startCol);

  if (startRow < 0 || startRow >= N || startCol < 0 || startCol >= N) {
    printf("Invalid position.\n");
    return 1;
  }

  board[startRow][startCol] = 1;

  if (!solveNQueensUtil(board, 0, startRow, startCol))
    printf("No possible solution with the given starting position.\n");

  return 0;
}

