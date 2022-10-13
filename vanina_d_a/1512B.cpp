#include<iostream>
int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		int n = 0;
		int x1 = -1, y1 = -1;//координаты первой *
		int x2 = -1, y2 = -1;//координаты второй *
		std::cin >> n;
		char a;
		int nmbr1 = 0;//чтобы был
		int nmbr2 = 0;
		for (int i = 0; i < n * n; i++) {
			std::cin >> a;
			if (a == '*' and x1 == -1) {
				x1 = i / n;
				y1 = i % n;
				nmbr1 = i;
			}
			else {
				if (a == '*') {
					x2 = i / n ;
					y2 = i % n == 0 ? n : i % n;
					nmbr2 = i;
				}
			}
		}
		std::cout << x1 << y1 << std::endl << x2 << y2;
		for (int i = 1; i <= n * n; i++) {
			
			if (i == nmbr1 || i == nmbr2 ) {
				std::cout << "*";
			}
			else {
				if (x1 != x2 && (i == n*(x1)+y2 || i== n*(x2)+y1)) {
					std::cout << "*";
				}
				else {
					if (x1 == x2 && (i == n * (x1) + n || i == n * (x2) + n))
						std::cout << "*";
					else
						std::cout << ".";
				}
			}
			if (i % n == 0) std::cout << std::endl;
		}
		
	}
}
