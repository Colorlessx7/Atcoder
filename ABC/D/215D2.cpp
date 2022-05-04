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
//a[i]の素因数を重複なく格納するset
set<ll> st;
//約数列挙関数O(sqrt(a))
void divisor(ll n) {
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      st.insert(i);
      if (i * i != n) st.insert(n / i);
    }
  }
  return;
}
int main(){
  ll n, m;
  cin >> n >> m;
  //入力しながら約数列挙O(n*sqrt(a))
  rep(i,n){
    ll a;
    cin >> a;
    divisor(a);
  }
  //条件gcd(a,k)=1を満たす数字の個数を記録 
  ll ans = 0;
  //b[i]:0なら条件を満たさない,1なら条件を満たす
  vector<ll> b(m+1,1);
  //1はgcd(a,k)=1の条件を満たすため素因数を格納したsetから削除
  st.erase(1);
  //1を除いた約数の数を格納
  ll x = st.size();
  //setを小さい順に見るので一番小さい値が格納されたsetのイテレータを用意
  auto itr = st.begin();
  //1を除いた全約数の倍数が条件を満たさないのでb[i]=0にするO(x)
  //中身込みでO(xlogn)
  rep(i,x){
    //*itrで約数を取得,*itr*jで約数の倍数となるO(logN)
    for(ll j = 1; *itr * j <= m; j++){
      //約数の倍数k=*itr*jを0に
      b[*itr*j] = 0;  
    }
    //約数を進める(setのイテレータ)
    itr++;
  }
  //条件を満たす(b[i]=1)数をカウントO(m)
  rep2(i,m){
    if(b[i]){
      ans++;
    }
  }
  //条件を満たす数を出力
  cout << ans << endl;
  //条件を満たす数字を小さい順に出力O(m)
  rep2(i,m){
    if(b[i]){
      cout << i << endl;
    }
  }
  return 0;
}
//計算量が遅い解
//O(n*sqrt(a)+xlog(*itr)+2*m)で制限時間の1/4となりギリギリ間に合う形
