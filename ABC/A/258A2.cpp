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
  int k;
  cin >> k;
  //21時スタートなので21にk/60を足す
  int h =  21 + k / 60;
  //余りが分になる
  int m = k % 60;
  //0paddingをprintf指定子で行う
  //%dでintを単純に出力、%2dでint2桁(1桁未満なら空きを空白で埋める)
  //%02dでint2桁(1桁未満なら空きを0で埋める)
  printf("%02d:%02d\n",h,m);
  return 0;
}
