#include <iostream>
using namespace std;

/* Một hàm tiện ích để kiểm tra xem một từ
có trong từ điển hay không. Một mảng của
chuỗi được sử dụng cho từ điển. Sử dụng mảng
chuỗi cho từ điển chắc chắn là không
một ý kiến ​​hay. Chúng tôi đã sử dụng để đơn giản hóa
chương trình*/
int dictionaryContains(string &word)
{
	string dictionary[] = {"mobile","samsung","sam","sung",
							"man","mango", "icecream","and",
							"go","i","love","ice","cream"};
	int n = sizeof(dictionary)/sizeof(dictionary[0]);
	for (int i = 0; i < n; i++)
		if (dictionary[i].compare(word) == 0)
			return true;
	return false;
}

// Nguyên mẫu của wordBreakUtil
void wordBreakUtil(string str, int size, string result);

// In tất cả các ngắt từ có thể có của chuỗi đã cho
void wordBreak(string str)
{
	// Đối số cuối cùng là tiền tố
	wordBreakUtil(str, str.size(), "");
}

// Kết quả lưu tiền tố hiện tại với dấu cách
// giữa các từ
void wordBreakUtil(string str, int n, string result)
{
	// Xử lý tất cả các tiền tố từng cái một
	for (int i=1; i<=n; i++)
	{
		// Trích xuất chuỗi con từ 0 đến i trong tiền tố
		string prefix = str.substr(0, i);


		// Nếu từ điển chứa tiền tố này, thì
		// chúng tôi kiểm tra chuỗi còn lại. Nếu không thì
		// chúng tôi bỏ qua tiền tố này (không có tiền tố nào khác cho
		// điều này nếu) và thử tiếp theo
		if (dictionaryContains(prefix))
		{
			// Nếu không còn phần tử nào thì in ra
			if (i == n)
			{
				// Thêm phần tử này vào tiền tố trước đó
				result += prefix;
				cout << result << endl;
				return;
			}
			wordBreakUtil(str.substr(i, n-i), n-i,
								result + prefix + " ");
		}
	}	
}

// Mã trình điều khiển
int main()
{
	// Gọi hàm
	cout << "First Test:\n";
	wordBreak("iloveicecreamandmango");

	cout << "\nSecond Test:\n";
	wordBreak("ilovesamsungmobile");
	return 0;
}

