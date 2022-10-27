#include<iostream>
int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		int n = 0;
		std::cin >> n;
		int k = 0;
		std::cin >> k;
		std::string s = "";
		std::cin >> s;
		int ans = n;
		int tek = 0;
		for (int i = 0; i < k; i++) {//подсчет белых в первых k элементах
			if (s[i] == 'W') {
				tek += 1;
			}
		}
		ans = std::min(ans, tek);
		for (int i = 0; i < n - k; i++) {
			if (s[i] != s[i + k ]) {
				if (s[i] == 'B') {
					tek += 1;
				}
				else {
 
					tek = tek != 0 ? tek -= 1 : 0;
				}
			}
			ans = std::min(ans, tek);
		}
		std::cout << ans << std::endl;
	}
}
