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
  ll n, w;
  cin >> n >> w;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }
  //dp[i]:iが良い整数ならtrue,違うならfalse
  vector<bool> dp(w+1,false);
  //数字1個でできるパターンについて
  rep(i,n){
    dp[a[i]] = true;
  }
  //数字2個でできるパターンについて(重複を除く)
  rep(i,n){
    rep(j,i){
      ll x = a[i] + a[j];
      //合計がwを超える可能性があるので注意
      if(x <= w){
        dp[x] = true;
      }
    }
  }
  //数字3個でできるパターンについて(重複を除く)
  rep(i,n){
    rep(j,i){
      rep(k,j){
        ll x = a[i] + a[j] + a[k];
        //合計がwを超える可能性があるので注意
        if(x <= w){
          dp[x] = true;
        }
      }
    }
  }
  ll ans = 0;
  //整数1~wについて良い整数ならdp[i]=trueなので計上する
  rep2(i,w){
    if(dp[i]){
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
