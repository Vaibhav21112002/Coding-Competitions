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
    while (t--) {
        int n, k; cin >> n >> k;
        if (k == n - 1 and n == 4) {
            cout << - 1 << endl;
            continue;
        }
        map<int, int> m;
        if (k == 0) {
            for (int i = 0; i < n / 2; i++) {
                cout << i << " " << n - i - 1 << endl;
            }
        } else {
            if (k == n - 1) {
                cout << 0 << " " << 1 << endl;
                cout << n-1 << " " << (n/2)-1 << endl;
                cout << n-2 << " " << (n/2) << endl;
                for(int i = 2; i<= (n/2)-2; i++){
                    cout << i << " "  << n-i-1 << endl;
                }
            } else {
                cout << k << " " << n - 1 << endl;
                cout << 0 << " " << n - k - 1 << endl;
                m[0] = 1;
                m[k] = 1;
                m[n - 1] = 1;
                m[n - k - 1] = 1;
                for (int i = 0; i < n; i++) {
                    if (!m[i] and !m[n - i - 1]) {
                        cout << i << " " << n - i - 1 << endl;
                        m[i] = 1;
                        m[n - i - 1] = 1;
                    }
                }
            }

        }

    }
    return 0;
}