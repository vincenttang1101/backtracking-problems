#include <bits/stdc++.h>
using namespace std;
#define V 4

// Triển khai bài toán người bán hàng đi du lịch
int travllingSalesmanProblem(int graph[][V], int s)
{
    // Lưu trữ tất cả các đỉnh ngoại trừ đỉnh nguồn
    vector<int> vertex;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);

    // Lưu trữ chu trình Hamilton có trọng số nhỏ nhất.
    int min_path = INT_MAX;
    do
    {

        // Lưu trọng số (chi phí) của đường đi hiện tại
        int current_pathweight = 0;

        // Tính toán trọng số (chi phí) của đường hiện tại
        int k = s;
        for (int i = 0; i < vertex.size(); i++)
        {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];

        // Cập nhật trọng số nhỏ nhất
        min_path = min(min_path, current_pathweight);

    } while (
        next_permutation(vertex.begin(), vertex.end()));

    return min_path;
}

// Hàm main
int main()
{
    // Ma trận biểu diễn đồ thị
    int graph[][V] = {{0, 10, 15, 20},
                      {10, 0, 35, 25},
                      {15, 35, 0, 30},
                      {20, 25, 30, 0}};
    int s = 0;
    cout << travllingSalesmanProblem(graph, s) << endl;
    return 0;
}

/*
    V là số lượng đỉnh trong đồ thị.
    s là đỉnh xuất phát của đường đi.
*/