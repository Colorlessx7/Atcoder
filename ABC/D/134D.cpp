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
  vector<ll> a(n+1);
  rep2(i,n){
    cin >> a[i];
  }
  //ボールを箱iに入れるか
  vector<bool> c(n+1);
  //ボールを入れる箱の個数
  ll m = 0;
  rep4(i,n){
    ll cnt = 0;
    for(ll j = i; j <= n; j += i){
      //すでに処理した部分にiの倍数の箱があるなら
      //iの倍数が書かれた箱に入っているボールの個数の偶奇が変わるので確認
      if(j != i && c[j]){
        //iの倍数の箱に入ったボールの数をインクリメント
        cnt++;
      }
    }
    //ボールの個数を偶奇に変換
    cnt %= 2;
    //a[i]とi以外のiの倍数の箱のボールの数の偶奇が一緒なら
    //iにはボールを入れない
    if(cnt == a[i]){
      c[i] = false;
    }else {
      //a[i]とi以外のiの倍数の箱のボールの数の偶奇が違うなら
      //ボールを入れることにしてボールを入れる箱の個数をインクリメント
      c[i] = true;
      m++;
    }
  }
  //出力部
  cout << m << endl;
  //箱iにボールを入れる(c[i]=true)ならiを出力
  rep2(i,n){
    if(c[i]){
      cout << i << " ";
    }
  }
  //m=0の時空白ができるので回避(意味はないと思う)
  if(m){
    cout << endl;
  }
  return 0;
}
//後ろから考える問題
//後ろからボールを入れるかa[i]との整合性を見ながら決めていくと
//いいボールの入れ方は必ず存在するので-1出力は考える必要がない
