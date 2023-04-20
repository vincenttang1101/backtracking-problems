#include <bits/stdc++.h>
using namespace std;
 
#define ARRAYSIZE(a) (sizeof(a))/(sizeof(a[0]))
static int total_nodes;
 
// in tập hợp con được tìm thấy
void printSubset(int A[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout<<" "<< A[i];
    }
    cout<<"\n";
}
 
// hàm so sánh qsort
int comparator(const void *pLhs, const void *pRhs)
{
    int *lhs = (int *)pLhs;
    int *rhs = (int *)pRhs;
    return *lhs > *rhs;
}
 
// đầu vào
// s - véc tơ đặt
// t - véc tơ bộ
// s_size - đặt kích thước
// t_size - kích thước bộ dữ liệu cho đến nay
// tổng - tổng cho đến nay
// ite - số nút
// target_sum - tổng cần tìm
void subset_sum(int s[], int t[],
                int s_size, int t_size,
                int sum, int ite,
                int const target_sum)
{
    total_nodes++;
 
    if( target_sum == sum )
    {
        // Chúng ta tìm thấy tổng
        printSubset(t, t_size);
 
        // constraint check
        if( ite + 1 < s_size && sum - s[ite] + s[ite + 1] <= target_sum )
        {
            // Loại trừ mục đã thêm trước đó và xem xét ứng cử viên tiếp theo
            subset_sum(s, t, s_size, t_size - 1, sum - s[ite], ite + 1, target_sum);
        }
        return;
    }
    else
    {
        // kiểm tra ràng buộc
        if( ite < s_size && sum + s[ite] <= target_sum )
        {
            // tạo các nút dọc theo chiều rộng
            for( int i = ite; i < s_size; i++ )
            {
                t[t_size] = s[i];
                if( sum + s[i] <= target_sum )
                {
                    // xem xét nút cấp tiếp theo (dọc theo độ sâu)
                    subset_sum(s, t, s_size, t_size + 1, sum + s[i], i + 1, target_sum);
                }
            }
        }
    }
}
 
// Trình bao bọc in các tập hợp con có tổng bằng target_sum
void generateSubsets(int s[], int size, int target_sum)
{
    int *tuplet_vector = (int *)malloc(size * sizeof(int));
    int total = 0;
 
    // sắp xếp tập hợp
    qsort(s, size, sizeof(int), &comparator);
    for( int i = 0; i < size; i++ )
    {
        total += s[i];
    }
    if( s[0] <= target_sum && total >= target_sum )
    {
        subset_sum(s, tuplet_vector, size, 0, 0, 0, target_sum);
    }
    free(tuplet_vector);
}
 
// Mã trình điều khiển
int main()
{
    int weights[] = {15, 22, 14, 26, 32, 9, 16, 8};
    int target = 53;
    int size = ARRAYSIZE(weights);
    generateSubsets(weights, size, target);
    cout << "Nodes generated " << total_nodes;
    return 0;
}
