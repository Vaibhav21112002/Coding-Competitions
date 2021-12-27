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

void solve(int tt)
{
    int n,k; cin >> n >> k;
    vector<int> v(n); read(v);
    sort(all(v));
    int ans = 0;
    for(int i = 0; i<n-2*k; i++){
        ans += v[i];
    }
    map<int,int> m;
    for(int i =n-2*k; i<n; i++ ){
        m[v[i]]++;
    }
    int more = 0, total = 0;
    for(auto i:m){
        if(i.ss <= k){
            total += i.ss;
        }
        if(i.ss >k){
            more = i.ss;
        }
    }
    if(more == 0){
        cout << ans << endl;
        return;
    }else{
        ans += (more-total)/2;
    }
    cout << ans << endl;
    debug(m);
    debug(ans);
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