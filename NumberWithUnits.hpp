//
// Created by ravid on 07/04/2021.
//

#ifndef UNTITLED1_NUMBERWITHUNITS_HPP
#define UNTITLED1_NUMBERWITHUNITS_HPP

#include <fstream>

namespace ariel {

    class NumberWithUnits {

    private:
        ///////-type-/////////
        //// 1 = distance ////
        //// 2 = weight   ////
        //// 3 = time     ////
        //// 4 = money    ////
        //////////////////////
        int _type;
        int _amount;
        std::string _subtype;


    public:


        NumberWithUnits(int amount, const std::string &subtype);
        NumberWithUnits();

        static void read_units(std::ifstream& ifstream);

        static int fine_type_by_subtype(const std::string &basicString);

        bool  operator== (const NumberWithUnits &n) const;
        bool  operator!= (const NumberWithUnits &n) const;
        bool  operator<= (const NumberWithUnits &n) const;
        bool  operator< (const NumberWithUnits &n) const;
        bool  operator>= (const NumberWithUnits &n) const;
        bool  operator> (const NumberWithUnits &n) const;


        NumberWithUnits  operator+= ( NumberWithUnits n) ;
        NumberWithUnits  operator+ ( NumberWithUnits &n) ;
        NumberWithUnits  operator+ () ;
        NumberWithUnits  operator-= ( NumberWithUnits n) ;
        NumberWithUnits  operator- ( NumberWithUnits &n) ;
        NumberWithUnits  operator- () ;

        NumberWithUnits  operator-- ();
        NumberWithUnits  operator-- (int);
        NumberWithUnits  operator++ ();
        NumberWithUnits  operator++ (int);
        friend NumberWithUnits  operator* ( double d, NumberWithUnits n);

        friend std::ostream& operator<<(std::ostream &os, NumberWithUnits n);
        friend std::istream& operator>>( std::istream &is, NumberWithUnits n );

    };

}
#endif //UNTITLED1_NUMBERWITHUNITS_HPP
