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
//n:マスの縦,横の長さ
//T:操作回数の限界
ll n, T;
//空きマスの上下左右を動かすので空きマスの座標を持つ必要がある
//center_x:空きマス(入力で0のやつ)のx座標(i,j)の時のjに対応
//center_y:空きマス(入力で0のやつ)のy座標(i,j)の時のiに対応
ll center_x, center_y;
//入力の文字群(n*nマス分)
vector<vector<char>> t;
void input(){
  cin >> n >> T;
  t = vector(n,vector<char>(n));
  rep(i,n){
    rep(j,n){
      cin >> t[i][j];
      if(t[i][j] == '0'){
        center_x = j;
        center_y = i;
      }
    }
  }
}
void output(){
  srand((unsigned) time(NULL));
  string ans;
  rep(i,T){
    ll rand_num = rand();
    if(rand_num % 4 == 0){
      if(center_y != 0){
        ans += 'U';
        center_y--;
      }
    }else if(rand_num % 4 == 1){
      if(center_y != n-1){
        ans += 'D';
        center_y++;
      }
    }else if(rand_num % 4 == 2){
      if(center_x != 0){
        ans += 'L';
        center_x--;
      }
    }else {
      if(center_x != n-1){
        ans += 'R';
        center_x++;
      }
    }
  }
  cout << ans << endl;
}
int main(){
  input();
  output();
  return 0;
}
