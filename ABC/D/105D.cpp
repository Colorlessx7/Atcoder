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
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }
  //今までの累積和の中でmodMがi(key)であるものの個数(value)
  map<ll, ll> mp;
  //累積和配列(%mを累積和の計算中にとっておく)
  vector<ll> s(n+1);
  //累積和計算処理(%mを累積和の計算中にとっておく)
  rep(i,n){
    s[i+1] = (s[i] + a[i]) % m;
  }
  ll ans = 0;
  //計算部分
  rep(i,n+1){
    //答えに今までの累積和の中でmodM=s[i]のものの個数を足す
    ans += mp[s[i]];
    //i番目の処理を終えたので今までの累積和の中で
    //modMがi(key)であるものの個数(value)を更新
    mp[s[i]]++;
  }
  cout << ans << endl;
  return 0;
}
//累積和を使う問題
//よくあるテクを使う
//右側を固定して、条件を満たす左端を高速に数え上げる
//区間和に関する問題なので、先頭からの累積和を使って条件を考える
//[l,r]の区間和がMの倍数 ↔ [0,l)と[0,r]のそれぞれの累積和がmodMで等しい
//mapを使ってこれまでの累積和modMの個数をカウントしておけば解ける
