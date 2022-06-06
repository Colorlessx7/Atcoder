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
using TP = tuple<ll,ll,ll>;
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  ll h, w, c;
  cin >> h >> w >> c;
  vector a(h,vector<ll>(w));
  rep(i,h){
    rep(j,w){
      cin >> a[i][j];
    }
  }
  //minを取るため10^18で初期化
  const ll INF = 1e18;
  //２駅の最小コストを求める
  ll ans = INF;
  //探索方向についてのループ(下の方法だと駅の配置が左上と右下の状態にしか対応しない)
  //下のreverseでaの上下を反転させることにより、真逆の駅が右上と左下にある状態にも対応させることができる
  rep(_,2){
    //d[i][j]:(0,0)~(i,j)のグリッド内の、以下の式における(Aij)'-c(i'+j')の最小値
    vector d(h,vector<ll>(w,INF));
    //グリッド内の全頂点についてループ
    rep(i,h){
      rep(j,w){
        //(0,0)~(i,j)のグリッドの頂点(i,j)を除いた範囲の各頂点の(Aij)'-c(i'+j')の最小値を求める
        //if(i)と以下のif(j)はi,jがそれぞれ1以上なら実行する(配列外参照を回避するため)
        if(i){
          //今見ている点の上側の最小を取る
          chmin(d[i][j],d[i-1][j]);
        }
        if(j){
          //今見ている点の左側の最小をとる
          chmin(d[i][j],d[i][j-1]);
        }
        //(0,0)~(i,j)のグリッドの頂点(i,j)を除いた範囲の(Aij)'-c(i'+j')の最小を求めた後に、答えを更新する
        //右辺の式が問題のコストの計算式に対応
        chmin(ans,a[i][j]+(i+j)*c+d[i][j]);
        //答えを更新した後に、頂点(i,j)を見ている範囲に追加する
        //右辺の式は(i,j)を駅の1点(線路の開始点)とした時の暫定のコスト(以下の式の(Aij)'-c(i'+j')に対応)
        chmin(d[i][j],a[i][j]-(i+j)*c);
      }
    }
    //aの上下を反転させる
    reverse(all(a));
  }
  cout << ans << endl;
  return 0;
}
//dp問題
//そもそも最小を求めたいコストの計算式はAij+(Aij)'+c*(i-i'+j-j')で
//移項すると(Aij+c(i+j))+((Aij)'-c(i'+j'))となり、右の括弧内の項(Aij)'-c(i'+j')をd[i][j]とする
//これを上のdpの遷移ではa[i][j]+c*(i+j)+d[i][j]とする
//この解法ではマンハッタン距離を頂点(0,0)からの距離として考えている
//(a-b間の距離を直接求めるのでなく、(0,0)-b間の距離から(0,0)-a間の距離を引いて求めている)
