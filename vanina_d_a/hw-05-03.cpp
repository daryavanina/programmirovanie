#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <iomanip>
int main() {
	double x = 0;//х=а, x∈[a,b]
	double b = 1;
	double step = 0.1;
	double eps = 0.0001;
	double s = 0;//сумма
	double tek = 0;//член суммы
	double y = 0;
	std::cout << "   x    s(x)  f(x)" << std::endl;
	for (; x <= b; x += step) {
		tek = 1;
		s = 0;
		for (int i = 1; i < 100; i++) {
			if (abs(tek) >= eps) {
				s += tek;
				tek *= (2*x) / i;
			}
			else {
				break;
			}
		}
		std::cout << std::fixed << std::setprecision(3);
		
		y = pow(M_E, 2 * x);
		std::cout << x << " " << s << " " << y << std::endl;
	}
}
