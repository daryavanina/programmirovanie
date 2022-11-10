#include <iostream>

int main() {
	int n = 0;
	std::cin >> n;
	int a = 0, b = 0, c = 0, d = 0;
	std:: cin >> a >> b >> c >> d;
	int s = a + b + c + d;
	int rank = 1;
	for (int i = 1; i < n; i++) {
		std::cin >> a >> b >> c >> d;
		if (a + b + c + d > s) rank++;
	}
	std::cout << rank << std::endl;
	return 0;
}
