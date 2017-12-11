#include "Catch.hpp"
#include "../code/PhoneNumber.h"

#include <string>

void require(bool b) {
    REQUIRE(b);
}

TEST_CASE("1st Test") {
    PhoneNumber ph("+1 858 775 2869");
    REQUIRE(ph.getStrippedNumber() == "+18587752869");
    require(ph.getValueAsNorthAmerican() == "(858)775-2869");
    require(ph.isNorthAmericanNumber() == true);
    require(ph.getValueAsInternational() == "+1.858.775.2869");
}

TEST_CASE("2st Test") {
    PhoneNumber ph("1 858 775 3456");
    REQUIRE(ph.getStrippedNumber() == "+18587753456");
    require(ph.getValueAsNorthAmerican() == "(858)775-3456");
    require(ph.isNorthAmericanNumber() == true);
    require(ph.getValueAsInternational() == "+1.858.775.3456");
}

TEST_CASE("3st Test") {
    PhoneNumber ph("+1(858)775-2868");
    REQUIRE(ph.getStrippedNumber() == "+18587752868");
    require(ph.getValueAsNorthAmerican() == "(858)775-2868");
    require(ph.isNorthAmericanNumber() == true);
    require(ph.getValueAsInternational() == "+1.858.775.2868");
}

TEST_CASE("4st Test") {
    PhoneNumber ph("+1(858)775-2868x123");
    require(ph.getStrippedNumber() == "+18587752868x123");
    require(ph.getValueAsNorthAmerican() == "(858)775-2868x123");
    require(ph.isNorthAmericanNumber() == true);
    require(ph.getValueAsInternational() == "+1.858.775.2868x123");
}

TEST_CASE("5st Test") {
    PhoneNumber ph("+598.123.4567x858\"");
    require(ph.getStrippedNumber() == "+18587752868");
    require(ph.getValueAsNorthAmerican() == "+5981234567x858");
    require(ph.isNorthAmericanNumber() == false);
    require(ph.getValueAsInternational() == "+598.123.456.7x858");
}

