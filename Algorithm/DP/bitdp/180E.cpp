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
  const ll INF = 1001001001;
  //n2 = n^2
  ll n2 = 1 << n;
  //bitdpのテーブル
  //dp[s][v]:sが今まで訪れた頂点集合でvが今いる頂点の番号の時の最小コスト
  //sは2進数でもって各頂点を2進数の各桁として扱うと良い
  //(sのi桁目が1なら訪れた、0ならまだ訪れていない状態を示す)
  //また頂点0は最初と最後の二回訪れることになるため最初はカウントせず最後に訪れたタイミングで
  //sの0桁目が1になるようにする
  //都市0から各都市に1回だけ移動した状態を以下の処理で初期化、それ以外をINFで初期化
  vector<vector<ll>> dp(n2,vector<ll>(n,INF));
  //dist[i][j]:iからjに向かう過程での問題文の式で計算されたコスト
  vector<vector<ll>> dist(n,vector<ll>(n));
  //各経路のコストを計算する処理O(17^2)
  rep(i,n){
    rep(j,n){
      //now:iからjへ向かうのにかかるコスト(問題文の式)
      ll now = abs(x[j]-x[i]);
      now += abs(y[j]-y[i]);
      now += max(0LL,z[j]-z[i]);
      //iからjへのコストnowをdist[i][j]に格納
      dist[i][j] = now;
    }
  }
  //dpの初期状態設定
  //dpの初期状態を頂点0から何処かの都市に移動した状態とする  
  rep(i,n){
    //0から0への移動は移動してないことになるのでコンティニュー
    if(i == 0){
      continue;
    }
    //左辺:1<<iでi桁目に1が立っている状態になる(これで頂点iだけ訪れた状態)
    //dp[1<<i][i]で頂点iだけ訪れて今頂点iにいる状態でこれまでにかかったコストの最小を示す
    //右辺:dist[0][i]は0からiに進む過程のコスト
    dp[1<<i][i] = dist[0][i];
  }
  //bitdpの遷移についての処理
  //都市をそれぞれ訪れたかどうかの全パターンについてのループ
  //集合s(dp[s][v]のs)は都市を訪れていくにつれどんどん大きくなっていくので
  //依存関係的にも昇順でiを0~n^2-1まで回していく
  rep(i,n2){
    //jは都市の移動の移動元について表す
    rep(j,n){
      //既に到達した都市jから別の都市kへの遷移をdpの遷移として処理する上で、
      //iのj桁目が1でないならその都市jはまだ到達していなく、j-kの遷移ができないのでスルー
      //~iでiのnotになりそのj桁目が1ならiのj桁目が1でないということになる
      if(~i>>j&1){
        continue;
      }
      //都市jからの移動先の都市n個についてのループ(各都市の集合iの中の未到着の都市について)
      rep(k,n){
        //k番目の都市に既に訪れているならコンティニュー
        if(i>>k&1){
          continue;
        }
        //i|1<<kで元のiの1だったbitとk桁目の元々0だったbitだけ1にした形になる
        //(元々訪れていた都市の集合iから都市kを集合に追加した物)
        //コストは元々の訪れた都市の集合がi|1<<kで最後に訪れた都市がkの時の最小コストを示す
        //dp[i|1<<k][k]と、j-kの都市の移動をする前のjにいる時点での最小コストdp[i][j]と
        //j-kのコストdist[j][k]を足したものの小さいほうが最小コストとなる
        chmin(dp[i|1<<k][k],dp[i][j]+dist[j][k]);
      }
    }
  }
  //dp[i][j]のi=n2-1で2進数でn桁全てが1になっている状態(全ての都市を訪れた状態)で、
  //j=0で最後に都市0にいる状態なので全都市を訪れた後に都市0に帰ってきた時の最小コストを出力する
  cout << dp[n2-1][0] << endl;
  return 0;
}
//bitDP(集合をもつdp)で解く問題
//今回は三次元座標上の問題なので、三角不等式よりi-jのルートより
//i,j以外に何点か経由したルートの方が距離が短くなることはない(ワーシャルフロイドは無意味)
//よって全ての都市を1回ずつ訪問するルートの中から最短を選べば良い
//
//nが5でdp[i][j]のiが28だったらiを2進数に変換すると11100となりこの2進数が
//都市それぞれの訪れたかに対応しているためこの例の場合は
//都市2,3,4を既に訪れて、都市0,1がまだ訪れていないことに対応している
