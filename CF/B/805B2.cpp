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
#define sz(v) (int)v.size()
using ll = long long;
using P = pair<int,int>;
using TP = tuple<int,int,int>;
void chmin(int &x, int y){ x = min(x,y); }
void chmax(int &x, int y){ x = max(x,y); }
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
void solve(){
  //文字列
  string s;
  cin >> s;
  //一日に使えるアルファベットの種類を格納
  set<char> v;
  //日数
  int ans = 0;
  //文字数
  int n = sz(s);
  //全ての文字について回す
  rep(i,n){
    //i番目のアルファベットの種類をsetに格納
    v.insert(s[i]);
    //setの要素数が4以上になったら処理
    if(sz(v) > 3){
      //日数を+1
      ans++;
      //setの中身を削除し、setの中身を次の日の使用するアルファベットにする
      v.clear();
      //次の日の最初に使えるアルファベットをi番目の文字とする
      v.insert(s[i]);
    }
  }
  //setにアルファベットが残っているなら日数を+1する
  if(sz(v)){
    ans++;
  }
  cout << ans << endl;
}
int main(){
  int t;
  cin >> t;
  rep(i,t) solve();
  return 0;
}
