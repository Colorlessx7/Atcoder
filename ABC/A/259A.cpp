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
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  //n:最大年齢(この時tcm),m:年齢(この時の身長を問う)
  //x:身長が毎年dcm伸びる年齢の限界(以降伸びない)
  int n, m, x, t, d;
  cin >> n >> m >> x >> t >> d;
  //0歳の身長(身長の最大値tから伸びる長さdと伸びる期間xをかけたものを引いたもの)
  int f = t - x * d;
  //m歳の時身長が伸びる時期なら処理
  if(m <= x){
    //0歳の身長に伸びる長さdと伸びる期間mをかけたものを足したものを出力
    cout << f + m * d << endl;
  }else {
    //m歳の時身長が伸びない時期なら処理(最大身長tを出力)
    cout << t << endl;
  }
  return 0;
}
