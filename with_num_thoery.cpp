/*--------------------------------------------------------------
 | In the Name of Allah, the Most Gracious, the Most Merciful  |
 | Author : Algorider                                          |
 --------------------------------------------------------------*/

#define tc_need
// #define i_want_bug_free_code

#ifdef i_want_bug_free_code
#include "algorider/debug.h"  // real debug
#else
#define debug(...) ((void)0) 
#define deb(x) ((void)0
#endif


#include <algorithm>   // sort (low to high), reverse, min, max, binary_search
#include <bitset>      // bitset
#include <cassert>     // assert
#include <cctype>      // isdigit, isalpha, tolower, toupper
#include <climits>     // INT_MAX, INT_MIN
#include <cmath>       // sqrt, pow, abs, ceil, floor
#include <cstring>     // memset, memcpy
#include <chrono>
#include <random>
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

// Useful Constants

const int MOD  = 1e9+7;
const int MOD2 = 998244353;
const int INF32 = 1e9;
const ll INF64 = 4e18;
const int MAXN = 1e6+5; // adjust as needed

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

// number theory and combinatorics stuff inspired from @colin_galen
namespace nt{
  // check working here ..
  using ll=long long; using vi=vector<int>; using vll=vector<ll>; using Mat=vll;
  // ---- gcd, lcm ----
  ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
  ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

  // ---- binpow, modpow ----
  ll binpow(ll a,ll e){ll r=1;while(e){if(e&1)r*=a;a*=a;e>>=1;}return r;}
  ll modpow(ll a,ll e,ll m=MOD){ll r=1;while(e){if(e&1)r=(__int128)r*a%m;a=(__int128)a*a%m;e>>=1;}return r;}

  // ---- extgcd + modinv ----
  ll extgcd(ll a,ll b,ll &x,ll &y){if(!b){x=1;y=0;return a;}ll x1,y1,g=extgcd(b,a%b,x1,y1);x=y1;y=x1-y1*(a/b);return g;}
  ll modinv(ll a,ll m=MOD){return modpow(a,m-2,m);}
  ll modinv_euclid(ll a,ll m){ll x,y,g=extgcd(a,m,x,y);return g!=1?-1:(x%m+m)%m;}

  // ---- modular ops ----
  inline ll add(ll a,ll b,ll m=MOD){return (a+b)%m;}
  inline ll sub(ll a,ll b,ll m=MOD){return (a-b+m)%m;}
  inline ll mul(ll a,ll b,ll m=MOD){return (__int128)a*b%m;}
  inline ll divm(ll a,ll b,ll m=MOD){return mul(a,modinv(b,m),m);}

  // ---- factorials & combinatorics ----
  vll fact,invfact;
  void init_fact(int n,ll m=MOD){fact.assign(n+1,1);invfact.assign(n+1,1);for(int i=1;i<=n;i++)fact[i]=fact[i-1]*i%m;invfact[n]=modpow(fact[n],m-2,m);for(int i=n;i;i--)invfact[i-1]=invfact[i]*i%m;}
  ll nCr(int n,int r,ll m=MOD){if(r<0||r>n)return 0;return fact[n]*invfact[r]%m*invfact[n-r]%m;}
  ll nPr(int n,int r,ll m=MOD){if(r<0||r>n)return 0;return fact[n]*invfact[n-r]%m;}
  ll nHr(int n,int r,ll m=MOD){if(n==0&&r>0)return 0;return nCr(n+r-1,r,m);}
  ll nCr_lucas(ll n,ll r,ll p=MOD){if(r==0)return 1;return nCr_lucas(n/p,r/p,p)*nCr(n%p,r%p,p)%p;}
  ll multinomial(vll ks,ll m=MOD){int n=0;for(ll x:ks)n+=x;ll r=fact[n];for(ll x:ks)r=r*invfact[x]%m;return r;}

  // ---- sieve & factorization ----
  vi spf; vll primes;
  void sieve(int n){spf.assign(n+1,0);primes.clear();for(int i=2;i<=n;i++){if(!spf[i])spf[i]=i,primes.pb(i);for(ll p:primes){if(p>spf[i]||1LL*i*p>n)break;spf[i*p]=p;}}}
  vi factorize(int x){vi f;while(x>1){f.pb(spf[x]);x/=spf[x];}return f;}

