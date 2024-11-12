#include <stdio.h>
#include "Node.h"

struct Range {
    MyPair* begin;
    MyPair* end;
};

MyPair* dichotomy(Range range, MyPair value) {
    MyPair* middle = range.begin +(range.end-range.begin)/2;
    if (*middle == value) {
        return middle;
    }
    if(range.begin == range.end) {
        return nullptr;
    }

    if (*middle < value) {
        Range new_range {middle, range.end};
        return dichotomy(new_range, value);
    }
    if (*middle > value) {
        Range new_range {range.begin,middle};
        return dichotomy(new_range, value);
    }
    return nullptr;
}

