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

        explicit NumberWithUnits(int = 0, std::string = "km");

        static void read_units(std::ifstream ifstream);

         static int fine_type_by_subtype(const std::string& basicString);
    };

}
#endif //UNTITLED1_NUMBERWITHUNITS_HPP
