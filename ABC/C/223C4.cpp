#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define replr(i,l,r) for(int i = l; i < r; i++)
#define reprl(i,l,r) for(int i = l; i >= r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
#define sz(v) (int)v.size()
using ll = long long;
using P = pair<int,int>;
using TP = tuple<int,int,int>;
template<typename Tx, typename Ty>Tx dup(Tx x, Ty y){return (x+y-1)/y;}
void chmin(int &x, int y){ x = min(x,y); }
void chmax(int &x, int y){ x = max(x,y); }
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  int n;
  cin >> n;
  vector<double> a(n),b(n);
  rep(i,n){
    cin >> a[i] >> b[i];
  }
  //導火線を左右両方から進めて考える
  //li:左の火が何番目の導火線に今いるか,ri:右の火が何番目の導火線に今いるか
  int li = 0, ri = n-1;
  //lx:左の火について導火線の切れ目(左端)から何cmのところに今いるか
  //rx:右の火について導火線の切れ目(右端)から何cmのところに今いるか
  //(導火線の変わり目まで火がたどり着いたら0になる)
  double lx = 0, rx = 0;
  //答え(何cmの地点で火がぶつかるか)
  double ans = 0;
  //シミュレーション(導火線の左右の火が同じ導火線上にたどり着くまで回す)
  while(li < ri){
    //lt:左の火について今いる導火線の火の位置lxから
    //導火線の切れ目(導火線の右端)にたどり着くまでかかる時間
    //li:今いる導火線のid,a[li]-lx:導火線の火が右端に辿り着くまでの残りの距離
    //時間は道のり/速さで求まる
    double lt = (a[li]-lx)/b[li];
    //rt:右の火について今いる導火線の火の位置rxから
    //導火線の切れ目(導火線の左端)にたどり着くまでかかる時間
    //計算式は上と同様
    double rt = (a[ri]-rx)/b[ri];
    //左の火が右の火より先に導火線の切れ目にたどり着くパターンについて処理
    if(lt < rt){
      //答えに火が燃え進んだ距離を加算する(シミュレーションは左右の火を同じ時間分だけ進める)
      //a[li]-lxでもb[li]*ltでもどっちでも良い
      //a[li]-lx:全体a[li]からすでに進んだ距離lxを引いたものが燃え進んだ距離
      //b[li]*lt:速さb[li]*燃え進む時間ltで燃え進んだ距離
      ans += b[li]*lt;
      //左の火が次の導火線の開始位置に辿り着いたので導火線の切れ目からの距離lxを0にする
      lx = 0;
      //逆側の火も左側と同じように火を進める
      //右の導火線の開始地点からすでに進んだ距離rxに、火が燃え進んだ距離を加算
      //燃え進んだ距離は導火線riの燃える速さb[ri]*燃え進んだ時間lt
      rx += b[ri]*lt;
      //左の火が次の導火線に移ったので導火線のidを+1
      li++;
    }else {
      //それ以外のパターン(同着or右が早い)は上の反対にrについて処理する
      ans += b[li]*rt;
      rx = 0;
      //同着の場合はここでlx=a[li]になるが次のwhileでlt=0になって
      //距離が進まず、導火線が次のものに更新される処理が行われる
      lx += b[li]*rt;
      ri--;
    }
  }
  //liとriが同じ導火線にたどり着いた時の処理
  //その導火線の全体a[li]から左右の火のすでに進んでしまった距離lx,rxを引いたものが
  //左右の火が辿る残りの距離でそれを2で割ると左側の火が辿る残りの距離となる。それを加算する
  ans += (a[li]-lx-rx)/2;
  printf("%.10f\n",ans);
  return 0;
}
//シミュレーション解法
