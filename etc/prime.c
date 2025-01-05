int is_prime(unsigned n)
{
    if (n < 2)
        return 0;
    for (int j = 2; j * j <= n; ++j)
        if ((n % j) == 0)
            return 0;
    return 1;
}
