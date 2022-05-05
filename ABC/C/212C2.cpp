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
  vector<ll> a(n),b(m);
  rep(i,n){
    cin >> a[i];
  }
  rep(i,m){
    cin >> b[i];
  }
  const ll INF = INT_MAX;
  //二分探索で帰ってくるイテレータが必ず数字が格納されている場所を指すように
  //bに+無限と-無限を用意(LLONG_MAXとかにするとabs関数内でオーバーフローしたためINT_MAXで処理)
  b.push_back(INF);
  b.push_back(-INF);
  //二分探索の下準備として昇順にsort
  sort(all(b));
  //a,bから数字をそれぞれ決めた時の絶対値の差の最小を格納
  ll ans = LLONG_MAX;
  //全てのa[i]について回す
  rep(i,n){
    //二分探索で配列bの中のa[i]以上の最初の値を示すイテレータを返す
    ll j = lower_bound(all(b),a[i]) - b.begin();
    //b[j]:b配列のa[i]以上の最も小さい値,b[j-1]:b配列のa[i]未満の最も大きい値
    //a[i]とb[j],b[j-1]のそれぞれの絶対値の差を計算し最小ならansに格納
    chmin(ans,abs(a[i]-b[j]));
    chmin(ans,abs(a[i]-b[j-1]));
  }
  //出力
  cout << ans << endl;
  return 0;
}
//二分探索法で解く問題
//
