#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
    IOS
    int t; cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        vector<int> ans;
        auto high = [&](int i, int j)->int{
            int a = abs(1-i) + abs(1-j);
            int b = abs(1-i) + abs(m-j);
            int c = abs(n-i) + abs(m-j);
            int d = abs(n-i) + abs(1-j);
            return max({a,b,c,d});
        };


        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                ans.push_back(high(i,j));
            }
        }
        sort(ans.begin(), ans.end());
        for(auto i:ans)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}