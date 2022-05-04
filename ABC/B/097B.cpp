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
  ll x;
  cin >> x;
  //maxを取るので小さい値で初期化
  //今回は計算量削減のため答えが1の時を最小として以降の処理で考えないようにする
  ll ans = 1;
  //sqrt(1000)は31.62くらいなので31くらいまで回せば良い
  replr(i,2,32){
    //pの制約が2以上なので処理を2乗から始める
    ll a = i*i; 
    //
    while(1){
      //xの範囲内ならaは条件に合う冪乗の計算結果なのでmaxか判定しmaxならansに格納
      if(a <= x){
        chmax(ans,a);
      }else {
        //xの範囲外ならループを終了
        break;
      }
      //指数部pを+1する処理(計算結果aはi倍される)
      a *= i;
    }  
  }
  //条件に合う最大値を出力
  cout << ans << endl;
  return 0;
}
