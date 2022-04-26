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
  //日数
  ll d;
  cin >> d;
  //満足度の低下係数
  //以下全ての変数を1indexedで持つ
  vector<ll> c(27);
  rep2(i,26){
    cin >> c[i];
  }
  //コンテストjをやった日iに上昇する満足度s
  vector<vector<ll>> s(d+1,vector<ll>(27));
  rep2(i,d){
    rep2(j,26){
      cin >> s[i][j];
    }
  }
  //i日目にコンテストt[i]を行う
  vector<ll> t(d+1);
  rep2(i,d){
    cin >> t[i];
  }
  //コンテストi最後にやった日を格納(初期0)
  vector<ll> last(27,0);
  //満足度(初期0)
  ll sc = 0;
  //d日分回す
  rep2(i,d){
    //i日目にコンテストt[i]を実施
    //現在のスコアに(i,t[i])のスコアを加算
    sc += s[i][t[i]];
    last[t[i]] = i;
    rep2(j,26){
      sc -= c[j] * ((i) - last[j]);
    }
    cout << sc << endl;
  }
  return 0;
}
