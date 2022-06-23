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
  //等差がマイナスなら変更処理
  if(d < 0){
    //等差がマイナスの時等差数列の初項が最大値でnが増えるごとに値が減っていく
    //最も小さい値である変更前の末項を変更後の初項として、等差を-1倍する
    //これにより等差が+の時と同様に処理できる
    a = a+d*(n-1);
    d = -d;
  }
  //二分探索のカーソル
  //st:初項の項番号,ed:末項の項番号
  ll st = 0;
  ll ed = n-1;
  //二分探索の実行(最終的にstがxに一番近い項の大きい方の項番号になり、
  //edがxに一番近い項の小さい方の項番号になる)
  while(st <= ed){
    //mid:等差数列[st,ed]の中間項
    ll mid = (st+ed)/2;
    //midが指す等差数列の項の値がx未満なら処理
    if((a+d*mid) < x){
      //初項の項番号を今見た項midの一つ左にしてmid以下の項をx未満の項とする
      st = mid + 1;
    }else {
      //midが指す等差数列の項の値がx以上なら処理
      //末項の項番号を今見た項midの一つ右にしてmid以上の項をx以上の項とする
      ed = mid - 1;
    }
  }
  //minを取るため最大初期化
  ll ans = LLONG_MAX;
  //だるかったら以下のようにst,edがxに近いところ付近にあるのでその周りでminを取れば良い
  /*for(ll i = max(0LL,st-3); i <= max(n-1,st+3); i++){
    ans = min(abs(a+d*i-x),ans);
  }*/
  //stが問題の等差数列の各項の項番号のどこかを指していたら処理
  if(0 <= st && st < n){
    ans = min(abs(a+d*st-x),ans);
  }
  //edが問題の等差数列の各項の項番号のどこかを指していたら処理
  if(0 <= ed && ed < n){
    ans = min(abs(a+d*ed-x),ans);
  }
  cout << ans << endl;
  return 0;
}
//等差数列の公式はf=a+(n-1)*dで、xに最も近いfとxとの差分を答える問題
//二分探索解法
//三分探索でも解けるらしい
