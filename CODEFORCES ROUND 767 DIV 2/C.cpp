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
        vector<int> v(n);
        for(int i = 0; i<n; i++){
            cin >> v[i];
        }
        set<int> s,st;
        for(int i = 0; i<=n+1; i++){
            s.insert(i);
            st.insert(i);
        }
        vector<int> sufMex;
        for(int i = n-1; i>= 0;i--){
            if(s.find(v[i]) != s.end()){
                s.erase(s.find(v[i]));
            }
            sufMex.push_back(*s.begin());
        }
        reverse(sufMex.begin(), sufMex.end());
        debug(sufMex);
        vector<int> ans;
        int curMex = sufMex[0];
        int mex = 0;
        bool ok = false;
        map<int,int> stt;
        for(int i = 0; i<n; i++){
            stt[v[i]]++;
            ok = false;
            while(mex <= n+1 and stt[mex]){
                mex++;
            }
            if(mex == curMex){
            debug(i,mex,curMex);
                ans.push_back(mex);
                stt.clear();
                ok = false;
                mex = 0;
                if(i+1<n){
                    curMex = sufMex[i+1];
                }
            }

        }
        if(ok){
            ans.push_back(mex);
        }
        cout << ans.size() << endl;
        for(auto i:ans){
            cout << i << " ";
        }
        cout << endl;
        // debug(ans);

    }
    return 0;
}