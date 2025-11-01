/*--------------------------------------------------------------
 | In the Name of Allah, the Most Gracious, the Most Merciful  |
 | Author : Algorider                                          |
 --------------------------------------------------------------*/

#define tc_need                        // enable test case loop
#define i_want_bug_free_code           // debug :)
#define all(x) (x).begin(), (x).end()  // shorthand for containers
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()

#include <algorithm>  // sort, min, max, reverse
#include <iostream>
#include <vector>  // vectors
using namespace std;

typedef long long ll;

#ifdef i_want_bug_free_code
#include "algorider/debug.h"
#else
#define debug(...) ((void)0)
#define deb(x) ((void)0)
#endif

#define endl '\n'
#define SUM(v) accumulate(all(v), 0LL)


void Solve(void) {
  // your solution goes here
}

int main() {
cin.tie(0)->sync_with_stdio(0);
#ifdef tc_need
  int tc;
  cin >> tc;
  while (tc--) Solve();
#else
  Solve();
#endif

  return 0;
}
