#if !defined(EAGER)
#define EAGER

#include <vector>
#include <string>
#include <ostream>
#include <shared_mutex>
#include "be_macro.hpp"

class EagerIntervalSeq {
    std::vector<minute_interval> data;
    mutable std::__shared_mutex_pthread data_mutex;

    private:

        inline void lock() { data_mutex.lock(); }

        inline void unlock() { data_mutex.unlock(); }

        inline void lock_shared() const { data_mutex.lock_shared(); }

        inline void unlock_shared() const { data_mutex.unlock_shared(); }

    public:

        EagerIntervalSeq(std::vector<minute_interval> input_data) {
            data = input_data;
        }

        EagerIntervalSeq(const EagerIntervalSeq& obj) {
            data = obj.data;
        }

        EagerIntervalSeq() = default;

        std::string to_str() const;

        void extend(const minute_interval);

        EagerIntervalSeq operator+(const EagerIntervalSeq);

        
};

std::ostream& operator<<(std::ostream&, const EagerIntervalSeq&);

#endif // EAGER
