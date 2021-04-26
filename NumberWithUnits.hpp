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

        friend NumberWithUnits operator*(const double &d, const NumberWithUnits &n);


        friend NumberWithUnits operator*(const NumberWithUnits &n, const double &d);

        friend std::ostream &operator<<(std::ostream &os, const NumberWithUnits &n);


        friend std::istream &operator>>(std::istream &is, NumberWithUnits &n);




    };

//    void add_types_for_demo_g(std::string s);

}
