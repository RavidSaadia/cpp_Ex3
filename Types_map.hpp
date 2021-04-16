////
//// Created by ravid on 12/04/2021.
////
//#pragma once
//#ifndef UNTITLED1_TYPES_MAP_H
//#define UNTITLED1_TYPES_MAP_H
//
//#endif //UNTITLED1_TYPES_MAP_H
//
//#include "map"
//
//class Types_map{
//
//    std::map <std::string, std::map<std::string, double>> _type_map;
//
//
//public:
//
//    Types_map();
//
//    void add_type(std::string s1, std::string s2, double d){
//        _type_map[s1][s2] = d;
//
//    };
//    bool is_in_map(std::string s){
//        return _type_map.contains(s);
//            }
//
//    bool are_same_dim(std::string s1, std::string s2 ){
//
//        if(is_in_map(s1)){
//            return _type_map[s1].contains(s2);
//        }
//        std::cout << "the type is unknown!"<<std::endl;
//        return false;
//
//    }
//
//};
//
//Types_map::Types_map() = default;
