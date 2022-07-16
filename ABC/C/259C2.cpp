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
//ランレングス圧縮関数
//s:ランレングス圧縮を行いたい文字列,res:i番目の要素のfi=文字,se=個数
void rle(const string &s, vector<P> &res){
  //全ての文字列について処理
  for(char c : s){
    //一番最初の文字でなく、かつ文字cが一つ前の文字と同じ場合に処理
    if(res.size() > 0 && res.back().first == c){
      //末尾の要素の文字が1個追加されたので末尾のsecondを+1する
      res.back().second++;
    }else {
      //一番最初の文字または、文字cが一つ前の文字と違う場合に処理
      //末尾に文字cと個数1のpairを格納
      res.emplace_back(c,1); 
    }
  }
}
//判定用関数
bool solve(){
  //s:変換元の文字列、t:変換先の文字列
  string s, t;
  cin >> s >> t;
  //sのランレングス圧縮配列
  vector<P> a;
  //sをランレングス圧縮する
  rle(s,a);
  //tのランレングス圧縮配列
  vector<P> b;
  //tをランレングス圧縮する
  rle(t,b);
  //ランレングス圧縮後の文字の要素数が違う場合falseを返す
  if(a.size() != b.size()){
    return false;
  }
  //ランレングス圧縮後の各要素について回す
  rep(i,a.size()){
    //文字が違う場合falseを返す
    if(a[i].first != b[i].first){
      return false;
    }
    //al:i番目の文字a[i].firstの文字数
    int al = a[i].second;
    //bl:i番目の文字b[i].firstの文字数
    int bl = b[i].second;
    //sのi番目の要素の文字が1つのみの時
    if(al == 1){
      //tのi番目の要素の文字が1より多いならsの文字a[i].firstを増殖できないのでfalseを返す
      if(bl != 1){
        return false;
      }
      //sのi番目の要素の文字が2つ以上の時
    }else {
      //sの文字数がtの文字数より多い場合増殖できるのはsの文字だけなのでfalseを返す
      if(bl < al){
        return false;
      }
    }
  }
  //上の全条件を満たさない場合trueを返す
  return true;
}
int main(){
  //判定関数の結果次第で出力させる
  if(solve()){
    cout << "Yes" << endl;
  }else {
    cout << "No" << endl;
  }
  return 0;
}
