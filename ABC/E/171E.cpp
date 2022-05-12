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
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }
  ll s = 0;
  //s=x0^x1^x2^x3
  rep(i,n){
    s ^= a[i];
  }
  //xi=s^ai
  rep(i,n){
    a[i] ^= s;
  }
  //出力部
  rep(i,n){
    cout << a[i] << endl;
  }
  return 0;
}
//xorの性質を使って解く問題
//問題の条件はx1^x2^x3=a0,x0^x2^x3=a1,x0^x1^x3=a2,x0^x1^x2=a3で
//a^a=0という性質から、全てのaについてのxorを取り、それをsとすると2回登場したxiが消えるので
//s=a0^a1^a2^a3=x0^x1^x2^x3となる
//ここからは各xiの求め方だが、同じようにa^a=0で二回登場したものが消える性質から
//x0=s^a0=x0^(x1^x1)^(x2^x2)^(x3^x3),x1=s^a1,x2=s^a2,x3=s^a3となる
//これを実装する
