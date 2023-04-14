#include<iostream>
using namespace std;
#define N 8

// H�m in b�n c?
void printBoard(int board[N][N]) {
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++)
         cout << board[i][j] << " ";
         cout << endl;
   }
}

// H�m ki?m tra xem c� th? d?t qu�n h?u v�o v? tr� (row, col) hay kh�ng
bool isValid(int board[N][N], int row, int col) {
   for (int i = 0; i < col; i++) // Ki?m tra xem c� qu�n h?u n�o tr�n h�ng ngang b�n tr�i c?a v? tr� (row, col) hay kh�ng
      if (board[row][i])
         return false;
   for (int i=row, j=col; i>=0 && j>=0; i--, j--)
      if (board[i][j]) // Ki?m tra xem c� qu�n h?u n�o tr�n du?ng ch�o ch�nh b�n tr�i c?a v? tr� (row, col) hay kh�ng
         return false;
   for (int i=row, j=col; j>=0 && i<N; i++, j--)
      if (board[i][j]) // Ki?m tra xem c� qu�n h?u n�o tr�n du?ng ch�o ph? b�n tr�i c?a v? tr� (row, col) hay kh�ng
         return false;
   return true;
}

// H�m gi?i quy?t b�i to�n N-Queen b?ng phuong ph�p Backtracking
bool solveNQueen(int board[N][N], int col) {
   if (col >= N) // Khi d� d?t du?c N qu�n h?u th�nh c�ng
      return true;
   for (int i = 0; i < N; i++) { // Ki?m tra c� th? d?t qu�n h?u v�o h�ng th? i hay kh�ng
      if (isValid(board, i, col) ) {
         board[i][col] = 1; // N?u c� th?, d?t qu�n h?u v�o v? tr� (i, col)
         if ( solveNQueen(board, col + 1)) // Ti?p t?c di t�m v? tr� c?a c�c qu�n h?u ti?p theo
            return true;
         board[i][col] = 0; // N?u kh�ng th? d?t qu�n h?u t?i v? tr� (i, col), lo?i b? qu�n h?u d�
      }
   }
   return false; // Khi kh�ng t�m du?c v? tr� d?t qu�n h?u ph� h?p
}

// H�m ki?m tra v� in ra gi?i ph�p c?a b�i to�n N-Queen
bool checkSolution() {
   int board[N][N];
   for(int i = 0; i<N; i++)
   for(int j = 0; j<N; j++)
   board[i][j] = 0; // �?t t?t c? c�c � tr�n b�n c? b?ng 0
   if ( solveNQueen(board, 0) == false ) { // B?t d?u t�m v? tr� d?t qu�n h?u t? c?t th? 0
      cout << "Kh�ng t�m du?c gi?i ph�p";
      return false;
   }
   printBoard(board);
   return true;
}

// H�m main d? ki?m tra v� gi?i quy?t b�i to�n N-Queen
int main() {
   checkSolution();
}
