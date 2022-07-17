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
  //数列a
  vector<int> a(n);
  const int mx = 200000;
  //個数分布を配列に格納(c[i]:aにiが登場する回数)
  vector<ll> c(mx+1);
  //数列の入力
  rep(i,n){
    cin >> a[i];
    //aの個数をカウント
    c[a[i]]++;
  }
  //cを累積和配列に変換する(c[i]:i以下の数字がaに登場する回数)
  rep(i,mx){
    c[i+1] += c[i];
  }
  //条件を満たす組み合わせの回数
  ll ans = 0;
  //全探索をjで行う
  //a[j]を決めると,a[i],a[k]はa[j]より小さいもの,大きいものから選べば良くなる
  //jを決めた時のi,j,kの場合の数はiのとりうる数(a[j]未満の数の総数)
  //*kのとりうる数(a[j]より大きい数の総数)となる
  //それを全てのjについて計算して加算していく
  rep(j,n){
    //右辺の左がa[j]未満の数の個数,右がa[j]より大きい数の個数
    //(全体の数nからa[j]以下の数の個数を引くことでa[j]より大きい数の個数となる)
    //int*intでオーバーフローが起きるためcをllで宣言するかキャストする必要がある
    ans += c[a[j]-1]*(n-c[a[j]]);
  }
  cout << ans << endl;
  return 0;
}
//累積和と全探索問題
