#include "Polynomial.h"
#include <algorithm>
#include <exception>

Polynomial::Polynomial() : m_degree(0) {
    m_monomials = new Monomial[1];
    m_monomials[0] = Monomial(0, 0);
}

Polynomial::Polynomial(Monomial* monomials, int size) {

    if (size <= 0) {
        throw std::invalid_argument("Size must be greater than 0.");
    }

    for (int i = 0; i < size; i++) {
        m_degree = std::max(m_degree, monomials[i].getExpo());
    }

    m_monomials = new Monomial[m_degree + 1];
    for (int i = 0; i <= m_degree; i++) {
        m_monomials[i] = Monomial(0, i);
    }

    for (int i = 0; i < size; i++) {
        m_monomials[monomials[i].getExpo()] += monomials[i];
    }
    while (m_degree > 0 && m_monomials[m_degree].getCoef() == 0) {
        m_degree--;
    }

};

Polynomial::Polynomial(int deg, float* coefs){
    if (deg < 0) {
        throw std::invalid_argument("Degree must be greater than or equal to 0.");
    }

    m_degree = deg;
    m_monomials = new Monomial[m_degree + 1];
    for (int i = 0; i <= m_degree; i++) {
        m_monomials[i] = Monomial(coefs[i], i);
    }

    while (m_degree > 0 && m_monomials[m_degree].getCoef() == 0) {
        m_degree--;
    }
};

Polynomial::Polynomial(const Polynomial& p){
    if (p.m_degree < 0) {
        throw std::invalid_argument("Degree must be greater than or equal to 0.");
    }

    try {
        m_degree = p.m_degree;
        m_monomials = new Monomial[m_degree + 1];
    }
    catch (std::bad_alloc& e) {
        throw std::invalid_argument("Memory allocation failed.");
    }

    for (int i = 0; i <= m_degree; i++) {
        m_monomials[i] = p.m_monomials[i];
    }
};

Polynomial::~Polynomial(){
    if (m_monomials != nullptr) {
        delete[] m_monomials;
    }
};

Polynomial Polynomial::operator+(const Polynomial& p) const {

    int newDegree = std::max(m_degree, p.m_degree);
    Monomial* newMonomials = new Monomial[newDegree + 1];

    for (int i = 0; i <= newDegree; i++) {
        newMonomials[i] = Monomial(0, i);
    }

    for (int i = 0; i <= m_degree; i++) {
        newMonomials[i] += m_monomials[i];
    }

    for (int i = 0; i <= p.m_degree; i++) {
        newMonomials[i] += p.m_monomials[i];
    }

    while (newDegree > 0 && newMonomials[newDegree].getCoef() == 0) {
        newDegree--;
    }

    return Polynomial(newMonomials, newDegree + 1);
}


Polynomial Polynomial::operator-(const Polynomial& p) const {

    int newDegree = std::max(m_degree, p.m_degree);
    Monomial* newMonomials = new Monomial[newDegree + 1];
    for (int i = 0; i <= newDegree; i++) {
        newMonomials[i] = Monomial(0, i);
    }

    for (int i = 0; i <= m_degree; i++) {
        newMonomials[i] += m_monomials[i];
    }

    for (int i = 0; i <= p.m_degree; i++) {
        newMonomials[i] -= p.m_monomials[i];
    }

    while (newDegree > 0 && newMonomials[newDegree].getCoef() == 0) {
        newDegree--;
    }

    return Polynomial(newMonomials, newDegree + 1);
}

Polynomial Polynomial::operator*(const Polynomial& p) const {

    int newDegree = m_degree + p.m_degree;
    Monomial* newMonomials = new Monomial[newDegree + 1];
    for (int i = 0; i <= newDegree; i++) {
        newMonomials[i] = Monomial(0, i);
    }

    for (int i = 0; i <= m_degree; i++) {
        for (int j = 0; j <= p.m_degree; j++) {
            newMonomials[i + j] += m_monomials[i] * p.m_monomials[j];
        }
    }

    while (newDegree > 0 && newMonomials[newDegree].getCoef() == 0) {
        newDegree--;
    }

    return Polynomial(newMonomials, newDegree + 1);
}

Polynomial Polynomial::operator!() const {

    if (m_degree == 0) {
        return Polynomial();
    }


    int newDegree = m_degree - 1;
    Monomial* newMonomials = new Monomial[newDegree + 1];


    for (int i = 0; i < m_degree; i++)
        newMonomials[i] = !m_monomials[i + 1];

    return Polynomial(newMonomials, newDegree + 1);
} // derivative

Polynomial Polynomial::operator~() const {

    int newDegree = m_degree + 1;
    Monomial* newMonomials = new Monomial[newDegree + 1];
    for (int i = 0; i <= m_degree; i++)
        newMonomials[i + 1] = ~m_monomials[i];
    newMonomials[0] = Monomial(0, 0);
    return Polynomial(newMonomials, newDegree + 1);
} // anti-derivative

