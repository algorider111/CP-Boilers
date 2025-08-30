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


#include <algorithm>   // sort (low to high), reverse, min, max, binary_search
#include <bitset>      // bitset
#include <cassert>     // assert
#include <cctype>      // isdigit, isalpha, tolower, toupper
#include <climits>     // INT_MAX, INT_MIN
#include <cmath>       // sqrt, pow, abs, ceil, floor
#include <cstring>     // memset, memcpy
#include <deque>       // deque
#include <functional>  // std::greater(high to low)
#include <iomanip>     // setprecision, fixed
#include <iostream>    // cin, cout
#include <limits>      // numeric_limits
#include <map>         // map
#include <numeric>     // std::accumulate(v.begin(), v.end(), 0);
#include <queue>       // queue, priority_queue
#include <set>         // set, multiset
#include <stack>       // stack
#include <string>      // string, substr, getline
#include <unordered_map>  // unordered_map (hash map)
#include <unordered_set>  // unordered_set
#include <utility>        // pair, make_pair
#include <vector>         // vector

using namespace std;

// io stuff 
template <typename T> void read(T &x){cin>>x;}
template <typename T, typename... Args> void read(T &f, Args&... r){cin>>f; read(r...);}
template <typename T> void read(vector<T> &v){for(auto &x:v) cin>>x;}
template <typename T> void read(vector<vector<T>> &m){for(auto &r:m) read(r);}
template <typename T> void print(const T &x){cout<<x<<"\n";}
template <typename T, typename... Args> void print(const T &f,const Args&... r){cout<<f<<" "; print(r...);}
template <typename T> void print(const vector<T> &v,char sep=' '){for(int i=0;i<sz(v);i++) cout<<v[i]<<(i+1<sz(v)?sep:'\n');}
template <typename T1, typename T2> void print(const pair<T1,T2> &p){cout<<p.first<<" "<<p.second<<"\n";}
template <typename... T> void printTuple(const tuple<T...> &t){apply([](auto&&... args){size_t i=0;((cout<<args<<(++i<sizeof...(args)?", ":"")),...);},t); cout<<"\n";}
template <typename T> void print2D(const vector<vector<T>> &m,char sep=' '){for(auto &r:m) print(r,sep);}

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
