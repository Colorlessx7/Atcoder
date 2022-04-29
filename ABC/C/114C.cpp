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
  queue<string> q;
  string s;
  s = '3';
  q.push(s);
  s = '5';
  q.push(s);
  s = '7';
  q.push(s);
  ll ans = 0;
  while(q.size()){
    s = q.front();
    q.pop();
    ll x = s.size();
    bool f3 = false;
    bool f5 = false;
    bool f7 = false;
    ll nx = 0;
    rep3(i,x){
      nx *= 10;
      if(s[i] == '3'){
        f3 = true;
      }
      if(s[i] == '5'){
        f5 = true;
      }
      if(s[i] == '7'){
        f7 = true;
      }
      nx += (s[i] - '0');
    }
    if(f3 && f5 && f7 && (n >= nx)){
      ans++;
    }
    if(x < 9){
      s += '3';
      q.push(s);
      s.pop_back();
      s += '5';
      q.push(s);
      s.pop_back();
      s += '7';
      q.push(s);
    }
  }
  cout << ans << endl;
  return 0;
}
//queue解法
//3,5,7と33みたいなくっつけた後のものに、3,5,7をくっつけ続け条件に合うものだけを計上する
