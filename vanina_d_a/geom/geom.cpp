#include <iostream>
#include<cmath>

struct Rdec2D {
    double x {0.0};
    double y {0.0};
    Rdec2D(double x, double y)
        :x(x), y(y) {}

};

struct Rpol2D {
    double r {0.0};
    double ph {0.0};
};

std::ostream& operator<<(std::ostream& ostrm, const Rdec2D& cd) {
    return ostrm << '(' << cd.x << ', ' << cd.y << ')';
}

std::ostream& operator<<(std::ostream& ostrm, const Rpol2D& cd) {
    return ostrm << '(' << cd.r << ', ' << cd.ph << ')';
}

Rdec2D& operator+=(Rdec2D& n,  const Rdec2D& n1) {
    n.x = n.x + n1.x;
    n.y = n.y + n1.y;
    return n;
}

Rdec2D& operator-=(Rdec2D& n,  const Rdec2D& n1) {
    n.x = n.x - n1.x;
    n.y = n.y - n1.y;
    return n;
}

Rdec2D& operator*=(Rdec2D& n,const double& num) {
    n.x = n.x * num;
    n.y = n.y * num;
    return n;
}

Rdec2D& operator/=(Rdec2D& n,const double& num) {
    n.x = n.x / num;
    n.y = n.y / num;
    return n;
}

Rdec2D operator+(const Rdec2D& n, const Rdec2D& n1) {
    Rdec2D res{n.x + n1.x, n.y + n1.y};
    return res;
}

Rdec2D operator-(const Rdec2D& n, const Rdec2D& n1) {
    Rdec2D res{n.x - n1.x, n.y - n1.y};
    return res;
}

Rdec2D operator*(const Rdec2D& n, const double& num) {
    Rdec2D res{n.x * num, n.y * num};
    return res;
}

Rdec2D operator/(const Rdec2D& n, const double& num) {
    Rdec2D res{n.x / num, n.y / num};
    return res;
}

double norm(const Rdec2D& n) {
    return sqrt(n.x * n.x + n.y * n.y);
}

double d(const Rdec2D& n, const Rdec2D& n1) {
    return n.x * n1.x + n.y * n1.y;
}

Rpol2D ToPol(Rdec2D vector) {
    double r = std::sqrt(vector.x * vector.x + vector.y * vector.y);
	double phi = std::asin(vector.y / r);
	Rpol2D v{r, phi};
	return v;
}

int main() {
    Rdec2D c1 (2.1, 4.2);
    Rdec2D c2 (2.2, 4.4);
    std::cout << "c1 = " << c1 << ', ' << "c2 = " << c2 << std::endl;
    Rdec2D sum = c1 + c2;
    std::cout << "c1 + c2 = " << sum << std::endl;
    Rdec2D min = c1 - c2;
    std::cout << "c1 - c2 = " << min << std::endl;
    Rdec2D mult1 = c1 * 2;
    Rdec2D mult2 = c2 * 2;
    std::cout << "c1 * 2 = " << mult1 << ', ' << "c2 * 2 = " << mult2 << std::endl;
    Rdec2D div1 = c1 / 2;
    Rdec2D div2 = c2 / 2;
    std::cout << "c1 / 2 = " << div1 << ', ' << "c2 / 2 = " << div2 << std::endl;
}
