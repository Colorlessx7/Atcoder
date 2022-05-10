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
  ll n, a, b;
  cin >> n >> a >> b;
  //文字列の配列 サイズはn*a(縦に対応)
  //s[i]の初期化はn*b文字(横に対応)で.で塗りつぶされた状態
  vector<string> s(n*a, string(n*b, '.'));
  //パネルの対応関係から偶奇性を使って黒マスの部分を塗り替える処理
  rep(i,n*a){
    rep(j,n*b){
      //マス(i,j)がn*nのパネルのどこに対応するかを計算
      //パネルの位置を(r,c)とするとr=i/aの切り捨て、c=j/bの切り捨てに対応する
      ll r = i/a, c = j/b;
      //r+cが奇数ならパネルは#なので#に変える
      if((r+c)%2 == 1){
        s[i][j] = '#';
      }
    }
  }
  //出力部
  rep(i,n*a){
    cout << s[i] << endl;
  }
  return 0;
}
//偶奇性考察と文字列配列処理
