#include<iostream>
int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		int n = 0;
		std::cin >> n;
		char color;
		std::cin >> color;
		std::string s;
		std::cin >> s;
		int ind = 0;
		int ans = 0;
		for (int i = 2 * n - 1; i >= 0; i--) {
			if (s[i%n] == 'g') {//последнее вхождение g
				ind = i;
			}
			if (s[i%n] == color) {
				ans = std::max(ans, ind - i);
			}
		}
		std::cout << ans << std::endl;
	}
}
