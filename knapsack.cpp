#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Một hàm tiện ích trả về tối đa hai số nguyên
int max(int a, int b) { return (a > b) ? a : b; }


// In các mục được đặt trong một chiếc ba lô có dung lượng W
void printknapSack(int W, int wt[], int val[], int n)
{
	int i, w;
	int K[n + 1][W + 1];

	// Xây dựng bảng K[][] theo cách từ dưới lên
	for (i = 0; i <= n; i++) {
		for (w = 0; w <= W; w++) {
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1] +
					K[i - 1][w - wt[i - 1]], K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}

	// lưu trữ kết quả của Knapsack
	int res = K[n][W];
	cout<< res << endl;
	
	w = W;
	for (i = n; i > 0 && res > 0; i--) {
		
	// hoặc là kết quả đến từ đầu
	// (K[i-1][w]) hoặc từ (val[i-1] + K[i-1]
	// [w-wt[i-1]]) như trong bảng Knapsack. Nếu như
	// nó đến từ cái sau/ nó có nghĩa là
	// mục được bao gồm.
		if (res == K[i - 1][w])
			continue;
		else {
			// Mục này được bao gồm.
			cout<<wt[i - 1] << " " ;
			
			// Vì trọng lượng này được bao gồm
			// giá trị bị trừ
			res = res - val[i - 1];
			w = w - wt[i - 1];
		}
	}
}

// Mã trình điều khiển
int main()
{
	int val[] = { 60, 100, 120 };
	int wt[] = { 10, 20, 30 };
	int W = 50;
	int n = sizeof(val) / sizeof(val[0]);
	
	printknapSack(W, wt, val, n);
	
	return 0;
}
