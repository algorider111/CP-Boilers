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

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// general macros
#define endl '\n'
#define sp ' '
#define ff first
#define ss second
#define pb push_back
#define ins insert
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define Yes cout << "Yes\n"
#define No cout << "No\n"
#define yO "YES\n"
#define nO "NO\n"
#define yo "Yes\n"
#define no "No\n"
#define MOD 1000000007
#define mkp make_pair
#define mems(a, x) memset((a), (x), sizeof(a))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a) * (b)) / gcd(a, b)
#define sq(x) ((x) * (x))
// vector and bs stuff
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define UNIQUE(x) \
  sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()
// bits
#define SET_BIT(n,k)       ((n) |  (1LL<<(k)))
#define CLEAR_BIT(n,k)     ((n) & ~(1LL<<(k)))
#define TOGGLE_BIT(n,k)    ((n) ^  (1LL<<(k)))
#define TOGGLE_ALL_BITS(n) (~(n))
#define TOGGLE_BIT_CHAR(c) ((c)=='0'?'1':'0')
#define TOGGLE_ALL_BITS_STR(s) for(char &c:s) c=(c=='0'?'1':'0')
#define CHECK_BIT(n,k)     (((n)>>(k)) & 1LL)
#define LSB(x)             ((x) & -(x))
#define MSB(x)             (63 - __builtin_clzll(x))
#define BIT_COUNT(x)       (__builtin_popcountll(x))
#define BIT_LENGTH(x)      (64 - __builtin_clzll(x))
#define IS_POWER_OF_TWO(x) ((x) && !((x)&((x)-1)))
#define ALL_BITS_SET(n)    ((1LL<<(n)) - 1)
#define IS_SUBMASK(a,b)    (((a)&(b))==(a))
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
