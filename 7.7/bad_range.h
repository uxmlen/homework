#include <exception>

struct bad_range : public std::exception
{
    const char *what() const noexcept override;
};
