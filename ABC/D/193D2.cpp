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
//ポーカーの手札(最後の1文字をちゃんと数字にしたもの)からその点数を求める関数
ll f(string s){
  //a[i]:ポーカーの手札の数字iの登場頻度を格納
  vector<ll> a(10);
  //aに数字の頻度を格納する処理
  for(char c : s){
    a[c-'0']++;
  }
  //ポーカーの手札の点数
  ll res = 0;
  //スコア計算処理
  replr(i,1,10){
    //x:係数(手札に登場する数字をi,その枚数をpとすると数字毎の得点はi*10^pとなる(x=1でp=0の状態))
    ll x = 1;
    //a[i]回10を係数にかけることでx=10^a[i]になる
    rep(j,a[i]){
      x *= 10;
    }
    //この処理でi*10^a[i]になったのでそれを点数に加算する
    res += x*i;
  }
  //ポーカーの手札の点数を返す
  return res;
}
int main(){
  ll k;
  string s, t;
  cin >> k >> s >> t;
  //c[i]:山札に残っている数字iの数になる(そのため最大のkで初期化)
  vector<ll> c(10,k);
  //0の書かれたカードは存在しないので0に
  c[0] = 0;
  //ポーカーのすでに開示されている手札4*2枚を残っている数字の数からひく
  rep(i,4){
    c[s[i]-'0']--;
    c[t[i]-'0']--;
  }
  //cnt:高橋がかつ配られ方のパターン数,tot:全ての5枚目の配られ方についてのパターン数
  ll cnt = 0, tot = 0;
  //確率を計算する処理
  //a:高橋が選ぶ数字1~9について回す
  replr(a,1,10){
    //高橋の最後の手札をセット
    s[4] = '0' + a;
    //ca:高橋が山札から数字aをとるパターン数
    ll ca = c[a];
    //高橋が山札から数字aを取ったので残りの数を-1する
    c[a]--;
    //b:青木が選ぶ数字1~9について回す
    replr(b,1,10){
      //青木の最後の手札をセット
      t[4] = '0' + b;
      //c[b]:青木が山札から数字bをとるパターン数
      //ca*c[b]でa,bの取り方のパターン数が求まる
      //あり得ない事象についてはcaかc[b]のどちらかが0になるためnow=0となる
      ll now = ca*c[b];
      //全事象にa,bを選択するパターン数nowを加算
      tot += now;
      //高橋の点数が青木の点数より大きい場合に処理
      if(f(s) > f(t)){
        //高橋が勝つパターンにa,bを選んだ時のパターン数nowを加算
        cnt += now;
      }
    }
    //処理のため1引いたのを戻す
    c[a]++;
  }
  //確率=場合の数/全事象(doubleでキャストする)
  double ans = (double)cnt/tot;
  printf("%.10f\n",ans);
  return 0;
}
//確率計算問題
//確率=場合の数/全事象
//山札の残りの枚数をsとすると全事象はs*(s-1)
//場合の数は数字aをとるパターン数*数字bをとるパターン数となる
