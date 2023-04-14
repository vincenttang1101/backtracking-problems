#include<iostream>
using namespace std;
#define N 8

// Hàm in bàn c?
void printBoard(int board[N][N]) {
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++)
         cout << board[i][j] << " ";
         cout << endl;
   }
}

// Hàm ki?m tra xem có th? d?t quân h?u vào v? trí (row, col) hay không
bool isValid(int board[N][N], int row, int col) {
   for (int i = 0; i < col; i++) // Ki?m tra xem có quân h?u nào trên hàng ngang bên trái c?a v? trí (row, col) hay không
      if (board[row][i])
         return false;
   for (int i=row, j=col; i>=0 && j>=0; i--, j--)
      if (board[i][j]) // Ki?m tra xem có quân h?u nào trên du?ng chéo chính bên trái c?a v? trí (row, col) hay không
         return false;
   for (int i=row, j=col; j>=0 && i<N; i++, j--)
      if (board[i][j]) // Ki?m tra xem có quân h?u nào trên du?ng chéo ph? bên trái c?a v? trí (row, col) hay không
         return false;
   return true;
}

// Hàm gi?i quy?t bài toán N-Queen b?ng phuong pháp Backtracking
bool solveNQueen(int board[N][N], int col) {
   if (col >= N) // Khi dã d?t du?c N quân h?u thành công
      return true;
   for (int i = 0; i < N; i++) { // Ki?m tra có th? d?t quân h?u vào hàng th? i hay không
      if (isValid(board, i, col) ) {
         board[i][col] = 1; // N?u có th?, d?t quân h?u vào v? trí (i, col)
         if ( solveNQueen(board, col + 1)) // Ti?p t?c di tìm v? trí c?a các quân h?u ti?p theo
            return true;
         board[i][col] = 0; // N?u không th? d?t quân h?u t?i v? trí (i, col), lo?i b? quân h?u dó
      }
   }
   return false; // Khi không tìm du?c v? trí d?t quân h?u phù h?p
}

// Hàm ki?m tra và in ra gi?i pháp c?a bài toán N-Queen
bool checkSolution() {
   int board[N][N];
   for(int i = 0; i<N; i++)
   for(int j = 0; j<N; j++)
   board[i][j] = 0; // Ð?t t?t c? các ô trên bàn c? b?ng 0
   if ( solveNQueen(board, 0) == false ) { // B?t d?u tìm v? trí d?t quân h?u t? c?t th? 0
      cout << "Không tìm du?c gi?i pháp";
      return false;
   }
   printBoard(board);
   return true;
}

// Hàm main d? ki?m tra và gi?i quy?t bài toán N-Queen
int main() {
   checkSolution();
}
