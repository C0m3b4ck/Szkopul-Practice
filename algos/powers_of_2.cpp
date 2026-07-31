// uses bit manipulation
bool isPowerOfTwo(long long n) {
    return n > 0 && (n & (n - 1)) == 0;
}

// returns 2^i as long long, or -1 on overflow
long long pow2(long long i) {
    if (i < 0 || i >= 63) return -1;   // 2^63 overflows signed long long
    return 1LL << i;
}