/*
* author : Vaibhav Gupta
*/

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(x...)
#endif

int32_t main()
{
    IOS
    int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        vector<pair<int,int>> v(n);
        for(int i = 0; i<n; i++){
            cin >> v[i].first;
        }
        for(int i = 0; i<n; i++){
            cin >> v[i].second;
        }

        int ans = k;
        sort(v.begin(),v.end());
        for(auto i: v){
            if(i.first <= k){
                k += i.second;
            }else{
                break;
            }
        }

        cout << k << endl;
    }
    return 0;
}