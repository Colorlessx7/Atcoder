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
  ll n;
  cin >> n;
  vector<P> ab(n);
  rep(i,n){
    cin >> ab[i].second >> ab[i].first;
  }
  sort(all(ab));
  ll num = 0;
  rep(i,n){
    num += ab[i].second;
    ab[i].second = num;
  }
  rep(i,n){
    if(ab[i].first < ab[i].second){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
//pairのsortは基本firstを昇順に、secondを昇順にという形なので
//この問題はfirstとsecondの入力を逆にすれば比較関数を用意しなくて良い
