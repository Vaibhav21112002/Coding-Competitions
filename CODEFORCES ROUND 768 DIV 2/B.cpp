/*
* author : Vaibhav Gupta
*/

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

#define int long long

int32_t main()
{
    IOS
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n);
        for(int i = 0; i<n;i++){
            cin >> v[i];
        }

        int ne = v[n-1];
        int i = n-2;
        int cnt = 1;
        int ans = 0;
        while(i >= 0){
            if(v[i] != ne){
                int nei = i;
                for(int j = i; j> max(-1LL,i-cnt); j--){
                    v[i] = ne;
                    nei = j;
                }
                i = nei;
                cnt = n - i;
                ans++;
            }else{
                cnt++;
            }
            i--;
        }
        cout << ans << endl;


    }
    return 0;
}