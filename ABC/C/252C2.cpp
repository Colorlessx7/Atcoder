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
  vector<string> s(n);
  rep(i,n){
    cin >> s[i];
  }
  //key:数字,val[i]:iがリールの場所何番目か、中身が場所の登場回数
  vector<vector<ll>> mp(10,vector<ll>(10));
  rep(i,10){
    rep(j,10){
      mp[i][j] = 0;
    }
  }
  rep(i,n){
    rep(j,10){
      ll num = s[i][j] - '0';
      mp[num][j]++;
    }
  }
  ll ans = LLONG_MAX;
  rep(j,10){
    ll cnt = 0;
    ll pl = 0;
    rep(i,10){
      if(cnt < mp[j][i]){
        cnt = mp[j][i];
        pl = i;
      }else if(cnt == mp[j][i] && pl < i){
        pl = i;
      }
    }
    ll num = (cnt-1)*10 + pl;
    chmin(ans,num);
  }
  cout << ans << endl;
  return 0;
}
