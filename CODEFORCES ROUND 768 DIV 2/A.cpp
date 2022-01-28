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
        vector<int> a(n),b(n);
        for(int i = 0; i<n; i++){
            cin >> a[i];
        }
        for(int i = 0; i<n; i++){
            cin >> b[i];
        }
        int mx = -1;
        int mxa = INT_MIN;
        for(int i = 0; i<n;i++){
            if(a[i] > mxa){
                mxa = a[i];
                mx = i;
            }

            if(b[i] > mxa){
                mxa = b[i];
                mx = i;
            }
        }
        int ans = mxa;
        mxa = min(a[mx], b[mx]);
        for(int i = 0; i<n; i++){
            if(i != mx){
                if(min(a[i], b[i]) > mxa){
                    mxa = min(a[i],b[i]);
                }
            }
        }

        cout << ans*mxa << endl;
    }
    return 0;
}