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
//O(1)
void solve(){
  //s:入力の文字列
  string s;
  cin >> s;
  //比較用文字列1:大文字のyesを格納
  string t1 = "YES";
  //比較用文字列2:小文字のyesを格納
  string t2 = "yes";
  //sの3文字について処理
  rep(i,3){
    //sのi文字目が比較用文字列のどちらかのi文字目とも一致していない場合条件を満たさないので処理
    if(s[i] != t1[i] && s[i] != t2[i]){
      //Noを出力して終了
      cout << "No" << endl;
      return;
    }
  }
  //条件を満たすのでYesを出力して終了
  cout << "Yes" << endl;
}
int main(){
  int t;
  cin >> t;
  rep(i,t) solve();
  return 0;
}
