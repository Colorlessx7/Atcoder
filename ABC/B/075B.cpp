#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(ll i = 0; i < N; i++)
#define rep2(i,N) for(ll i = 1; i <= N; i++)
#define rep3(i,N) for(ll i = N - 1; i >= 0; i--)
#define rep4(i,N) for(ll i = N; i > 0; i--)
#define replr(i,l,r) for(ll i = l; i <= r; i++)
#define reprl(i,l,r) for(ll i = l; i >= r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
using ll = long long;
using P = pair<ll,ll>;
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  ll h, w;
  cin >> h >> w;
  vector<vector<char>> s(h+2,vector<char>(w+2,'.'));
  rep2(i,h){
    rep2(j,w){
      cin >> s[i][j];
    }
  }
  vector<vector<ll>> ans(h+2,vector<ll>(w+2,0));
  rep2(i,h){
    rep2(j,w){
      replr(a,-1,1){
        replr(b,-1,1){
          if(a == 0 && b == 0){
            continue;
          }
          if(s[i+a][j+b] == '#'){
            ans[i][j]++;
          }
        }
      }
    }
  }
  rep2(i,h){
    rep2(j,w){
      if(s[i][j] == '#'){
        cout << '#';
      }else {
        char c = ans[i][j] + '0';
        cout << c;
        //(失敗例)cout << ans[i][j]+'0';
      }
    }
    cout << endl;
  }
  return 0;
}
