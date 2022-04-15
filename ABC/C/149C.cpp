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
  for(int i = 2; i * i <= x + 1; ++i){
    if(prime[i]){
      for(int j = 2; i * j <= x + 1; ++j){
        prime[i * j] = 0;
      }
    }
  }
  return;
}  
int main(){
  ll x;
  cin >> x;
  vector<bool> primes(105000,1);
  prime(105000,primes);
  replr(i,x,105000){
    if(primes[i]){
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
