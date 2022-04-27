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
vector<vector<ll>> s(365,vector<ll>(26));

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
  return;
}

//評価関数計算関数
ll compute_score(vector<ll> &out){
  ll score = 0;
  vector<ll> last(26,0);
  ll n = out.size();
  rep(d,n){
    last[out[d]] = d + 1;
    rep(i,26){
      score -= c[i] * ((d + 1) - last[i]);
    }
    score += s[d][out[d]];
    //cout << score << endl;
  }
  return score;
}

//貪欲法を解く関数
vector<ll> solve(){
  //i日目にコンテストt[i]を行う
  vector<ll> out;
  rep(d,D){
    ll max_score = LLONG_MIN;
    ll best_i = 0;
    rep(i,26){
      out.push_back(i);
      ll score = compute_score(out);
      if(max_score < score){
        max_score = score;
        best_i = i;
      }
      out.pop_back();
    }
    out.push_back(best_i);
  }
  return out;
}

//main
int main(){
  input();
  vector<ll> ans = solve();
  rep(i,D){
    cout << ans[i] + 1 << endl;
  }
  return 0;
}

//62'634'806点
