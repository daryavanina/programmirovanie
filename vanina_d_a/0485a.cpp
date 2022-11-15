#include<iostream>
#include<set>
int main()
{
	int x = 0;//детали
	int m = 0;//mod m
	std::cin >> x >> m;
	std::set <int> ostatki;
	bool ans = 1;
	while (ostatki.count(x%m) == 0) {
		if (x % m == 0) {
			ans = 0;
			break;
		}
		else{
		ostatki.insert(x % m);
		x += x % m;
		}
	}
	if (ans) {
		std::cout << "No";
	}
	else {
		std::cout << "Yes";
	}
}
