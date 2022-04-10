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
  ll k;
  cin >> k;
  queue<ll> q;
  //最初のルンルン数1桁の設定(初期化)
  for(ll i = 1; i <= 9; i++){
    q.push(i);
  }
  ll cnt = 0;
  while(1){
    ll x = q.front();
    q.pop();
    cnt++;
    if(cnt == k){
      cout << x << endl;
      return 0;
    }
    for(ll i = -1; i <= 1; i++){
      ll d = x%10 + i;
      if(d < 0 || d > 9){
        continue;
      }
      ll nx = x*10 + d;
      //新しいルンルン数が作れたのでaに格納
      q.push(nx);
    }  
  }
  return 0;
}
//ルンルン数の桁数ごとに分けて考える解法2
//queueで実装する
//1桁のルンルン数を全て作る、その中にk番目のルンルン数があるか判定、
//2桁のルンルン数を全て作る、その中にk番目のルンルン数があるか判定、
//...n桁のルンルン数を全て作る、その中にk番目のルンルン数があるか判定を繰り返す
//k番目のルンルン数が出たらそれを出力して終了
