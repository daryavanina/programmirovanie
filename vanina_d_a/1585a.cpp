#include<iostream>
#include<vector>
int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		int n = 0;
		std::cin >> n;
		std::vector <int> a;
		//int a[100];
		int ans = 1;
		for (int i = 0; i < n; i++) {
			int el = 0;
			std::cin >> el;
			a.push_back(el);
		}
		if (a[0] == 1) {
			ans += 1;
		}
		for (int i = 1; i < n; i++) {
			if (a[i] == 0) {
				if (a[i - 1] == 0) {
					ans = -1;
					break;
				}
			}
				else if (a[i]==1) {
				if (a[i - 1] == 0) {
					ans += 1;
				}
				else {
					ans += 5;
				}
				}
		}
		std::cout << ans << std::endl;
	}
}
