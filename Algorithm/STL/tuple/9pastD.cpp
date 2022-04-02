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
bool compare(tuple<ll,ll,ll> a, tuple<ll,ll,ll> b){
    if(get<0>(a) != get<0>(b)){
        //降順でsort
        return get<0>(a) > get<0>(b);
    }
    if(get<1>(a) != get<1>(b)){
        //降順sort
        return get<1>(a) > get<1>(b);
    }else{
        //昇順
        return get<2>(a) < get<2>(b);
    }
}
int main(){
  ll n;
  cin >> n;
  vector<ll> a(n),b(n);
  rep(i,n){
    cin >> a[i];
  }
  rep(i,n){
    cin >> b[i];
  }
  vector<tuple<ll,ll,ll>> sc(n);
  rep(i,n){
    sc[i] = make_tuple(a[i]+b[i],a[i],i+1);
  }
  sort(all(sc),compare);
  rep(i,n){
    cout << get<2>(sc[i]) << " ";
  }
  cout << endl;
  return 0;
}
