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
  //非負整数の個数
  int n;
  //xor対象のXの最大値
  ll k;
  cin >> n >> k;
  //非負整数n個を格納
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }
  const ll INF = 1e18;
  //桁dp
  //dp[digit][isless]:上位ビットdigit個を確定させた時の
  //isless=0:上位ビットdigit個がkと一致する
  //isless=1:上位ビットdigit個の時点でk未満が確定する
  //場合のf(X)の最大値
  //2^40がKの制約の10^12より大きいので桁数は40桁分見れば良い
  vector<vector<ll>> dp(41,vector<ll>(2,-INF));
  dp[0][0] = 0;
  //桁数について回す
  rep(digit,40){
    //Xの2パターンについて回す
    rep(isless,2){
      //-INFはあり得ない状態なのでそこからの遷移は行わない
      if(0 <= dp[digit][isless]){
        //Kの制約よりXのとりうる値は2^40以下で、上の位からXを決めていくとすると
        //二進数(bit)で考えるとXの桁の番号は左から39,38...1,0桁目となる
        //Xを左の桁から順に決める時の桁数がdに対応する
        int d = 39 - digit;
        //下からd桁目(上からdigit桁目)(d:0indexed)だけbitが立っている数字(マスクビット)
        ll msk = 1LL << d;
        //zero:各非負整数Ai(2進数)の上からdigit桁目
        //(digit:0indexed)のbitが0のものの個数
        int zero = 0;
        //one:各非負整数Ai(2進数)の上からdigit桁目
        //(digit:0indexed)のbitが1のものの個数
        int one = 0;
        //各Aiの上からdigit桁目のbit(1,0)それぞれの個数をカウントするループ
        //全非負整数について回す
        rep(i,n){
          //非負整数a[i]と上からd桁目(d:0indexed)だけbitが立っている値の
          //ANDを取った結果が0でない場合の処理
          //(a[i]=5でmsk=4(digit=37,d=2)の時a[i]&mskは101&100となって
          //100で4となり条件式はtrueとなる
          //a[i]=3,msk=4なら011&100=000で0となり条件式はfalseとなる)
          if(a[i] & msk){
            //a[i]の上からdigit桁目が1だったので1の個数を+1
            one++;
          }else {
            //a[i]の上からdigit桁目が0だったので0の個数を+1
            zero++;
          }
        }
        //Xのdigit桁目を0とする場合の遷移
        //isless2:Xのdigit桁目を0とした場合にXがkになるかk未満になるかの2値信号
        int isless2 = isless;
        //kの上からdigit桁目が1の時、Xのdigit桁目を0とするとXがk未満であることが
        //確定するのでk未満に遷移させるためisless2を1にする
        if(k & msk){
          isless2 = 1;
        }
        //Xのdigit桁目を0とする場合f(X)=Sum(X^Ai)なので
        //xorの性質上Aiのdigit桁目が1であるiの数*桁の倍率分だけ
        //digit桁目まで考えた時のf(X)の最大値が上昇する
        //(例k=101,Ai={001,110,011}の時左の先頭のbitについて考えると
        //one=1,zero=2でf(X=0??)はf(X)=Sum(X^Ai)より
        //f(0??)=(0??^0__)+(0??^1__)+(0??^0__)=0*4+1*4+0*4=(1)*4=4となる)
        chmax(dp[digit+1][isless2],dp[digit][isless]+one*msk);
        //Xのdigit桁目を1にする場合の遷移
        //・kの上からdigit桁目が1(islessが0でkの上からdigit桁目が0の場合
        //Xのその桁を1にするとXはk以下という条件を満たせなくなるため)
        //・すでにXがk未満 のどちらかを満たす場合に処理(すでにk未満なのでこの桁に
        //0が入っても1が入っても問題ないため)
        if((k & msk) || isless == 1){
          //Xのdigit桁目を1とする場合f(X)=Sum(X^Ai)なので
          //xorの性質上Aiのdigit桁目が0であるiの数*桁の倍率分だけ
          //digit桁目まで考えた時のf(X)の最大値が上昇する
          //(例k=101,Ai={001,110,011}の時左の先頭のbitについて考えると
          //one=1,zero=2でf(X=1??)はf(X)=Sum(X^Ai)より
          //f(1??)=(1??^0__)+(1??^1__)+(1??^0__)=1*4+0*4+1*4=(2)*4=8となる)
          //この条件だとdp[38][0]=8,dp[38][1]=4となる
          chmax(dp[digit+1][isless],dp[digit][isless]+zero*msk);
        }
      }
    }
  }
  //dp[40][0]:Xの上から40桁を決め切った時のXが丁度kになるパターン(1種)のf(X)の最大値
  //dp[40][1]:Xの上から40桁を決め切った時のXがk未満になるパターンのf(X)の最大値
  //これらのmaxが答えるべきf(X)の最大値となる
  cout << max(dp[40][0],dp[40][1]) << endl;
  return 0;
}
//桁dp問題
