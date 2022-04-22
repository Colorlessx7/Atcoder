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
  vector<ll> a(n);
  ll x = LLONG_MAX;
  rep(i,n){
    cin >> a[i];
    chmin(x,a[i]);
  }
  //係数2,4,9...
  ll now = 0;
  //max取るやty
  ll ans = 0;
  while(1){
    //幅の最も長い山
    ll cnt = 0;
    //山の幅集計
    ll ch = 0;
    //その時点での配列の最小(0を除く)
    ll diff = x;
    x = LLONG_MAX;
    //全て0ならwhileを抜ける
    bool frag = true;
    //処理部分
    rep(i,n){
      //全て0になったか確認
      if(a[i] != 0){
        frag = false;
      }
      //
      if(a[i] >= diff){
        ch++;
        a[i] -= diff;
        if(a[i] != 0){
          chmin(x,a[i]);
        }
      }else {
        chmax(cnt,ch);
        ch = 0;
      }
    }
    if(frag){
      break;
    }
    now += diff;
    chmax(cnt,ch);
    chmax(ans,cnt*now);
  }
  cout << ans << endl;
  return 0;
}
