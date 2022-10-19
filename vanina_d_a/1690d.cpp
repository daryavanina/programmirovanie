#include<iostream>
int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		int n = 0;
		std::cin >> n;
		int k = 0;
		std::cin >> k;
		std::string s;
		std::cin >> s;
		int ans = n;
		for (int str = 0; str <= n - k; str++) {
			int tek = 0;//для подсчета текущ колва белых
			for (int i = str; i < k; i++) {
				if (s[i] == 'W') { 
					tek += 1;
				}
			}
			ans = std::min(ans, tek);
		}
		std::cout << ans;
	}
}
