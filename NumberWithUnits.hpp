//
// Created by ravid on 07/04/2021.
//

#ifndef UNTITLED1_NUMBERWITHUNITS_HPP
#define UNTITLED1_NUMBERWITHUNITS_HPP
#define DIST 1
#define WEIGHT 2
#define TIME 3
#define MONEY 4

#include "map"
#include <fstream>

namespace ariel {

    class NumberWithUnits {

    private:

        int _amount;
        std::string _type;


    public:


        NumberWithUnits(int amount, std::string subtype);

        NumberWithUnits();

        static void read_units(std::ifstream &ifstream);

//        static int fine_type_by_subtype(const std::string &basicString);

        bool operator==(const NumberWithUnits &n) const;

        bool operator!=(const NumberWithUnits &n) const;

        bool operator<=(const NumberWithUnits &n) const;

        bool operator<(const NumberWithUnits &n) const;

        bool operator>=(const NumberWithUnits &n) const;

        bool operator>(const NumberWithUnits &n) const;


        NumberWithUnits operator+=(NumberWithUnits n);

        NumberWithUnits operator+(NumberWithUnits &n);

        NumberWithUnits operator+();

        NumberWithUnits operator-=(NumberWithUnits n);

        NumberWithUnits operator-(NumberWithUnits &n);

        NumberWithUnits operator-();

        NumberWithUnits operator--();

        NumberWithUnits operator--(int);

        NumberWithUnits operator++();

        NumberWithUnits operator++(int);

        friend NumberWithUnits operator*(double d, NumberWithUnits n);

        friend std::ostream &operator<<(std::ostream &os, const NumberWithUnits &n);

        friend std::istream &operator>>(std::istream &is, NumberWithUnits &n);

//        friend std::ostream &operator<<(NumberWithUnits n, std::ostream &os);


    };

}
#endif //UNTITLED1_NUMBERWITHUNITS_HPP
