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


struct Graph {
private:
    std::map<std::string, std::map<std::string, double>> _graph;


public:


    void add_type(const std::string &s1, const std::string &s2, double d) {
        _graph[s1][s1] = 1;
        _graph[s2][s2] = 1;
        _graph[s1][s2] = 1 / d;
        _graph[s2][s1] = d;
    };

    [[nodiscard]] bool is_in_graph(const std::string &s) const {
        return _graph.contains(s);
    }

    bool are_connected(const std::string &s1, const std::string &s2) {

        if (this->is_in_graph(s1) && this->is_in_graph(s2)) {
            return (_graph[s1]).contains(s2);
        }
        std::cout << "the type " << s1 << " is unknown!" << std::endl;
        return false;

    }

    double get_edge(const string &s1, const string &s2) {
        if (_graph.contains(s1) && _graph.contains(s2)) {
            return _graph[s1][s2];
        }
        return -1;
    }


};

static Graph t_map;


NumberWithUnits::NumberWithUnits(double amount, string type) :
        _amount(amount),
        _type(std::move(type)) {}

void throw_type_exception(const string &s1, const string &s2) {
    if (!t_map.are_connected(s1, s2) || !t_map.is_in_graph(s1) || !t_map.is_in_graph(s2)) {
        throw invalid_argument("Units do not match - [" + s2 + "] cannot be converted to [" + s1 + "]");
    }
}

void NumberWithUnits::read_units(ifstream &file) {
    string line;
    while (getline(file, line)) {

        array<string, 3> parts;
        for (size_t i = 0; i < 3;) {

            string key = line.substr(0, line.find_first_of(' ', 0));
            if (key != "=" && key != "1") {
                parts.at(i++) = key;
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
bool NumberWithUnits::operator==(const NumberWithUnits &n) const {
    string s1 = this->_type;
    string s2 = n._type;
    if (s1 == s2 && this->_amount == n._amount) { return true; }
    throw_type_exception(s1, s2);

    double edge = t_map.get_edge(s1, s2);

    return (abs(this->_amount - (n._amount * edge)) <= EPS);
}

bool NumberWithUnits::operator!=(const NumberWithUnits &n) const {

    return this != &n;
}

bool NumberWithUnits::operator<=(const NumberWithUnits &n) const {
    string s1 = this->_type;
    string s2 = n._type;
    throw_type_exception(s1, s2);
    double edge = t_map.get_edge(s1, s2);

    return (this->_amount <= n._amount * edge);
}

bool NumberWithUnits::operator>=(const NumberWithUnits &n) const {
    string s1 = this->_type;
    string s2 = n._type;

    throw_type_exception(s1, s2);
    double edge = t_map.get_edge(s1, s2);

    return (this->_amount >= n._amount * edge);


}

bool NumberWithUnits::operator<(const NumberWithUnits &n) const {
    NumberWithUnits temp{this->getAmount(), this->getType()};
    return !(temp >= n);
}

bool NumberWithUnits::operator>(const NumberWithUnits &n) const {
    NumberWithUnits temp{this->getAmount(), this->getType()};
    return !(temp <= n);

}

// PLUS OPERATORS //

NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits &n) const {
    string s1 = this->_type;
    string s2 = n._type;
    throw_type_exception(s1, s2);
    double edge = t_map.get_edge(s1, s2);


    return NumberWithUnits(this->_amount + n._amount * edge, s1);
}

NumberWithUnits NumberWithUnits::operator+() {
    return *this;
}

NumberWithUnits &NumberWithUnits::operator+=(const NumberWithUnits &n) {
    string s1 = this->_type;
    string s2 = n._type;

    throw_type_exception(s1, s2);
    double edge = t_map.get_edge(s1, s2);
    this->_amount += n._amount * edge;

    return *this;
}

NumberWithUnits &NumberWithUnits::operator++() {// pre
    this->_amount++;
    return *this;
}

NumberWithUnits NumberWithUnits::operator++(int) {// post
    NumberWithUnits temp{this->_amount, this->_type};
    this->_amount++;
    return temp;
}

// MINUS OPERATORS //

NumberWithUnits &NumberWithUnits::operator-=(const NumberWithUnits &n) {
    NumberWithUnits temp{n._amount, n._type};
    return *this += (-temp);
}

NumberWithUnits NumberWithUnits::operator-(const NumberWithUnits &n) const {
    string s1 = this->_type;
    string s2 = n._type;
    throw_type_exception(s1, s2);
    double edge = t_map.get_edge(s1, s2);


    return NumberWithUnits(this->_amount - n._amount * edge, s1);
}

NumberWithUnits NumberWithUnits::operator-() {

    return NumberWithUnits(-this->_amount, this->_type);
}

NumberWithUnits &NumberWithUnits::operator--() {// pre
    this->_amount--;

    return *this;
}

NumberWithUnits NumberWithUnits::operator--(int) { // post

    NumberWithUnits temp{this->_amount, this->_type};
    this->_amount--;
    return temp;
}

//double NumberWithUnits::getAmount() const {
//    return _amount;
//}
//
//const string &NumberWithUnits::getType() const {
//    return _type;
//}
