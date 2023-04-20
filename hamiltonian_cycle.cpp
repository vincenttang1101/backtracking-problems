#include <bits/stdc++.h>
using namespace std;
 
// Số đỉnh của đồ thị
#define V 5
 
void printSolution(int path[]);
 
/* Một hàm tiện ích để kiểm tra xem
đỉnh v có thể được thêm vào chỉ mục 'pos'
trong Chu trình Hamilton được xây dựng
cho đến nay (được lưu trữ trong 'path[]') */
bool isSafe(int v, bool graph[V][V],
            int path[], int pos)
{
    /* Kiểm tra xem đỉnh này có phải là đỉnh liền kề không
    đỉnh của đỉnh đã thêm trước đó. */
    if (graph [path[pos - 1]][ v ] == 0)
        return false;
    /* Kiểm tra xem đỉnh đã được bao gồm chưa.
    Bước này có thể được tối ưu hóa bằng cách tạo
    một mảng có kích thước V */
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
    return true;
}
 
/* Một hàm tiện ích đệ quy
để giải bài toán chu trình hamilton */
bool hamCycleUtil(bool graph[V][V],
                  int path[], int pos)
{
    /* trường hợp cơ sở: Nếu tất cả các đỉnh là
    bao gồm trong Chu trình Hamilton */
    if (pos == V)
    {
        // Và nếu có một cạnh từ
        // đỉnh bao gồm cuối cùng đến đỉnh đầu tiên
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }
    // Thử các đỉnh khác nhau làm ứng cử viên tiếp theo
    // trong Chu trình Hamilton. Chúng tôi không cố gắng cho 0 như
    // chúng tôi đã bao gồm 0 làm điểm bắt đầu trong hamCycle()
    for (int v = 1; v < V; v++)
    {
        /* Kiểm tra xem đỉnh này có thể được thêm vào không
        // đến Chu trình Hamilton */
        if (isSafe(v, graph, path, pos))
        {
            path[pos] = v;
            /* lặp lại để xây dựng phần còn lại của đường dẫn */    
            if (hamCycleUtil (graph, path, pos + 1) == true)
                return true;    
        /* Nếu thêm đỉnh v không dẫn đến một giải pháp,
        sau đó xóa đi */
            path[pos] = -1;
        }
    }
    /* Nếu không thể thêm đỉnh vào
    Chu trình Hamilton được xây dựng cho đến nay,
    sau đó trả về false */
    return false;
}
 
/* Hàm này giải bài toán Chu trình Hamilton
sử dụng Quay lui. Nó chủ yếu sử dụng hamCycleUtil() để
giải quyết vấn đề. Nó trả về false nếu không có
Chu trình Hamilton có thể, nếu không thì trả về true
và in đường dẫn. Xin lưu ý rằng có thể có
nhiều hơn một giải pháp, chức năng này in một
của các giải pháp khả thi. */
bool hamCycle(bool graph[V][V])
{
    int *path = new int[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;
    /* Đặt đỉnh 0 làm đỉnh đầu tiên của đường đi.
    Nếu tồn tại Chu trình Hamilton thì đường đi có thể là
    bắt đầu từ bất kỳ điểm nào của chu trình vì đồ thị là vô hướng */
    path[0] = 0;
    if (hamCycleUtil(graph, path, 1) == false )
    {
        cout << "\nNo solution exists";
        return false;
    }
    printSolution(path);
    return true;
}
 
/* Một hàm tiện ích để in lời giải */
void printSolution(int path[])
{
    cout << "Solution Exists:"
            " Following is one Hamiltonian Cycle \n";
    for (int i = 0; i < V; i++)
        cout << path[i] << " ";
    // Hãy để chúng tôi in đỉnh đầu tiên một lần nữa
    // để hiển thị chu trình hoàn chỉnh
    cout << path[0] << " ";
    cout << endl;
}
 
// Mã trình điều khiển
int main()
{
    /* (0)--(1)--(2)
        |   / \   |
        |  /   \  | 
        | /     \ |
    (3)-------(4) */
    bool graph1[V][V] = {{0, 1, 0, 1, 0},
                        {1, 0, 1, 1, 1},
                        {0, 1, 0, 0, 1},
                        {1, 1, 0, 0, 1},
                        {0, 1, 1, 1, 0}};
     
    // In ra giải pháp
    hamCycle(graph1);
     
    /* Tạo biểu đồ
    (0)--(1)--(2)
       | / \ |
       | / \ |
       | / \ |
       (3) (4) */
    bool graph2[V][V] = {{0, 1, 0, 1, 0},
                         {1, 0, 1, 1, 1},
                         {0, 1, 0, 0, 1},
                         {1, 1, 0, 0, 0},
                         {0, 1, 1, 0, 0}};
 
    // In ra giải pháp
    hamCycle(graph2);
    return 0;
}
 
