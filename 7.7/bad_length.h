#include <exception>

struct bad_length : public std::exception
{
    const char *what() const noexcept override;
};
