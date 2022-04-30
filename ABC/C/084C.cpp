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
  //駅の個数
  ll n;
  cin >> n;
  //c:i-i+1間の列車の移動時間
  //s:駅iの最初の列車の発車時間
  //f:駅iの最初の駅が発車して以降の発車間隔
  vector<ll> c(n-1),s(n-1),f(n-1);
  rep(i,n-1){
    cin >> c[i] >> s[i] >> f[i];
  }
  //駅iから出発した時の駅n-1に到着するまでの最短時間(i=n-1でans[i]=0となる)
  vector<ll> ans(n);
  //i=n-1は答えが0固定なのでi=0~n-2についてを開始点としてループを回す
  rep(i,n-1){
    //駅iから出発した時の駅n-1に到着するまでの最短時間を計算するための変数
    ll num = 0;
    //それぞれの駅についてループ処理 
    for(ll j = i; j < n-1; j++){
      //今見ている駅が開始点なら処理
      if(j == i){
        //最初の列車に乗るまでにかかる時間(最初の発車までの時間)を経過時間numにたす
        num += s[j];
        //次の駅までの移動時間を経過時間numに足す
        num += c[j];
      }else {
        //今見ている駅が開始点でない場合の処理
        //到着した時点で始発がまだ出てない場合とちょうど始発が出る場合に処理
        if(num <= s[j]){
          //経過時間はその駅の始発に乗る時間になる
          num = s[j];
          //次の駅までの移動時間を経過時間numに足す
          num += c[j];
        }else {
          //到着した時点で始発がすでに出ていて2つ目以降の列車に乗る場合の処理
          //計算のため現在の経過時間をxに格納
          //このxを使ってx:始発以降の何回目の列車に乗るかを計算する
          ll x = num;
          //xから始発が出るまでの時間をひく
          x -= s[j];
          //切上げ除算を用いて始発以降の何回目の列車に乗るかを計算する
          x = (x + f[j] - 1) / f[j];
          //列車に乗るまでの経過時間はその駅の始発が出る時間s[j]+乗ることが可能な
          //始発以降のx回目の列車が発車するまでにかかる時間f[j]*xになる
          num = s[j] + f[j] * x;
          //次の駅までの移動時間を経過時間numに足す
          num += c[j];
        }
      }
    }
    //jについてのfor文の終了によりn-1駅に到着し、
    //その時点での経過時間numが駅iから出発した時の駅n-1に到着するまでの最短時間となる
    ans[i] = num;
  }
  //出力部
  rep(i,n){
    cout << ans[i] << endl;
  }
  return 0;
}
