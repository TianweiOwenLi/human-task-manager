#include <chrono>
#include <ctime>

using namespace std::chrono;

long min_since_epoch(const system_clock::time_point t) {
    auto duration_since_epoch{ duration_cast<minutes>(t.time_since_epoch()) };
    return duration_since_epoch.count();
}

system_clock::time_point tm_to_timepoint(std::tm t) {
    return system_clock::from_time_t(std::mktime(&t));
}

std::tm* timepoint_to_tm(system_clock::time_point tp) {
    std::time_t tt = system_clock::to_time_t(tp);

    return std::gmtime(&tt);
}
