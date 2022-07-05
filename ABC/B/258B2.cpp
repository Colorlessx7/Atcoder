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
void chmin(int &x, int y){ x = min(x,y); }
void chmax(int &x, int y){ x = max(x,y); }
int main(){
  //n:マスの縦・横の長さ
  int n;
  cin >> n;
  //マス(i,j)の数字
  vector<vector<int>> a(n,vector<int>(n));
  //各マスの情報の入力
  rep(i,n){
    string s;
    cin >> s;
    //i行目の文字列sを1文字ずつ切り出してaに格納
    rep(j,n){
      a[i][j] = s[j] - '0';
    }
  }
  //移動方向vに1回進むと座標(i,j)がどう動くかの配列
  //v=[0,7]で、(左上、上、右上、左、右、左下、下、右下)に進む
  vector<int> di = {-1,-1,-1,0,0,1,1,1};
  vector<int> dj = {-1,0,1,-1,1,-1,0,1};
  //答え
  ll ans = 0;
  //(si,sj)を開始点とする(開始点についての2重ループを回す)
  rep(si,n){
    rep(sj,n){
      //移動方向v(8通りについて回す)
      rep(v,8){
        //開始点(si,sj)を移動で見る点(i,j)の初期値とする
        int i = si;
        int j = sj;
        //x:(i,j)からv方向に移動した時にできる数字の値
        ll x = 0;
        //最初の点1つと移動後の点n-1個について処理
        rep(k,n){
          //一つ前のxの値を10倍してから新しい移動先の頂点の値を足すことで
          //左から通った順番に並べた整数を作る(開始点はxが0なので開始点の数字がxとなる)
          x = x*10 + a[i][j];
          //v方向への1回の移動での座標の変化分を(i,j)に加算する
          i += di[v];
          j += dj[v];
          //移動先の頂点(i,j)が範囲外になることがあるのでnで割ったあまりを移動先とする
          //vでの移動が左または上方向の遷移の場合、割る前の(i,j)が負の数になるので
          //先にnを足してからnで割った余りを遷移先の座標とする
          i = (i+n)%n;
          j = (j+n)%n;
        }
        //xのmaxを取り、最大なら格納
        ans = max(ans,x);
      }    
    }
  }
  cout << ans << endl;
  return 0;
}
//全探索問題
//実装が重い問題
//トーラス構造を処理(%n)
