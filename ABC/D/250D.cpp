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
//エラトステネスの篩で素数かどうかを判定するための配列
vector<bool> primes;
//列挙した素数を格納する配列
vector<ll> d;
//問題の条件k=p*q^3<=nからとりうる最大の素数はq<=nの三乗根より
//10^6くらいまでとなる
const ll M = 1e6;
//エラトステネスの篩をする関数
void prime(){
  //0,1は素数ではないので0
  primes[0] = primes[1] = 0;
  //最初の素数である2から判定する最大値のMまで回す
  for(ll i = 2; i <= M; ++i){
    //primes[i]=0ならiは素数ではないのでコンティニュー
    if(!primes[i]){
      continue;
    }
    //iは素数なので素数配列dに格納
    d.push_back(i);
    //i^2から素数iの倍数[i*j]を全てfalseにする
    for(ll j = i*i; j <= M; j += i){
      //素数iの倍数は素数でないのでfalseに
      primes[i * j] = 0;
    }
  }
  return;
}
int main(){
  //条件の数
  ll n;
  cin >> n;
  //エラトステネス用の配列のresizeと初期化を行う
  primes = vector<bool>(M+1,1);
  //エラトステネスの篩の実行
  prime();
  //s[i]:i以下の素数の個数(累積和)
  vector<ll> s(M+1);
  //全素数について回す
  for(ll p : d){
    //素数なら1にする
    s[p] = 1;
  }
  //この時点でsは素数なら1,素数でないなら0の状態となる
  //次のループで素数の個数を足し合わせて累積和の形とする
  rep(i,M){
    s[i+1] += s[i];
  }
  //(p,q)の組み合わせの数
  ll ans = 0;
  //全ての素数について回す
  for(ll q : d){
    //問題文の条件はk=p*q^3<=n,p<qで移項するとp<=n/q^3,p<=q-1
    //よってp<=min(n/q^3,q-1)となる
    ll p = min<ll>(n/q/q/q, q-1);
    //p以下の素数の数だけ答えにたす
    ans += s[p];
  }
  //出力部
  cout << ans << endl;
  return 0;
}
//エラトステネスの篩で素数を列挙し、条件式にあう数字の個数を累積和配列から高速に求める問題
