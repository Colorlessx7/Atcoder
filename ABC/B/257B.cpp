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
  int n, k, q;
  cin >> n >> k >> q;
  vector<bool> a(n);
  rep(i,k){
    int x;
    cin >> x;
    //0indexed
    x--;
    //駒の設置
    a[x] = true;
  }
  //クエリ処理
  rep(i,q){
    //l:左から何番目の駒を動かすか
    int l;
    cin >> l;
    //左端から見ていって何個駒が見えたか
    int cnt = 0;
    //全マスを探索
    rep(j,n){
      //駒がマスjにあるならカウンタを加算
      if(a[j]){
        cnt++;
      }
      //jにある駒が左からl番目の駒だったら処理
      if(l == cnt){
        //左からl番目の駒が右端でないなら処理
        if(j != n-1){
          //一つ右に駒が存在しないなら処理
          if(!a[j+1]){
            //駒を1つ右にずらす
            a[j] = false;
            a[j+1] = true;
          }
        }
      }
    }
  }
  //全てのマスについて処理
  rep(i,n){
    //駒があるなら処理
    if(a[i]){
      //駒の座標iが0indexedなので1indexedにして出力
      printf("%d\n",i+1);
    }
  }
  return 0;
}
//愚直にbool配列で左から何番目のやつかを調べて操作する解法
