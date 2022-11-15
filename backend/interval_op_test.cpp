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
#include <cmath>
#include <string>
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

#include "be_macro.hpp"
#include "interval_eager.hpp"

int main() {
    auto seq1 = EagerIntervalSeq();
    seq1.extend({20, 30});
    cout << seq1 << endl;
    seq1.extend({25, 40});
    cout << seq1 << endl;
    seq1.extend({50, 60});
    cout << seq1 << endl;
    seq1.extend({35, 44});
    cout << seq1 << endl;

    vector<minute_interval> v = {{15, 21}, {25, 35}};
    auto seq2 = EagerIntervalSeq(v);
    seq2.extend({2,4});
    seq2.extend({49,51});
    seq2.extend({65,70});
    cout << seq2 << endl;

    auto seq3 = seq1 + seq2;
    cout << seq3 << endl;
    auto seq4 = seq2 + seq1;
    cout << seq4 << endl;
    cout << seq3 + seq4 << endl;

    return 0;
}