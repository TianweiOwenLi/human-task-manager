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
using namespace std::chrono;
using std::string;

#include "be_macro.hpp"

class Task {

    std::string name;
    minutes from;
    minutes to;
    pattern patt;
    minutes end_date;

    public: 
        
        Task(string c_name, minutes c_from, minutes c_to, pattern c_patt, 
                minutes c_end_date) {
            name = c_name;
            from = c_from;
            to = c_to;
            patt = c_patt;
            end_date = c_end_date;
        }

        string getName(){ return name; }

        minutes getDuration(){
            int occur_per_patt = std::count(patt.data.begin(), patt.data.end(), true);
            int patt_len = patt.data.size();


        }

};