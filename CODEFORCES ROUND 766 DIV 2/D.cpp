/*
* author : Vaibhav Gupta
*/

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

const int A = int(1e6)+5;

int32_t main()
{
    IOS
    int n; cin >> n;
    vector<int> v(n);
    vector<bool> present(A+1,false);
    for(int i = 0; i<n; i++){
        cin >> v[i];
        present[v[i]] = true;
    }

    vector<int> mul(A+1,0);
    for(int i = 1;i<=A; i++){
        for(int j = i; j<= A; j+= i){
            mul[i] += present[j];
        }
    }

    int ans = 0;

    for(int i = 1; i<=A; i++){
        if(present[i] or !mul[i])
            continue;

        int x = 1;
        for(int b = 2*i; b<= A; b+= i){
            if(mul[i] == mul[b]){
                x = 0;
                break;
            }
        }

        ans += x;

    }

    cout << ans << endl;
    return 0;
}