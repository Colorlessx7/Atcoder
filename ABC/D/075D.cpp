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
  //入力部
  //n:点の個数,k:条件(長方形の内部に必要な点の個数)
  ll n, k;
  cin >> n >> k;
  //各点の座標(xi,yi)
  vector<ll> x(n),y(n);
  rep(i,n){
    cin >> x[i] >> y[i];
  }
  //全探索用のset,昇順に並ぶ 
  set<ll> xx, yy;
  //各点の座標をsetにそれぞれ格納
  rep(i,n){
    xx.insert(x[i]); yy.insert(y[i]);
  }
  //ans:k点以上内部に含む長方形の最小面積(minを取るため最大で初期化)
  ll ans = LLONG_MAX;
  //長方形の左下の座標(sx,sy)と右上の座標(tx,ty)について全探索する
  for(auto sx : xx){
    for(auto sy : yy){
      for(auto tx : xx){
        for(auto ty : yy){
          if(sx <= tx && sy <= ty){
            //全探索で決めた長方形の左下を(sx,sy), 右上を(tx,ty)
            //とする長方形の面積を計算
            ll sm = 1LL * (tx - sx) * (ty - sy);
            //全探索で決めた長方形の左下を(sx,sy), 右上を(tx,ty)
            //とする長方形の内部にある点の個数のカウンタ
            ll c = 0;
            //全点が全探索で決めた長方形の内部に存在するか判定
            rep(i,n){
              //長方形の内部か判定(sx<=x[i]<=tx,sy<=y[i]<=ty)
              if(sx <= x[i] && x[i] <= tx && sy <= y[i] && y[i] <= ty){
                //長方形の内部に点があったので個数のカウンタに+1
                c++;
              }
            }
            //全探索で決めた長方形の左下を(sx,sy), 右上を(tx,ty)
            //とする長方形の内部にk個以上点が存在するなら面積smが最小か判定して
            //最小ならansに格納
            if(k <= c){
              chmin(ans,sm);
            }
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
//
//重要な考察として、最適な長方形は四辺がどれも何かの頂点と交わっている
//仮に頂点がK個以上あり、四辺のうちどこかが何かの頂点と交わっていない長方形があった場合、
//交わっていない辺を移動させて、より面積が小さい長方形に変形できるため
//長方形の上下左右を全探索するが、その候補は頂点のx,y座標に限られる
//この候補から、長方形の左下を(sx,sy), 右上を(tx,ty)として全探索する
//
