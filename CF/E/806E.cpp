#include<bits/stdc++.h>
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
template<typename Tx, typename Ty>Tx dup(Tx x, Ty y){return (x+y-1)/y;}
void chmin(int &x, int y){ x = min(x,y); }
void chmax(int &x, int y){ x = max(x,y); }
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
//グリッド(i,j)の値aが0ならb=fa,1ならc=trを加算する関数
void addsum(int a, int &b, int &c){
  //aが1なら処理
  if(a){
    //c=trを加算
    c++;
    //aが0なら処理
  }else {
    //b=faを加算
    b++;
  }
}
void solve(){
  //n:グリッドの1辺の長さ
  int n;
  cin >> n;
  //a:元のグリッド
  vector<vector<int>> a(n,vector<int>(n));
  //b:aを90度回転したグリッド
  vector<vector<int>> b(n,vector<int>(n));
  //c:aを180度回転したグリッド
  vector<vector<int>> c(n,vector<int>(n));
  //d:aを270度回転したグリッド
  vector<vector<int>> d(n,vector<int>(n));
  //グリッド全段について回す
  rep(i,n){
    //i段目のグリッドの情報
    string s;
    cin >> s;
    //i段目のグリッドの情報で回す
    rep(j,n){
      //sのj文字目をintに直したものをa[i][j]とする
      a[i][j] = s[j] - '0';
      //90度回転して入力
      b[n-1-j][i] = a[i][j];
      //180度回転して入力
      c[n-1-i][n-1-j] = a[i][j];
      //270度回転して入力
      d[j][n-1-i] = a[i][j];
    }
  }
  //グリッドの1辺の長さが奇数の時に使う中心点の座標(x,x)を計算
  int x = (n + 2 - 1) / 2;
  //入れ替える座標の数
  int ans = 0;
  //全座標について処理O(N^2)
  rep(i,n){
    rep(j,n){
      //グリッドの1辺の長さが奇数の場合、中心点は何度回転させても真ん中で影響がないので処理しない
      if(n % 2 != 0 && i == x-1 && j == x-1){
        continue;
      }
      //fa:addsumで座標の値が0ならカウント
      int fa = 0;
      //tr:addsumで座標の値が1ならカウント
      int tr = 0;
      //4回の回転での同じ位置関係にある座標がa,b,c,d配列の(i,j)の要素なので
      //それら4つの座標の0の個数と1の個数をそれぞれカウントする
      addsum(a[i][j],fa,tr);
      addsum(b[i][j],fa,tr);
      addsum(c[i][j],fa,tr);
      addsum(d[i][j],fa,tr);
      //0の個数、1の個数の小さい方をansに加算する
      //(多い方に少ない方を書き換えるため書き換える個数ansに加算するのは少ないものの個数となる)
      ans += min(fa,tr);
    }
  }
  //同じ位置関係の座標について4回チェックしたので答えが本来の4倍になっているので4で割る
  ans /= 4;
  //出力
  cout << ans << '\n';
}
int main(){
  int t;
  cin >> t;
  rep(i,t) solve();
  return 0;
}
