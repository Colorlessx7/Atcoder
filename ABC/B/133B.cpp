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
  //n:点の個数,d:次元数
  ll n, d;
  cin >> n >> d;
  //x[i][j]:i番目の点の座標(jは各次元の値)
  vector<vector<ll>> x(n,vector<ll>(d));
  //座標入力
  rep(i,n){
    rep(j,d){
      cin >> x[i][j];
    }
  }
  //距離をsqrt(?)とすると?がi^2となる数字のみvalueをtrueとするmap
  map<ll,bool> mp;
  //127^2からギリギリ16000を超えてしまうので1~126の2乗のみmapのvalueをtrueにしておく
  rep2(i,126){
    mp[i*i] = true;
  }
  //距離が整数となる組の個数
  ll ans = 0;
  //i,jのループで二点間の距離(根号を考えないもの)を求めている(重複なし)
  rep(i,n){
    rep(j,i){
      //根号を考えない距離の合計
      ll num = 0;
      //全次元について差分の二乗を計算してnumに加算
      rep(k,d){
        num += (x[i][k]-x[j][k])*(x[i][k]-x[j][k]);
      }
      //trueなら距離はsqrt(i^2)の形になり、整数となるので答えに+1
      if(mp[num]){
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
//最大パターンの時の距離は((20-(-20))^2)*10=16000となる(根号は外している)
