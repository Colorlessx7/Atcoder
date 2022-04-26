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
  //aの取りうる値の最大
  const ll MA = 1000000;
  vector<ll> a(n);
  //cnt[x]:a[i]=xとなるa[i]が何個入力されたかのカウンタ
  vector<ll> cnt(MA+1);
  rep(i,n){
    cin >> a[i];
    cnt[a[i]]++;
  }
  //ok[x]:(trueで初期化)
  vector<bool> ok(MA+1,true);
  rep2(x,MA){
    //そもそもa[i]として登場しているxにのみ処理を行う
    if(0 < cnt[x]){
      //a[i]=xとなるxが複数回入力されたなら
      //お互いがお互いを割り切れてしまうのでok[x]をfalseに
      if(1 < cnt[x]){
        ok[x] = false;
      }
      //xの倍数について処理(x2+=xで)
      //調和級数的計算量で計算できる(エラトステネスの篩の計算量解析と同じ)
      //rep2(i,N) for(j=i;j<=N;j+=i) というループ構造はO(NlogN)で行える
      for(ll x2 = x * 2; x2 <= MA; x2 += x){
        //x以外のxの倍数x2はxで割り切れるのでok[x2]をfalseに
        ok[x2] = false;
      }
    }
  }
  ll ans = 0;
  rep(i,n){
    //ok[a[i]]がtrueであるならば問題分の条件を満たすので答えに+1
    if(ok[a[i]]){
      ans++;
    }
  }
  //答えの出力
  cout << ans << endl;
  return 0;
}
//Aの制約がA<=10^6であることを生かして、調和級数的計算量で判定する問題
//判定しづらいので、約数ではなく倍数を使う事にする。
//最終的に以下の配列を作成する。
//ok[x] := A[i]=xである要素が性質を満たすか
//これが分かれば、ok[A[i]]=trueであるiの個数が答えになる。
//jを固定したときにダメなiというのは、A[j]の倍数であるA[i]となる。
//つまり、A[j]が存在すれば、A[j]2,A[j]3,...は全てダメなA[i]となる。
//よって、数を[1,106]の範囲でA[j]をチェックして、存在すれば、その倍数は全部ダメなA[i]とする。
//このように倍数に対して全探索するような処理は計算量的にはO(NlogN)であり、間に合う。
//注意点として、A[j]が存在するときに複数存在する場合はA[j]もダメなA[i]となるのが注意。
//なので、各数毎に個数を数えて利用していくのがいい
