#include <iostream>
  
using namespace std;
  
// N là kích thước của ma trận 2D N*N
#define N 9
  

/* Hàm tiện ích để in lưới */
void print(int arr[N][N])
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
  
// Kiểm tra xem nó có phải là
// hợp lệ để gán num cho
// đã cho hàng, col
bool isSafe(int grid[N][N], int row, 
                       int col, int num)
{
    // Kiểm tra xem chúng ta có tìm thấy num giống nhau không
    // trong hàng tương tự, chúng ta
    // trả về false
    for (int x = 0; x <= 8; x++)
        if (grid[row][x] == num)
            return false;
  
    // Kiểm tra xem chúng ta có tìm thấy num giống nhau không
    // cột tương tự, chúng ta
    // trả về false
    for (int x = 0; x <= 8; x++)
        if (grid[x][col] == num)
            return false;
  
    // Kiểm tra xem chúng ta có tìm thấy num giống nhau không
    // ma trận 3*3 cụ thể,
    // chúng ta trả về false
    int startRow = row - row % 3, 
            startCol = col - col % 3;
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + 
                            startCol] == num)
                return false;
  
    return true;
}
  

/* Lấy một lưới được điền một phần và thử
để gán giá trị cho tất cả các vị trí chưa được gán trong
một cách như vậy để đáp ứng các yêu cầu cho
Giải Sudoku (không trùng lặp giữa các hàng,
cột và hộp) */
bool solveSudoku(int grid[N][N], int row, int col)
{
    // Kiểm tra xem chúng ta đã đến vị trí thứ 8 chưa
    // hàng và cột thứ 9 (0
    // ma trận được lập chỉ mục), chúng ta là
    // trả về true để tránh
    // quay lui thêm
    if (row == N - 1 && col == N)
        return true;
  
    // Kiểm tra xem giá trị cột có trở thành 9 không,
    // chúng ta di chuyển đến hàng tiếp theo và
    // cột bắt đầu từ 0
    if (col == N) {
        row++;
        col = 0;
    }
    
    // Kiểm tra xem vị trí hiện tại của
    // lưới đã chứa
    // giá trị >0, lặp cho cột tiếp theo
    if (grid[row][col] > 0)
        return solveSudoku(grid, row, col + 1);
  
    for (int num = 1; num <= N; num++) 
    {
          
        // Kiểm tra xem nó có an toàn không
        // số (1-9) trong
        // hàng đã cho, col -> chúng ta
        // di chuyển đến cột tiếp theo

        if (isSafe(grid, row, col, num)) 
        {
            
            /* Gán số trong
            hiện tại (hàng, cột)
            vị trí lưới
            và giả sử chúng tôi được giao
            số ở vị trí
            đúng     */
            grid[row][col] = num;
            
            // Kiểm tra khả năng tiếp theo với cột tiếp theo
            if (solveSudoku(grid, row, col + 1))
                return true;
        }
        
        // Xóa số đã gán,
        // vì giả định của chúng ta
        // đã sai, và chúng ta tiếp tục
        // giả định tiếp theo với
        // giá trị số khác
        grid[row][col] = 0;
    }
    return false;
}
  
// Mã trình điều khiển
int main()
{
    // 0 có nghĩa là các ô chưa được gán
    int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
  
    if (solveSudoku(grid, 0, 0))
        print(grid);
    else
        cout << "No solution exists " << endl;
  
    return 0;
}