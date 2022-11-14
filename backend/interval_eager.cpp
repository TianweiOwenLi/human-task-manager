#include <iostream>
#include <fstream>
#include <assert.h>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <bitset>
#include <random>
#include <algorithm>
#include <functional>
#include <chrono>
#include <string>
#include <shared_mutex>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::stack;
using std::queue;
using std::pair;
using std::unordered_set;
using std::unordered_map;
using std::multimap;
using std::function;
using std::min;
using std::max;
#define dbg(x) std::cout<<#x<<" = "<<x<<'\n'
#define mp(x,y) std::make_pair(x,y)

using namespace std::chrono;

#include "be_macro.hpp";


class EagerIntervalSeq {

    vector<minute_interval> data;
    mutable std::__shared_mutex_pthread data_mutex;

    private:

        inline void lock() {
            data_mutex.lock();
        }

        inline void unlock() {
            data_mutex.unlock();
        }

        inline void lock_shared() const {
            data_mutex.lock_shared();
        }

        inline void unlock_shared() const {
            data_mutex.unlock_shared();
        }

        void extend(const minute_interval iv) {

            lock();

            if (data.empty() || data.back().end < iv.start) {
                data.push_back(iv);
            } else if (data.back().start <= iv.start) {
                data.back() = {data.back().start, max(data.back().end, iv.end)};
            } else { // O(n) expensive case, unavoidable when pt.
                stack<minute_interval> tail;
                while (data.back().start > iv.start) {
                    tail.push(data.back());
                    data.pop_back();
                }

                data.push_back(iv);

                while (!tail.empty()) {
                    extend(tail.top());
                    tail.pop();
                }
            }

            unlock();

            return;
        }

    public:
        EagerIntervalSeq(vector<minute_interval> input_data) {
            data = input_data;
        }

        EagerIntervalSeq(const EagerIntervalSeq& obj) {
            data = obj.data;
        }

        EagerIntervalSeq operator+(const EagerIntervalSeq s) {

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

        
};