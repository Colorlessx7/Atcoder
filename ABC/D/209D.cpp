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
    int n, qm;
    cin >> n >> qm;
    vector<vector<int>> G(n);
    rep(i,n-1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    const int INF = 1001001001;
    vector<int> dist(n,INF);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while(q.size()){
        int v = q.front();
        q.pop();
        for(int u : G[v]){
            if(dist[u] != INF){
                continue;
            }
            dist[u] = dist[v] + 1;
            q.push(u);
        }
    }
    rep(i,qm){
        int c, d;
        cin >> c >> d;
        c--; d--;
        int x = dist[c] + dist[d];
        cout << (x % 2 == 0 ? "Town" : "Road") << endl;
    }
    return 0;
}
