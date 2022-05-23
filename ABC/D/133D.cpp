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
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }
  //x2:下の解説の2xを求める
  ll x2 = 0;
  //x2を求めるループ
  rep(i,n){
    //i%2=0ならelseが、=1なら以下の式が実行される
    //問題では1indexedだったものを配列の添字で0indexedにしているため
    //下の式とindexの符号の正負が逆になるがi=0からa[i]を+,-,+,-...していく
    if(i%2){
      x2 -= a[i];
    }else {
      x2 += a[i];
    }
  }
  vector<ll> ans(n);
  //上の処理で2xが求まったため、以下の式で頂点1の値がxであるので2xを2で割った値を格納する
  //(x2:山1に降った雨の量,x2/2:山1からダム1に流れた水の量)
  ans[0] = x2/2;
  //ダムの片方からの水の量がわかったため下の式より全ての山からダムに流れる水の量がわかるので計算して格納
  rep(i,n-1){
    ans[i+1] = a[i] - ans[i];
  }
  //上で求めたのはあくまでダムに流れた水の量(降水量の半分)なので2倍して降水量を求める
  rep(i,n){
    ans[i] *= 2;
  }
  //出力部
  rep(i,n){
    //%lld=ans[i],%c=最後の要素以外は空白,最後の要素のみ改行
    printf("%lld%c",ans[i],i==n-1?'\n':' ');
  }
  return 0;
}
//この問題を頂点n(odd)個のグラフ問題として考える(以下で例を5として扱う)
//頂点をi,頂点間の最終的な水の量をAiとすると
//1-A1-2-A2-3-A3-4-A4-5-A5-1という円環構造のグラフになる
//仮に頂点1に降った雨の量をxとすると
//頂点1:x 
//頂点2:A1-x
//頂点3:A2-2 = A2-A1+x
//頂点4:A3-3 = A3-A2+A1-x
//頂点5:A4-4 = A4-A3+A2-A1+x
//頂点1:x = A5-5 = A5-A4+A3-A2+A1-x
//よって移項して2x = A5-A4+A3-A2+A1
//(nが偶数の場合は上の式のように移項するとxが消えてしまうため関係式が得られず難しくなる)
