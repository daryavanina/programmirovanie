#include <iostream> 

int main() {
	int t;
	std::cin >> t;
	while (t--) {
		int n = 0;
		int k = 0;
		int z = 0;
		int o = 0;
		int ok = 1;
		std::string s;
		std::cin >> n;
		std::cin >> k;
		std::cin >> s;
		for (int i = 0; i < n; i++) {
			if (s[i] != '?' && s[i % k] != '?' && s[i] != s[i % k])
				ok = 0;
			if (s[i] != '?')
				s[i % k] = s[i];
		}
		for (int i = 0; i < k; ++i) {
			z += (s[i] == '0');
			o += (s[i] == '1');
		}
		std::cout << ((ok && z <= k / 2 && o <= k / 2) ? "YES\n" : "NO\n");
	}
}
