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
  ll n, q;
  cin >> n >> q;
  //ボールの番号についての配列
  vector<ll> ball(n);
  //pos[i]:ボールiのball配列のindexの現在地
  vector<ll> pos(n);
  //ボールの番号とindexの初期化(ボールiはi番目にある)
  rep(i,n){
    ball[i] = i;
    pos[i] = i;
  }
  //クエリ処理
  rep(qi,q){
    //動かすボールの番号
    ll x;
    cin >> x;
    //0indexed調整
    x--;
    //i:ボールxのindex
    ll i = pos[x];
    //ボールxの交換対象のindex(右隣なのでi+1)
    ll j = i+1;
    //j=nならiは右端なので左隣と交換するので
    //ボールxの交換対象のindexはi-1
    if(j == n){
      j = i-1;
    }
    //ボールxとの交換対象のボールの番号
    ll y = ball[j];
    //ball配列上でボールの位置を交換
    swap(ball[i],ball[j]);
    //上の処理に対応してボールのindexを交換
    swap(pos[x],pos[y]);
  }
  //出力部(ボールを0indexで扱っていたため+1)
  rep(i,n){
    cout << ball[i] + 1 << endl;
  }
  return 0;
}
