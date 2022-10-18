#include<iostream>
#include<string>
int v10(std::string s) {
	int step = 1;
	int ans = 0;
	for (int i = 0; i < s.size(); i++){
		ans += (s[i] - 48) * step;
		step *= 3;
	}
	return ans;
}
int main() {
	int a = 0;
	int c = 0;
	int b = 0;
	std::string s;
	std::cin >> a >> c;
	while (a || c) {
		s += (c % 3 - a % 3 + 3) % 3 + '0';//find b
		c /= 3;
		a /= 3;
	}
	std::cout << v10(s);
}
