unsigned long long fact_rec(int n) // n! = n * (n - 1)!; 0! = 1
{
    // (n > 2) ? n * fact_rec(n - 1) : 1;
    return (n < 2) ? 1 : n * fact_rec(n - 1);
}

int fact_iter(int n)
{
    int res = 1;
    for (int i = 1; i < n; i++) {
        res *= i;
    }
    return res;
}
