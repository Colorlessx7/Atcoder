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
void chmin(int &x, int y){ x = min(x,y); }
void chmax(int &x, int y){ x = max(x,y); }
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  //数列の数字の個数
  int n;
  cin >> n;
  //個数分布を配列に格納
  vector<int> c(200001);
  //数列Aの最大値を格納
  int m = 0;
  //数列の入力
  rep(i,n){
    //Ai
    int a;
    cin >> a;
    chmax(m,a);
    //aの個数をカウント
    c[a]++;
  }
  //dp[i][j]:数字iまでからj個選び、大きい順にAi,Aj,Ak(j=0~3個)とした時に
  //問題文の条件を満たす組み合わせの個数(iはdpからnxの遷移で行う)
  vector<ll> dp(4);
  //0個から1個も選ばないというパターンは1通りなのでdp[0][0]だけ1初期化
  dp[0] = 1;
  //dpの遷移と更新
  //数字を0~200000まで回す
  for(int f : c){
    //dpの遷移先
    vector<ll> nx(4);
    //集合の個数について処理
    rep(i,4){
      //集合にc[x]=fとなる数字xを追加する遷移
      //x未満の数字でi個選んだ時の場合の数にxの個数fをかけたものを加算
      nx[i+1] += dp[i] * f;
      //集合にxを含めない時の場合の数の遷移
      nx[i] += dp[i];
    }
    //遷移先だったnxを遷移元として遷移をさせる
    dp = nx;
  }
  //m種類のAの中から3個選び、大きい順にAi,Aj,Ak(j=0~3個)とした時に
  //問題文の条件を満たす組み合わせの個数を出力
  cout << dp[3] << endl;
  return 0;
}
//dp問題
