#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(ll i = 0; i < N; i++)
#define rep2(i,N) for(ll i = 1; i <= N; i++)
#define rep3(i,N) for(ll i = N - 1; i >= 0; i--)
#define rep4(i,N) for(ll i = N; i > 0; i--)
#define replr(i,l,r) for(ll i = l; i < r; i++)
#define reprl(i,l,r) for(ll i = l; i >= r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
using ll = long long;
using P = pair<ll,ll>;
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }
  //x=1~nそれぞれについてAi=xなるiを昇順に管理した配列
  vector<vector<ll>> is(n+1);
  rep(i,n){
    is[a[i]].push_back(i);
  }
  ll q;
  cin >> q;
  //クエリ処理
  rep(i,q){
    ll l, r, x;
    cin >> l >> r >> x;
    //0indexed調整
    l--; r--;
    //ラムダ式
    //[0,r]の範囲のAi=xとなる数の個数を求める関数
    auto f = [&](vector<ll> &is, ll r){
      //二分探索 rより大きい配列aの値の添字からbeginをひくと区間[0,r]のxの個数が得られる
      return upper_bound(all(is),r) - is.begin();
    };
    //累積和に近い考え方
    //[l,r]について見るときに[0,r]-[0,l-1]を考えれば良い
    ll ans = f(is[x], r) - f(is[x], l-1);
    //endlが重いのでprintf\nで出力
    printf("%lld\n",ans);
  }
  return 0;
}
//Ai=xなるiを昇順に管理した配列を作り、二分探索で解く問題
//Ai={3,1,4,1,4}の時x=1,is={1,3},x=3,is={0},x=4,is={2,4}となり、
//クエリが1,5=(0,4),1の時x=1を参照しf(r)-f(l-1)を計算すると
//f(r)はis={1,3}の1の場所がis.begin()でr=4を超える値がisにないため
// 
