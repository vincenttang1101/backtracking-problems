#include <bits/stdc++.h>
using namespace std;

#define N 8

int solveKTUtil(int x, int y, int movei, int sol[N][N],
int xMove[], int yMove[]);

/* H�m h? tr? ki?m tra xem i,j c� ph?i l� ch? s? h?p l?
trong b�n c? N*N hay kh�ng */
int isSafe(int x, int y, int sol[N][N])
{
return (x >= 0 && x < N && y >= 0 && y < N
&& sol[x][y] == -1);
}

/* H�m h? tr? in ma tr?n sol[N][N] */
void printSolution(int sol[N][N])
{
for (int x = 0; x < N; x++) {
for (int y = 0; y < N; y++)
cout << " " << setw(2) << sol[x][y] << " ";
cout << endl;
}
}

/* H�m n�y gi?i b�i to�n Knight Tour b?ng Backtracking.
H�m n�y ch? y?u s? d?ng h�m solveKTUtil() d? gi?i quy?t b�i to�n.
N� tr? v? gi� tr? false n?u kh�ng c� tour ho�n ch?nh n�o c� th?,
ngu?c l?i tr? v? true v� in ra tour.
Luu � r?ng c� th? c� nhi?u hon m?t gi?i ph�p, h�m n�y in ra m?t trong c�c gi?i ph�p kh? thi. */
int solveKT()
{
int sol[N][N];

/* Kh?i t?o ma tr?n solution */
for (int x = 0; x < N; x++)
    for (int y = 0; y < N; y++)
        sol[x][y] = -1;

/* xMove[] v� yMove[] d?nh nghia nu?c di ti?p theo c?a Knight.
xMove[] l� cho gi� tr? ti?p theo c?a t?a d? x
yMove[] l� cho gi� tr? ti?p theo c?a t?a d? y */
int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

// V� Knight ban d?u ? � d?u ti�n
sol[0][0] = 0;

/* B?t d?u t? 0,0 v� kh�m ph� t?t c? c�c tour b?ng c�ch
s? d?ng solveKTUtil() */
if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == 0) {
    cout << "Kh�ng t�m th?y gi?i ph�p";
    return 0;
}
else
    printSolution(sol);

return 1;
}

/* H�m d? quy h? tr? gi?i b�i to�n Knight Tour */
int solveKTUtil(int x, int y, int movei, int sol[N][N],
int xMove[8], int yMove[8])
{
int k, next_x, next_y;
if (movei == N * N)
return 1;

/* Th? t?t c? c�c nu?c di ti?p theo t?
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

// Chuong tr�nh ch�nh
int main()
{
// G?i h�m gi?i b�i to�n Knight Tour
solveKT();
return 0;
}
