#if !defined(BACKEND_MACRO)
#define BACKEND_MACRO

#include <vector>
#include <chrono>

using namespace std::chrono;

enum TimeUnit {u_sec, u_min, u_hr, u_day, u_week, u_mon, u_yr};

typedef struct {
    TimeUnit unit;
    std::vector<bool> data;
} pattern;

typedef struct {
    long start;
    long end;
} minute_interval;

#endif // BACKEND_MACRO
