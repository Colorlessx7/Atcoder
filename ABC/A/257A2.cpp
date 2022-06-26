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
  int n, x;
  cin >> n >> x;
  //0indexed
  x--;
  //65='A',printf指定子の%cはintの値でも対応する
  //アルファベットがあればそれを出力する
  printf("%c\n",x/n+65);
  return 0;
}
//n=3,x=5だとすると
//文字列はAAABBBからBが答えになる、n=3,x=6でもBとなる
//AAABBBはindexを0indexにしてみると012345で
//(x-1)/nの切り捨てがxの指すアルファベットの種類を数字に変換したものに対応する
//(xが1indexed,x-1で0indexed)

//注意点としてcout << "A" + i << endl;
//(A:char,i:intだと整数の型の方がcoutで優先されて整数が出力される)
//解決法はあらかじめcharの変数を用意してchar c = "A" + i;
//からcout << c << endl;で出力するか、
//cout << (char)('A' + i)と型をキャストして変換する必要がある
