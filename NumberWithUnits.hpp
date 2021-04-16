//
// Created by ravid on 07/04/2021.
//
//#ifndef UNTITLED1_NUMBERWITHUNITS_HPP
//#define UNTITLED1_NUMBERWITHUNITS_HPP
#pragma once

#include <sstream>
#include <ostream>
#include <iostream>

#include <map>
#include <fstream>
//#include "Types_map.hpp"

namespace ariel{
    class NumberWithUnits {

    private:
        double _amount;

        std::string _type;
//        static  Types_map _typesMap;


    public:


        NumberWithUnits(double amount, std::string subtype);

//        NumberWithUnits();

        static void read_units(std::ifstream &ifstream);


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


        NumberWithUnits &operator--();

        NumberWithUnits operator--(int);//post

        NumberWithUnits &operator++();

        NumberWithUnits operator++(int);//post

        friend const  NumberWithUnits operator*(const double &d, const NumberWithUnits &n){
            return n;
        }

        friend const  NumberWithUnits operator*(const NumberWithUnits &n, const double &d){
            return n;
        }
//        friend const NumberWithUnits operator*( const ariel::NumberWithUnits &n,int d);
//        friend const NumberWithUnits operator*(int d,const NumberWithUnits &n);

        friend std::ostream& operator<<(std::ostream& os, const NumberWithUnits &n){
            return os;
        }
//            friend std::ostream& operator<<(  NumberWithUnits &n, std::ostream &os);

        friend std::istream& operator>>(std::istream &is, NumberWithUnits &n){
            return is;
        }
//        friend std::istream& operator>>( NumberWithUnits &n, std::istream &is);

//        friend std::ostream &operator<<(NumberWithUnits n, std::ostream &os);


    };

}
//#endif //UNTITLED1_NUMBERWITHUNITS_HPP
