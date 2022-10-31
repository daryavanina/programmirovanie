#include<iostream>
int main() {
	int n = 0;
	std::cin >> n;
	int ans = n&1;
	while (n >>= 1) {
		ans += n & 1;
 
	}
	std::cout << ans;
}
