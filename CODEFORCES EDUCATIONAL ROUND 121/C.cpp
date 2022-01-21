/*
* author : Vaibhav Gupta
*/

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;

int32_t main()
{
    IOS
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<pair<int,int>> v(n);
        for(int i = 0;i<n; i++){
            cin >> v[i].first;
        }
        for(int i = 0;i<n; i++){
            int x; cin >> x;
            v[i].second = v[i].first;
            v[i].first = v[i].first - x + 1;
        }
        sort(v.begin(),v.end());
        int l = v[0].first;
        int r = v[0].second;
        int ans = 0;
        vector<pair<int,int>> mod;
        for(int i = 1; i<n; i++){
            if(v[i].first<= r){
                r = max(r,v[i].second);
            }else{
                mod.push_back({l,r});
                l = v[i].first;
                r = v[i].second;
            }
        }
        mod.push_back({l,r});
        for(auto i:mod){
            int x = i.second - i.first + 1LL;
            ans += x*(x+1)/2;
        }
        cout << ans << endl;
    }
    return 0;
}