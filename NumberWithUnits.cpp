//
// Created by ravid on 07/04/2021.
//
#include <string>
#include <fstream>

#include <iostream>
#include <utility>
#include "NumberWithUnits.hpp"
//#include "Types_map.hpp"
#include <unordered_map>
#include <ostream>

using namespace std;
using namespace ariel;


struct Graph {
private:
    unordered_map<std::string, unordered_map<std::string, double>> _graph;


public:


    void add_type(const string &s1, const string &s2, double d) {
        _graph[s1][s2] = 1 / d;
        _graph[s2][s1] = d;

        auto it = _graph[s1].begin();
        for (; it != _graph[s1].end(); ++it) {
            _graph[s2][it->first] = d * it->second;//_graph[s1][it->first] ;
            _graph[it->first][s2] = 1 / d * 1 / it->second;
        }
        it = _graph[s2].begin();

        for (; it != _graph[s2].end(); ++it) {
            _graph[s1][it->first] = 1 / d * it->second;//_graph[s1][it->first] ;
            _graph[it->first][s1] = d * 1 / it->second;

        }

    };

    [[nodiscard]] bool is_in_graph(const std::string &s) const {
        return _graph.contains(s);
    }

    bool are_connected(const std::string &s1, const std::string &s2) const {

        if (this->is_in_graph(s1) && this->is_in_graph(s2)) {
            return _graph.at(s1).contains(s2);
        }
        std::cout << "the type " << s1 << " or " << s2 << " is unknown!" << std::endl;
        return false;

    }

    double get_edge(const string &s1, const string &s2) {
        if (_graph.contains(s1) && _graph.contains(s2)) {
            return _graph[s1][s2];
        }
        return -1;
    }


};

static Graph g;



void check_type_exception(const string &s1, const string &s2) {
    if (!g.are_connected(s1, s2) || !g.is_in_graph(s1) || !g.is_in_graph(s2)) {
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
            if ( line.length() >= line.find_first_not_of(' ', key.length())) {
                line = line.substr(line.find_first_not_of(' ', key.length()));
            }
        }

        g.add_type(parts[0], parts[2], (double) stod(parts[1]));// consider use stold
    }
    file.close();
}

static void split_line_to_parts(string &line, string &type, double &amount) {
    line.erase(remove(line.begin(), line.end(), ' '), line.end());

    amount = stod(line.substr(0, line.find_first_of('[')));

    unsigned long type_length = line.find_first_of(']') - 1 - line.find_first_of('[');
    type = line.substr(line.find_first_of('[') + 1, type_length);
}

NumberWithUnits::NumberWithUnits(double amount, string type) : _amount(amount), _type(type) { // constructor
    if (!g.is_in_graph(type)) {
        throw invalid_argument(" Units do not match to the text file!");
        type = "";
    }
}

//                                      ///////////////////////////
//                                      //// BOOL OPERATORS ///////
//                                      ///////////////////////////

bool NumberWithUnits::operator==(const NumberWithUnits &n) const {
    string s1 = this->_type;
    string s2 = n._type;
    check_type_exception(s1, s2);

    double edge = g.get_edge(s1, s2);

    return (abs(this->_amount - (n._amount * edge)) <= EPS);
}

bool NumberWithUnits::operator!=(const NumberWithUnits &n) const {

    return !(*this == n);
}

bool NumberWithUnits::operator<(const NumberWithUnits &n) const {
    return !(*this >= n);
}

bool NumberWithUnits::operator<=(const NumberWithUnits &n) const {

    return (*this == n || !(*this >= n));
}

bool NumberWithUnits::operator>(const NumberWithUnits &n) const {
    return !(*this <= n);

}

bool NumberWithUnits::operator>=(const NumberWithUnits &n) const {
    string s1 = this->_type;
    string s2 = n._type;

    check_type_exception(s1, s2);
    double edge = g.get_edge(s1, s2);

    return (this->_amount >= n._amount * edge);


}


//                                      //////////////////////////////
//                                      //// ARITHMETICS OPERATOR ////
//                                      //////////////////////////////


NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits &n) const {
    string s1 = this->_type;
    string s2 = n._type;
    check_type_exception(s1, s2);
    double edge = g.get_edge(s1, s2);


    return NumberWithUnits(this->_amount + n._amount * edge, s1);
}

NumberWithUnits NumberWithUnits::operator+() { // unary
    return *this;
}

NumberWithUnits &NumberWithUnits::operator+=(const NumberWithUnits &n) {
    string s1 = this->_type;
    string s2 = n._type;

    check_type_exception(s1, s2);
    double edge = g.get_edge(s1, s2);
    this->_amount += n._amount * edge;

    return *this;
}

NumberWithUnits &NumberWithUnits::operator++() { // pre
    this->_amount++;
    return *this;
}

NumberWithUnits NumberWithUnits::operator++(int) { // post
    NumberWithUnits temp{this->_amount, this->_type};
    this->_amount++;
    return temp;
}


NumberWithUnits &NumberWithUnits::operator-=(const NumberWithUnits &n) {
    NumberWithUnits temp{n._amount, n._type};
    return *this += (-temp);
}

NumberWithUnits NumberWithUnits::operator-(const NumberWithUnits &n) const {
    string s1 = this->_type;
    string s2 = n._type;
    check_type_exception(s1, s2);
    double edge = g.get_edge(s1, s2);


    return NumberWithUnits(this->_amount - n._amount * edge, s1);
}

NumberWithUnits NumberWithUnits::operator-() { // unary
    return NumberWithUnits{-this->_amount, this->_type};
}

NumberWithUnits &NumberWithUnits::operator--() { // pre
    this->_amount--;

    return *this;
}

NumberWithUnits NumberWithUnits::operator--(int) { // post

    NumberWithUnits temp{this->_amount, this->_type};
    this->_amount--;
    return temp;
}

NumberWithUnits ariel::operator*(const NumberWithUnits &n, const double &d) {
    return ariel::NumberWithUnits(n._amount * d, n._type);
}

NumberWithUnits ariel::operator*(const double &d, const NumberWithUnits &n) {
    return (n * d);
}


//                                      ////////////////////////////////
//                                      //// O & I STREAM operators ////
//                                      ////////////////////////////////

std::istream &ariel::operator>>(istream &is, NumberWithUnits &n) {
    double amount = 0;
    std::string type;
    std::string line;
    getline(is, line, ']');

    split_line_to_parts(line, type, amount);

    NumberWithUnits temp = NumberWithUnits(amount, type);
    n = temp;

    return is;
}


std::ostream &ariel::operator<<(ostream &os, const NumberWithUnits &n) {
    os << n._amount << "[" << n._type << "]";
    return os;
}
