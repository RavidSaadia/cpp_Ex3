
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
    while (true) {
        bool flag1 = true;
        bool flag2 = true;
        cout << "from this list: " << endl <<
             "km, m, cm" << endl <<
             "kg, g, ton" << endl <<
             "hour, min, sec, milly_sec" << endl <<
             "USD, ILS, AGORA, BITCOIN" << endl <<
             "tera, gb, mb, kb, byte, bit" << endl;
        while (flag1 || flag2) {

            string a_input;
            string b_input;
            cout << "enter  type" << endl;

            getline(cin, a_input);

            istringstream input_1{a_input};
            try {
                input_1 >> a;
                flag1 = false;

            }
            catch (const exception &ex) {
                cout << "something wrong with the input! (for example: 2 [kg])" << endl << endl;
            }
            if (!flag1) {
                cout << "enter  type " << endl;
                getline(cin, b_input);
//        cin >> b_input;
                istringstream input_2{b_input};

                try {

                    input_2 >> b;
                    flag2 = false;
                }
                catch (const exception &ex) {

                    cout << "something wrong with the input! (for example: 2 [kg])" << endl << endl;
                }
            }
        }


//                                      //////////////////////////////
//                                      //// ARITHMETICS OPERATOR ////
//                                      //////////////////////////////
        try {
            a+b;
            cout << "a = " << a << endl;
            cout << "b = " << b << endl;
            cout << "+a = " << +a << endl;
            cout << "-a = " << (-a) << endl;
            cout << "3*a = " << (3 * a) << endl;
            cout << "a*3 = " << (a * 3) << endl;
            NumberWithUnits c = a;
            cout << "--a = " << (--c) << endl;
            cout << "a-- = " << (c--) << endl;
            cout << "a++ = " << (c++) << endl;
            cout << "++a = " << (++c) << endl;


            cout << "a+b = " << (a + b) << endl;
            cout << "b+a = " << (b + a) << endl;
            cout << "b+4*a = " << (b + 4 * a) << endl;
            cout << "b-a = " << (b - a) << endl;
            cout << "b-=a = " << (b -= a) << endl;
            cout << "b+=a = " << (b += a) << endl;


//                                      ///////////////////////////
//                                      //// BOOL OPERATORS ///////
//                                      ///////////////////////////
            cout << boolalpha;

            cout <<"a > b = " <<(a > b) << endl;
            cout <<"a >= b = " <<(a >= b) << endl;
            cout <<"a <= b = " <<(a <= b) << endl;
            cout <<"a < b = " <<(a < b) << endl;
            cout <<"b < a = " <<(b < a) << endl;
            cout <<"b == a = " <<(b == a) << endl;
            cout <<"b != a = " <<(b != a);
        }
        catch (const std::exception &ex) {

            cout << ex.what() << endl;

        }


    }

}
