#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define replr(i,l,r) for(int i = l; i < r; i++)
#define all(x) x.begin(),x.end() 
typedef long long ll;
using P = pair<int,int>;
void dfs(int i,vector<bool>& visit,vector<vector<int>>& g,ll& ans){
    ans++;
    visit[i] = 1;
    for(int j : g[i]){
        if(visit[j]){
            continue;
        }
        dfs(j,visit,g,ans);
    }
    return;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
    }
    ll ans = 0;
    vector<bool> visit(n);
    rep(i,n){
        dfs(i,visit,g,ans);
        rep(j,n){
            visit[j] = 0;
        }
    }
    cout << ans << endl;
    return 0;
}
