#define _USE_MATH_DEFINES
#include "geom.hpp"
#include <cmath>
#include<iostream>
#include <limits>


std::ostream& operator<<(std::ostream& ostrm, const Rdec2D& z) {
	return ostrm << '(' << z.x << ',' << z.y << ')';
}
std::ostream& operator<<(std::ostream& ostrm, const Rpol2D& z) {
	return ostrm << '[' << z.r << ',' << z.phi << ']';
}
Rdec2D operator-(const Rdec2D& lhs) {
	return { -lhs.x, -lhs.y };
}
Rpol2D operator-(const Rpol2D& lhs) {
	if (lhs.phi >= M_PI) {
		return { lhs.r, lhs.phi - M_PI };
	}
	else {
		return { lhs.r, lhs.phi + M_PI };
	}
}
void operator-=(Rdec2D& lhs, Rdec2D& rhs) {
	lhs.x -= rhs.x;
	lhs.y -= rhs.y;
	//return lhs;
}
void operator-=(Rpol2D& lhs, Rpol2D& rhs) {
	Rdec2D vectr1 = ToDec(lhs);
	Rdec2D vectr2 = ToDec(rhs);
	vectr1.x -= vectr2.x;
	vectr1.y -= vectr2.y;
	lhs = ToPol(vectr1);
}

Rdec2D operator+(const Rdec2D& lhs, const Rdec2D& rhs) {
	return { lhs.x + rhs.x, lhs.y + rhs.y };
}
Rpol2D operator+(const Rpol2D& lhs, const Rpol2D& rhs) {
	Rdec2D vectr1 = ToDec(lhs);
	Rdec2D vectr2 = ToDec(rhs);
	return ToPol({ vectr1.x + vectr2.x, vectr1.y + vectr2.y });
}

void operator+=(Rdec2D& lhs, Rdec2D& rhs) {
	lhs.x += rhs.x;
	lhs.y += rhs.y;
}

void operator+=(Rpol2D& lhs, Rpol2D& rhs) {
	Rdec2D vectr1 = ToDec(lhs);
	Rdec2D vectr2 = ToDec(rhs);
	vectr1.x += vectr2.x;
	vectr1.y += vectr2.y;
	lhs = ToPol(vectr1);
	//rhs = ToPol(vectr2);
}

Rdec2D operator-(const Rdec2D& lhs, const Rdec2D& rhs) {
	return { lhs.x - rhs.x, lhs.y - rhs.y };
}
Rpol2D operator-(const Rpol2D& lhs, const Rpol2D& rhs) {
	Rdec2D vectr1 = ToDec(lhs);
	Rdec2D vectr2 = ToDec(rhs);
	return ToPol({ vectr1.x - vectr2.x, vectr1.y - vectr2.y });
}

Rdec2D operator*(const Rdec2D& lhs, const double& nmbr) {
	return { nmbr * lhs.x,nmbr * lhs.y };
}
Rpol2D operator*(const Rpol2D& lhs, const double& nmbr) {
	return { lhs.r * nmbr, lhs.phi };
}

Rdec2D operator /(const Rdec2D& lhs, const double& nmbr) {
	return {lhs.x/nmbr, lhs.y/nmbr };
}
Rpol2D operator /(const Rpol2D& lhs, const double& nmbr) {
	return { lhs.r / nmbr, lhs.phi };
}

double Dot(const Rdec2D& lhs, const Rdec2D& rhs) {
	return lhs.x*rhs.x + lhs.y*rhs.y;
}
double Dot(const Rpol2D& lhs, const Rpol2D& rhs) {
	return (lhs.r * rhs.r * std::cos(std::abs(lhs.phi - rhs.phi)));
}

double Norm(const Rdec2D& lhs) {
	return sqrt(lhs.x * lhs.x + lhs.y * lhs.y);
}

Rdec2D ToDec(const Rpol2D& lhs) {
	return { lhs.r * std::cos(lhs.phi), lhs.r * std::sin(lhs.phi) };
}
Rpol2D ToPol(const Rdec2D& lhs) {
	if (lhs.y > 0) {
		return { Norm(lhs), std::acos(lhs.x / Norm(lhs)) };
	}
	else {
		return { Norm(lhs), 2 * M_PI - std::acos(lhs.x / Norm(lhs)) };
	}
}

bool operator ==(const Rpol2D& lhs, const Rpol2D& rhs) {
	return ((std::abs(lhs.r - rhs.r) < epsl) && (std::abs(lhs.phi - rhs.phi) < epsl));
}
bool operator ==(const Rdec2D& lhs, const Rdec2D& rhs) {
	return (std::abs(Norm(rhs)-Norm(lhs))<epsl && std::abs(rhs.x/lhs.x-rhs.y/lhs.y)<epsl);
}
bool operator!=(const Rpol2D& lhs, const Rpol2D& rhs) {
	return !((std::abs(lhs.r - rhs.r) < epsl) && (std::abs(lhs.phi - rhs.phi) < epsl));
}
bool operator!=(const Rdec2D& lhs, const Rdec2D& rhs) {
	return !(std::abs(Norm(rhs) - Norm(lhs))<epsl && std::abs(rhs.x / lhs.x - rhs.y / lhs.y)<epsl);
}
