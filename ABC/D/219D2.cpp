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
  ll n, x, y;
  cin >> n >> x >> y;
  const ll INF = 1001001001;
  vector dp(x+1,vector<ll>(y+1,INF));
  dp[0][0] = 0;
  rep(i,n){
    ll a, b;
    cin >> a >> b;
    rep3(j,x+1){
      rep3(k,y+1){
        chmin(dp[min(j+a,x)][min(k+b,y)],dp[j][k]+1);
      }
    }
  }
  ll ans = dp[x][y];
  if(ans == INF){
    ans = -1;
  }
  cout << ans << endl;
  return 0;
}
//dpの変数iごとにテーブルを分けずに使いまわしたver
//dpを前から回すと既に買った弁当の遷移先を弁当を買って遷移させたタイミングで
//見ていないのでそのまま処理すると弁当を複数個変える処理になってしまう
//dpを後ろから見ることで遷移先を見るのが次のiのタイミングとなるため
//後ろから見ることによって時間とメモリ使用量を削減できる
