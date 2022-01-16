/*
* author : Vaibhav Gupta
*/

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
    IOS
    int t; cin >> t;
    while(t--){
        int n,m,x,y; cin >> n >> m >> x >> y;
        --x; --y;
        string arr[n];
        int bl = 0;
        for(int i = 0; i<n; i++){
            cin >> arr[i];
            for(int j = 0; j<m; j++){
                if(arr[i][j] == 'B'){
                    bl++;
                }
            }
        }
        if(!bl){
            cout << -1 << endl;
            continue;
        }

        if(arr[x][y] == 'B'){
            cout << 0 << endl;
            continue;
        }

        bool ok = false;
        for(int i = 0; i<m; i++){
            if(arr[x][i] == 'B'){
                ok = true;
            }
        }

        for(int i = 0; i<n; i++){
            if(arr[i][y] == 'B'){
                ok = true;
            }
        }

        if(ok){
            cout << 1 << endl;
            continue;
        }

        cout << 2 << endl;

    }
    return 0;
}