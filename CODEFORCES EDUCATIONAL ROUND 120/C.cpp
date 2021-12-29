/*
* author : Vaibhav Gupta
*/

#include <bits/stdc++.h>
#include <chrono> 
using namespace std;
using namespace chrono;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;

//template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag ,  tree_order_statistics_node_update >;

#define ll long long int
#define eb emplace_back
#define pb push_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define read(args...) read1(args)
#define sortf(args...) sortf1(args)
#define sortr(args...) sortr1(args)
#define all(v) v.begin(),v.end()
#define endl "\n"

const int mod = 1e9+7;
const int smod = 1e5+1;

void read1() {return;} template<typename T, typename... Args> void read1 (T &a, Args&... args) {for (auto &i : a) cin >> i; read1(args...); }
void sortf1(){return;} template<typename T, typename... Args> void sortf1(T &a, Args&... args) {sort(a.begin(), a.end()); sortf1(args...);  }
void sortr1(){return;} template<typename T, typename... Args> void sortr1(T &a, Args&... args) {sort(a.rbegin(), a.rend()); sortr1(args...);}

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V> void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T> void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";} void _print() {cerr << "]\n";}
template<typename T, typename... V> void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
ll pwr(ll a, ll b) {a %= mod; ll res = 1; while (b > 0) {if (b & 1) res = res * a % mod; a = a * a % mod; b >>= 1;} return res;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

// bool test = false;
bool test = true;

void solve(int tt)
{   
    ll n,k; cin >> n >> k;
    vector<ll> v(n+1);
    ll s = 0;
    for(ll i = 1;  i<=n;i++){
        ll x; cin >> x;
        v[i] = x;
        s += x;
    }
    sortf(v);
    debug(v);
    ll profitRequired = s - k;
    if(profitRequired <= 0){
        cout << 0 << endl;
        return;
    }
    if(s == k+1){
        cout << 1 << endl;
        return;
    }
    ll diff = s - k;
    ll ans = s - k;
    ll sum = 0;
    for(ll i = n; i>1; i--){
        sum += v[i];
        ll x;
        if(sum - (n - i + 1)*v[1] >= diff ) x = 0;
        else x = max(ceil_div(diff - sum + ((n - i + 1)*v[1]),n - i + 2),0LL);
        ans = min(ans, x + n - i + 1);
    }
    cout << ans << endl;
}

int main()
{
    auto start = high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    if(test) cin >> t;
    for(int i = 1; i<=t; i++) solve(i);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    float timeCount = duration.count();
    timeCount /= 1000000;
    debug("Time Taken",timeCount);
}