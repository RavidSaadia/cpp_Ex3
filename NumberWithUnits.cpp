//
// Created by ravid on 07/04/2021.
//
#include <string>
#include <fstream>

#include <iostream>
#include <utility>
#include "NumberWithUnits.hpp"
//#include "Types_map.hpp"
#include <map>
#include <ostream>

using namespace std;
using namespace ariel;
//using namespace ariel;


//Types_map NumberWithUnits:: _typesMap;
//NumberWithUnits::NumberWithUnits() : _amount(0), _type(0) {}
struct TypesMap {

    std::map<std::string, std::map<std::string, double>> _type_map;


public:


    void add_type(std::string s1, std::string s2, double d) {
        _type_map[s1][s1] = 1;
        _type_map[s2][s2] = 1;
        _type_map[s1][s2] = 1 / d;
        _type_map[s2][s1] = d;
    };

    bool is_in_map(std::string s) {
        return _type_map.contains(s);
    }

    bool are_same_dim(std::string s1, std::string s2) {

        if (is_in_map(s1)) {
            return _type_map[s1].contains(s2);
        }
        std::cout << "the type " << s1 << " is unknown!" << std::endl;
        return false;

    }

    double get_edge(string s1, string s2) {
        if (_type_map.contains(s1) && _type_map.contains(s2)) {
            return _type_map[s1][s2];
        }
        return -1;
    }


};

static TypesMap t_map;


ariel::NumberWithUnits::NumberWithUnits(double amount, string type) :
        _amount(amount),
        _type(std::move(type)) {}

void throw_type_exception(string s1, string s2) {
    if (!t_map.are_same_dim(s1, s2) || !t_map.is_in_map(s1) || !t_map.is_in_map(s2)) {
        throw invalid_argument("Units do not match - [" + s1 + "] cannot be converted to [" + s2 + "]");
    }
}

void NumberWithUnits::read_units(ifstream &file) {
    string line;
    while (getline(file, line)) {

        array<string, 3> parts;
        for (size_t i = 0; i < 3;) {

            string key = line.substr(0, line.find_first_of(' ', 0));
            if (key != "=" && key != "1") {
                parts[i++] = key;
            }
            if (line.length() > key.length()) {
                line = line.substr(line.find_first_not_of(' ', key.length()));
            }
        }

        t_map.add_type(parts[0], parts[2], (double) stod(parts[1]));// consider use stold
    }
    file.close();
}

// BOOL OPERATORS //
bool ariel::NumberWithUnits::operator==(const NumberWithUnits &n) const {
    string s1 = this->_type;
    string s2 = n._type;
    if (s1 == s2 && this->_amount == n._amount) { return true; }
    throw_type_exception(s1, s2);

    double edge = t_map.get_edge(s1, s2);

    if (this->_amount == n._amount * edge) {
        return true;
    }

    return false;
}

bool ariel::NumberWithUnits::operator!=(const NumberWithUnits &n) const {

    return this != &n;
}

bool ariel::NumberWithUnits::operator<=(const NumberWithUnits &n) const {
    string s1 = this->_type;
    string s2 = n._type;
    throw_type_exception(s1, s2);
    double edge = t_map.get_edge(s1, s2);

    if (this->_amount <= n._amount * edge) {
        return true;
    }

    return false;
}

bool ariel::NumberWithUnits::operator>=(const NumberWithUnits &n) const {
    string s1 = this->_type;
    string s2 = n._type;

    throw_type_exception(s1, s2);
    double edge = t_map.get_edge(s1, s2);

    if (this->_amount >= n._amount * edge) {
        return true;
    }

    return false;
}

bool ariel::NumberWithUnits::operator<(const NumberWithUnits &n) const {
    NumberWithUnits temp { this->getAmount(),this->getType()};
    return !(temp >= n);
}

bool ariel::NumberWithUnits::operator>(const NumberWithUnits &n) const {
    NumberWithUnits temp { this->getAmount(),this->getType()};
    return !(temp <= n);

}

// SUM OPERATORS //

ariel::NumberWithUnits ariel::NumberWithUnits::operator+(const ariel::NumberWithUnits &n) const {
    string s1 = this->_type;
    string s2 = n._type;
    throw_type_exception(s1, s2);
    double edge = t_map.get_edge(s1, s2);


    return NumberWithUnits(this->_amount + n._amount * edge, s1);
}

ariel::NumberWithUnits ariel::NumberWithUnits::operator-(const ariel::NumberWithUnits &n) const {
    string s1 = this->_type;
    string s2 = n._type;
    throw_type_exception(s1, s2);
    double edge = t_map.get_edge(s1, s2);


    return NumberWithUnits(this->_amount - n._amount * edge, s1);
}

ariel::NumberWithUnits &ariel::NumberWithUnits::operator+=(const NumberWithUnits &n) {
    string s1 = this->_type;
    string s2 = n._type;

    throw_type_exception(s1, s2);
    double edge = t_map.get_edge(s1, s2);
    this->_amount += n._amount * edge;

    return *this;
}

ariel::NumberWithUnits &ariel::NumberWithUnits::operator-=(const ariel::NumberWithUnits &n) {
NumberWithUnits temp {n._amount,n._type};
    return *this += (-temp);
}

ariel::NumberWithUnits ariel::NumberWithUnits::operator+() {
    return *this;
}

ariel::NumberWithUnits ariel::NumberWithUnits::operator-() {

    return NumberWithUnits( -this->_amount,this->_type);
}

ariel::NumberWithUnits &ariel::NumberWithUnits::operator++() {
    this->_amount++;
    return *this;
}

ariel::NumberWithUnits &ariel::NumberWithUnits::operator--() {
    this->_amount--;

    return *this;
}

ariel::NumberWithUnits ariel::NumberWithUnits::operator--(int) {

//    NumberWithUnits temp {this->_amount--,this->_type};
//    return temp;
    this->_amount--;
    return *this;
}

ariel::NumberWithUnits ariel::NumberWithUnits::operator++(int) {
    this->_amount++;

    return *this;
}

double NumberWithUnits::getAmount() const {
    return _amount;
}

const string &NumberWithUnits::getType() const {
    return _type;
}

//const NumberWithUnits ariel::operator*(const double &d, const NumberWithUnits &n) {
//    return n ;
//}
//
//const NumberWithUnits ariel::operator*(const NumberWithUnits &n,const  double &d) {
//    return n;
//}

//std::ostream &operator<<(std::ostream &os, const ariel::NumberWithUnits &n) {
//    return os;
//}
//
//std::istream &operator>>(std::istream &is, ariel::NumberWithUnits &n) {
//    return is;
//}





//NumberWithUnits ariel::operator*(const NumberWithUnits &n, int d) {
//    return NumberWithUnits(0, "h");
//}
//
//NumberWithUnits ariel::operator*(int d, const NumberWithUnits &n) {
//    return NumberWithUnits(0, "l");
//}



