/*
* author : Vaibhav Gupta
*/

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

#define ff first
#define ss second

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
        map<string,pair<int,int>>m;
        bool ok = false;
        for(int i = 0; i<n; i++){
            string x; cin >> x;
            if(m.find(x) == m.end()){
                m[x].ff = i;
            }
            m[x].ss = i;

            if(x.size() == 1){
                ok = true;
            }
        }
        if(ok){
            cout << "YES" << endl;
            continue;
        }


        for(auto i:m){
            if(i.ff.size() == 2 and i.ff[0] == i.ff[1]){
                ok = true;
                break;
            }

            if(i.ff.size() == 2){
                string x = i.ff;
                reverse(x.begin(), x.end());
                if(m.find(x) != m.end()){
                    ok = true;
                    break;
                }
            }
        }

        if(ok){
            cout << "YES" << endl;
            continue;
        }

        for(auto i:m){
            if(i.ff.size() == 3){
                string one = i.ff.substr(1); reverse(one.begin(), one.end());
                string two = i.ff.substr(0,2); reverse(two.begin(), two.end());
                string three = i.ff.substr(0); reverse(three.begin(), three.end());
                if(m.find(one) != m.end() and m[one].ff < i.ss.ss){
                    ok = true;
                    break;
                }
                if(m.find(two) != m.end() and m[two].ss > i.ss.ff){
                    ok = true;
                    break;
                }
                if(m.find(three) != m.end()){
                    ok = true;
                    break;
                }

                if(i.ff[0] == i.ff[2]){
                    ok = true;
                    break;
                }

            }
        }
        if(ok){
            cout << "YES" << endl;
            continue;
        }

        cout <<"NO" << endl;



    }
    return 0;
}