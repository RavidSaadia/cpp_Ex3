
//
// Created by ravid on 21/04/2021.
//



#include <iostream>
#include <fstream>
//#include <sstream>
#include "NumberWithUnits.hpp"

using namespace std;
using namespace ariel;

int main() {
    ifstream units_file{"for_demo.txt"};
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{0, "km"};
    NumberWithUnits b{0, "km"};

    bool flag1 = true;
    bool flag2 = true;
    while (flag1 || flag2) {

        string a_input;
        string b_input;
        cout << "enter first type " << endl;
        cin >> a_input;
        istringstream input_1{a_input};
        try {
            input_1 >> a;
            flag1 = false;

        }
        catch (const exception &ex) {
            cout  << "something wrong with the first input" << endl;
        }

        cout << "enter second type " << endl;
        cin >> b_input;
        istringstream input_2{ b_input};

        try {

            input_2 >> b;
            flag2 = false;
        }
        catch (const exception &ex) {

            cout  << "something wrong with the input" << endl;
        }
        cin>>empty();
    }


//    NumberWithUnits a{5, "km"};   // 2 kilometers
//    NumberWithUnits b{100, "m"};  // 300 meters
//                                      //////////////////////////////
//                                      //// ARITHMETICS OPERATOR ////
//                                      //////////////////////////////

    cout << a << endl;           // Prints "5[km]".
    cout << +a << endl;           // Prints "5[km]".
    cout << (-a) << endl;    // Prints "-5[km]"
    cout << (3 * a) << endl;    // Prints "15[km]"
    cout << (a * 3) << endl;    // Prints "15[km]"
    NumberWithUnits c = a;
    cout << (--c) << endl;   // Prints "4[km]"
    cout << (c--) << endl;   // Prints "4[km]"
    cout << (c++) << endl;   // Prints "3[km]"
    cout << (++c) << endl;   // Prints "5[km]"


    cout << (a + b) << endl;   // Prints "5.1[km]"
    cout << (b + a) << endl;   // Prints "5100[mm]"
    cout << (b + 4 * a) << endl;   // Prints "20100[mm]"
    cout << (b - a) << endl;   // Prints "-4900[m]"
    cout << (b -= a) << endl;   // Prints "-4900[m]"
    cout << (b += a) << endl;   // Prints "100[m]"


//                                      ///////////////////////////
//                                      //// BOOL OPERATORS ///////
//                                      ///////////////////////////
    istringstream sample_input1{"10 [ BITCOIN ]"};
    istringstream sample_input2{"1000 [ ILS ]"};
    sample_input1 >> a;
    sample_input2 >> b;
    cout << boolalpha; // print booleans as strings from now on:

    cout << (a > b) << endl;  // Prints "true"
    cout << (a >= b) << endl;  // Prints "true"
    cout << (a <= b) << endl;  // Prints "false"
    cout << (a < b) << endl;  // Prints "false"
    cout << (b < a) << endl;  // Prints "true"
    cout << (b == NumberWithUnits{3330, "USD"}) << endl;  // Prints "true"
    cout << (b != NumberWithUnits{30, "USD"}) << endl;  // Prints "true"
    cout << (b == NumberWithUnits{2000, "AGORA"}) << endl;  // Prints "false"


    try {
        cout << (a + NumberWithUnits{12, "sec"}) << endl;
    } catch (const std::exception &ex) {
        cout << ex.what() << endl; // Prints "Units do not match - [sec] cannot be converted to [BITCOIN]"
    }
    cout << "End of demo!" << endl;


    return 0;
}









