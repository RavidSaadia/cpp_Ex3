//
// Created by ravid on 07/04/2021.
//

#include <iostream>
#include "NumberWithUnits.hpp"
using namespace std;

void ariel::NumberWithUnits::read_units(std::ifstream ifstream) {

}

ariel::NumberWithUnits::NumberWithUnits(int amount, std::string subtype) {
    _amount = amount;
    _subtype = subtype;
    _type = fine_type_by_subtype(subtype);



}

int ariel::NumberWithUnits::fine_type_by_subtype(const string& basicString) {

    if(basicString == string("km")
    or basicString == string("m")
    or basicString == string("cm")){
        return 1;
    }
    if(basicString == string("kg")
       or basicString == string("g")
       or basicString == string("ton")){
        return 2;
    }
    if(basicString == string("hour")
       or basicString == string("min")
       or basicString == string("sec")){
        return 3;
    }
    if(basicString == string("USD")
       or basicString == string("ILS")){
        return 4;
    }
    cout << " illegal type " << endl;
    throw std::exception();
}
