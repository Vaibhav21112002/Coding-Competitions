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
        bool ok = true;
        string s; cin >> s;
        int n = s.size();
        for(int i = n-1;i>0; i--){
            int a = (int)(s[i] - '0');
            int b = (int)(s[i-1] - '0');
            if(a+b >= 10){
                cout << s.substr(0,i-1) + to_string(a+b) + s.substr(i+1) << endl;
                ok = false;
                break;
            }
        }
        if(ok){
            int a = (int)(s[0] - '0');
            int b = (int)(s[1] - '0');
            cout << to_string(a+b) + s.substr(2)<< endl;
        }
    }
    return 0;
}