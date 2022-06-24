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
  ll h, w;
  cin >> h >> w;
  vector<string> s(h);
  bool flag = false;
  ll xa = 0, xb = 0, ya = 0, yb = 0;
  rep(i,h){
    cin >> s[i];
    rep(j,w){
      if(s[i][j] == 'o'){
        if(!flag){
          xa = i;
          ya = j;
          flag = true;
        }else {
          xb = i;
          yb = j;
        }
      }
    }
  }
  ll ans = (max(xa,xb) - min(xa,xb)) + (max(ya,yb) - min(ya,yb)) ;
  cout << ans << endl;
  return 0;
}
