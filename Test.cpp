//
// Created by ravid on 18/04/2021.
//

#include "doctest.h"
#include <string>
#include "NumberWithUnits.hpp"

using namespace ariel;
using namespace std;



TEST_CASE ("operators with known types") {

    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);

    NumberWithUnits n1{2, "km"};   // 2 kilometers
    NumberWithUnits n2{2000, "m"};
    NumberWithUnits m1{2, "hour"};
    NumberWithUnits m2{120, "min"};
    NumberWithUnits m3{180, "min"};
            CHECK((m3 > m2));
    CHECK((n1 == n2));
    CHECK((n1 == n1));
    CHECK_THROWS(bool stam = (m1 == n1));
    CHECK_THROWS(bool stam = (m2 == n1));
    CHECK((m2 == m1));
            CHECK(!(m3 < m1));
            CHECK((n2 <= n1));
            CHECK((n2 >= n1));
            CHECK((m2 == m1));
            CHECK((m2 == m2));
            CHECK((m1 + m2).getAmount() == 4);
            CHECK((m2 + m1).getAmount() == 240);
            CHECK((m2 + m2).getAmount() == 240);


            CHECK((+m2 == m2));
            CHECK_EQ((NumberWithUnits(120,"min") += m2).getAmount(), 240);
            CHECK_EQ((NumberWithUnits(400,"min") -= m1).getAmount(), 280);
            CHECK_EQ((NumberWithUnits(400,"min") -= m1).getAmount(), 280);
            CHECK_EQ((NumberWithUnits(400,"min") -= m1).getAmount(), 280);
            CHECK_EQ((NumberWithUnits(400,"min") -= m1).getAmount(), 280);
            CHECK_EQ((NumberWithUnits(400,"min") -= m1).getAmount(), 280);
            CHECK_EQ((NumberWithUnits(400,"min") -= m1).getAmount(), 280);
            CHECK_EQ((NumberWithUnits(400,"min") -= m1).getAmount(), 280);
            CHECK_EQ((NumberWithUnits(400,"min") -= m1).getAmount(), 280);
            CHECK_EQ((NumberWithUnits(400,"min")++).getAmount(), 401);
            CHECK_EQ((++NumberWithUnits(400,"min")).getAmount(), 401);
            cout<<++NumberWithUnits(400,"min");
            cout<<NumberWithUnits(400,"min")++;


}