  // ---- Euler phi, divisor count/sum ----
  ll phi(ll n){ll r=n;for(ll p=2;p*p<=n;p++){if(n%p==0){while(n%p==0)n/=p;r-=r/p;}}if(n>1)r-=r/n;return r;}
  ll dcount(ll n){ll r=1;for(ll p=2;p*p<=n;p++){int c=0;while(n%p==0)c++,n/=p;r*=(c+1);}if(n>1)r*=2;return r;}
  ll dsum(ll n){ll s=1;for(ll p=2;p*p<=n;p++){ll c=1,m=1;while(n%p==0){n/=p;m*=p;c++;}s*= (m*p-1)/(p-1);}if(n>1)s*=n+1;return s;}

  // ---- CRT (coprime) ----
  ll crt(vll a,vll m){ll M=1,res=0;n=a.size();for(ll x:m)M*=x;for(int i=0;i<sz(a);i++){ll Mi=M/m[i],inv=modinv_euclid(Mi,m[i]);res=(res+(__int128)a[i]*Mi%M*inv)%M;}return (res%M+M)%M;}
  // ---- Miller-Rabin primality ----
  bool isPrime(ll n){if(n<2)return 0;for(ll p:{2,3,5,7,11,13,17,19,23,29,31,37})if(n%p==0)return n==p;ll d=n-1,s=0;while((d&1)==0)d>>=1,++s;auto chk=[&](ll a){if(a%n==0)return 1;ll x=modpow(a,d,n);if(x==1||x==n-1)return 1;for(int i=1;i<s;i++){x=(__int128)x*x%n;if(x==n-1)return 1;}return 0;};for(ll a:{2,325,9375,28178,450775,9780504,1795265022})if(a%n && !chk(a))return 0;return 1;}

  // ---- Pollard's Rho factorization ----
  ll f_rho(ll x,ll c,ll m){return (mul(x,x,m)+c)%m;}
  ll rho(ll n){if(n%2==0)return 2;mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());while(1){ll x=uniform_int_distribution<ll>(2,n-2)(rng);ll y=x,c=uniform_int_distribution<ll>(1,n-1)(rng),d=1;while(d==1){x=f_rho(x,c,n);y=f_rho(f_rho(y,c,n),c,n);d=gcd(abs(x-y),n);}if(d!=n)return d;}}

  // ---- Discrete log (BSGS) ----
  ll dlog(ll a,ll b,ll m){a%=m;b%=m;ll n=sqrt(m)+1;unordered_map<ll,ll> vals;ll an=1;for(int i=0;i<n;i++)an=an*a%m;ll cur=b;for(int q=0;q<n;q++){vals[cur]=q;cur=cur*a%m;}cur=1;for(int p=1;p<=n+1;p++){cur=cur*an%m;if(vals.count(cur))return n*p-vals[cur];}return -1;}
  
  // ---- Matrix exponentiation & Fibonacci ----
  using Mat=vector<vector<ll>>;
  Mat mulMat(const Mat&A,const Mat&B,ll m=MOD){int n=sz(A);Mat C(n,vector<ll>(n));for(int i=0;i<n;i++)for(int k=0;k<n;k++)if(A[i][k])for(int j=0;j<n;j++)C[i][j]=(C[i][j]+A[i][k]*B[k][j])%m;return C;}
  Mat matpow(Mat A,ll e,ll m=MOD){int n=sz(A);Mat R(n,vector<ll>(n));for(int i=0;i<n;i++)R[i][i]=1;while(e){if(e&1)R=mulMat(R,A,m);A=mulMat(A,A,m);e>>=1;}return R;}
  ll fib(ll n,ll m=MOD){if(n==0)return 0;Mat F={{1,1},{1,0}};Mat R=matpow(F,n-1,m);return R[0][0];}
}


// my solution
void Solve() { 
   
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef tc_need
  int t;
  read(t);
  while (t--) Solve();
#else
  Solve();
#endif
  return 0;
}
