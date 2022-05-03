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
  //筒m個をqueueの配列として確保
  vector<queue<ll>> a(m);
  //筒の中のボールの数(最初2*n個固定だから取り出す時だけカウントして最後にcnt=2*nか判定した方が良さそう)
  ll cnt = 0;
  rep(i,m){
    ll k;
    cin >> k;
    rep(j,k){
      ll aa;
      cin >> aa;
      aa--;
      a[i].push(aa);
      cnt++;
    }
  }
  //1:色,2:筒
  queue<P> que;
  //筒の場所を格納(id[i]:i色のボールが元々あった筒の番号を示す)
  vector<ll> id(n,-1);
  ll f;
  //初めに全ての筒の一番上のボールを取り出す処理
  rep(i,m){
    ll x = a[i].front();
    a[i].pop();
    cnt--;
    if(id[x] == -1){
      id[x] = i;
    }else {
      //元々見つけていた片方のボールの入っていた筒
      if(a[id[x]].size()){
        f = a[id[x]].front();
        a[id[x]].pop();
        cnt--;
        que.push({f,id[x]});
      }
      if(a[i].size()){
        f = a[i].front();
        a[i].pop();
        cnt--;
        que.push({f,i});
      }
      id[x] = -1;
    }
  }
  //それ以降のボールを取り出す処理
  while(que.size()){
    P s = que.front();
    ll x = s.first;
    ll i = s.second;
    que.pop();
    if(id[x] == -1){
      id[x] = i;
    }else {
      if(a[id[x]].size()){
        f = a[id[x]].front();
        a[id[x]].pop();
        cnt--;
        que.push({f,id[x]});
      }
      if(a[i].size()){
        f = a[i].front();
        a[i].pop();
        cnt--;
        que.push({f,i});
      }
      id[x] = -1;
    }
  }
  if(cnt){
    cout << "No" << endl;
  }else {
    cout << "Yes" << endl;
  }
  return 0;
}
//vector<queue<ll>>で解く解法
//初期状態のrep(i,m)でqueに突っ込むだけにして判定は全部whileの部分でやった方が良さそう
