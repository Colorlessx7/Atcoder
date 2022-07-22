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
  int n, m;
  cin >> n >> m;
  vector<int> l(m),r(m);
  //区間Liの最大
  int lm = 0;
  //区間Riの最小
  int rm = INT_MAX;
  rep(i,m){
    cin >> l[i] >> r[i];
    //区間Liの最大をとる
    chmax(lm,l[i]);
    //区間Riの最小をとる
    chmin(rm,r[i]);
  }
  //[Lm,Rm]の区間の要素数を答える(rm-lm+1)
  //Lm>Rmなら条件を満たす区間が存在しないので0が答えとなる
  int ans = max(0,rm-lm+1);
  cout << ans << endl;
  return 0;
}
//解法1
//i番目のidカードが[li,ri]の区間のゲートを開けられる
