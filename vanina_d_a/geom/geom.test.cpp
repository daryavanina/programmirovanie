#include "geom.hpp"
#include<iostream>

int main() {
	Rdec2D d1{ 1.5, -5.0 };
	Rdec2D d2{ 1.5, -5.0 };
	Rpol2D p1{ 2,3.14 };
	Rpol2D p2{ 0.1,0 };
	std::cout << "d1=" << d1 << " d2=" << d2 << std::endl;
	std::cout << "p1=" << p1 << " p2=" << p2 << std::endl;
	std::cout << "-d1=" << -d1 << " -d2=" << -d2 << std::endl;
	std::cout << "-p1=" << -p1 << " -p2=" << -p2 << std::endl;
	std::cout << "d1+d2=" << d1+d2 << " p1+p2=" << p1+p2 << std::endl;
	std::cout << "d1-d2=" << d1-d2 << " p1-p2=" << p1-p2 << std::endl;
	std::cout << "d1*5=" << d1*5 << " d2*5=" << d2*5 << std::endl;
	std::cout << "p1*2=" << p1*2 << " p2*2=" << p2*2 << std::endl;
	std::cout << "p1/0.5=" << p1/0.5 << " p2/0.5=" << p2/0.5 << std::endl;
    std::cout << "Dot(d1,d2): " << Dot(d1, d2) << std::endl;
	std::cout << "Dot(p1,p2): " << Dot(p1, p2) << std::endl;
	std::cout << "length d1: " << Norm(d1) << std::endl;
	std::cout << "ToDec(p1): " << ToDec(p1) << std::endl;
	std::cout << "ToPol(d1): " << ToPol(d1) << std::endl;
	if (d1 != d2) {
        std::cout << "d1!=d2";
	}
	else {
		std::cout << "d1==d2";
	}	
}
