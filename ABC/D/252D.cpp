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
  //数列の数字の個数
  int n;
  cin >> n;
  //key:Aiの数字,value:keyの数字の頻度
  map<int,int> cnt;
  //数列の入力
  rep(i,n){
    //Ai
    int a;
    cin >> a;
    //aの個数をカウント
    cnt[a]++;
  }
  //個数分布を配列に格納
  vector<int> c;
  //dpのため個数分布を配列に格納
  for(auto p : cnt){
    c.push_back(p.second);
  }
  //m:数列Aに登場した数字の種類数
  int m = c.size();
  //dp[i][j]:i種類のAの中からj個選び、大きい順にAi,Aj,Ak(j=0~3個)とした時に
  //問題文の条件を満たす組み合わせの個数
  vector<vector<ll>> dp(m+1, vector<ll>(4));
  //0個から1個も選ばないというパターンは1通りなのでdp[0][0]だけ1初期化
  dp[0][0] = 1;
  //dpの遷移と更新
  //数字の種類分回す
  rep(i,m){
    //選んだ個数(0~3)分回す
    rep(j,4){
      //集合にi番目の要素を追加しない場合の遷移
      //場合の数はdp[i][j]のまま、集合のサイズはjのままとなる
      dp[i+1][j] = dp[i][j];
      //1個以上数字を選ぶ場合に処理
      if(j){
        //集合にi番目の要素を追加する場合の遷移
        //cのi番目の要素から1つを集合として新たに加える場合の場合の数はc[i]通りで、
        //i+1番目の要素を考慮していない状態のサイズが1つ少ない集合の場合の数dp[i][j-1]に
        //それをかけたものが集合にi番目の要素を追加する場合の数となる(それを場合の数に加算する)
        dp[i+1][j] += dp[i][j-1]*c[i];
      }
    }
  }
  //m種類のAの中から3個選び、大きい順にAi,Aj,Ak(j=0~3個)とした時に
  //問題文の条件を満たす組み合わせの個数を出力
  cout << dp[m][3] << endl;
  return 0;
}
//dp問題
//Ai!=Aj!=Akであるのが問題の条件なので位置関係が重要でなく個数分布で管理すれば良い
