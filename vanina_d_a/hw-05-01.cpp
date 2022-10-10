#include <iostream>
#include <cmath>
#include<iomanip>
int main() {
	double x = -1;//х=а, x∈[a,b]
	double b = 1;
	double step = 0.1;
	double eps = pow(10, -3);//do while x>eps
	double s = 0;//сумма
	double tek = 0;//член суммы
	double factorial = 1.0;
	//int x = 0;
	std::cout << "   x    s(x)  f(x)" << std::endl;
	for (; x <= b; x += step) {
		tek = 1.0;
		s = 0.0;
		for (int i = 1; i < 100; i++) {
			if (abs(tek) >= eps) {
				s += tek;
				tek = (-tek) * x * x /( (2 * i - 1) * (2 * i));
			}
			else
				break;
		}
		std::cout << std::fixed << std::setprecision(3);
		std::cout << x << " " << s << " " << cos(x) << std::endl;
		//std::cout << std::endl;
	}
}
