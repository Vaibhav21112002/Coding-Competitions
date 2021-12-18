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

#define ll long long
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
#define read(x) for(auto &inps: x) cin>>inps
#define all(v) v.begin(),v.end()
#define endl "\n"

const int mod = 1e9+7;
const int mod2 = 998244353;
const int smod = 1e5+1;

//template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag ,  tree_order_statistics_node_update >;


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


void init_code(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r", stdin);
  freopen("output.txt","w", stdout);
  #endif
}

ll ans;
bool ok;

vector<bool> red;
vector<vll> adj;
vector<ll> neared;
vector<ll> dist;


void dfs(ll node, ll p){
    if(node != 1){
        dist[node] = dist[p]+1;
    }
    if(red[node]){
        neared[node] = 0;
    }
    ll ctr = 0;
    for(auto x: adj[node]){
        if(x != p){
            dfs(x,node);
        }
        neared[node] = min(neared[node], 1 + neared[x]);
    }
}

void dfs2(ll node, ll p){
    if(node != 1 and adj[node].size()== 1){
        ok = true;
        return;
    }
    for(auto x:adj[node]){
        if(x == p){
            continue;
        }
        if(neared[x] > dist[x]){
            dfs2(x,node);
        }else{
            ans++;
        }
    }
}

void solve()
{
    int t; cin >> t;
    for(int tt = 1; tt <=t; tt++){
        ll n,k; cin >> n >> k;
        red.assign(n+1,false);
        adj.assign(n+1,{});
        neared.assign(n+1, mod);
        dist.assign(n+1, 0LL);
        for(ll i = 0; i<k; i++){
            ll x; cin >> x;
            red[x] = true;
        }
        for(ll i = 0; i<n-1; i++){
            ll x,y; cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        ans = 0;
        ok = false;
        dfs(1,-1);
        dfs2(1,-1);
        if(!ok){
            cout << ans << endl;
        }else{
            cout << -1 << endl;
        }

    }   
}

int main()
{
    init_code();
    auto start = high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    float timeCount = duration.count();
    timeCount /= 1000000;
    debug("Time Taken",timeCount);
}