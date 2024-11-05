#include "Monomial.h"
class Polynomial {
private:
    Monomial* m_monomials = nullptr;
    int m_degree = 0;
public:

    Polynomial();
    Polynomial(Monomial* monomials, int size);
    Polynomial(int deg, float* coefs);
    Polynomial(const Polynomial& p);
    ~Polynomial();

    Polynomial operator+(const Polynomial& p) const;
    Polynomial operator-(const Polynomial& p) const;
    Polynomial operator*(const Polynomial& p) const;
    Polynomial operator!() const; // derivative
    Polynomial operator~() const; // anti-derivative

    Polynomial operator/(float f) const;
    Polynomial operator*(float f) const;
    Polynomial operator+(float f) const;
    Polynomial operator-(float f) const;


    bool operator==(const Polynomial& p) const;
    bool operator!=(const Polynomial& p) const;
    bool operator<(const Polynomial& p) const;
    bool operator<=(const Polynomial& p) const;
    bool operator>(const Polynomial& p) const;
    bool operator>=(const Polynomial& p) const;

    Polynomial& operator+=(const Polynomial& p);
    Polynomial& operator*=(const Polynomial& p);
    Polynomial& operator=(const Polynomial& p);

    void setDegree(int deg);
    int getDegree() const;
    int getCoefOfDeg(int deg) const;
    void setCoefOfDeg(int deg, int coef);

    friend std::ostream& operator<<(std::ostream& os, const Polynomial& p);
    friend std::istream& operator>>(std::istream& is, Polynomial& p);

};