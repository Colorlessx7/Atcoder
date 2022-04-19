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
  ll n, k, x;
  cin >> n >> k >> x;
  vector<ll> a(n);
  //クーポン未使用時の必要金額
  ll sum = 0;
  //x円カットできるクーポンの回数
  ll ex = 0;
  rep(i,n){
    cin >> a[i];
    //合計に入力を足す
    sum += a[i];
    //入力をxで割った値がx円しっかり値段をカットできるクーポンの枚数になるのでそれを足す
    ex += a[i] / x;
    //クーポンでx円ちょうど値段をカットできる回数使い切った後の必要金額にしておく
    a[i] %= x;
  }
  //最終的な必要金額
  ll ans = 0;
  //クーポンをx円ちょうど値段をカットできない対象に使う場合は
  //値段の高い方からクーポンを使いたいので(貪欲法)値段を降順にしておく
  sort(allr(a));
  //クーポンでx円ちょうど値下げできる分しかクーポンがない場合の処理
  if(k <= ex){
    //クーポンなしの場合の金額からクーポンの枚数n*クーポンの値下げ金額xを
    //掛けたものを引いたものが最終的な金額となる
    ans = sum - k * x;
  }else {
    //x円ちょうど値下げできるクーポンを使い切ったものとして
    //考えるためにexを元のクーポンの数kからひく
    k -= ex;
    //配列外参照回避のために配列サイズと残りのクーポン数のminをとる
    //nを超えたクーポンを所持しているならここでnとなりansは最終的に0となる
    k = min(k,n);
    //クーポンを使う処理(この時点でa配列の値はx未満なのでクーポンを使うと0円になる)
    rep(i,k){
      a[i] = 0;
    }
    //クーポンを使って0円にした後のa配列の値の合計が最終的な必要金額となる
    rep(i,n){
      ans += a[i];
    }
  }
  cout << ans << endl;
  return 0;
}

