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
  const ll L = 100001;
  //個数分布
  vector<bool> x(L);
  //入力をとる
  rep(i,n){
    ll a;
    cin >> a;
    //aが存在するので個数分布xのa番目をtrueに
    x[a] = true;
  }
  //約数のリスト
  vector<ll> d;
  //1を除く約数の判定(1はgcd(a,k)=1)計算量はO(L),中身も含めてO(LlogL)
  for(ll i = 2; i < L; i++){
    //n個のaの中に約数iが含まれていたらtrue,含まれないならfalse
    bool flag = false;
    //iの倍数jがn個のaの中に存在したか判定(j+=iより計算量はo(logL))
    for(ll j = i; i < L; j += i){
      //個数分布上でiの倍数jが存在したら約数iがn個のaの中に存在したことになるのでflagを立てる
      if(x[j]){
        flag = true;
      }
    }
    //flagが立っている(iが約数である)ため約数のリストにiを追加
    if(flag){
      d.push_back(i);
    }
  }
  //問題分の条件gcd(a,k)=1を満たすかどうかのbool配列(trueなら満たす)
  vector<bool> ok(m+1,true);
  //約数のリスト内の約数全てについて探索
  for(ll i : d){
    //その約数の倍数j全てがgcd(ai,k)=1を満たさないのでok[j]をfalseに
    for(ll j = i; j <= m; j += i){
      ok[j] = false;
    }
  }
  //問題の条件を満たす数字の個数のカウンタ
  ll cnt = 0;
  //問題の条件を満たすならok[i]がtrueになっているので判定しインクリメント
  rep2(i,m){
    if(ok[i]){
      cnt++;
    }
  }
  //問題の条件を満たす数字の個数を出力
  cout << cnt << endl;
  //問題分の条件を満たす数字を小さい順に出力
  rep2(i,m){
    if(ok[i]){
      cout << i << endl;
    }
  }
  return 0;
}
