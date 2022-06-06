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
  ll ans = 0;
  //1~nまで愚直に処理(iを固定した時、jの候補がいくつあるか求めるループ)O(n)
  rep2(i,n){
    //i*kが平方数となる最小のkは、iを平方数で割れるだけ割って残った数になる
    //これを求めるためにkにiを代入する
    ll k = i;
    //最小のkを求めるループO(sqrt(n))
    for(ll d = 2; d*d <= k; d++){
      //平方数d*dでkを割れるだけ割る
      while(k%(d*d)==0){
        k /= d*d;
      }
    }
    //j=k*d*d O(sqrt(n))
    for(ll d = 1; k*d*d <= n; d++){
      //dを決めた時のk*d*dがn以下(範囲内)なら
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
//数学問題(全体O(N*sqrt(N)))
//平方数の条件は素因子がペアにできるか(x:12=(2*2)*(3) o:36=(2*2)*(3*3))
//上のプログラムの動作をi=72,n=49を例として考えると
//i=72,k=72,一回目のfor文で2*2,3*3で割られてk=2
//d=1:j=2*1*1=2,d=2:j=2*2*2=8,d=3:j=2*3*3=18,d=4:j=2*4*4=32がjの候補となる
