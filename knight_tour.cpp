#include <bits/stdc++.h>
using namespace std;
#define N 8

int solveKTUtil(int x, int y, int movei, int sol[N][N],
                int xMove[], int yMove[]);

/* Hàm hỗ trợ kiểm tra xem i,j có phải là chỉ số hợp lệ
trong bàn cờ N*N hay không */
int isSafe(int x, int y, int sol[N][N])
{
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

/* Hàm hỗ trợ in ma trận sol[N][N] */
void printSolution(int sol[N][N])
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
            cout << " " << setw(2) << sol[x][y] << " ";
        cout << endl;
    }
}

/* Hàm này giải bài toán Knight Tour bằng Backtracking.
Hàm này chủ yếu sử dụng hàm solveKTUtil() để giải quyết bài toán.
Nó trả về giá trị false nếu không có tour hoàn chỉnh nào có thể,
ngược lại trả về true và in ra tour.
Lưu ý rằng có thể có nhiều hơn một giải pháp, hàm này in ra một trong các giải pháp khả thi. */
int solveKT()
{
    int sol[N][N];

    /* Khởi tạo ma trận solution */
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            sol[x][y] = -1;

    /* xMove[] và yMove[] định nghĩa nước đi tiếp theo của Knight.
    xMove[] là cho giá trị tiếp theo của tọa độ x
    yMove[] là cho giá trị tiếp theo của tọa độ y */
    int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    // Vì Knight ban đầu ở ô đầu tiên
    sol[0][0] = 0;

    /* Bắt đầu từ 0,0 và khám phá tất cả các tour bằng cách
    sử dụng solveKTUtil() */
    if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == 0)
    {
        cout << "Không tìm thấy giải pháp";
        return 0;
    }
    else
        printSolution(sol);

    return 1;
}

/* Hàm đệ quy hỗ trợ giải bài toán Knight Tour */
int solveKTUtil(int x, int y, int movei, int sol[N][N],
                int xMove[8], int yMove[8])
{
    int k, next_x, next_y;
    if (movei == N * N)
        return 1;

    /* Thử tất cả các nước đi tiếp theo từ
    tọa độ hiện tại x, y */
    for (k = 0; k < 8; k++)
    {
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if (isSafe(next_x, next_y, sol))
        {
            sol[next_x][next_y] = movei;
            if (solveKTUtil(next_x, next_y, movei + 1, sol,
                            xMove, yMove) == 1)
                return 1;
            else
                // Backtracking
                sol[next_x][next_y] = -1;
        }
    }
    return 0;
}

// Chương trình chính
int main()
{
    // Gọi hàm giải bài toán Knight Tour
    solveKT();
    return 0;
}