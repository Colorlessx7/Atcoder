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
  vector<int> ans(3);
  int x;
  cin >> x;
  //n>=(x/3)+1 からnは必ず整数を取るためx/3の切り上げを計算する
  int n = (x+3-1) / 3;
  //上の式の+1部分を処理
  n += 1;
  //b=n
  ans[1] = n;
  //a=n-1
  ans[0] = n-1;
  //c=x-a-b
  ans[2] = x - ans[0] - ans[1];
  //c=0になったときにaを-1してcを+1する
  //(制約がx>=6なのでc(ans[2])をいじってもa(ans[0])がc以下にならない)
  if(ans[2] == 0){
    ans[0]--;
    ans[2] = 1;
  }
  //出力部
  rep(i,3){
    if(i == 2){
      printf("%d\n",ans[i]);
    }else {
      printf("%d ",ans[i]);
    } 
  }
}
int main(){
  int t;
  cin >> t;
  rep(i,t) solve();
  return 0;
}
//xが与えられたらa b cを答える問題
//a b cの条件はb > a > cかつ、bが左の条件を満たす最小の値であり、a,b,c>0であること
//bをnとおくと、貪欲に考えればa=n-1,c=n-2として、後から辻褄合わせをすれば良いことになる
//移項すると3(n-1)>=x n-1>=x/3 n>=(x/3)+1となる
