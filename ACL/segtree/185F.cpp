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
//二項演算(axorb)
ll op(ll a, ll b){
  return a^b;
}
//単位元(0初期化)
ll e(){
  return 0;
}
int main(){
  //n:整数列の数,q:クエリ数
  ll n, q;
  cin >> n >> q;
  //segtreeのコンストラクタ(n<=300000を超える数2^19で初期化)
  segtree<ll,op,e> a(1<<19);
  //segtreeの葉の設定
  rep(i,n){
    //ax:正数列aのi番目の値
    ll ax;
    cin >> ax;
    //segtreeのi番目にaxを格納
    a.set(i,ax);
  }
  //クエリ処理
  rep(i,q){
    //t:クエリの種類
    ll t, x, y;
    cin >> t >> x >> y;
    //xはindexとしてしか扱わないので0indexed調整のため-1
    //yはt=1の時xorでそのまま使い、t=2の時indexとして扱う
    x--;
    if(t == 1){
      //a[X]をa[X]xorYで置き換える処理
      //x番目の値a[X]を仮変数fに退避
      ll f = a.get(x);
      //a[X]xorYを計算
      f ^= y;
      //a[X]をa[X]xorYに変更
      a.set(x,f);
    }else {
      //[x,y)の全要素のxorを返す(右端のyを含まないので本来は0indexedの場合y+1と指定する
      //必要があるがyのみ1indexedで扱っているのでy+1を-1したらyなのでprod(x,y)となる)
      ll ans = a.prod(x,y);
      //[x,y)のxorの結果を出力
      cout << ans << endl;
    }
  }
  return 0;
}
//segtree解
