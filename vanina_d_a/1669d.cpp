#include<iostream>


int main()
{
	int T;
	std::cin >> T;
	while (T--) {
		int n;
		std::string s;
		std::string ans = "YES\n";
		std::cin >> n >> s;
		s += 'W';
		int sz = 0;
		int ok = 0;
		for (int i = 0; i <= n; i++)
			if (s[i] == 'W') {
				if (sz && !ok) {
					ans = "NO\n";
				}
				sz = 0;
				ok = 0;
			}
			else {
				sz++;
				if (i && s[i - 1] - 'B' == 'R' - s[i]) {
					ok = 1;
				}
			}
		std::cout << ans;
	}
}
