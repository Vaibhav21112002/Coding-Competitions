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
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define fbo find_by_order
#define ook order_of_key
#define read(x) for(auto &inps: x) cin>>inps
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define endl "\n"

const int mod = 1e9+7;
const int smod = 1e5+1;

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
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
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

ll lcm(ll a, ll b){
    return ((a*b)/(__gcd(a,b)));
}

bool atleast(ll a, ll b){
    if(a >1 and b >1) return true;
    return false;
}

bool atlast(ll a, ll b){
    if(a == 1 and b >1) return true;
    if(a > 1 and b == 1) return true;

    return false;
}

void solve(int tt)
{
    ll n; cin >> n;
    vector<ll> v(n);
    read(v);
    ll h1 = 0, h2 = 0;
    for(ll i = 0; i<n;i++){
        if(i%2 == 0){
            h1 = __gcd(h1,v[i]);
        }else{
            h2 = __gcd(h2,v[i]);
        }
    }
    bool ok1 = false, ok2 = false;

    if(h1 == 1 and h2 == 1){
        cout << 0 << endl;
        return;
    }
    for(ll i = 0; i<n;i++){
        if(i%2 == 0){ 
            if(v[i]%h2 == 0){
                ok1 = true;
            }
        }else{
            if(v[i]%h1 == 0){
                ok2 = true;
            }
        }
    }
    if(ok1 and ok2){
        cout << 0 << endl;
    }else{
        if(!ok1) cout << h2 << endl;
        else cout << h1 << endl;
    }

}

int main()
{
    auto start = high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    if(test){
        cin >> t;
    }
    for(int i = 1; i<=t; i++) solve(i);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    float timeCount = duration.count();
    timeCount /= 1000000;
    debug("Time Taken",timeCount);
}