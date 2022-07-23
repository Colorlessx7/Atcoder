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
  string s;
  cin >> s;
  int n = s.size();
  //文字列サイズが3以上の時処理
  //(文字列サイズが2になると文字列をpop_backした時点で1文字になって
  //偶文字列にならないため)
  while(n > 2){
    //末尾を削除
    s.pop_back();
    //文字数を-1
    n--;
    //奇数なら偶文字列にならないのでコンティニュー
    if(n % 2 != 0){
      continue;
    }
    //偶文字列ならtrue
    bool flag = true;
    //文字列sの前半部分についてループ
    rep(i,n/2){
      //前半と後半の同じ場所i,i+n/2の文字が違うなら
      //偶文字列ではないのでflagを下ろす
      if(s[i] != s[i+n/2]){
        flag = false;
      }
    }
    //flagが立ったままなら偶文字列なので文字数を出力して終了
    if(flag){
      cout << n << endl;
      return 0;
    }
  }
  return 0;
}
