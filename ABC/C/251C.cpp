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
  ll n;
  cin >> n;
  map<string,P> mp;
  rep(i,n){
    string s;
    ll x;
    cin >> s >> x;
    if(mp[s].first == 0){
      mp[s].first = x;
      mp[s].second = i+1;
    }
  }
  ll num = 0;
  ll id = 0;
  for(auto p : mp){
    if(num < p.second.first){
      num = p.second.first;
      id = p.second.second;
    }else if(num == p.second.first){
      if(id > p.second.second){
        id = p.second.second;
      }
    }
  }
  cout << id << endl;
  return 0;
}
