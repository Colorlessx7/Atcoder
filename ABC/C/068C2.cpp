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
int main(){
    int n, m;
    cin >> n >> m;
    map<int,vector<int>> mp;
    rep(i,m){
        int a, b;
        cin >> a >> b;
        mp[a].push_back(b);
    }
    queue<int> q;
    vector<int>& p = mp[1];
    rep(i,p.size()){
        q.push(p[i]);
    }
    int x = q.size();
    int f;
    rep(i,x){
        f = q.front();
        q.pop();
        vector<int>& p2 = mp[f];
        rep(j,p2.size()){
            if(p2[j] == n){
                cout << "POSSIBLE" << endl;
                return 0;
            }
        } 
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
//BFS? queue?な正解プログラム
