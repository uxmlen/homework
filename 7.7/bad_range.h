#include <stdexcept>

struct bad_range : public std::logic_error {
    bad_range()
        : std::logic_error("error: out of range")
    {
    }
};
