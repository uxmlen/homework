#include <stdbool.h>

bool is_palindrom(const char* str, int len)
{
    for (int i = 0; i < len; ++i) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }
    return true;
}
