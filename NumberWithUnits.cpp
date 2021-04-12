//
// Created by ravid on 07/04/2021.
//

#include <iostream>
#include <utility>
#include "NumberWithUnits.hpp"
#include "types_map.hpp"

using namespace std;
using namespace ariel;


//NumberWithUnits::NumberWithUnits() : _amount(0), _type(0) {}

NumberWithUnits::NumberWithUnits(int amount, string type) :
        _amount(amount),
        _type(std::move(type)){}

void ariel::NumberWithUnits::read_units(ifstream &ifs) {
string line;
    getline(ifs,line);
line.

}

// OPERATORS //
bool NumberWithUnits::operator==(const NumberWithUnits &n) const {

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

NumberWithUnits ariel::NumberWithUnits::operator+(NumberWithUnits &n) {

    return n;
}

NumberWithUnits ariel::NumberWithUnits::operator+() {
    return NumberWithUnits();
}

NumberWithUnits ariel::NumberWithUnits::operator+=(NumberWithUnits n) {
    return n;
}

NumberWithUnits ariel::NumberWithUnits::operator-(NumberWithUnits &n) {
    return n;
}

NumberWithUnits ariel::NumberWithUnits::operator-() {
    return NumberWithUnits();
}

NumberWithUnits ariel::NumberWithUnits::operator-=(NumberWithUnits n) {
    return n;
}

NumberWithUnits ariel::NumberWithUnits::operator--() {
    return NumberWithUnits();
}

NumberWithUnits ariel::NumberWithUnits::operator++() {
    return NumberWithUnits();
}

NumberWithUnits ariel::operator*(double d, NumberWithUnits n) {
    return NumberWithUnits();
}

 NumberWithUnits ariel::NumberWithUnits::operator--(int) {
    return NumberWithUnits();
}

NumberWithUnits ariel::NumberWithUnits::operator++(int) {
    return NumberWithUnits();
}

ostream &ariel::operator<<(std::ostream &os, const NumberWithUnits &n) {
    return os;
}

istream &ariel::operator>>(std::istream &is, NumberWithUnits &n) {
    return is;
}

int NumberWithUnits::fine_type_by_subtype(const string &basicString) {

    if (basicString == string("km")
        or basicString == string("m")
        or basicString == string("cm")) {
        return DIST;
    }
    if (basicString == string("kg")
        or basicString == string("g")
        or basicString == string("ton")) {
        return WEIGHT;
    }
    if (basicString == string("hour")
        or basicString == string("min")
        or basicString == string("sec")) {
        return TIME;
    }
    if (basicString == string("USD")
        or basicString == string("ILS")) {
        return MONEY;
    }
    cout << " illegal type " << endl;
    throw std::exception();
}


