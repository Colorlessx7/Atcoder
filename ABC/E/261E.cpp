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
  //n:操作の種類,c:変数Xの初期状態
  int n, c;
  cin >> n >> c;
  //関数合成後の関数としての配列
  //d[0]が最初の全てのbitが0の状態で操作0から操作iまで行った時のbitの状態を示す
  //d[1]が最初の全てのbitが1の状態で操作0から操作iまで行った時のbitの状態を示す
  vector<int> d(2);
  //~がbit演算のnotにあたる
  //~0は実際には-1だが全てのbitが1の数字を示す
  d[1] = ~0;
  //全入力について処理
  rep(i,n){
    //t:クエリのタイプ,a:bit演算の値
    int t, a;
    cin >> t >> a;
    //関数合成処理
    rep(j,2){
      //クエリタイプが1なら初期bitが0,1の羅列それぞれに&aを関数合成
      if(t == 1){
        d[j] &= a;
      }
      //クエリタイプが2なら初期bitが0,1の羅列それぞれに|aを関数合成
      if(t == 2){
        d[j] |= a;
      }
      //クエリタイプが3なら初期bitが0,1の羅列それぞれに^aを関数合成
      if(t == 3){
        d[j] ^= a;
      }
    }
    //c&d[1]:cの桁の元々1だったbitが合成関数により最終的に1になるならその桁のbitを立てる
    //~c&d[0]:cの桁の元々0だったbitが合成関数により最終的に1になるならその桁のbitを立てる
    //これのorを取ることにより合成関数により最終的に1になるbitだけ立った状態になる
    //(左でold_cの1のbitのみについて最終的に1になるもののbitを立てて、
    //右でold_cの0のbitのみについて最終的に1になるもののbitを立てて
    //そのorを取ることにより最終的に1になるbitだけが立っているnew_cを計算できる)
    c = (c&d[1]) | (~c&d[0]);
    //endlは重いので\nで出力
    cout << c << '\n';
  }
  return 0;
}
//bit演算問題をbit一桁毎に分けて考えて
//各操作を関数として見て関数合成をしていく問題
//例として
//c=10,^3とすると
//d[0]=0000,d[1]=1111で
//^3(^0011)によりd[0]=0011,d[1]=1100となり、
//合成関数をcの各段階毎に計算すると、
//c=1010からc&d[1]=1010&1100=1000,~c&d[0]=0101&0011=0001
//c=(c&d[1])|(~c&d[0])=1000|0001=1001=9と計算できる
