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
void dfs(int i,int back,vector<bool>& visited,vector<vector<int>> &jump,vector<int>& ans){
    visited[i] = 1;
    ans.push_back(i+1);
    for(int j : jump[i]){
        if(visited[j]){
            continue;
        }
        dfs(j,i,visited,jump,ans);
    }
    ans.push_back(back+1);
    return;
}
int main(){
    int n;
    cin >> n;
    vector<vector<int>> jump(n);
    rep(i,n-1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        jump[a].push_back(b);
        jump[b].push_back(a);
    }
    rep(i,n){
        sort(jump[i].begin(),jump[i].end());
    }
    vector<bool> visit(n);
    vector<int> ans;
    dfs(0,-1,visit,jump,ans);
    ans.pop_back();
    int f = ans.size();
    rep(i,f){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
