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
using mint = modint998244353;
void chmin(int &x, int y){ x = min(x,y); }
void chmax(int &x, int y){ x = max(x,y); }
int main(){
  //n:数列の項数,m:数列の最大値の条件,k:数列の隣接する数字の絶対値の条件
  int n, m, k;
  cin >> n >> m >> k;
  //特殊ケース
  if(k == 0){
    //答えはm^nとなる
    //aclのmodintはx.pow(n)でmodを加味した指数計算ができる(xがmintでキャストされる必要がある)
    mint ans = mint(m).pow(n);
    cout << ans.val() << endl;
    return 0;
  }
  //dp([i])[j]をAの先頭からi項を決めて、i項目がjであるような場合の数とする
  //iはpからdpへの遷移として扱い、省略する
  //(最初の1桁は1~mまでの選び方1通りずつなので1で初期化)
  vector<mint> dp(m,1);
  //dpの遷移処理
  for(int i = 1; i < n; i++){
    //pからdpへの遷移を考える
    //dp,pは1indexedのもの(j=1~m)を0indexed(j=0~m-1)で扱っている
    vector<mint> p(m);
    //swapし、pが旧、dpが新とする
    swap(dp,p);
    //遷移を高速化するための累積和配列(s[j]で1~jまでの総和)
    vector<mint> s(m+1);
    //累積和配列の設定
    rep(j,m){
      s[j+1] = s[j] + p[j];
    }
    //以下の計算でsum(0,j-k)の場合は左からmax(0,r+1-l)項の和を
    //sum(j+k,m-1)の場合は右からmax(0,r+1-l)項の和を求める関数
    auto sum = [&](int l, int r) -> mint {
      //1>j-k(左),j+k>m(右)の時0を返す
      //(見ている側に上の見ている側の方の条件に合う数字が存在しないため)
      if(l > r){
        return 0;
      }
      //s[r+1]:左r+1項の総和でs[l]:左l項の総和になる
      //よって以下の式で[l+1,r+1]の範囲の総和が求まる
      return s[r+1] - s[l];
    };
    //dpテーブルの更新
    rep(j,m){
      //sum(0,j-k):dp[1]+…+dp[j−K]の部分
      //sum(j+k, m-1):dp[j+K]+…+dp[M]の部分
      dp[j] = sum(0,j-k) + sum(j+k, m-1);
    }
  }
  //問題の条件を満たす場合の数
  mint ans = 0;
  //最後の遷移後のdp[1]~dp[m]の総和が答えになる
  rep(i,m){
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

// 0 1 2 3  4  5   (pのindex)
// 1 2 3 4  5  6   (pのi項目にとりうる値)
//0 1 3 6 10 15 21 (sの値)
//0 1 2 3  4  5  6 (sのindex)
//