///**
// * Demo file for the exercise on numbers with units
// *
// * @author Erel Segal-Halevi
// * @since 2019-02
// */
//#include <iostream>
//#include <ostream>
//#include <fstream>
//#include <sstream>
//#include "NumberWithUnits.hpp"
//#include <map>
//#include <unordered_map>
////#include "doctest.h"
//
//using namespace std;
//using namespace ariel;
//
//struct Graph {
//private:
//    unordered_map<string, unordered_map<string, double>> _graph;
//
//
//public:
//
//
//    void add_type(const string &s1, const string &s2, double d) {
//        _graph[s1][s2] = 1 / d;
//        _graph[s2][s1] = d;
//
//        auto it = _graph[s1].begin();
//        for (; it != _graph[s1].end(); ++it) {
//            _graph[s2][it->first] = d * it->second;//_graph[s1][it->first] ;
//            _graph[it->first][s2] = 1 / d * 1 / it->second;
//        }
//        it = _graph[s2].begin();
//
//        for (; it != _graph[s2].end(); ++it) {
//            _graph[s1][it->first] = 1 / d * it->second;//_graph[s1][it->first] ;
//            _graph[it->first][s1] = d * 1 / it->second;
//
//        }
//
//    };
//
//    [[nodiscard]] bool is_in_graph(const std::string &s) const {
//        return _graph.contains(s);
//    }
//
//    bool are_connected(const std::string &s1, const std::string &s2) const {
//
//        if (this->is_in_graph(s1) && this->is_in_graph(s2)) {
//            return _graph.at(s1).contains(s2);
//        }
//        std::cout << "the type " << s1 << " or " << s2 << " is unknown!" << std::endl;
//        return false;
//
//    }
//
//    double get_edge(const string &s1, const string &s2) {
//        if (_graph.contains(s1) && _graph.contains(s2)) {
//            return _graph[s1][s2];
//        }
//        return -1;
//    }
//
//
//};
//
//
//static Graph demo_g;
//static map<string, ariel::NumberWithUnits> units_map;
////static unordered_map<string, unordered_map<string ,double>> units_map;
//
//
//
//
//void add_types_for_demo_g(string s) {
//    array<string, 3> parts;
//    cout << "succses!" << endl;
//
//    for (size_t i = 0, c = 0; i < 3 && c < 5; ++c) {
//
//        string key = s.substr(0, s.find_first_of(' ', 0));
//        if (key != "=" && key != "1") {
//            parts.at(i++) = key;
//        }
//
//        if (s.length() > key.length()) {
//            s = s.substr(s.find_first_not_of(' ', key.length()));
//        }
//        if (c > 12) {
//            cout << "not a good input!" << endl;
//            break;
//        }
//    }
//    demo_g.add_type(parts[0], parts[2], (double) stod(parts[1]));// consider use stold
//    cout << "succses!" << endl;
//}
//
//void add_unit_to_client_map(string s) {
//    array<string, 3> parts;
//    for (size_t i = 0; i < 3;) {
//
//        string key = s.substr(0, s.find_first_of(' ', 0));
//        if (key != "=") {
//            parts.at(i++) = key;
//        }
//
//        if (s.length() > key.length()) {
//            s = s.substr(s.find_first_not_of(' ', key.length()));
//        }
//    }
//    NumberWithUnits n{(double) stod(parts[1]), (string) parts[2]};
////    pair p = pair(parts[0],n) ;
//
//    units_map[parts[0]] = n;
////    units_map.insert(p);//[(string) parts[0]] = ;
////units_map[parts[0]][parts[2]] = (double) stod(parts[1]);
//}
//
//NumberWithUnits calculation(NumberWithUnits &a, NumberWithUnits &b, string &s) {
//    if (s == "+") {
//        return a + b;
//    } else if (s == "-") {
//        return a - b;
//    } else if (s == "+=") {
//        return a += b;
//    } else if (s == "-=") {
//        return a -= b;
//    } else {
//        throw_with_nested("not a good input");
//    }
//
//}
//
//NumberWithUnits calculate_units(string s) {
//    array<string, 3> parts;
//    for (size_t i = 0; i < 3;) {
//
//        string key = s.substr(0, s.find_first_of(' ', 0));
//        parts.at(i++) = key;
//
//        if (s.length() > key.length()) {
//            s = s.substr(s.find_first_not_of(' ', key.length()));
//        }
//    }
//    NumberWithUnits n{units_map[parts[0]]};
//    units_map[parts[0]];
//    return calculation(n, n, parts[1]);//units_map.operator[](parts[0]), units_map.operator[](parts[2]), parts[1]);
//
//
//}
//
//int main() {
//    ifstream units_file{"for_demo.txt"};
//    NumberWithUnits::read_units(units_file);
//    cout << "this are the types:" << endl;
//    string line;
//    while (!units_file.fail() && !units_file.eof()) {
//        getline(units_file,line);
//        cout << line;
//
//    }
//    while (true) {
//        cout << "choose:" << endl
//             << "1- add types" << endl
//             << "2- create one (only after you add him)" << endl
//             << "3- calculate (only after you add him)" << endl
//             << "only for existing types!" << endl
//             << "4- Exit" << endl;
//        int choose;
//        cin >> choose;
//        switch (choose) {
//
//            case 1: {
//                cout << " choose type and value " << endl
//                     << "for example: 1 km = 1000 m" << endl;
//
//                string buffer;// = "1 km = 1000 m";
//                cin >> buffer;
//                add_types_for_demo_g(buffer);
//                cout << "added successfully" << endl;
//                break;
//            }
//            case 2: {
//                cout << "(for example: a = 10 km )";
//                string buffer;
//                cin >> buffer;
//                add_unit_to_client_map(buffer);
//                cout << "created successfully" << endl;
//                break;
//            }
//            case 3: {
//                cout << "for example: a + b, a ++, a > b, a += a..." << endl
//                     << "spaces are important! ";
//                string buffer;
//                cin >> buffer;
//                NumberWithUnits n = calculate_units(buffer);
//
//                cout << "your answer is : " << endl;
//                break;
//            }
//            case 4: {
//
//                break;
//            }
//            default: {
//
//                break;
//            }
//        }
//        if (choose == 4) {
//            cout << "good by!";
//            break;
//        }
//
//
//    }
//    return 0;
//}
//
//



