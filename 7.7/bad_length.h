#include <stdexcept>

struct bad_length : public std::logic_error {
    bad_length()
        : std::logic_error("Error: wrong length of the container")
    {
    }
};
