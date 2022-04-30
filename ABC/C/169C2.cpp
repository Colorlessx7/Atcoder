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
  //bの実数部をb1,小数部をb2としてscanfで入力を受け取って計算する
  ll a, b1, b2;
  //この方法でa b1.b2として入力を受け取る
  scanf("%lld %lld.%lld", &a, &b1, &b2);
  //答えの計算(bを100倍して整数として計算し、最後に100で割る)
  ll ans = a * (b1 * 100 + b2) / 100;
  cout << ans << endl;
  return 0;
}
