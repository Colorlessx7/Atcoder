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
void prime(int x,vector<bool> &prime){
  prime[0] = 0;
  prime[1] = 0;
  for(int i = 2; i * i <= x; ++i){
    if(prime[i]){
      for(int j = 2; i * j <= x; ++j){
        prime[i * j] = 0;
      }
    }
  }
  return;
}
void rs2017(int x,vector<ll> &rs,vector<bool> &prime){
  ll num = 0;
  rs[0] = 0;
  rep2(i,x){
    if(prime[i] && prime[(i+1)/2]){
      num++;
    }
    rs[i] = num;
  }
  return;
}
int main(){
  ll q;
  cin >> q;
  vector<bool> primes(100001,true);
  prime(100000,primes);
  vector<ll> rs(100001);
  rs2017(100000,rs,primes);
  rep(i,q){
    ll l, r;
    cin >> l >> r;
    cout << rs[r] - rs[l-1] << endl;
  }
  return 0;
}
