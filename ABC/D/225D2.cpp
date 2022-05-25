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
vector<ll> front;
vector<ll> back;
ll st;
ll m;
void search(ll i){
  m++;
  if(front[i] == -1){
    st = i;
    return;
  }
  search(front[i]);
}
void rev(ll i){
  m++;
  if(back[i] == -1){
    return;
  }
  rev(back[i]);
}
void prt(ll i){
  if(back[i] == -1){
    printf("%lld\n",i+1);
    return;
  }
  printf("%lld ",i+1);
  prt(back[i]);
}
int main(){
  ll n, q;
  cin >> n >> q;
  front.resize(n,-1);
  back.resize(n,-1);
  rep(qi,q){
    ll t,x;
    cin >> t >> x;
    x--;
    if(t == 1){
      ll y;
      cin >> y;
      y--;
      back[x] = y;
      front[y] = x;
    }else if(t == 2){
      ll y;
      cin >> y;
      y--;
      back[x] = -1;
      front[y] = -1;
    }else {
      m = 0;
      search(x);
      rev(x);
      m--;
      cout << m << " ";
      prt(st);
    }
  }
  return 0;
}
