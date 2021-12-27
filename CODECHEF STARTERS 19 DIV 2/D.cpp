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
    string s; cin >> s;
    string t = s;
    reverse(all(s));
    map<int,int> fr,se;
    int ans = 0;
    int n = s.size();
    for(int i = 0; i<n; i++){
        if(i == 0 and s[i] == 'N'){
            s[i] = 'P';
            fr[n-i-1] = 1;
        }else if(s[i] == 'N' and s[i-1] == 'P'){
            continue;
        }else if(s[i] == 'N' and s[i-1] == 'N'){
            s[i] = 'P';
            fr[n-i-1] = 1;
        }
    }
    int p =0, np = 0;
    reverse(all(s));
    for(int i = 0; i<n; i++){
        if(s[i] == 'N'){
            np++;
        }else if(i>0 and s[i] == 'P' and s[i-1] == 'N'){
            continue;
        }else{
            p++;
        }
    }
    if(np > p){
        for(int i = 0; i<n; i++){
            if(np == p) break;
            if(s[i] == 'N'){
                debug(s[i],s);
                s[i] = 'P';
                debug(s[i],s,i);
                np--; p+= 2;
                se[i]++;
            }
        }
    }else{
        for(int i= 0; i<n-1; i++){
            if(np == p) break;
            if(s[i] == 'P' and s[i+1] == s[i]){
                s[i] = 'N';
                se[i]++;
                np++; p-=2;
            }
        }
    }
    debug(fr,se);
    int ans1 = 0,ans2 = 0;
    for(auto i:fr) 
        if(i.ss>0)
            ans1++;

    for(auto i:se) 
        if(i.ss>0 and !fr[i.ff])
            ans2++;
    debug(tt,ans1,ans2);
    cout << ans1 + ans2 << endl;
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