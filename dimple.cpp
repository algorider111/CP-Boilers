//---------------------------------------------
// In the Name of Allah, the Most Gracious, the Most Merciful
// Author : Algorider
//---------------------------------------------

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef ONLINE_JUDGE
#include "algorider/debug2.h" // full debug 
#else
#define DEBUG(...) (void)0
#define DUMP_CONTAINER(x, ...) (void)0
#define START_TIMER() (void)0
#define STOP_TIMER() (void)0
#define dassert(cond) (void)0
struct ScopedTimer { ScopedTimer(const std::string&){} ~ScopedTimer(){} };
struct _NullDebugStream {
    template<typename T> _NullDebugStream& operator<<(const T&) { return *this; }
    _NullDebugStream& operator<<(ostream& (*)(ostream&)) { return *this; }
};
static _NullDebugStream _debug;
inline long get_memory_kb() { return -1; }
inline void print_backtrace() {}
template<typename Gen, typename Brute, typename Fast> void stress(Gen, Brute, Fast, int=0) {}
struct _NullRNG {
    template<typename T> T operator()(T a, T b) { return a; }
};
static _NullRNG rnd_int, rnd_ll, rnd_vec;
#endif

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define SUM(v) accumulate(all(v), 0LL)
#define endl '\n'

constexpr bool ENABLE_TESTCASES = true;
constexpr bool ENABLE_CASE_LABEL = false;

void Solve([[maybe_unused]] int cs = 0) {
  // Write your Solution here
}

int main(){
  cin.tie(0)->sync_with_stdio(0);
  int tc=1; if constexpr(ENABLE_TESTCASES) cin>>tc;
    for(int t=1;t<=tc;++t)
        Solve((ENABLE_CASE_LABEL && ENABLE_TESTCASES)?t:0);
  return 0;
}
