#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include<iomanip>
double fact(int N)
{
	if (N < 0)
		return 0;
	if (N == 0)
		return 1;
	else
		return N * fact(N - 1);
}
int main() {
	double x = 0;//х=а, x∈[a,b]
	double b = 1;
	double step = 0.1;
	double eps = 0.0001;
	double s = 0;//сумма
	double tek = 0;//член суммы
	int i_nach = 1;
	//int x = 0;
	std::cout << "   x    s(x)  f(x)" << std::endl;
	for (; x <= b; x += step) {
		tek = 1;
		s = 0;
		for (int i = i_nach; i < 100; i++) {
			if (abs(tek) >= eps) {
				s += tek;
				tek = pow(2*x,i)/fact(i);
			}
			else {
				break;
			}
		}
		std::cout << std::fixed << std::setprecision(3);
		double y = 0;
		y = pow(M_E, 2 * x);
		std::cout << x << " " << s << " " << y << std::endl;
		std::cout << std::endl;
	}
	//std::cout << fact(4);
}

