/*--------------------------------------------------------------
 | In the Name of Allah, the Most Gracious, the Most Merciful  |
 | Author : Algorider                                          |
 | Ultimate Number Theory & Matrix Library                     |
 --------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> Mat;

const ll MOD=1000000007;

template<typename T>
T gcd_array(const vector<T>& arr) {
    if (arr.empty()) return 0;
    T g = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        g = gcd(g, arr[i]);
        if (g == 1) break; // early stop
    }
    return g;
}

// GCD of array difference a[0] - a[i]

template<typename T>
inline T fast_gcd(T a,T b){while(b){a%=b;swap(a,b);}return a;}

template<typename T>
T gcd_of_differences(const vector<T>& a){
    int n=a.size();
    if(n<=1) return 0;  // no difference
    T g=0;
    for(int i=1;i<n;++i){
        g=fast_gcd(g, abs(a[i]-a[0]));
        if(g==1) return 1; // early stop
    }
    return g;
}
// Example
// int main(){
//     vector<long long> a={10,14,22,34};
//     cout<<gcd_of_differences(a)<<"\n"; // Output: 2
// }



// ---------------- GCD / LCM ----------------
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : abs(a); }
ll lcm(ll a,ll b){return abs(a/gcd(a,b)*b);}
bool coprime(ll a,ll b){return gcd(a,b)==1;}

// ---------------- Binary Exponentiation ----------------
ll binpow(ll a,ll e){ll r=1; while(e){if(e&1) r*=a; a*=a; e>>=1;} return r;}
ll modpow(ll a,ll e,ll m=MOD){ll r=1; while(e){if(e&1) r=(__int128)r*a%m; a=(__int128)a*a%m; e>>=1;} return r;}

// ---------------- Extended GCD / Modular Inverse ----------------
ll extgcd(ll a,ll b,ll &x,ll &y){if(!b){x=1;y=0;return a;} ll x1,y1,g=extgcd(b,a%b,x1,y1); x=y1; y=x1-(a/b)*y1; return g;}
ll modinv(ll a,ll m=MOD){return modpow(a,m-2,m);}
ll modinv_euclid(ll a,ll m){ll x,y,g=extgcd(a,m,x,y); return g!=1?-1:(x%m+m)%m;}

// ---------------- Modular Operations ----------------
inline ll add(ll a,ll b,ll m=MOD){return (a+b)%m;}
inline ll sub(ll a,ll b,ll m=MOD){return (a-b+m)%m;}
inline ll mul(ll a,ll b,ll m=MOD){return (__int128)a*b%m;}
inline ll divm(ll a,ll b,ll m=MOD){return mul(a,modinv(b,m),m);}

// ---------------- Factorials / Combinatorics ----------------
vll fact,invfact;
void init_fact(int n,ll m=MOD){
    fact.assign(n+1,1); invfact.assign(n+1,1);
    for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i%m;
    invfact[n]=modpow(fact[n],m-2,m);
    for(int i=n;i;i--) invfact[i-1]=invfact[i]*i%m;
}
ll nCr(int n,int r,ll m=MOD){if(r<0||r>n) return 0; return fact[n]*invfact[r]%m*invfact[n-r]%m;}
ll nPr(int n,int r,ll m=MOD){if(r<0||r>n) return 0; return fact[n]*invfact[n-r]%m;}
ll nHr(int n,int r,ll m=MOD){if(n==0&&r>0) return 0; return nCr(n+r-1,r,m);}
ll multinomial(vll ks,ll m=MOD){int n=0; for(ll x:ks) n+=x; ll r=fact[n]; for(ll x:ks) r=r*invfact[x]%m; return r;}

// ---------------- Sieve / SPF / Prime Factors ----------------
vi spf; vll primes;
void sieve(int n){
    spf.assign(n+1,0); primes.clear();
    for(int i=2;i<=n;i++){
        if(!spf[i]) spf[i]=i, primes.push_back(i);
        for(ll p:primes){
            if(p>spf[i]||1LL*i*p>n) break;
            spf[i*p]=p;
        }
    }
}
vi factorize(int x){vi f; while(x>1){f.push_back(spf[x]); x/=spf[x];} return f;}

// ---------------- Euler Phi / Divisor Count / Sum ----------------
ll phi(ll n){ll r=n; for(ll p=2;p*p<=n;p++){if(n%p==0){while(n%p==0)n/=p;r-=r/p;}} if(n>1) r-=r/n; return r;}
ll dcount(ll n){ll r=1; for(ll p=2;p*p<=n;p++){int c=0; while(n%p==0){c++; n/=p;} r*=(c+1);} if(n>1) r*=2; return r;}
ll dsum(ll n){ll s=1; for(ll p=2;p*p<=n;p++){ll c=1,m=1; while(n%p==0){n/=p; m*=p; c++;} s*=(m*p-1)/(p-1);} if(n>1) s*=(n+1); return s;}

// ---------------- CRT (coprime) ----------------
ll crt(vll a,vll m){
    ll M=1,res=0,n=sz(a);
    for(ll x:m) M*=x;
    for(int i=0;i<n;i++){
        ll Mi=M/m[i], inv=modinv_euclid(Mi,m[i]);
        res=(res+(__int128)a[i]*Mi%M*inv)%M;
    }
    return (res%M+M)%M;
}

// ---------------- Miller-Rabin / Pollard-Rho ----------------
bool isPrime(ll n){
    if(n<2) return false;
    for(ll p:{2,3,5,7,11,13,17,19,23,29,31,37}) if(n%p==0) return n==p;
    ll d=n-1,s=0; while((d&1)==0) d>>=1,++s;
    auto chk=[&](ll a){
        if(a%n==0) return true;
        ll x=modpow(a,d,n);
        if(x==1||x==n-1) return true;
        for(int i=1;i<s;i++){x=(__int128)x*x%n; if(x==n-1) return true;}
        return false;
    };
    for(ll a:{2,325,9375,28178,450775,9780504,1795265022}) if(a%n && !chk(a)) return false;
    return true;
}
ll f_rho(ll x,ll c,ll m){return (mul(x,x,m)+c)%m;}
ll rho(ll n){
    if(n%2==0) return 2;
    std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    while(1){
        ll x=std::uniform_int_distribution<ll>(2,n-2)(rng);
        ll y=x,c=std::uniform_int_distribution<ll>(1,n-1)(rng),d=1;
        while(d==1){x=f_rho(x,c,n); y=f_rho(f_rho(y,c,n),c,n); d=gcd(std::abs(x-y),n);}
        if(d!=n) return d;
    }
}

// ---------------- Discrete Logarithm ----------------
ll dlog(ll a,ll b,ll m){
    a%=m;b%=m; ll n=std::sqrt(m)+1;
    std::unordered_map<ll,ll> vals;
    ll an=1; for(int i=0;i<n;i++) an=an*a%m;
    ll cur=b; for(int q=0;q<n;q++){vals[cur]=q; cur=cur*a%m;}
    cur=1; for(int p=1;p<=n+1;p++){cur=cur*an%m; if(vals.count(cur)) return n*p-vals[cur];}
    return -1;
}

// ---------------- Matrix Operations ----------------
Mat mat_add(const Mat&A,const Mat&B,ll m=MOD){
    int n=sz(A), k=sz(A[0]); Mat C(n,vll(k));
    for(int i=0;i<n;i++) for(int j=0;j<k;j++) C[i][j]=(A[i][j]+B[i][j])%m;
    return C;
}
Mat mat_sub(const Mat&A,const Mat&B,ll m=MOD){
    int n=sz(A), k=sz(A[0]); Mat C(n,vll(k));
    for(int i=0;i<n;i++) for(int j=0;j<k;j++) C[i][j]=(A[i][j]-B[i][j]+m)%m;
    return C;
}
Mat mat_mul(const Mat&A,const Mat&B,ll m=MOD){
    int n=sz(A), k=sz(A[0]), p=sz(B[0]); Mat C(n,vll(p,0));
    for(int i=0;i<n;i++) for(int j=0;j<p;j++) for(int x=0;x<k;x++)
        C[i][j]=(C[i][j]+A[i][x]*B[x][j]%m)%m;
    return C;
}
Mat mat_pow(Mat A,ll e,ll m=MOD){
    int n=sz(A); Mat R(n,vll(n,0)); for(int i=0;i<n;i++) R[i][i]=1;
    while(e){if(e&1) R=mat_mul(R,A,m); A=mat_mul(A,A,m); e>>=1;}
    return R;
}
ll fib(ll n,ll m=MOD){if(n==0) return 0; Mat F={{1,1},{1,0}}; Mat R=mat_pow(F,n-1,m); return R[0][0];}

// ---------------- Extra Helpers ----------------
ll ceil_div(ll a,ll b){return (a+b-1)/b;}
ll floor_div(ll a,ll b){return a/b;}
bool is_power_of_two(ll n){return n>0 && (n&(n-1))==0;}

// More useful stuff v2

// ---------------- Modular Utilities ----------------
inline ll norm(ll a,ll m=MOD){a%=m; if(a<0) a+=m; return a;}
inline ll modadd(ll a,ll b,ll m=MOD){a+=b; if(a>=m) a-=m; return a;}
inline ll modsub(ll a,ll b,ll m=MOD){a-=b; if(a<0) a+=m; return a;}
inline ll modmul(ll a,ll b,ll m=MOD){return (__int128)a*b%m;}
inline ll modpow_sum(ll a,ll n,ll m=MOD){ // (1 + a + a^2 + ... + a^(n-1))
    if(n==0) return 0;
    if(n==1) return 1;
    if(n%2) return (1 + a*modpow_sum(a,n-1,m))%m;
    ll half=modpow_sum(a,n/2,m);
    ll p=modpow(a,n/2,m);
    return (half + modmul(half,p,m))%m;
}

// ---------------- Binary GCD (Stein's Algorithm) ----------------
ll binary_gcd(ll a,ll b){
    if(!a) return abs(b);
    if(!b) return abs(a);
    int shift=__builtin_ctzll(a|b);
    a>>=__builtin_ctzll(a);
    do {
        b>>=__builtin_ctzll(b);
        if(a>b) swap(a,b);
        b-=a;
    } while(b);
    return a<<shift;
}

// ---------------- Segmented Sieve ----------------
vll seg_sieve(ll L,ll R){
    ll lim = sqrt(R)+1;
    vector<bool> mark(R-L+1,true);
    vector<bool> base(lim+1,false);
    vector<ll> ps;
    for(ll i=2;i<=lim;i++) if(!base[i]){
        ps.push_back(i);
        for(ll j=i*i;j<=lim;j+=i) base[j]=true;
    }
    for(ll p:ps){
        for(ll j=max(p*p,(L+p-1)/p*p);j<=R;j+=p)
            mark[j-L]=false;
    }
    if(L==1) mark[0]=false;
    vll primes;
    for(ll i=0;i<=R-L;i++) if(mark[i]) primes.push_back(L+i);
    return primes;
}

// ---------------- Factorization (unordered_map version) ----------------
map<ll,int> factorize_ll(ll n){
    map<ll,int> f;
    while(n>1 && n%2==0){f[2]++; n/=2;}
    for(ll i=3;i*i<=n;i+=2){
        while(n%i==0){f[i]++; n/=i;}
    }
    if(n>1) f[n]++;
    return f;
}

// ---------------- All Divisors ----------------
vll divisors(ll n){
    vll d;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            d.push_back(i);
            if(i*i!=n) d.push_back(n/i);
        }
    }
    sort(d.begin(),d.end());
    return d;
}

// ---------------- Sieve for Totient & Möbius ----------------
const int MAXN = 1e6+5;
int phi_sieve[MAXN], mu_sieve[MAXN];
bool comp_sieve[MAXN];
void precompute_phi_mu(){
    for(int i=1;i<MAXN;i++) phi_sieve[i]=i, mu_sieve[i]=1;
    for(int i=2;i<MAXN;i++){
        if(!comp_sieve[i]){
            for(int j=i;j<MAXN;j+=i){
                comp_sieve[j]=1;
                phi_sieve[j]=phi_sieve[j]/i*(i-1);
                mu_sieve[j]*=-1;
            }
            for(long long j=1LL*i*i;j<MAXN;j+=1LL*i*i)
                mu_sieve[j]=0;
        }
    }
}

// ---------------- Fibonacci (Fast Doubling) ----------------
pair<ll,ll> fib_doubling(ll n,ll m=MOD){
    if(n==0) return {0,1};
    auto [a,b]=fib_doubling(n>>1,m);
    ll c=modmul(a,(2*b% m - a + m)%m,m);
    ll d=(modmul(a,a,m)+modmul(b,b,m))%m;
    if(n&1) return {d,(c+d)%m};
    else return {c,d};
}
ll fib_fast(ll n,ll m=MOD){return fib_doubling(n,m).first;}

// ---------------- Modular Geometric Sum ----------------
// Sum = a^0 + a^1 + ... + a^(n-1)
ll modgeom(ll a,ll n,ll m=MOD){
    if(n==0) return 0;
    if(n==1) return 1;
    if(n%2==0){
        ll half=modgeom(a,n/2,m);
        ll p=modpow(a,n/2,m);
        return modmul(half,modadd(1,p,m),m);
    }else{
        return modadd(1,modmul(a,modgeom(a,n-1,m),m),m);
    }
}

// ---------------- Modular Linear Equation: ax ≡ b (mod m) ----------------
ll mod_linear(ll a,ll b,ll m){
    ll x,y,g=extgcd(a,m,x,y);
    if(b%g!=0) return -1; // no solution
    x = (x * (b/g)) % m;
    return (x%m+m)%m;
}

// ---------------- Lucas Theorem (nCr mod prime) ----------------
ll nCr_lucas(ll n,ll r,ll p=MOD){
    if(r==0) return 1;
    return (nCr_lucas(n/p,r/p,p)*nCr(n%p,r%p,p))%p;
}

// ---------------- Modular Equation Solver (for a set) ----------------
vector<ll> solve_congruences(vll a,vll m){
    // all mod not necessarily coprime
    // pairwise reduce using CRT for coprime sets only
    return {}; // to-do: placeholder if needed
}

// ---------------- Perfect Square / Integer sqrt ----------------
ll isqrt(ll n){
    ll x = sqrtl(n);
    while(x*x > n) --x;
    while((x+1)*(x+1) <= n) ++x;
    return x;
}
bool is_square(ll n){
    if(n<0) return false;
    ll r=isqrt(n);
    return r*r==n;
}

// ---------------- Sum of Divisors up to N ----------------
vector<ll> divisor_sum_prefix(int n){
    vector<ll> d(n+1,0);
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j+=i)
            d[j]+=i;
    return d;
}

