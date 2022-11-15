#include <iostream>
#include <sstream>
#include <assert.h>
#include <stack>
#include <vector>
#include <chrono>
#include <string>
#include <shared_mutex>
using std::vector;
using std::stack;
#define dbg(x) std::cout<<#x<<" = "<<x<<'\n'
#define mp(x,y) std::make_pair(x,y)

using namespace std::chrono;

#include "interval_types.hpp"
#include "interval_eager.hpp"


void EagerIntervalSeq::extend(const minute_interval iv) {

    // cout << to_str() << " extend with " << iv.start << ", " << iv.end << endl;

    lock();

    if (data.empty() || data.back().end < iv.start) {
        data.push_back(iv);
    } else if (data.back().start <= iv.start) {
        data.back() = {data.back().start, std::max(data.back().end, iv.end)};
    } else { // O(n) expensive case, unavoidable when pt.
        std::stack<minute_interval> tail;
        while (!data.empty() && data.back().start > iv.start) {
            tail.push(data.back());
            data.pop_back();
        }

        extend(iv);

        while (!tail.empty()) {
            extend(tail.top());
            tail.pop();
        }
    }

    unlock();

    // cout << "result: " << to_str() << endl;
    return;
}

std::string EagerIntervalSeq::to_str() const {
    lock_shared();

    std::stringstream ss;

    ss << "[";
    for (int i = 0; i < data.size(); i++) {
        auto item = data[i];

        ss << "(";
        ss << item.start;
        ss << " - ";
        ss << item.end;
        ss << ")";
        if (i < data.size() - 1) {
            ss << ", ";
        }
    }
    ss << "]";

    unlock_shared();
    return ss.str();
}

EagerIntervalSeq EagerIntervalSeq::operator+(const EagerIntervalSeq s) {

    lock_shared();
    s.lock_shared();

    // intervals are added to ret with increased starting point.
    auto it1 = data.begin();
    auto it2 = s.data.begin();

    vector<minute_interval> v(0);
    EagerIntervalSeq ret(v);

    while (it1 < data.end() && it2 < s.data.end()) {
        if (it1->start <= it2->start) {
            ret.extend(*it1);
            it1++;
        } else {
            ret.extend(*it2);
            it2++;
        }
    }

    while (it1 < data.end()) {
        ret.extend(*it1);
        it1++;
    }

    while (it2 < s.data.end()) {
        ret.extend(*it2);
        it2++;
    }

    unlock_shared();
    s.unlock_shared();
    return ret;
}

std::ostream& operator<<(std::ostream& strm, const EagerIntervalSeq& obj) {
    strm << obj.to_str();
    return strm;
}
