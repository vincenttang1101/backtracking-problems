#include <bits/stdc++.h>
using namespace std;

#define N 8

int solveKTUtil(int x, int y, int movei, int sol[N][N],
int xMove[], int yMove[]);

/* Hàm h? tr? ki?m tra xem i,j có ph?i là ch? s? h?p l?
trong bàn c? N*N hay không */
int isSafe(int x, int y, int sol[N][N])
{
return (x >= 0 && x < N && y >= 0 && y < N
&& sol[x][y] == -1);
}

/* Hàm h? tr? in ma tr?n sol[N][N] */
void printSolution(int sol[N][N])
{
for (int x = 0; x < N; x++) {
for (int y = 0; y < N; y++)
cout << " " << setw(2) << sol[x][y] << " ";
cout << endl;
}
}

/* Hàm này gi?i bài toán Knight Tour b?ng Backtracking.
Hàm này ch? y?u s? d?ng hàm solveKTUtil() d? gi?i quy?t bài toán.
Nó tr? v? giá tr? false n?u không có tour hoàn ch?nh nào có th?,
ngu?c l?i tr? v? true và in ra tour.
Luu ý r?ng có th? có nhi?u hon m?t gi?i pháp, hàm này in ra m?t trong các gi?i pháp kh? thi. */
int solveKT()
{
int sol[N][N];

/* Kh?i t?o ma tr?n solution */
for (int x = 0; x < N; x++)
    for (int y = 0; y < N; y++)
        sol[x][y] = -1;

/* xMove[] và yMove[] d?nh nghia nu?c di ti?p theo c?a Knight.
xMove[] là cho giá tr? ti?p theo c?a t?a d? x
yMove[] là cho giá tr? ti?p theo c?a t?a d? y */
int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

// Vì Knight ban d?u ? ô d?u tiên
sol[0][0] = 0;

/* B?t d?u t? 0,0 và khám phá t?t c? các tour b?ng cách
s? d?ng solveKTUtil() */
if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == 0) {
    cout << "Không tìm th?y gi?i pháp";
    return 0;
}
else
    printSolution(sol);

return 1;
}

/* Hàm d? quy h? tr? gi?i bài toán Knight Tour */
int solveKTUtil(int x, int y, int movei, int sol[N][N],
int xMove[8], int yMove[8])
{
int k, next_x, next_y;
if (movei == N * N)
return 1;

/* Th? t?t c? các nu?c di ti?p theo t?
t?a d? hi?n t?i x, y */
for (k = 0; k < 8; k++) {
    next_x = x + xMove[k];
    next_y = y + yMove[k];
    if (isSafe(next_x, next_y, sol)) {
        sol[next_x][next_y] = movei;
        if (solveKTUtil(next_x, next_y, movei + 1, sol,
                        xMove, yMove)
            == 1)
            return 1;
        else                 
           // Backtracking
            sol[next_x][next_y] = -1;
    }
}
return 0;
}

// Chuong trình chính
int main()
{
// G?i hàm gi?i bài toán Knight Tour
solveKT();
return 0;
}
