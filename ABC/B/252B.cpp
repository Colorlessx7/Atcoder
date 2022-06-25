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
  ll n, k;
  cin >> n >> k;
  //x[i][j]:おいしさがi+1の食品jが何番目の食品か
  vector<vector<ll>> x(100);
  //y[i]:食品iが嫌いならtrue,嫌いでないならfalse
  vector<bool> y(100);
  //食品情報の入力
  rep(i,n){
    ll a;
    cin >> a;
    //おいしさを0indexedにして扱う
    a--;
    x[a].push_back(i);
  }
  //嫌いな食品についてのループ
  rep(i,k){
    ll b;
    cin >> b;
    //食品の番号を0indexedで扱う
    b--;
    y[b] = true;
  }
  //おいしさが最大の食品から調査(i=99~0)
  rep3(i,100){
    //おいしさがi+1の食品の個数
    ll xx = x[i].size();
    //おいしさがi+1の食品が存在するなら処理
    if(xx){
      //おいしさがi+1の食品全てを調査
      rep(j,xx){
        //x[i][j]:おいしさがi+1の食品のid
        //trueなら嫌いな食品があったのでYesを出力し終了
        if(y[x[i][j]]){
          cout << "Yes" << endl;
          return 0;
        }
      }
      //嫌いな食品がおいしさが最大の食品になかったので判定を終了しNoを出力して終了
      break;
    }
  }
  cout << "No" << endl;
  return 0;
}
