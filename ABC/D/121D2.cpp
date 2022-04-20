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
//[0,a]のxorの計算をする関数
ll calc(ll a){
  //0^1=1,2^3=1,4^5=1のように0を含むa+1個の数字のxorを考える上で
  //二つずつxorを取ると全て1になる(下記の説明参照)
  //cnt1:xorを取ったら1になる隣接した数字の組み合わせの個数
  ll cnt1 = (a + 1) / 2;
  //1^1=0となるためxor=1の組み合わせの個数であるcnt1の偶奇が、
  //2つずつまとめたものの最終的なxorの値となる
  ll ans = cnt1 % 2;
  //aが偶数なら0から順に2つずつまとめたときにaが余ってしまうので
  //[0,a]のxorであるansが[0,a-1]の状態になっていることになるので
  //ansとaのxorを取ることで[0,a]のxorの形になる
  if(a % 2 == 0){
    ans ^= a;
  }
  //全桁について処理し終えたら[0,a]のxorの結果であるansを返す
  return ans;
}
int main(){
  ll a,b;
  cin >> a >> b;
  //下記の説明より交換法則を適用してans=b^(a-1)が成り立つのでそれを計算
  ll ans = calc(b) ^ calc(a - 1);
  cout << ans << endl;
  return 0;
}
//xor問題
//累積和と同様の思考で[a,b]のxorを計算するときに
//[0,a-1]=A,[0,b]=B,[a,b]=Cとすると
//問題文よりB=A^Cが自明に成り立つ
//xorは交換法則が成り立つので(算数の+,-,*,/と違い符号が逆転せずxorの形のまま移項される)
//C=A^Bとなる

//XORな問題で各桁ごとに独立に解くことができるという方向性を考えるのは定石

//下一桁だけ偶奇が変わる偶数から奇数への+1はその偶数と奇数のxorを取ると1になる
//(下一桁しか変わっていないため)よって[0,a]のxorは
