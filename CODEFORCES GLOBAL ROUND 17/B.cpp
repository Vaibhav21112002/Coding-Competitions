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
#define read(x) for(auto &inps: x) cin>>inps
#define all(v) v.begin(),v.end()
#define endl "\n"

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


bool isPand(vector<int> v){
    for(int i = 0; i<v.size()/2; i++){
        if(v[i] != v[v.size()-i-1]){
            return false;
        }
    }

    return true;
}

void solve()
{
    int tx; cin >> tx;
    for(int tt = 1; tt <=tx; tt++){
        int n; cin >> n;
        vi v(n); read(v);
        vector<int> s;
        int x = 0,y = n-1;
        if(isPand(v)){
            cout << "YES" << endl;
        }else{
            for(int i = 0; i<n/2; i++){
                if(v[i] != v[n-i-1]){
                    x = i; y = n-i-1;
                    break;
                }   
            }
            for(int i = x;i<=y; i++){
            s.pb(v[i]);
        }
        debug(s);
        n = s.size();
        int f = s[0];
        int l = s[n-1];
        vector<int> t = s;
        bool isF = false, isL = false;
        int st = 0, en = s.size()-1;
        int ans1 = 0, ans2 = 0;
        while(st < en){ // With the first element
            if(t[st] == t[en]){
                st++;
                en--;
            }else if(t[st] == f){
                st++;
                ans1++;
            }else if(t[en] == f){
                en--;
                ans1++;
            }else if(t[st]!=f and t[en]!=f){
                break;
            }
            debug(tt,t[st],t[en]);
        }
        if(st-en>=0){
            isF = true;
        }
        debug(isF);
        st = 0;
        en = n-1;
        while(st < en){ // With the Second element
            if(t[st] == t[en]){
                st++;
                en--;
            }else if(t[st] == l){
                st++;
                ans2++;
            }else if(t[en] == l){
                en--;
                ans2++;
            }else if(t[st]!=l and t[en]!=l){
                break;
            }
            debug(tt,t[st],t[en]);
        }
        if(st-en>=0){
            isL = true;
        }
     
        if(!isF and !isL){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
        }
        // cout << (!isF?ans2:(!isL?ans1:min(ans1,ans2))) << endl;
    }
}

int main()
{
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