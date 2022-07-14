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
//o(NlogN)
void solve(){
  int n;
  cin >> n;
  vector<int> a(n+1);
  rep2(i,n){
    cin >> a[i];
  }
  //条件を満たす(i,j)のペアの数
  ll res = 0;
  //a[i]<iを満たすiを格納する配列
  vector<int> v;
  //全要素についてiを昇順に回すO(N)
  rep2(i,n){
    //a[i]<iを満たさないものはコンティニューして捨てる
    if(a[i] >= i){
      continue;
    }  
    //vにすでに格納した要素(全てa[i]<iを満たす)をa[i],iとし、
    //現在見ているa[i],iをa[j],jとして考え、i<ajを満たすものの個数を二分探索で計算する
    //二分探索でa[i]以上のiの値(条件の最初の範囲外)が格納されているvのindexを得るO(logN)
    //そのindexの値が0番目のindexから条件を満たすものの個数となる
    //([0,4)の4が二分探索で得られ、要素の個数は4となる)
    res += (ll)(lower_bound(all(v),a[i]) - v.begin());
    //a[i]<iの条件を満たすもののiをvに格納する
    v.push_back(i);
  }
  cout << res << '\n';
}
int main(){
  int t;
  cin >> t;
  rep(i,t) solve();
  return 0;
}
//ai<i<aj<jをai<i, i<aj, aj<jに分けて考える
//端2つの条件は1回で調べられる
//真ん中の条件を二分探索で高速化する
