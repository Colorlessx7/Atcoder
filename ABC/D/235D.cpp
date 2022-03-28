#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(ll i = 0; i < N; i++)
#define rep2(i,N) for(ll i = 1; i <= N; i++)
#define rep3(i,N) for(ll i = N - 1; i >= 0; i--)
#define rep4(i,N) for(ll i = N; i > 0; i--)
#define replr(i,l,r) for(ll i = l; i < r; i++)
#define reprl(i,l,r) for(ll i = l; i > r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
typedef long long ll;
using P = pair<ll,ll>;
int main(){
    ll a, n;
    cin >> a >> n;
    vector<ll> visited(1000001,-1);
    queue<ll> q;
    q.push(1);
    visited[1] = 0;
    while(q.size()){
        ll v = q.front();
        q.pop();
        if(v*a <= 1000000 && visited[v*a] == -1){
            visited[v*a] = visited[v] + 1;
            q.push(v*a);
        }
        if(v >= 10 && v % 10 != 0){
            string f = to_string(v);
            ll sz = f.size() - 1;
            string f2;
            f2 += f[sz];
            f2 += f;
            f2.pop_back();
            ll v2 = stoll(f2);
            if(v2 <= 1000000 && visited[v2] == -1){
                visited[v2] = visited[v] + 1;
                q.push(v2);
            }
        }
    }
    cout << visited[n] << endl;
    return 0;
}
//DFSに見えるBFS問題(最短路なのでBFS)
//