bool Polynomial::operator==(const Polynomial& p) const {
    if (m_degree != p.m_degree) {
        return false;
    }

    int newDegree = std::max(m_degree, p.m_degree);

    for (int i = 0; i <= newDegree; i++) {
        if (m_degree < i) {
            if (m_monomials[i].getCoef() != 0) {
                return false;
            }
        }
        else if (p.m_degree < i) {
            if (p.m_monomials[i].getCoef() != 0) {
                return false;
            }
        }
        else

        if (m_monomials[i] != p.m_monomials[i]) {
            return false;
        }
    }

    return true;

}
bool Polynomial::operator!=(const Polynomial& p)const {
    return !(*this == p);
}

bool Polynomial::operator<(const Polynomial& p) const {
    if (m_degree < p.m_degree) {
        return true;
    }

    if (m_degree > p.m_degree) {
        return false;
    }

    for (int i = m_degree; i >= 0; i--) {
        if (m_monomials[i] < p.m_monomials[i]) {
            return true;
        }
        if (m_monomials[i] > p.m_monomials[i]) {
            return false;
        }
    }

    return false;
}

bool Polynomial::operator<=(const Polynomial& p) const {
    return *this < p || *this == p;
}

bool Polynomial::operator>(const Polynomial& p) const {
    return !(*this <= p);
}

bool Polynomial::operator>=(const Polynomial& p) const {
    return !(*this < p);
}

Polynomial& Polynomial::operator+=(const Polynomial& p){
    return *this = *this + p;
};
Polynomial& Polynomial::operator*=(const Polynomial& p){
    return *this = *this * p;
};
Polynomial& Polynomial::operator=(const Polynomial& p){
    if (m_monomials != nullptr) {
        delete[] m_monomials;
    }

    m_degree = p.m_degree;
    m_monomials = new Monomial[m_degree + 1];
    for (int i = 0; i <= m_degree; i++) {
        m_monomials[i] = p.m_monomials[i];
    }

    return *this;
};

void Polynomial::setDegree(int deg){

    if (deg < 0) {
        throw std::invalid_argument("Degree must be greater than or equal to 0.");
    }

    if (deg <= m_degree) {
        while (m_degree > deg) {
            m_monomials[m_degree] = Monomial(0, m_degree);
            m_degree--;
        }
        return;
    }

    Monomial* newMonomials = new Monomial[deg + 1];

    for (int i = 0; i <= m_degree; i++) {
        newMonomials[i] = m_monomials[i];
    }

    for (int i = m_degree + 1; i <= deg; i++) {
        newMonomials[i] = Monomial(0, i);
    }

    m_degree = deg;
    delete[] m_monomials;
    m_monomials = newMonomials;
};

int Polynomial::getDegree() const {
    return m_degree;
} ;

int Polynomial::getCoefOfDeg(int deg) const {
    if (deg < 0 || deg > m_degree) {
        throw std::invalid_argument("Degree must be greater than or equal to 0 and less than or equal to the degree of the polynomial.");
    }

    return m_monomials[deg].getCoef();
} ;
void Polynomial::setCoefOfDeg(int deg, int coef){
    if (deg < 0 || deg > m_degree) {
        throw std::invalid_argument("Degree must be greater than or equal to 0 and less than or equal to the degree of the polynomial.");
    }

    m_monomials[deg] = Monomial(coef, deg);
};

std::ostream& operator<<(std::ostream& os, const Polynomial& p){
    for (int i = 0; i <= p.m_degree; i++) {
        os << p.m_monomials[i];
        if (i < p.m_degree) {
            os << " + ";
        }
    }
    return os;
};
std::istream& operator>>(std::istream& is, Polynomial& p){
    int deg;
    is >> deg;
    float* coefs = new float[deg + 1];
    for (int i = 0; i <= deg; i++) {
        is >> coefs[i];
    }
    p = Polynomial(deg, coefs);
    delete[] coefs;
    return is;
};

Polynomial Polynomial::operator/(float f) const {
    if (f == 0) {
        throw std::invalid_argument("Division by zero.");
    }

    Polynomial p = *this;
    for (int i = 0; i <= m_degree; i++) {
        p.m_monomials[i] = p.m_monomials[i] / Monomial(f, 0);
    }

    return p;
}

Polynomial Polynomial::operator*(float f) const {
    Polynomial p = *this;
    for (int i = 0; i <= m_degree; i++) {
        p.m_monomials[i] = p.m_monomials[i] * Monomial(f, 0);
    }

    return p;
}

Polynomial Polynomial::operator+(float f) const {
    Polynomial p = *this;
    p.m_monomials[0] = p.m_monomials[0] + Monomial(f, 0);
    return p;
}
Polynomial Polynomial::operator-(float f) const {
    Polynomial p = *this;
    p.m_monomials[0] = p.m_monomials[0] - Monomial(f, 0);
    return p;
}
