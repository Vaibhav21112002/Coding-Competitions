/*
* author : Vaibhav Gupta
*/
 
// Problem : Omkar and Determination

#include <bits/stdc++.h>
#include <chrono> 
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
using namespace chrono;
 
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
#define read(x) for(auto &inps: x) cin>>inps
#define all(v) v.begin(),v.end()
 
#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
 
const int mod = 1e9+7;
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
 
bool isPowerOfTwo(ll n) {return!(n&&(n&(n-1)));}
int setBits(ll n){ll ans = 0; while(n>0){n = (n&(n-1)); ans++; } return ans; }
 
void init_code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
    #endif
}
 
void solve()
{
    int n,m; cin >> n >> m;
    string a[n];
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    vector<int> lx(m,0);
    // memset(lx,0,sizeof(lx));
    for(int i = 1; i<n; i++){
        for(int j = 1; j<m; j++){
            if(a[i][j-1] == 'X' and a[i-1][j] == 'X'){
                lx[j]++;
            }
        }
    }
    vector<int> cs(m,0);
    // cs[0] = lx[0];
    int s = 0 ;
    for(int i = 0; i<m; i++){
        // cs[i] = cs[i-1] + lx[i-1];
        s+= lx[i];
        lx[i] = s;
    }
 
    int q; cin >> q;
    for(int i = 0; i<q; i++){
        int x,y; cin >> x >> y;
        --x; --y;
        int count = lx[y] - lx[x];
        cout << (count==0?"YES":"NO") << endl;
    }
    debug(lx,cs);
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
    return 0;
}
