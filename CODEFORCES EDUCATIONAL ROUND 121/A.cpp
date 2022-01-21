#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
    IOS
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        map<char,int> m;
        for(auto i:s)
            m[i]++;
        for(auto i:m)
            for(int j = 0; j<i.second; j++){
                cout << i.first;
            }

        cout << endl;
    }
    return 0;
}