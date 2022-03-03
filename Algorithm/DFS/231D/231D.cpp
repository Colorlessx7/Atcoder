#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define all(x) x.begin(),x.end() 
typedef long long ll;
using P = pair<int,int>;
bool dfs(int v, int par, vector<bool>& visited, vector<ll> adj[]){
    visited[v] = 1;
    for(int u : adj[v]){
        if(u == par){
            continue;
        }
        if(visited[u]){
            return 1;
        }
        if(dfs(u,v,visited,adj)){
            return 1;
        }
    }
    return 0;
}
int main(){
    ll n, m;
    cin >> n >> m;
    vector<ll> adj[n];
    rep(i,m){
        ll u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool flag = 1;
    rep(i,n){
        if(adj[i].size() > 2){
            flag = 0;
        }
    }
    vector<bool> visit(n,0);
    rep(i,n){
        if(!visit[i]){
            if(dfs(i,0,visit,adj)){
                flag = 0;
            }
        }
    }
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}

