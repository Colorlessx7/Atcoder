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
//二項演算(mintの足し算)
mint op(mint a, mint b){
  return a + b;
}
//単位元(0初期化)
mint e(){
  return 0;
}
int main(){
  //n:数列の項数,m:数列の最大値の条件,k:数列の隣接する数字の絶対値の条件
  ll n, m, k;
  cin >> n >> m >> k;
  //dp[i][j]をAの先頭からi項を決めて、i項目がjであるような場合の数とする
  vector<mint> dp(m+1);
  //遷移高速化のためのsegtree(区間和の高速化,1<<13 > M=5000)
  //(1~m以外の場所は0から変化しない)
  segtree<mint,op,e> fw(1<<13);
  //数列1項の数字の取り方は1~mまで1パターンずつなので
  //segtreeのfw[i](i=1~m)を1で初期化
  rep2(i,m){
    fw.set(i,1);
  }
  //dpの遷移部分(初期状態fwから一遷移でdp,fwを繰り返す)
  rep(i,n-1){
    rep2(j,m){
      //kが0でないなら処理
      if(k != 0){
        //prod(l,r)は[l,r)の範囲の合計を返す
        //遷移はdp[i+1][j]=(dp[i][1]+…+dp[i][j−K])+(dp[i][j+K]+…+dp[i][M])
        //dp[i][1]+…+dp[i][j−K]の部分(1>j-kの時はrが0+1=1となり、
        //segtreeの二項演算の範囲が0になり、ここでdp[j]=0となる)
        dp[j] = fw.prod(0LL,max(0LL,j-k)+1);
        //dp[i][j+K]+…+dp[i][M]の部分(j+k>mの時はlがm+1となり、
        //segtreeの二項演算の範囲が0になり、dp[j]に何も加算されない)
        dp[j] += fw.prod(min(j+k,m+1),m+1);
        //kが0なら処理(WApoint)
      }else {
        //数列の隣接する数字の絶対値が関係ない場合は1~mから適当に選ぶだけなので
        //Aのi項目がjであるような場合の数はi-1項目が1~mであるような場合の数の総数になる
        //よってsegtreeの1~mの総和がdpの1~mの値になる
        dp[j] = fw.all_prod();
      }
    }
    //segtreeの1~mをdpの1~mの値に変更し、次の遷移の準備をする
    rep2(j,m){
      fw.set(j,dp[j]);
    }
  }
  //問題の条件を満たす場合の数
  mint ans = 0;
  //最後の遷移後のdp[1]~dp[m]の総和が答えになる
  rep2(i,m){
    ans += dp[i];
  }
  cout << ans.val() << endl;
  return 0;
}
//dp問題
//dp[i][j]をAの先頭からi項を決めて、i項目がjであるような場合の数とする
//遷移はdp[i+1][j]=(dp[i][1]+…+dp[i][j−K])+(dp[i][j+K]+…+dp[i][M])
//なお、1>j−K のときやj+K>M のとき、K=0 のときは微妙に遷移が異なるので注意
//このdpでは状態数がO(NM)、遷移がO(M)となり、全体の計算量はO(NM^2)となりTLEする
//ここで、dp[i+1]への遷移を考える際に事前にdp[i]の累積和を求めておくことで、
//遷移がO(1)で可能になり、全体の計算量がO(NM)になり間に合う
//この解法は本番中に累積和が浮かばずsegtreeで高速化したver O(NMlogM)
