#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(ll i = 0; i < N; i++)
#define rep2(i,N) for(ll i = 1; i <= N; i++)
#define rep3(i,N) for(ll i = N - 1; i >= 0; i--)
#define rep4(i,N) for(ll i = N; i > 0; i--)
#define replr(i,l,r) for(ll i = l; i < r; i++)
#define reprl(i,l,r) for(ll i = l; i >= r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
using ll = long long;
using P = pair<ll,ll>;
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  ll n;
  cin >> n;
  vector<ll> x(n),y(n),z(n);
  rep(i,n){
    cin >> x[i] >> y[i] >> z[i];
  }
  //iからjに向かう
  vector<vector<ll>> d(n,vector<ll>(n));
  //O(17^2)
  rep(i,n){
    rep(j,n){
      if(i != j){
        d[i][j] = abs(x[j]-x[i])+abs(y[j]-y[i])+max(0LL,z[j]-z[i]);
      }
    }
  }
  //O(17^3)
  rep(k,n){
    rep(i,n){
      rep(j,n){
        chmin(d[i][j],d[i][k]+d[k][j]);
      }
    }
  }
  ll ans = LLONG_MAX;
  //
  vector<ll> p(n-1);
  rep(i,n-1){
    p[i] = i+1;
  }
  //O(17!)ここが計算量爆発ポイント
  do{
    ll sm = 0;
    sm += d[0][p[0]];
    rep(i,n-2){
      sm += d[p[i]][p[i+1]];
    }
    sm += d[p[n-2]][0];
    chmin(ans,sm);
  }while(next_permutation(all(p)));
  cout << ans << endl;
  return 0;
}
//TLE解
//ワーシャルフロイド順列全探索をしたら順列全探索の部分で計算量が爆発した
