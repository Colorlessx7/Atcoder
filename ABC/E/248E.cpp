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
  //入力部
  //n:点の個数,k:カウントする線の条件(何個点を通らないといけないか)
  ll n, k;
  cin >> n >> k;
  //各点の座標を入力(x,y)
  vector<ll> x(n),y(n);
  rep(i,n){
    cin >> x[i] >> y[i];
  }
  //1点を通る直線は傾きを変えて無限に作れるのでInfinityを出力し終了
  if(k == 1){
    cout << "Infinity" << endl;
    return 0;
  }
  //直線を判別するための傾きのパラメータa,bとy切片の値cが同じものを計上するためのカウンタ
  map<tuple<ll,ll,ll>,ll> cnt;
  //2点を通る直線について処理(被らない2点をそれぞれ(xi,yi),(xj,yj)としてループ)
  rep(i,n){
    rep(j,i){
      //2点を通る直線の傾きを計算(分数として計算するのではなく)
      //a:x座標の変化分について計算,b:y座標の変化分について計算
      ll a = x[i] - x[j];
      ll b = y[i] - y[j];
      //aが負になる場合はa,bにそれぞれ-1をかけて分母が必ず正になるようにする
      if(a < 0){
        a = -a; b = -b;
      }
      //x座標の変化分が0なら直線はy座標に平行な縦1直線のような形になるので例外処理をする
      if(a == 0){
        b = 1;
      }else {
        //傾きが(4/2)と(2/1)の直線があったとして、約分すれば傾きは等しくなるため
        //全ての2点間の直線の傾きが既約分数の形になるように調整
        //分子bと分母aの最大公約数が約分するときに割る数となるので計算し、a,bからそれを割る
        ll g = gcd(a,b);
        a /= g; b /= g;
      }
      //c:直線のy切片に対応
      //傾き＝fで(p,q)を通る直線の式はy=f(x-p)+qとなり、
      //今回の条件ではf=b/aで(p,q)は(0,q)で切片を求めるためにqを求めるよう式変形すると
      //y=(b/a)*(x-0)+q , y=(b/a)*x+q , q=y-(b/a)*x , aq=ay-bxとなり、
      //cは切片をaで割ったものに対応する
      //(aq=c,傾きが違うならaが変わり、y切片が違うならqが変わるので同じ直線ならcを使えば判定できる)
      ll c = a * y[i] - b * x[i];
      //今見た直線の種類をmapに計上
      cnt[{a,b,c}]++;
    }
  }
  //k個点を通る直線の本数を計算
  ll ans = 0;
  //全ての直線の種類について検証する
  for(auto p : cnt){
    //右辺はkC2を式変形したもの
    //2点間の直線を調べたときにkC2回以上登場したのなら
    //その直線上に点がk点以上存在するため答えを+1
    if(p.second >= k*(k-1)/2){
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
