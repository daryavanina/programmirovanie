#ifndef RATIONAL_H
#define RATIONAL_H
#endif 
#include <iosfwd>

class Rational{
public:
    Rational() = default;
    explicit Rational(const int second);
    Rational(const Rational& second);
    Rational(const int num, const int denum);
    Rational& operator=(const Rational& second) = default;
    ~Rational() = default;

    bool operator==(const Rational& second) const;
    bool operator!=(const Rational& second) const;
    bool operator>(const Rational& second) const;
    bool operator<(const Rational& second) const;

    Rational operator-() const noexcept;

    Rational& operator+=(const Rational& second);
    Rational& operator+=(const int second){
        return operator+= (Rational(second));
    }

    Rational& operator-=(const Rational& second);
    Rational& operator-=(const int second){
        return operator-= (Rational(second));
    }

    Rational& operator*= (const Rational& second);
    Rational& operator*= (const int second){
        return operator*= (Rational(second));
    }

    Rational& operator/= (const Rational& second);
    Rational& operator/= (const int second){
        return operator/= (Rational(second));
    }

    std::ostream& writeTo (std::ostream& ostrm) const;
    std::istream& readFrom (std::istream& istrm);

private:
    int num_{0};
    int denum_{1};
    int NOD(int x, int y);
    static const char slash{'/'};
    Rational& round();
};
inline Rational operator+ (const Rational& first, const Rational& second){
    return Rational(first) += second;
}
inline Rational operator+ (const Rational& first, const int second){
    return Rational(first) + Rational(second);
}
inline Rational operator+ (const int first, const Rational& second){
    return Rational(first) + Rational(second);
}

inline Rational operator- (const Rational& first, const Rational& second){
    return Rational(first) -= second;
}
inline Rational operator- (const Rational& first, const int second){
    return Rational(first) - Rational(second);
}
inline Rational operator- (const int first, const Rational& second){
    return Rational(first) - Rational(second);
}

inline Rational operator* (const Rational& first, const Rational& second){
    return Rational(first) *= second;
}
inline Rational operator* (const Rational& first, const int second){
    return Rational(first) * Rational(second);
}
inline Rational operator* (const int first, const Rational& second){
    return Rational(first) * Rational(second);
}

inline Rational operator/ (const Rational& first, const Rational& second){
    return Rational(first) /= second;
}
inline Rational operator/ (const Rational& first, const int second){
    return Rational(first) / Rational(second);
}
inline Rational operator/ (const int first, const Rational& second){
    return Rational(first) / Rational(second);
}

std::ostream& operator<< (std::ostream& ostrm, const Rational& second);
std::istream& operator>> (std::istream& istrm, Rational& second);
