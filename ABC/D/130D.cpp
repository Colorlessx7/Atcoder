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
using TP = tuple<ll,ll,ll>;
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }
  //連続部分列の要素の和
  ll s = 0;
  //連続部分列の右端についてのカーソル
  ll j = 0;
  //要素の和がk未満になる連続部分列の個数
  ll ans = 0;
  //尺取法の実行
  //i:連続部分列の左端の開始点について
  rep(i,n){
    //右側のカーソルを要素の和がk未満の条件を満たすなら進め続ける
    while(j < n && s+a[j] < k){
      //条件を満たすので連続部分列の和にa[j]を加算
      s += a[j];
      //カーソルを1つ右に移動
      ++j;
    }
    //条件を満たさない連続部分列の範囲(最長)が[i,j)になる
    //ansに加算される値は左端をiとした時の連続部分列の個数で
    //例として[3,5)とするとそれを満たすのは3,3-4なので(5-3=2から)j-iとなる
    ans += j-i;
    //左端を一つ右に移動させるため左端の値a[i]を連続部分列の和sからひく
    s -= a[i];
  }
  //n*(n+1)/2が全ての連続部分列のパターン数(和の公式より(1/2)*(a+l) (a:初項,l:末項))
  //全体から条件外(k未満)の要素を引く
  ans = n * (n + 1) / 2 - ans;
  cout << ans << endl;
  return 0;
}
//尺取法で解く問題(sortして二分探索でも可)(BITでもできるらしい)
