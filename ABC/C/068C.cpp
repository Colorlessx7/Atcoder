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
void dfs(const int i,int k,int n,int m,bool& f,vector<P>& ab){
    if(i == 2){
        if(n == k){
            f = 1;
        }
        return;
    }
    int p = i + 1;
    rep(j,m){
        if(ab[j].first == k){
            int w = ab[j].second;
            dfs(p,w,n,m,f,ab);
        }
    }
    return;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<P> ab(m);
    rep(i,m){
        cin >> ab[i].first >> ab[i].second;
    }
    bool f = 0;
    dfs(0,1,n,m,f,ab);
    cout << (f ? "POSSIBLE" : "IMPOSSIBLE") << endl;
    return 0;
}
//TLEしたdfs解
