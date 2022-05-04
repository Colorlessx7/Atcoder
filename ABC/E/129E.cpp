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
using mint = modint1000000007;
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
//dp[i][j]:a+bの値を上位i桁目まで確定させた時の
//j=0:a+bの値を二進数表記した時のi桁目まで全てがsと一致
//j=1:a+bの値を二進数表記した時のi桁目の時点でs未満であることが既に確定 
//しているa,bの組の個数
vector<vector<mint>> dp(100005,vector<mint>(2));
int main(){
  string s;
  cin >> s;
  //dpの初期化
  dp[0][0] = 1;
  //n:文字列も長さ(桁数)
  ll n = s.size();
  //各桁についてdp処理
  rep(i,n){
    { //s[i]=0でa[i]+b[i]=0(a,bのi桁目のどちらも0)の時の処理
      //この場合はa+b=sのものはそのままa+b=sとなり
      //a+bがs未満のものもそのままa+bがs未満となるため引き継ぐ形の処理をする
      if(s[i] == '0'){
        dp[i+1][0] += dp[i][0];
        dp[i+1][1] += dp[i][1];
      }else {
        //s[i]=1でa[i]+b[i]=0(a[i]=b[i]=0)の時の処理
        //a[i]とb[i]を0にすると自動的にa+bはs以下になる
        //よって既に見つかったパターン数dp[i][0],dp[i][1]をdp[i+1][1]に足し合わせる
        dp[i+1][1] += dp[i][0];
        dp[i+1][1] += dp[i][1];
      }
    }
    { //s[i]=0でa[i]+b[i]=1(a,bのi桁目のどちらかが1,どちらかが0)の時の処理
      //以降の*2は全てa[i]を1にするかb[i]を1にするかの2択だから2倍したものを遷移させる
      //これまでのi桁が全て一致している場合、a,bのi桁目のどちらかを1にするとa+bがsを
      //超えてしまうのでdp[i][0]から遷移できない
      //既にs未満が確定しているdp[i][1]のパターンについてはa,bのi桁目のどちらかを1にできる
      //ため遷移させることができる
      if(s[i] == '0'){
        dp[i+1][1] += dp[i][1] * 2;
      }else {
        //s[i]=1でa[i]+b[i]=1(a,bのi桁目のどちらかが1,どちらかが0)の時の処理
        //i桁目まで全てが一致している場合(a+b=s)はそのままa+b=sとなり、
        //既にa+bがs未満の場合もそのままa+bがs未満となるため引き継ぐような形の遷移をする
        dp[i+1][0] += dp[i][0] * 2;
        dp[i+1][1] += dp[i][1] * 2;
      }
    }
  }
  //dpの遷移は最後にnまで遷移する
  //dp[n][0]がa+b=sとなる条件を満たすa,bの組み合わせで
  //dp[n][1]がa+b<sとなる条件を満たすa,bの組み合わせなので
  //問題文の条件を満たす組み合わせはa+b<=sとなる上2つの合計となる
  mint ans = dp[n][0] + dp[n][1];
  cout << ans.val() << endl;
  return 0;
}
//桁dpで解く問題(今回の場合大小関係に注目しているタイプの問題となる)
//a+b<=L,a^b=a+bの二式を満たす(a,b)の組み合わせを数え上げる問題で
//a+bをa^bを使った式で表すと、a+b=a^b+(a&b)*2と表すことができる
//(xorは繰り上がりのない足し算であり(a^b)、繰り上がりが発生する部分はaとbの同じ桁が
//どちらも1の時であり、繰り上がりで1がたされる桁はa,bが共に1だった桁の1つ左の桁となるため
//(a&b)が１ビット左シフトされたもの、つまり(a&b)*2がxorに足されたものがa+bとなる)
//２番目の条件式から(a&b)*2=0,で係数を無視して
//a+b<=Lかつa&b=0となる(a,b)の組み合わせを数え上げる問題に変わる
//dpの遷移はL=101とした時に最初a+b=???として?に問題文の条件が合うように0,1を入れることを繰り返す
//
