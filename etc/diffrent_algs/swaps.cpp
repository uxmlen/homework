#include <cassert>

// swap c++98
template <typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

void arithmetic_swap(int& a, int& b) // or in-place swapping
{
    if (a == b)
        return;
    a = a + b; // a + b
    b = a - b; // a = (a + b) - b => b = a
    a = a - b; // b = (a + b) - a => a = b
               // (a + b) - a + b - b, (a + b) - (a - b) - b
}

void xor_swap(int& a, int& b)
{
    if (a == b)
        return;

    // x ^ x = 0, a ^ 0 = a, a ^ 1 = ~a
    a ^= b; // a = a ^ b
    b ^= a; // b = b ^ (a ^ b) => b = a
    a ^= b; // a = (a ^ b) ^ b => a = b
            // a ^ b ^ b, a ^ b ^ a ^ b ^ a
    /* (a, b)
    a = a ^ b #  (a ^ b, b)
    b = a_(a ^ b) ^ b, #  (a ^ b, a)
    a = a_(a ^ b) ^ b_(a) # (a, b)
    */
}

int main()
{
    int a = 5;
    int b = 6;

    xor_swap(a, b);

    assert(a != b);
    assert(b != a);
}
