#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include<iomanip>
int main() {
	double x = 0;//х=а, x∈[a,b]
	double b = 1;
	double step = 0.05;
	double eps = 0.001;//do while x>eps
	double s = 0;//сумма
	double tek = 0;//член суммы
	std::cout << "   x    s(x)  f(x)" << std::endl;
	for (; x <= b; x += step) {
		s = x * sin(M_PI / 4);
		tek = x;
		for (int i = 2; i < 100; i++) {
			tek *= x;
			if (i%4!=0 && abs(tek * sin(i * M_PI / 4))>=eps) {
				s += tek * sin(i * M_PI / 4);
			}
			else {
				break;
			}
		}
		std::cout << std::fixed << std::setprecision(3);
		double y = 0;
		y = x * sin(M_PI / 4) / (1 - 2 * x * cos(M_PI / 4));
		std::cout << x << " " << s << " " << y << std::endl;
	}
}
