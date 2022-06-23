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
using ll = long long;
using P = pair<int,int>;
using TP = tuple<int,int,int>;
void chmin(int &x, int y){ x = min(x,y); }
void chmax(int &x, int y){ x = max(x,y); }
int main(){
  //x:初期値,a:初項,d:等差,n:項数
  ll x,a,d,n;
  cin >> x >> a >> d >> n;
  //等差が0なら等差数列の全要素はaで固定なのでaとxの差分が答えになる
  if(d == 0){
    cout << abs(a-x) << endl;
    return 0;
  }
  //等差がマイナスなら等差数列の反転処理
  if(d < 0){
    //等差がマイナスの時等差数列の初項が最大値でnが増えるごとに値が減っていく
    //最も小さい値である変更前の末項を変更後の初項として、等差を-1倍する
    //これにより等差が+の時と同様に処理できる
    a = a+d*(n-1);
    d = -d;
  }
  //等差数列の何項目がxに最も近いかを計算(等差数列の範囲内は0~n-1で、計算結果が範囲外になる可能性がある)
  ll i = (x-a)/d;
  //等差数列の何項目が最もxと近いか判定する関数
  auto f = [&](ll i){
    //iが0未満なら範囲外で、xに一番近いのは等差数列の初項となる
    if(i < 0){
      //0項目が一番近いので0に
      i = 0;
    }
    //iがn以上なら範囲外で、xに一番近いのは等差数列の末項となる
    if(i >= n){
      //n-1項目が一番近いのでn-1に
      i = n-1;
    }
    //等差数列の最も近い項の値を計算し返す
    return a+d*i;
  };
  //xと隣接する項一つ目(小さい方)との差分を計算しansに格納
  ll ans = abs(f(i)-x);
  //xと隣接する項二つ目(大きい方)との差分を計算し最小ならansに格納
  ans = min(ans,abs(f(i+1)-x));
  cout << ans << endl;
  return 0;
}
//等差数列の公式はf=a+(n-1)*dで、xに最も近いfとxとの差分を答える問題
//a=2,d=3,n=3の時、a={2,5,8}となる
//iの計算についてだが、x=2の時、(2-2)/3=0,x=5の時、(5-2)/3=1となる
//xに最も近いfの何項目かがiだが、上の例におけるx=3,4の時など差分が0でないときは
//iはxに隣接する項のうち小さい方の項を示すので、もう片方の隣接する項との差分を調べるときはiを+1する
