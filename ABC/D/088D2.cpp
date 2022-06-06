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
  ll h, w;
  cin >> h >> w;
  vector<vector<char>> s(h,vector<char>(w));
  ll cnt = 0;
  rep(i,h){
    rep(j,w){
      cin >> s[i][j];
      if(s[i][j] == '.'){
        cnt++;
      }
    }
  }
  const ll INF = 1001001001;
  vector<vector<ll>> dp(h,vector<ll>(w,INF));
  queue<TP> q;
  q.push({0,0,1});
  while(q.size()){
    TP x = q.front();
    q.pop();
    ll i = get<0>(x);
    ll j = get<1>(x);
    ll num = get<2>(x);
    if(dp[i][j] > num){
      dp[i][j] = num;
    }else {
      continue;
    }
    num++;
    if(i != 0 && s[i][j] != '#'){
      q.push({i-1,j,num});
    }
    if(i != h-1 && s[i][j] != '#'){
      q.push({i+1,j,num});
    }
    if(j != 0 && s[i][j] != '#'){
      q.push({i,j-1,num});
    }
    if(j != w-1 && s[i][j] != '#'){
      q.push({i,j+1,num});
    }
  }
  if(dp[h-1][w-1] == INF){
    cout << -1 << endl;
    return 0;
  }
  cout << cnt - dp[h-1][w-1] << endl;
  return 0;
}
