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
  //ax:n次多項式aの係数の数
  ll ax = n + 1;
  //cx:m次多項式cの係数の数
  ll cx = n+m+1;
  //bx:多項式bの係数の数(割り算の筆算の処理回数)
  ll bx = n+m+1-(n+1)+1;
  vector<ll> a(ax);
  //aの各係数の入力(以下のcと同様に以降の処理を楽にするため逆に入力を受け取っている)
  rep3(i,ax){
    cin >> a[i];
  }
  vector<ll> c(cx);
  rep3(i,cx){
    cin >> c[i];
  }
  vector<ll> b(bx);
  //筆算処理部
  rep(i,bx){
    //筆算のbのi桁目の数(割る数)を決める処理
    //問題の条件からcのi桁目からaの先頭の桁を割った結果は整数になる
    b[i] = c[i] / a[0];
    //割る数b[i]で除算を行った時に影響のある桁(ax桁)から数字を引く処理
    rep(j,ax){
      //cのi+j桁から割る数b[i]*aのj桁の数字を引く
      c[i+j] -= b[i] * a[j];  
    }
  }
  //出力部
  rep3(i,bx){
    cout << b[i] << endl;
  }
  return 0;
}
//除算の筆算のような計算を実装する問題
//    /   2  4  6
//1 2 / 2 8 14 12
//    / 2 4
//    /   4 14
//    /   4  8
//    /      6 12
//    /      6 12
//              0
//上のような筆算を実装するだけ
//
