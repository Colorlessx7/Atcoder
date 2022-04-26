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
//日数
ll D = 365;
//満足度の低下係数
vector<ll> c(26);
//コンテストjをやった日iに上昇する満足度s
vector<vector<ll>> s(D,vector<ll>(26));
//i日目にコンテストt[i]を行う
vector<ll> t(D);

//入力部
void input(){
  cin >> D;
  rep(i,26){
    cin >> c[i];
  }
  rep(i,D){
    rep(j,26){
      cin >> s[i][j];
    }
  }
  rep(i,D){
    cin >> t[i];
    t[i]--;
  }
  return;
}

//評価関数計算関数
ll compute_score(){
  ll score = 0;
  vector<ll> last(26,0);
  rep(d,D){
    last[t[d]] = d + 1;
    rep(i,26){
      score -= c[i] * ((d + 1) - last[i]);
    }
    score += s[d][t[d]];
    cout << score << endl;
  }
  return score;
}

//main
int main(){
  input();
  ll ans = compute_score();
  cout << ans << endl;
  return 0;
}
