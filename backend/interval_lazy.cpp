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
#include <complex>
#include <algorithm>
#include <functional>
#include <chrono>
#include <string>
#include <mutex>
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

#include "be_macro.hpp"

class LazyIntervalSeq {

    minutes from;
    minutes to;
    minutes end;
    pattern patt;

    std::mutex seq_mutex;
    

    public:
        
        LazyIntervalSeq(minutes c_from, minutes c_to, minutes c_end, pattern c_patt) {
            from = c_from;
            to = c_to;
            end = c_end;
            patt = c_patt;
        }
};