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
  //文字列を昇順にsort
  sort(all(s));
  //左2文字が違うか比較(abb,abcを検出)
  if(s[0] != s[1]){
    //一番左を出力
    cout << s[0] << endl;
    //右2文字が違うか比較(aabを検出)
  }else if(s[2] != s[1]){
    //一番右を出力
    cout << s[2] << endl;
  }else {
    //aaaのパターンなので-1を出力
    cout << -1 << endl;
  }
  return 0;
}
//文字列を昇順にsortした後の文字列のパターン
//aaa,abb,aab,abcの4パターン
//一番右のパターンは両端2つを出力しても問題ないので真ん中の文字を答える必要がなくなる
//
