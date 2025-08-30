// In the Name of Allah
// Author : Algorider
// File   : bitwise_utils.cpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <climits>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

/*--------------------------------------------------------------
 | Helpful Macros
 --------------------------------------------------------------*/
#define setbit(x, i)   ((x) |  (1LL << (i)))   // set i-th bit
#define clearbit(x, i) ((x) & ~(1LL << (i)))   // clear i-th bit
#define flipbit(x, i)  ((x) ^  (1LL << (i)))   // toggle i-th bit
#define checkbit(x, i) (((x) >> (i)) & 1LL)    // check i-th bit
#define lowestbit(x)   ((x) & -(x))            // extract lowest set bit
#define allbits(x)     ((1ULL << (x)) - 1)     // mask of x bits set

/*--------------------------------------------------------------
 | Bitwise Helper Functions
 --------------------------------------------------------------*/

// Count set bits (Brian Kernighan’s Algorithm)
int countBits(ll x) {
    int cnt = 0;
    while (x) {
        x &= (x - 1);
        cnt++;
    }
    return cnt;
}

// Built-in bit count\int popcount(ll x) { return __builtin_popcountll(x); }

// Position of lowest set bit (1-indexed), 0 if none
int lowbitPos(ll x) {
    if (!x) return 0;
    return __builtin_ctzll(x) + 1;
}

// Position of highest set bit (1-indexed), 0 if none
int highbitPos(ll x) {
    if (!x) return 0;
    return 64 - __builtin_clzll(x);
}

// Check if number is power of two
bool isPowerOfTwo(ll x) {
    return x > 0 && (x & (x - 1)) == 0;
}

// Next power of two >= x
ll nextPowerOfTwo(ll x) {
    if (x <= 0) return 1;
    return 1LL << (64 - __builtin_clzll(x - 1));
}

// XOR of all numbers from 0 to n
ll xorUpto(ll n) {
    switch (n & 3) {
        case 0: return n;
        case 1: return 1;
        case 2: return n + 1;
        default: return 0;
    }
}

// Fast parity (1 if odd set bits, 0 if even)
int parity(ll x) {
    return __builtin_parityll(x);
}

// Reverse bits in 64-bit integer
ull reverseBits(ull x) {
    ull res = 0;
    for (int i = 0; i < 64; i++) {
        res = (res << 1) | (x & 1);
        x >>= 1;
    }
    return res;
}

// Rotate left
ull rotl(ull x, int k) {
    return (x << k) | (x >> (64 - k));
}

// Rotate right
ull rotr(ull x, int k) {
    return (x >> k) | (x << (64 - k));
}

// Generate all submasks of mask
vector<int> submasks(int mask) {
    vector<int> res;
    for (int sub = mask; ; sub = (sub - 1) & mask) {
        res.push_back(sub);
        if (!sub) break;
    }
    return res;
}

// Gray code conversion
int binaryToGray(int num) { return num ^ (num >> 1); }
int grayToBinary(int gray) {
    int num = gray;
    while (gray >>= 1) num ^= gray;
    return num;
}

// Compute mask with only highest set bit
ll highestOneBit(ll x) {
    if (x == 0) return 0;
    return 1LL << (63 - __builtin_clzll(x));
}

// Check if two numbers have opposite signs
bool oppositeSigns(ll a, ll b) {
    return (a ^ b) < 0;
}

// Multiply by power of two
ll mulPow2(ll x, int k) { return x << k; }

// Divide by power of two (floor for positive numbers)
ll divPow2(ll x, int k) { return x >> k; }

// Modulo by power of two
ll modPow2(ll x, int k) { return x & ((1LL << k) - 1); }

// Count leading zeros
int clz(ll x) { return __builtin_clzll(x); }

// Count trailing zeros
int ctz(ll x) { return __builtin_ctzll(x); }

// Hamming distance between two numbers
int hammingDist(ll a, ll b) { return __builtin_popcountll(a ^ b); }

// Iterate over all subsets of size k from n elements using bitmask
vector<int> kSubsets(int n, int k) {
    vector<int> res;
    int comb = (1 << k) - 1;
    while (comb < (1 << n)) {
        res.push_back(comb);
        int x = comb & -comb;
        int y = comb + x;
        comb = ((comb & ~y) / x >> 1) | y;
    }
    return res;
}

// Generate all subsets of n elements
vector<int> allSubsets(int n) {
    vector<int> res;
    for (int mask = 0; mask < (1 << n); mask++) res.push_back(mask);
    return res;
}
