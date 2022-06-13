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
void chmin(int &x, int y){ x = min(x,y); }
void chmax(int &x, int y){ x = max(x,y); }
void solve(){
  //要素数
  int x;
  cin >> x;
  //減算前の要素
  vector<int> a(x);
  //減算後の要素
  vector<int> b(x);
  //最大値調査用
  int mx = 0;
  rep(j,x){
    cin >> a[j];
  }
  rep(j,x){
    cin >> b[j];
    //減算前後の変化の最大値を基準にする
    mx = max(mx,a[j]-b[j]);
  }
  //減算処理
  rep(j,x){
    //全要素をmxで減算する(減算結果がマイナスになる場合は問題文の条件より0とする)
    a[j] = max(0,a[j]-mx);
  }
  bool flag = true;
  rep(j,x){
    //aを減算した結果がbと一致していない場合flagをおろす
    if(a[j] != b[j]){
      flag = false;
      break;
    }
  }
  //フラグが立ったままならYes,下ろしたならNoを出力
  if(flag){
    cout << "YES" << endl;
  }else {
    cout << "NO" << endl;
  }
}
int main(){
  int t;
  cin >> t;
  rep(i,t) solve();
  return 0;
}
//a配列の全要素を1ずつ減算して行ってbになるか(0を下回る減算処理は0のまま減らないとして扱う)
