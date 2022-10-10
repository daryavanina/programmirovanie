#include<iostream>
#include<vector>
#include<algorithm>
int main() {
	int t;
	std::cin >> t;
	while (t--) {
		int a, b, n;
		std::cin >> a >> b;
		n = a + b;
		std::string s;
		std::cin >> s;
		for (int i = 0; i < n; i++) {
			if (s[i] == '?')
				s[i] = s[n - i - 1];
		}
		a -= std::count(s.begin(), s.end(), '0');
		b -= std::count(s.begin(), s.end(), '1');
		for (int i = 0; i <= n / 2; i++) {
			if (i != n - i - 1 && s[i] == '?') {//если это не середина
				if (a > 1) {
					s[i] = s[n - 1 - i] = '0';
					a -= 2;
				}
				else {
				if (b > 1) {
					s[i] = s[n - 1 - i] = '1';
					b -= 2;
				}
			}
			}
			else {
				if (s[i] == '?') {//если нечетное кол-во и это середина
					if (a!=0)
					{
						s[i] = '0';
						a--;
					}
					else {
						s[i] = '1';
						b--;
					}
				}
			}
		}
		std::string v = s;
		reverse(v.begin(), v.end());
		if (v == s && a == 0 && b == 0)
			std::cout << s << std::endl;
		else 
			std::cout << "-1" << std::endl;
	}
}
