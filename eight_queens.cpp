#include <iostream>
using namespace std;
#define N 8

// Hàm in bàn cờ
void printBoard(int board[N][N])
{
   for (int i = 0; i < N; i++)
   {
      for (int j = 0; j < N; j++)
         cout << board[i][j] << " ";
      cout << endl;
   }
}

// Hàm kiểm tra xem có thể đặt quân hậu vào vị trí (row, col) hay không
bool isValid(int board[N][N], int row, int col)
{
   for (int i = 0; i < col; i++) // Kiểm tra xem có quân hậu nào trên hàng ngang bên trái của vị trí (row, col) hay không
      if (board[row][i])
         return false;
   for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
      if (board[i][j]) // Kiểm tra xem có quân hậu nào trên đường chéo chính bên trái của vị trí (row, col) hay không
         return false;
   for (int i = row, j = col; j >= 0 && i < N; i++, j--)
      if (board[i][j]) // Kiểm tra xem có quân hậu nào trên đường chéo phụ bên trái của vị trí (row, col) hay không
         return false;
   return true;
}

// Hàm giải quyết bài toán N-Queen bằng phương pháp Backtracking
bool solveNQueen(int board[N][N], int col)
{
   if (col >= N) // Khi đã đặt được N quân hậu thành công
      return true;
   for (int i = 0; i < N; i++)
   { // Kiểm tra có thể đặt quân hậu vào hàng thứ i hay không
      if (isValid(board, i, col))
      {
         board[i][col] = 1;               // Nếu có thể, đặt quân hậu vào vị trí (i, col)
         if (solveNQueen(board, col + 1)) // Tiếp tục đi tìm vị trí của các quân hậu tiếp theo
            return true;
         board[i][col] = 0; // Nếu không thể đặt quân hậu tại vị trí (i, col), loại bỏ quân hậu đó
      }
   }
   return false; // Khi không tìm được vị trí đặt quân hậu phù hợp
}

// Hàm kiểm tra và in ra giải pháp của bài toán N-Queen
bool checkSolution()
{
   int board[N][N];
   for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
         board[i][j] = 0; // Đặt tất cả các ô trên bàn cờ bằng 0
   if (solveNQueen(board, 0) == false)
   { // Bắt đầu tìm vị trí đặt quân hậu từ cột thứ 0
      cout << "Không tìm được giải pháp";
      return false;
   }
   printBoard(board);
   return true;
}

// Hàm main để kiểm tra và giải quyết bài toán N-Queen
int main()
{
   checkSolution();
}
