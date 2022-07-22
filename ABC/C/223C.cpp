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
  //t:導火線に左端だけ火をつけた時に火が燃え進み右端に辿り着くまでの時間を計算
  double t = 0;
  rep(i,n){
    //時間=道のり/速さ
    t += a[i]/b[i];
  }
  //2で割ることにより左右に火をつけた時に火がぶつかる時間を計算
  //以降は導火線iの開始位置からぶつかる位置に到達するまでにかかる時間として処理
  t /= 2;
  //左端からぶつかる点までの距離
  double ans = 0;
  //全導火線について処理
  //O(N)
  rep(i,n){
    //導火線iが燃え尽きるまでにかかる時間
    double nt = a[i] / b[i];
    //導火線iの開始位置から火がぶつかる位置に到達するまでの時間tより
    //導火線iが燃え尽きるまでにかかる時間ntの方が大きい場合に処理
    //導火線iで火がぶつかる
    if(nt > t){
      //火がぶつかる導火線iの燃える速度b[i]*ぶつかるまでにかかる時間tが
      //導火線iの左端からぶつかる地点までの距離となるのでansに加算
      ans += b[i] * t;
      //火がぶつかったのでbreakで処理を終了
      break;
    }
    //両端の火がぶつかる導火線がi番目の導火線ではなかった場合に処理
    //導火線iは全部燃えるので、左端から火がぶつかる位置までの長さansに
    //導火線iの長さa[i]を加算
    ans += a[i];
    //導火線i+1の開始位置から火がぶつかる位置に火が辿り着くまでの時間tから
    //導火線iが燃え尽きる時間ntを引く
    t -= nt;
  }
  printf("%.10f\n",ans);
  return 0;
}
//導火線がぶつかるまでの半分全探索
