#include<iostream>
#include <vector>
#include<algorithm>
int main() {
	int n = 0;
	std::cin >> n;
	std::vector <int> a;
	int el = 0;
	int ans = 0;
	for (int i = 0; i < n;i++) {
		std::cin >> el;
		a.push_back(el);
	}
	sort(a.begin(), a.end());
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		if (a[i] >= cnt) {
			ans += 1;
			cnt += 1;
		}
	}
	std::cout << ans;
}
