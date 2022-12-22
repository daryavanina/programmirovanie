#include <iostream>

int main() {
    double a = 0.1;
    double b = 1.0;
    double delta = 0.05;
    double el = 0.0;
    double summ = 0.0;
    double eps = 0.0001;
    for (double x = a; x <= b + 0.01; x += delta) {
        int i = 0;
        summ = x;
        el = x;
        while (el >= eps) {
            i++;
            el = (el * (-x) * x * (2 * i - 1)) / (2 * i + 1);
            summ += el;
        }
        //std::cout << "x      sum" << std::endl;
        std::cout << std::fixed << x << " " << std::fixed << summ << std::endl;
    }
}
