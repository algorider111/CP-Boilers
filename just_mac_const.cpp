// In the Name of Allah
// Author : Algorider
// File   : competitive_macros.cpp

#include <bits/stdc++.h>
using namespace std;

/*--------------------------------------------------------------
 | Typedefs
 --------------------------------------------------------------*/
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;

typedef priority_queue<int> pqmax;
typedef priority_queue<int, vector<int>, greater<int>> pqmin;

typedef tuple<int,int,int> t3i;
typedef tuple<ll,ll,ll> t3l;

/*--------------------------------------------------------------
 | Useful Constants
 --------------------------------------------------------------*/
const int INF = 1e9+7;
const ll LINF = 1e18;
const ld PI = 3.14159265358979323846;
const ld EPS = 1e-9;
const ll MOD = 1000000007;
const ll MOD1 = 998244353;
const ll MOD2 = 1000000009;
const ll MOD3 = 1e9+21;
const int dx[8] = {-1,0,1,0,-1,-1,1,1};
const int dy[8] = {0,1,0,-1,-1,1,-1,1};

/*--------------------------------------------------------------
 | General Macros
 --------------------------------------------------------------*/
#define endl '\n'
#define sp ' '
#define ff first
#define ss second
#define pb push_back
#define ins insert
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define yO "YES\n"
#define nO "NO\n"
#define yo "Yes\n"
#define no "No\n"
#define mkp make_pair
#define mems(a, x) memset((a), (x), sizeof(a))
#define sq(x) ((x) * (x))

// Vector and BS stuff
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define SUM(v) accumulate(all(v), 0LL)
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()

// Loops
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define RREP(i, a, b) for(int i = (a); i >= (b); --i)
#define FOREACH(it, x) for(auto it = (x).begin(); it != (x).end(); ++it)
#define FORE(a, v) for(auto &a : v)

// Bitwise Macros
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define SETBIT(x, i) ((x) |  (1LL << (i)))
#define CLEARBIT(x, i) ((x) & ~(1LL << (i)))
#define FLIPBIT(x, i) ((x) ^  (1LL << (i)))
#define LOWBIT(x) ((x) & -(x))

// Math Helpers
#define CHKMIN(a, b) if(a > b) a = b
#define CHKMAX(a, b) if(a < b) a = b
#define POW2(x) (1LL<<(x))
#define MODADD(a, b, m) (((a) + (b)) % (m))
#define MODSUB(a, b, m) (((a) - (b) + (m)) % (m))
#define MODMUL(a, b, m) (((a) * (b)) % (m))
#define MODINV(a, m) binpow(a, m-2, m) // a^(m-2) mod m assuming m is prime

// Fast IO
#define FASTIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

/*--------------------------------------------------------------
 | Implementation Helpers
 --------------------------------------------------------------*/
inline ll binpow(ll a, ll b, ll m){
    a %= m;
    ll res = 1;
    while(b > 0){
        if(b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
