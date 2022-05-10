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
  vector<ll> a(n);
  //aを0,1,2,3...で初期化
  iota(all(a),0);
  //key:ボールの番号,value:a配列のkeyの番号のボールがあるindex
  map<ll,ll> id;
  //mapの初期化(ボールiはi番目にある)
  rep(i,n){
    id[i] = i;
  }
  //クエリ処理
  rep(i,q){
    //動かすボールの番号
    ll x;
    cin >> x;
    //0indexed調整
    x--;
    //ボールxの添字が右端
    if(id[x] == n-1){
      //ボールの番号の配列についてswap
      swap(a[id[x]],a[id[x]-1]);
      //ボールのindexの位置についてswap
      swap(id[a[id[x]]],id[a[id[x]-1]]);
    }else {
      //ボールxの添字が右端でない
      //ボールの番号の配列についてswap
      swap(a[id[x]],a[id[x]+1]);
      //ボールのindexの位置についてswap
      swap(id[a[id[x]]],id[a[id[x]+1]]);
    }
  }
  //出力部(ボールを0indexで扱っていたため+1)
  rep(i,n){
    cout << a[i] + 1 << endl;
  }
  return 0;
}
