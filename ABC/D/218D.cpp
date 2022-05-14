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
  //n:頂点数
  ll n;
  cin >> n;
  //x,y:各頂点の座標
  vector<ll> x(n),y(n);
  //st:ある頂点が存在するかを判定するset
  //順番が関係ないのでunorderedsetなら少し早くなるかも
  set<P> st;
  //座標の入力とsetへの格納
  rep(i,n){
    cin >> x[i] >> y[i];
    //setに各座標を格納し、対角線が決まった場合の残りの座標が
    //存在するかの判定に使う
    st.emplace(x[i],y[i]);
  }
  //x,y軸共に並行な四角形の個数
  ll ans = 0;
  //全頂点から2つ頂点を選び、条件を満たすならそれを対角線として扱う
  rep(i,n){
    rep(j,n){
      //四角形を構成する座標4つはそれぞれ(xi,yi),(xj,yj),(xj,yi),(xi,yj)
      //今後配列のアクセスを減らすために事前に値を用意しておく
      //x1とかx2とかにするとstlかなんかの予約語と衝突するので回避
      ll xi = x[i],xj = x[j];
      ll yi = y[i],yj = y[j];
      //四角形の座標が(xi,yi)を左下、(xj,yj)を右上とするものだけを判定に使用する(重複回避)
      if(xi < xj && yi < yj){
        //setに(x1,y2)が存在しないならコンティニュー(O(logN))
        //==st.endなのは存在しない場合イテレータがst.endの場所に向かうため
        if(st.find(P(xi,yj)) == st.end()){
          continue;
        }
        //setに(x2,y1)が存在しないならコンティニュー
        if(st.find(P(xj,yi)) == st.end()){
          continue;
        }
        //対角線以外の座標が両方存在するので+1
        ans++;
      }
    }
  }
  //出力部
  cout << ans << endl;
  return 0;
}
//0(N^2*logN)の解法
//問題の都合上対角線の座標2つ(x1,y1),(x2,y2)が決まると
//長方形ができる場合の残りの座標の位置が(x1,y2),(x2,y1)に確定する
//よって2重ループで二つ座標を決めちゃってそれに対応する残りの座標が両方とも
//存在するのなら答えを+1する
