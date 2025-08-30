/*--------------------------------------------------------------
 | In the Name of Allah, the Most Gracious, the Most Merciful  |
 | Author : Algorider                                          |
 --------------------------------------------------------------*/

#define tc_need                        // enable test case loop
#define all(x) (x).begin(), (x).end()  // shorthand for containers
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()

#include <iostream>
#include <vector>       // vectors
#include <algorithm>    // sort, min, max, reverse
using namespace std;

typedef long long ll;

#ifdef i_want_bug_free_code
#include "algorider/debug.h"  
#else
#define debug(...) ((void)0)
#define deb(x) ((void)0)
#endif

void Solve() {
    // your solution goes here
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

#ifdef tc_need
    int tc;
    cin >> tc;
    while (tc--) Solve();
#else
    Solve();
#endif

    return 0;
}
