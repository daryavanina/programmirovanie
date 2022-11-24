#include <iosfwd>
#include <limits>
struct Rdec2D {
	double x = 0.0;
	double y = 0.0;
};
struct Rpol2D {
	double r = 0.0;
	double phi = 0.0;
};
const double epsl = std::numeric_limits<double>::epsilon() * 2;
std::ostream& operator<<(std::ostream& ostrm, const Rdec2D& z);
std::ostream& operator<<(std::ostream& ostrm, const Rpol2D& z);

Rpol2D operator-(const Rpol2D& lhs);
Rdec2D operator-(const Rdec2D& lhs);

Rdec2D operator+(const Rdec2D& lhs, const Rdec2D& rhs);
Rpol2D operator+(const Rpol2D& lhs, const Rpol2D& rhs);

Rdec2D operator-(const Rdec2D& lhs, const Rdec2D& rhs);
Rpol2D operator-(const Rpol2D& lhs, const Rpol2D& rhs);

Rdec2D operator*(const Rdec2D& lhs, const double& nmbr);
Rpol2D operator*(const Rpol2D& lhs, const double& nmbr);

Rdec2D operator /(const Rdec2D& lhs, const double& nmbr);
Rpol2D operator /(const Rpol2D& lhs, const double& nmbr);

double Dot(const Rdec2D& lhs, const Rdec2D& rhs);
double Dot(const Rpol2D& lhs, const Rpol2D& rhs);

double Norm(const Rdec2D& lhs);

Rdec2D ToDec(const Rpol2D& lhs);
Rpol2D ToPol(const Rdec2D& lhs);

bool operator==(const Rdec2D& lhs, const Rdec2D& rhs);
bool operator==(const Rpol2D& lhs, const Rpol2D& rhs);

bool operator!=(const Rpol2D& lhs, const Rpol2D& rhs);
bool operator!=(const Rdec2D& lhs, const Rdec2D& rhs);
