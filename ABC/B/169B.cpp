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
using TP = tuple<ll,ll,ll>;
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
    //aの中に0があるならa1*a2...*anは0なので出力し終了
    if(a[i] == 0){
      cout << 0 << endl;
      return 0;
    }
  }
  //a1*a2...*anの答え(乗算なので1初期化)
  ll ans = 1;
  //aの要素を全てかけるループ
  rep(i,n){
    //ans*a[i]が10^18を超えたら-1を出力して終了
    //(a*b>c -> a>c/b)オーバーフロー対策で移項することにより判定時のオーバーフローを回避できる
    if(ans > 1000000000000000000LL / a[i]){
      cout << -1 << endl;
      return 0;
    }
    //aiをかける
    ans *= a[i];
  }
  cout << ans << endl;
  return 0;
}
//a,ab,abc,abcdとかけていくよりa,b,c,dをab,cdそしてabcdとかける
//と計算中のプログラムへの処理速度的な負荷が少なく済む
