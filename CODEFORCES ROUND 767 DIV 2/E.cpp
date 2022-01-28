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
        int n; cin >> n;
        vector<vector<int>> v(n, vector<int>(n,0));
        vector<vector<bool>> vis(n+2,vector<bool>(n+2,false));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                cin >> v[i][j];
            }
        }

        auto isPossible = [&](int x, int y)->bool{
            bool ok1 = vis[x+1][y];
            bool ok2 = vis[x-1][y];
            bool ok3 = vis[x][y+1];
            bool ok4 = vis[x][y-1];
            if(!ok1 and !ok2 and !ok3 and !ok4){
                vis[x+1][y] = true;
                vis[x-1][y] = true;
                vis[x][y+1] = true;
                vis[x][y-1] = true;
                return true;
            }

            return false;
        };
        int ans = 0;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(isPossible(i,j)){
                    ans = (ans ^ v[i-1][j-1]);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}