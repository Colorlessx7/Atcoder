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
using ll = long long;
using P = pair<ll,ll>;
//dpでは度々遷移でmin,maxを取ることがあり代入式の左右で同じものを2回書きたくないから
//chmin,chmaxという関数が採用される(xが参照なのでxに遷移先を書くこと)
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  ll n, x, y;
  cin >> n >> x >> y;
  //dpの遷移の過程でminを取るためdpの初期値は取りうる値(300)を超えた大きい値にしておく
  const ll INF = 1001001001;
  //dpの変数iをpからdpの遷移として考えるためdp[j][k]とする
  vector dp(x+1,vector<ll>(y+1,INF));
  //初期化(最初はどちらも入っていないので弁当を0個買った状態はj=0,k=0)
  dp[0][0] = 0;
  rep(i,n){
    //次買うか考える弁当の各個数を入力
    ll a, b;
    cin >> a >> b;
    vector p(x+1,vector<ll>(y+1,INF));
    //dpをi+1,pをiとしてiについてのdpの遷移を考える
    swap(dp,p);
    //dp遷移処理部分
    rep(j,x+1){
      rep(k,y+1){
        //minを取るのでdp[j][k]がINFでないところに限定して遷移させる必要はない
        //(遷移しない場所はそのままINFが入る)
        //弁当iを買わない場合の処理,変化がないので一つ前のiのdp[j][k]をそのまま遷移
        chmin(dp[j][k],p[j][k]);
        //買う場合の遷移,遷移先j+a,k+bがそれぞれx,yを超えていたら配列外参照回避のため
        //x,yに丸めて最小値の更新を行う
        //遷移元の最小の弁当の購入個数に+1したものが
        //既により小さい値で更新されていないかぎり遷移する
        //既に買ったもので変えない組み合わせ(j,k)からの遷移はどのみちINFになる
        chmin(dp[min(j+a,x)][min(k+b,y)],p[j][k]+1);
      }
    }
  }
  //超過分をx,yに丸めているのでdp[x][y]が答え
  ll ans = dp[x][y];
  //変えない場合初期状態のINFのままなので-1にする
  if(ans == INF){
    ans = -1;
  }
  cout << ans << endl;
  return 0;
}
//三次元dp問題
//x,yの制約が300以下ととても小さいことを利用する
//dpテーブルはdp[i][j][k]:i個目までを買うか買わないか決めた時に
//たこ焼きをj個、たい焼きをk個買えるように取った時の弁当の最小個数
//ただし、制約上a*n,b*nの最大は300*300で90000になり、
//メモリのサイズが足りなくなるので
//x,yの超過分は捨てる(dpテーブルの最大をx,yにして
//遷移先がx,yのどっちかまたは両方を超えるならx,yそれぞれちょうどとして扱う)
//
