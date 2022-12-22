#include <iostream>
#include<cmath>

int main() {
    double x, y;
    int i = 0;
        
    std::cin >> x >> y;
    i++;
    int summ = 0;
    if ((y <= 2 - x*x) && (y >= abs(x))) {
        summ += 1;
    }
    std::cout << i / summ;
}
