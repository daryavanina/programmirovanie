#include<iostream>
#include<vector>
#include<algorithm>
const int N = 2e5 + 10;
int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		int n = 0;
		std::cin >> n;
		int cnt = 0, ans = 0;
		int a[N];
		for (int i = 1; i <= n; ++i) {
			int v;
			std::cin >> v;
			while (v % 2 == 0) {
				v /= 2;
				cnt++;
			}
			int j = i; 
			
			a[i] = 0;
			while (j % 2 == 0)j /= 2, a[i]++;
		}
		std::sort(a + 1, a + n + 1, std::greater<int>());
		for (int i = 1; i <= n && cnt < n; i++) {
			cnt += a[i];
			ans++;
		}
		if (cnt < n) {
			std::cout << -1 << std::endl;
		}
		else {
			std::cout << ans << std::endl;
		}
	}
	return 0;
}
