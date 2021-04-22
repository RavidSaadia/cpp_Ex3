//
// Created by ravid on 07/04/2021.
//
#pragma once

#include <sstream>
#include <ostream>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#define EPS 0.001

namespace ariel {
    class NumberWithUnits {

    private:
        double _amount;

        std::string _type;
    public:
        [[nodiscard]] double getAmount() const {
            return _amount;
        }

        [[nodiscard]] const std::string &getType() const {
            return _type;
        }


        NumberWithUnits(double amount, std::string subtype);


        static void read_units(std::ifstream &file);


        bool operator==(const NumberWithUnits &n) const;

        bool operator!=(const NumberWithUnits &n) const;

        bool operator<=(const NumberWithUnits &n) const;

        bool operator<(const NumberWithUnits &n) const;

        bool operator>=(const NumberWithUnits &n) const;

        bool operator>(const NumberWithUnits &n) const;


        NumberWithUnits &operator+=(const NumberWithUnits &n);

        NumberWithUnits operator+(const NumberWithUnits &n) const;

        NumberWithUnits operator+();

        NumberWithUnits &operator-=(const NumberWithUnits &n);

        NumberWithUnits operator-(const NumberWithUnits &n) const;

        NumberWithUnits operator-();


        NumberWithUnits &operator--();//pre

        NumberWithUnits operator--(int);//post

        NumberWithUnits &operator++();//pre

        NumberWithUnits operator++(int);//post

        friend NumberWithUnits operator*(const double &d, const NumberWithUnits &n) {
            return (n * d);
        }

        friend NumberWithUnits operator*(const NumberWithUnits &n, const double &d) {
            return ariel::NumberWithUnits(n._amount * d, n._type);
        }

        friend std::ostream &operator<<(std::ostream &os, const NumberWithUnits &n) {
            os << n._amount << "[" << n._type << "]";
            return os;
        }

        friend std::istream &operator>>(std::istream &is, NumberWithUnits &n) {
//            char c = 0;
            std::string s;
            getline(is, s);
            s.erase(remove(s.begin(), s.end(), ' '), s.end());

            double amount = std::stod(s.substr(0, s.find_first_of('[')));
            unsigned long type_length = s.find_first_of(']')-1 - s.find_first_of('[');
            std::string type = s.substr(s.find_first_of('[') + 1, type_length);

            NumberWithUnits temp = NumberWithUnits(amount, type);
            n = temp;
            unsigned long s_left_length = s.length()-s.find_first_of(']')+1;
            s = s.substr(s.find_first_of(']')+1,s_left_length);
            for (char i : s) {
                is.fill((char)i);
            }
            return is;
        }

//        static void throw_type_exception(const std::string &s1, const std::string &s2);

    };

    void add_types_for_demo(std::string s);

}
