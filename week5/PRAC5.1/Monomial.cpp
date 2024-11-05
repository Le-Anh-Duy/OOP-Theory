#include "Monomial.h"

Monomial::Monomial() : m_coef(0), m_expo(0) {};
Monomial::Monomial(int coef, int expo) : m_coef(coef), m_expo(expo) {};
Monomial::Monomial(const Monomial& m) : m_coef(m.m_coef), m_expo(m.m_expo) {};
Monomial::~Monomial() {};

Monomial Monomial::operator+(const Monomial& m) const {
    if (m_expo != m.m_expo) {
        throw std::invalid_argument("Exponents must be the same.");
        return Monomial(0, 0);
    }
    return Monomial(m_coef + m.m_coef, m_expo);
}


Monomial Monomial::operator-(const Monomial& m) const {
    if (m_expo != m.m_expo) {
        throw std::invalid_argument("Exponents must be the same.");
        return Monomial(0, 0);
    }
    return Monomial(m_coef - m.m_coef, m_expo);
}

Monomial Monomial::operator*(const Monomial& m) const {
    return Monomial(m_coef * m.m_coef, m_expo + m.m_expo);
}

bool Monomial::operator==(const Monomial& m) const {
    return m_coef == m.m_coef && m_expo == m.m_expo;
}

bool Monomial::operator!=(const Monomial& m) const {
    return !(*this == m);
}

bool Monomial::operator<(const Monomial& m) const {
    return m_expo < m.m_expo;
}

bool Monomial::operator<=(const Monomial& m) const {
    return *this < m || *this == m;
}

bool Monomial::operator>(const Monomial& m) const {
    return !(*this <= m);
}

bool Monomial::operator>=(const Monomial& m) const {
    return !(*this < m);
}

Monomial& Monomial::operator+=(const Monomial& m) {
    if (m_expo != m.m_expo) {
        throw std::invalid_argument("Exponents must be the same.");
        return *this;
    }
    m_coef += m.m_coef;
    return *this;
}


Monomial& Monomial::operator-=(const Monomial& m) {
    if (m_expo != m.m_expo) {
        throw std::invalid_argument("Exponents must be the same.");
        return *this;
    }
    m_coef -= m.m_coef;
    return *this;
}

Monomial& Monomial::operator*=(const Monomial& m) {
    m_coef *= m.m_coef;
    m_expo += m.m_expo;
    return *this;
}

Monomial& Monomial::operator=(const Monomial& m) {
    m_coef = m.m_coef;
    m_expo = m.m_expo;
    return *this;
}

Monomial& Monomial::operator++() {
    m_expo++;
    return *this;
}

Monomial Monomial::operator++(int) {
    Monomial temp = *this;
    m_expo++;
    return temp;
}


Monomial& Monomial::operator--() {
    m_expo--;
    return *this;
}

Monomial Monomial::operator--(int) {
    Monomial temp = *this;
    m_expo--;
    return temp;
}

Monomial Monomial::operator!() const {
    if (m_expo == 0) {
        return Monomial(0, 0);
    }

    Monomial temp = *this;
    temp.m_coef *= temp.m_expo;
    temp.m_expo--;
    return temp;
}

std::ostream& operator<<(std::ostream& os, const Monomial& m) {
    os << m.m_coef << "x^" << m.m_expo;
    return os;
}

std::istream& operator>>(std::istream& is, Monomial& m) {
    is >> m.m_coef >> m.m_expo;
    return is;
}


int Monomial::getCoef() const {
    return m_coef;
};

int Monomial::getExpo() const {
    return m_expo;
};

Monomial Monomial::operator~() const {

    Monomial temp = *this;
    temp.m_expo++;
    temp.m_coef /= temp.m_expo;
    return temp;
}

Monomial Monomial::operator/(const Monomial& m) const {
    if (m.m_expo > m_expo) {
        throw std::invalid_argument("Exponent of the divisor must be less than or equal to the exponent of the dividend.");
        return Monomial(0, 0);
    }

    if (m.m_coef == 0) {
        throw std::invalid_argument("Coefficient of the divisor must be different from 0.");
        return Monomial(0, 0);
    }

    return Monomial(m_coef / m.m_coef, m_expo - m.m_expo);
}
