#include<iostream>

int main() {
	int t;
	std::cin >> t;
	while (t--) {
		std::string s;
		std::cin >> s;
		int n = s.size();
		int l = 0;//последнее вхождение 1
		int r = n - 1;//первое вхождение 0
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				l = i;
			}
			else {
				if (s[i] == '0') {
					r = i;
					break;
				}
		    }
		}
		std::cout << r - l + 1 << std::endl;
	}
}
