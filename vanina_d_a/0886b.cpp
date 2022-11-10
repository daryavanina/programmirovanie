#include<iostream>
#include<vector>
#include<map>
int main() {
	int n = 0;// , c = 0;
	int ans = 0;
	std::cin >> n;
	std::vector<int>v(n + 1);
	std::map<int, int>mp;
	for (int i = 1; i <= n; i++) {
		std::cin >> v[i];
	}
	for (int i = n; i >= 1; i--) {

		if (mp[v[i]] == 0) {
			ans = v[i];
		}
		mp[v[i]]++;
	}
	std::cout << ans << std::endl;
}
