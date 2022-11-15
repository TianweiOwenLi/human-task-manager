#include <iostream>
#include <assert.h>

#include "time_arithmetic.cpp"

int main() {
    std::tm t{ 0 };
    t.tm_year = 122;
    t.tm_mon = 10;
    t.tm_mday = 14;
    t.tm_hour = 15;
    t.tm_min = 25;
    assert(min_since_epoch(tm_to_timepoint(t)) == 27807625l);

    std::tm *t2 = timepoint_to_tm(tm_to_timepoint(t));
    assert(t2->tm_year == 122);
    assert(t2->tm_mon == 10);
    assert(t2->tm_mday == 14);
    assert(t2->tm_hour == 20); // greenwich time
    assert(t2->tm_min == 25);
    assert(t2->tm_sec == 0);

    std::cout << "[Time Arithmetic Test] All Tests Passed! \n";

    return 0;
}