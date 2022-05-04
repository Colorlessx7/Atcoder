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
using mint = modint998244353;
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
//問題の処理部分
void solve(){
  //入力部
  ll n;
  string s;
  cin >> n >> s;
  //長さnの回文は先頭n/2の切り上げ文字がわかれば一意に定まるとしてその先頭何文字かをlとする
  ll l = (n+1) / 2;
  //pw[i]:回文tのi桁目が文字列sのi桁目より確実に小さい文字を選んだ時に
  //自分で文字を決められる残りの桁(l-i桁)のとりうる文字のパターン数を係数として持つ
  //例:s=BBCABで自分で上3桁決められるとして、0桁目をAなどの確実に辞書順がt<=Sになる文字にした場合
  //のこりの2桁(1,2桁目)をA~Zで独立して決められるので26^2がpw[0]の値になる
  //同じ要領で1桁目をより小さい文字にすると残りの1桁が独立して決まるのでpw[1]=26
  //決められる桁の最後の桁はそれ以降の桁を決められないのでその最後の桁を決めたパターン数の
  //pw[2]=1として以降の係数作成はpw[l-1]=1を初期状態として26をかけ続けることで係数を作成する
  vector<mint> pw(l);
  //係数作成の初期状態
  pw[l-1] = 1;
  //係数作成(26をかけるだけ)
  rep4(i,l-1){
    pw[i-1] = pw[i]*26;
  }
  //辞書順でt≤Sかつ長さがnの回文tの数
  mint ans;
  //自動的に条件を満たす回文(自分で決められるl桁をsと全く同じにしたもの以外)の個数をカウント
  //s=ABCZAZの時の回文の上3桁はAAA~AAZ,ABA~ABCでABCを除いたものを計上する
  //例の場合0桁目は自動的にAに確定するため以降の2桁を適当に決められず(0*26^2)
  //1桁目はAにした場合のみ2桁目をA~Zにできて(1*26)
  //2桁目は最初の2桁をABとするとAorBしか条件を確実に満たさないので(2*1)
  rep(i,l){
    //x:sのi桁目より小さいアルファベットの個数
    ll x = s[i] - 'A';
    //例:0*26^2+1*26+2*1=28
    ans += pw[i]*x;
  }
  //回文の先頭l文字をsと全く同じ文字で作った場合(s=ABCAB,t=ABCBAの場合)
  //その回文が辞書順でt<=Sかどうかを判定する
  //回文の先頭l文字をsと全く同じ文字で作る処理(例の場合t=AB)
  string t = s.substr(0,n-l);
  //(例の場合t=BA)
  reverse(all(t));
  //(例の場合t=ABC+BA=ABCBA)
  t = s.substr(0,l)+t;
  //回文tが辞書順でt<=Sなら答えに+1
  if(t <= s){
    ans++;
  }
  //出力
  cout << ans.val() << endl;
}
int main(){
  ll t;
  cin >> t;
  rep(qi,t){
    solve();
  }
  return 0;
}
