/*
* author : Vaibhav Gupta
*/

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;

// #ifndef ONLINE_JUDGE
// #include "debug.h"
// #else
// #define debug(x...)
// #endif

int32_t main()
{
    IOS
    int t; cin >> t;
    while(t--){
        int l,r,k; cin >> l >> r >> k;
        if(l == r and l != 1){
            cout << "YES" << endl;
            continue;
        }else if(l == r and l == 1){
            cout << "NO" << endl;
            continue;
        }

        int total = r-l+1;
        int minOp = total - ((r/2) - ((l-1)/2));
        cout << (minOp <= k ?"YES":"NO") << endl;
        // debug(l,r,minOp);
    }
    return 0;
};