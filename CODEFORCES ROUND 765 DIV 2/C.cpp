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
    int n,l,k; cin >> n >> l >> k;
    vector<int> d(n), s(n);
    for(auto &i : d)
        cin >> i;
    for(auto &i : s)
        cin >> i;
    d.push_back(l);
    s.push_back(0);
    const long long inf = (long long)1e18;
    vector<vector<int>> dp(n+1,vector<int>(k+1,inf));
    dp[0][0] = 0;
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<=k; j++){
            for(int p = i-1; p>= 0; p--){
                int old = j - (i - p - 1);
                if(old >= 0){
                    dp[i][j] = min(dp[i][j], dp[p][old] + (d[i] - d[p])*(s[p]));
                }
            }
        }
    }
    // for(auto i:dp){
    //     for(auto j:i){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    cout << *min_element(dp.back().begin(), dp.back().end())<< endl;
    return 0;
}