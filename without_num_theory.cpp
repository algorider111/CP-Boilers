/*--------------------------------------------------------------
 | In the Name of Allah, the Most Gracious, the Most Merciful  |
 | Author : Algorider                                          |
 --------------------------------------------------------------*/

#define tc_need
// #define i_want_bug_free_code

#ifdef i_want_bug_free_code
#include "algorider/debug.h"  // real debug
#else
#define debug(...) ((void)0)   // safe dummy
#define deb(x) ((void)0)       // safe dummy
#endif

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


// my solution
void solver() { 
   
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
#ifdef tc_need
  int t;
  read(t);
  while (t--) solver();
#else
  solver();
#endif
  return 0;
}
