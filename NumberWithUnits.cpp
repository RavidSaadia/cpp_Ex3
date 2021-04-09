//
// Created by ravid on 07/04/2021.
//

#include <iostream>
#include "NumberWithUnits.hpp"

using namespace std;
using namespace ariel;


NumberWithUnits::NumberWithUnits() : _amount(0), _type(0) {}

NumberWithUnits::NumberWithUnits(int amount, const string &subtype) :
        _amount(amount),
        _subtype(subtype),
        _type(fine_type_by_subtype(subtype)) {}

void ariel::NumberWithUnits::read_units(ifstream &ifstream) {

}

// OPERATORS //
bool NumberWithUnits::operator==(const NumberWithUnits &n) const {
    return false;
}

bool NumberWithUnits::operator<=(const NumberWithUnits &n) const {
    return false;
}

bool NumberWithUnits::operator!=(const NumberWithUnits &n) const {
    return false;
}

bool NumberWithUnits::operator<(const NumberWithUnits &n) const {
    return false;
}

bool NumberWithUnits::operator>=(const NumberWithUnits &n) const {
    return false;
}

bool NumberWithUnits::operator>(const NumberWithUnits &n) const {
    return false;
}

NumberWithUnits NumberWithUnits::operator+(NumberWithUnits &n) {
    return n;
}

NumberWithUnits NumberWithUnits::operator+() {
    return NumberWithUnits();
}

NumberWithUnits NumberWithUnits::operator+=(NumberWithUnits n) {
    return n;
}

NumberWithUnits NumberWithUnits::operator-(NumberWithUnits &n) {
    return n;
}

NumberWithUnits NumberWithUnits::operator-() {
    return NumberWithUnits();
}

NumberWithUnits NumberWithUnits::operator-=(NumberWithUnits n) {
    return n;
}

NumberWithUnits NumberWithUnits::operator--() {
    return NumberWithUnits();
}

NumberWithUnits NumberWithUnits::operator++() {
    return NumberWithUnits();
}

NumberWithUnits operator*(double d, NumberWithUnits n) {
    return NumberWithUnits();
}

NumberWithUnits NumberWithUnits::operator--(int) {
    return NumberWithUnits();
}

NumberWithUnits NumberWithUnits::operator++(int) {
    return NumberWithUnits();
}

int NumberWithUnits::fine_type_by_subtype(const string &basicString) {

    if (basicString == string("km")
        or basicString == string("m")
        or basicString == string("cm")) {
        return 1;
    }
    if (basicString == string("kg")
        or basicString == string("g")
        or basicString == string("ton")) {
        return 2;
    }
    if (basicString == string("hour")
        or basicString == string("min")
        or basicString == string("sec")) {
        return 3;
    }
    if (basicString == string("USD")
        or basicString == string("ILS")) {
        return 4;
    }
    cout << " illegal type " << endl;
    throw std::exception();
}

ostream &operator<<(std::ostream &os, NumberWithUnits n) {
    return os;
}

istream &operator>>(std::istream &is, NumberWithUnits n) {
    return is;
}


