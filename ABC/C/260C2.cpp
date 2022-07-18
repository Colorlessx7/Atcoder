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
  int n, x, y;
  cin >> n >> x >> y;
  //r[i]:レベルiの赤い宝石の個数
  //b[i]:レベルiの青い宝石の個数
  vector<ll> r(n+1),b(n+1);
  //レベルnの赤い宝石の個数を問題文通り1初期化
  r[n] = 1;
  //レベルnからレベル2まで処理
  reprl(i,n,2){
    //レベルiの赤い宝石全てを一つずつレベルi-1の赤い宝石に変換
    r[i-1] += r[i];
    //レベルiの赤い宝石全てを一つずつレベルiの青い宝石*x個に変換
    b[i] += r[i]*x;
    //レベルiの青い宝石全てを一つずつレベルi-1の赤い宝石に変換
    r[i-1] += b[i];
    //レベルiの青い宝石全てを一つずつレベルi-1の青い宝石*y個に変換
    b[i-1] += b[i]*y;
  }
  //レベル1の青い宝石の個数を出力
  cout << b[1] << endl;
  return 0;
}
//dpをしっかりかいたver
//処理順と処理量をグラフに書いていくと
//レベルの高い順に赤、青の順番にできるだけ貪欲に変換していくといいことがわかる
//
