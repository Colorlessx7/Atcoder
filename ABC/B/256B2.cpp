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
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
  }
  //b:出塁状況を４桁の２進数で管理する
  //bの桁と塁の順番は0桁目3塁,1桁目2塁,2桁目1塁,3桁目本塁の順番で
  //本塁,1塁,2塁,3塁,数字の0以下の桁(消える)の順に並ぶ
  int b = 0;
  rep(i,n){
    //本塁に人を立たせる(打席に立つ)
    b |= 8;
    //a[i]ベースヒットにより全ての塁の走者をa[i]個進める
    b >>= a[i];
  }
  //打席に立った人nから最後の盤面で塁にまだ残っている人を引いたものが
  //得点数となる(i塁に残っているかはbのi桁目が1かどうかでわかる)
  //__builtin_popcount(b)でbを2進数表記した時に1が何桁存在するかを調べることができる
  int p = n - __builtin_popcount(b);
  cout << p << endl;
  return 0;
}
