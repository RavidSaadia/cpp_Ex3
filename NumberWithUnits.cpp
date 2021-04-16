//
// Created by ravid on 07/04/2021.
//
#include <sstream>

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
        _type_map[s1][s2] = d;
        _type_map[s2][s1] = 1 / d;

    };

    bool is_in_map(std::string s) {
        return _type_map.contains(s);
    }

    bool are_same_dim(std::string s1, std::string s2) {

        if (is_in_map(s1)) {
            return _type_map[s1].contains(s2);
        }
        std::cout << "the type is unknown!" << std::endl;
        return false;

    }


};

TypesMap t_map;


ariel::NumberWithUnits::NumberWithUnits(double amount, string type) :
        _amount(amount),
        _type(std::move(type)) {

    //throw exep' if unknown
}

void ariel::NumberWithUnits::read_units(ifstream &ifs) {
    string line;
    while (getline(ifs, line)) {
        array<string, 3> parts;
        for (size_t i = 0; i < 3;) {

            string key = line.substr(0, line.find_first_of(' ', 0));
            if (key != "=" && key != "1") {
                parts[i++] = key;
            }
            line = line.substr(line.find_first_not_of(' ', key.length()));
        }
        t_map.add_type(parts[0], parts[2], (double) stod(parts[1]));// consider use stold
//        t_map.add_type(parts[2], parts[0], (double) 1 / stod(parts[1]));// consider use stold
    }
    ifs.close();
}

// OPERATORS //
bool ariel::NumberWithUnits::operator==(const NumberWithUnits &n) const {

    return false;
}

bool ariel::NumberWithUnits::operator<=(const NumberWithUnits &n) const {
    return false;
}

bool ariel::NumberWithUnits::operator!=(const NumberWithUnits &n) const {
    return false;
}

bool ariel::NumberWithUnits::operator<(const NumberWithUnits &n) const {
    return false;
}

bool ariel::NumberWithUnits::operator>=(const NumberWithUnits &n) const {
    return false;
}

bool ariel::NumberWithUnits::operator>(const NumberWithUnits &n) const {
    return false;
}

ariel::NumberWithUnits ariel::NumberWithUnits::operator+(const ariel::NumberWithUnits &n) const {

    return *this;
}

ariel::NumberWithUnits ariel::NumberWithUnits::operator+() {
    return *this;
}

ariel::NumberWithUnits &ariel::NumberWithUnits::operator+=(const NumberWithUnits &n) {
    return *this;
}

ariel::NumberWithUnits ariel::NumberWithUnits::operator-(const ariel::NumberWithUnits &n) const {
    return *this;
}

ariel::NumberWithUnits ariel::NumberWithUnits::operator-() {
    return *this;
}

ariel::NumberWithUnits &ariel::NumberWithUnits::operator-=(const ariel::NumberWithUnits &n) {
    return *this;
}

ariel::NumberWithUnits &ariel::NumberWithUnits::operator--() {
    return *this;
}

ariel::NumberWithUnits &ariel::NumberWithUnits::operator++() {
    return *this;
}

ariel::NumberWithUnits ariel::NumberWithUnits::operator--(int) {
    return *this;
}

ariel::NumberWithUnits ariel::NumberWithUnits::operator++(int) {
    return *this;
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



