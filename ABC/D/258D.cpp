#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define replr(i,l,r) for(int i = l; i < r; i++)
#define reprl(i,l,r) for(int i = l; i >= r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
using ll = long long;
using P = pair<int,int>;
using TP = tuple<int,int,int>;
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  ll n, x;
  cin >> n >> x;
  vector<ll> a(n),b(n);
  rep(i,n){
    cin >> a[i] >> b[i];
  }
  //minを取るため最大初期化
  ll ans = LLONG_MAX;
  ll num = 0;
  int dx = 0;
  rep(i,n){
    num += a[i];
    ll num2 = num + b[i];
    dx++;
    if(dx < x){
      num2 += b[i] * (x - dx);
    }else {
      continue;
    }
    chmin(ans,num2);
    num += b[i];
  }
  cout << ans << endl;
  return 0;
}
//貪欲法
//1周にb[i]だけかかる所を最終ステージとして、周回場所(最終ステージ)n個についての全探索をしている
