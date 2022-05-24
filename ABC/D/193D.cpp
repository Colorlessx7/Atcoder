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
  ll k;
  string s, t;
  cin >> k >> s >> t;
  map<ll,ll> mp,tm,am;
  replr(i,1,10){
    mp[i] = k;
    tm[i] = 0;
    am[i] = 0;
  } 
  ll tk = 0,ao = 0;
  rep(i,4){
    tm[s[i]-'0']++;
    mp[s[i]-'0']--;
    am[t[i]-'0']++;
    mp[t[i]-'0']--;
  } 
  for(auto p : tm){
    tk += p.first*pow(10,p.second);
  }
  for(auto p : am){
    ao += p.first*pow(10,p.second);
  }
  double sum = 9*k-8;
  double twin = 0;
  double awin = 0;
  replr(i,1,10){
    bool flag = false;
    if(mp[i] == 0){
      continue;
    }
    if(mp[i] == 1){
      flag = true;
    }
    ll tkch = tk;
    tkch -= i*pow(10,tm[i]);
    tkch += i*pow(10,tm[i]+1);
    replr(j,1,10){
      if(mp[j] == 0){
        continue;
      }
      if(i == j && flag){
        continue;
      }
      ll aoch = ao;
      aoch -= j*pow(10,am[j]);
      aoch += j*pow(10,am[j]+1);
      if(tkch > aoch){
        if(i == j){
          twin += ((double)mp[i]/sum) *((double)(mp[j]-1)/(sum-1)); 
        }else {
          twin += ((double)mp[i]/sum) *((double)mp[j]/(sum-1));
        }
      }else {
        if(i == j){
          awin += ((double)mp[i]/sum) *((double)(mp[j]-1)/(sum-1));
        }else {
          awin += ((double)mp[i]/sum) *((double)mp[j]/(sum-1));
        }
      }
    }
  }
  double ans = twin/(awin+twin);
  printf("%.10f\n",ans);
  return 0;
}
