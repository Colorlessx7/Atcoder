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
  int n;
  cin >> n;
  //key:文字列,value:すでに出てきた回数
  map<string,int> cnt;
  //全文字列について処理
  rep(i,n){
    //文字列の入力
    string s;
    cin >> s;
    //出力文字列の左側にsを格納
    string ans = s;
    //文字列sがすでに登場しているなら処理
    //cnt.find(s)はイテレータを返す関数
    //cnt.find(s)ですでに文字列sが登場している文字列なら
    //sがkeyの場所のイテレータを返す
    //cnt.find(s)でsが未登場ならend()を指すイテレータを返す
    if(cnt.find(s) != cnt.end()){
      //aa(2)という形にする(cnt[s])がすでに登場したsの個数
      ans += "(" + to_string(cnt[s]) + ")";
    } 
    //sの個数を+1
    cnt[s]++;
    //出力(\nでendlのflashを回避)
    cout << ans << '\n';
  }
  return 0;
}
