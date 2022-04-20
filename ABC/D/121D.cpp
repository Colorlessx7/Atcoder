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
  if(a <= 0){
    return 0;
  }
  //4の時に、0,1,2,3,4までになるので、これは5つの整数まで
	//なので帳尻合わせで１足す。
  a++;
  //10^12 <= 2進数40桁くらい
  ll ans = 0;
  //i桁目の偶奇を調べる
  //区間[0,a]を2進数に変換した時の各桁について1が奇数回or偶数回出てくるかを判定する
  rep(i,50){
    //loop:xor後ではなくxor前の[0,a]の各桁の0,1が変わる周期を計算する
    //0桁目 → 周期2
		//1				4
		//2				8
    ll loop = (1LL << (i+1));
    //a/loopが区間に何回周期が訪れるか
    //loop/2が1周期に1がi桁目に出てくる回数
    ll cnt = (a / loop) * (loop / 2);
    //区間の周期ピッタリとしてして扱えなかった区間の余りの部分について
    //i桁目の1が出てくる回数を追加
    //余りの部分の0,1は00000.....0011111.....11の順に出てくるため
    //a%loopが周期から溢れた区間の数の個数でそれから1周期にi桁目に0が出てくる回数loop/2
    //を引くと周期から溢れた区間の数のi桁目に1が出てくる回数を求めることができる
    //0とのmaxをとっているのは周期から溢れた部分のi桁目が0のみで1が出てこない場合
    //計算結果がマイナスになってしまい、欲しいのは1の個数なので0とのmaxを取るようにしている
    cnt += max(0LL,(a % loop) - (loop / 2));
    //その桁の1の数が奇数だったらi桁目のxor結果が1になるので
    //ここでansのi桁目が1になるように区間[0,a]のxorの答えに2^iを足す
    if(cnt % 2 == 1){
      ans += 1LL << i;
    }
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
