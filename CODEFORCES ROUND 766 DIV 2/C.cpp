#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<vector<int>> adj;
vector<int> ins;
map<pair<int,int>,int>m;
vector<pair<int,int>> edges;
int n;

void dfs(int u, int v, int c){
    for(auto i:adj[u]){
        if(i == v)
            continue;
        m[make_pair(min(i,u), max(i,u))] = c;
        if(c == 2)
            c = 3;
        else{
            c = 2;
        }

        dfs(i,u,c);
    }
}

int main()
{
    IOS
    int t; cin >> t;
    while(t--){
        cin >> n;
        adj.assign(n+1,{});
        ins.assign(n+1,0);
        edges.clear();
        m.clear();
        for(int i = 0; i<n-1; i++){
            int x,y; cin >> x >> y;
            ins[x]++; ins[y]++;
            adj[x].push_back(y);
            adj[y].push_back(x);
            edges.push_back(make_pair(min(x,y), max(x,y)));
        }

        bool ok = true;
        for(int i = 1; i<=n; i++){
            if(ins[i] > 2){
                ok = false;
                break;
            }
        }
        if(!ok){
            cout << -1 << endl;
            continue;
        }

        dfs(1,-1,2);
        vector<int> ans(n-1);
        for(int i = 0; i<n-1;i++){
            // cout << t << " " << i << " " << edges[i].first << " " << edges[i].second << " " << m[edges[i]] << endl;
            ans[i] = m[edges[i]];
        }
        for(auto i:ans){
            cout <<i << " ";
        }
        cout << endl;
    }
    return 0;
}