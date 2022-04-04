#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(ll i = 0; i < N; i++)
#define rep2(i,N) for(ll i = 1; i <= N; i++)
#define rep3(i,N) for(ll i = N - 1; i >= 0; i--)
#define rep4(i,N) for(ll i = N; i > 0; i--)
#define replr(i,l,r) for(ll i = l; i < r; i++)
#define reprl(i,l,r) for(ll i = l; i > r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
using ll = long long;
using P = pair<ll,ll>;
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  ll h, w;
  cin >> h >> w;
  vector<vector<char>> s(h,vector<char>(w));
  vector<vector<ll>> dp(h,vector<ll>(w,INT_MAX));
  ll wh = 0;
  rep(i,h){
    rep(j,w){
      cin >> s[i][j];
      if(s[i][j] == '.'){
        wh++;
      }
    }
  }
  dp[0][0] = 1;
  queue<P> q;
  P x = make_pair(0,0);
  q.push(x);
  while(q.size()){
    x = q.front();
    q.pop();
    ll i = x.first;
    ll j = x.second;
    P y;
    if(j != w-1 && s[i][j+1] == '.'){
      if(dp[i][j+1] == INT_MAX){
        y = make_pair(i,j+1);
        dp[i][j+1] = dp[i][j]+1;
        q.push(y);
      }
    }
    if(j != 0 && s[i][j-1] == '.'){
      if(dp[i][j-1] == INT_MAX){
        y = make_pair(i,j-1);
        dp[i][j-1] = dp[i][j]+1;
        q.push(y);
      }
    }
    if(i != h-1 && s[i+1][j] == '.'){
      if(dp[i+1][j] == INT_MAX){
        y = make_pair(i+1,j);
        dp[i+1][j] = dp[i][j]+1;
        q.push(y);
      }
    }
    if(i != 0 && s[i-1][j] == '.'){
      if(dp[i-1][j] == INT_MAX){
        y = make_pair(i-1,j);
        dp[i-1][j] = dp[i][j]+1;
        q.push(y);
      }
    }
  }
  if(dp[h-1][w-1] == INT_MAX){
    cout << -1 << endl;
  }else {
    cout << wh - dp[h-1][w-1] << endl;
  }
  return 0;
}
//DPの遷移問題に見せかけたBFS最短経路問題 dpテーブルは実質的にbfsのvisit配列
