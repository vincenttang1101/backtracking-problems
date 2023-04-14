// Chuong trình CPP d? tri?n khai bài toán ngu?i bán hàng di du l?ch b?ng phuong pháp don gi?n.
#include <bits/stdc++.h>
using namespace std;
#define V 4

// Tri?n khai bài toán ngu?i bán hàng di du l?ch
int travllingSalesmanProblem(int graph[][V], int s)
{
// Luu tr? t?t c? các d?nh ngo?i tr? d?nh ngu?n
vector<int> vertex;
for (int i = 0; i < V; i++)
if (i != s)
vertex.push_back(i);

// Luu tr? chu trình Hamilton có tr?ng s? nh? nh?t.
int min_path = INT_MAX;
do {

    // Luu tr?ng s? (chi phí) c?a du?ng di hi?n t?i
    int current_pathweight = 0;

    // Tính toán tr?ng s? (chi phí) c?a du?ng hi?n t?i
    int k = s;
    for (int i = 0; i < vertex.size(); i++) {
        current_pathweight += graph[k][vertex[i]];
        k = vertex[i];
    }
    current_pathweight += graph[k][s];

    // C?p nh?t tr?ng s? nh? nh?t
    min_path = min(min_path, current_pathweight);

} while (
    next_permutation(vertex.begin(), vertex.end()));

return min_path;
}

// Hàm main
int main()
{
// Ma tr?n bi?u di?n d? th?
int graph[][V] = { { 0, 10, 15, 20 },
{ 10, 0, 35, 25 },
{ 15, 35, 0, 30 },
{ 20, 25, 30, 0 } };
int s = 0;
cout << travllingSalesmanProblem(graph, s) << endl;
return 0;
}

/*
    V là s? lu?ng d?nh trong d? th?.
    s là d?nh xu?t phát c?a du?ng di.
*/

