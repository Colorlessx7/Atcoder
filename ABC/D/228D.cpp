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
  //n:数列数2^20
  ll n = 1<<20;
  //q:クエリ数
  ll q;
  cin >> q;
  //s:順序付きsetでa[i]=-1のiについて格納されている
  set<ll> s;
  //はじめは全て-1なので全index(i)をsetに格納
  rep(i,n){
    s.insert(i);
  }
  //a:シミュレーション用の配列(サイズはn,初期値は-1)
  vector<ll> a(n,-1);
  //クエリ処理ループ
  rep(qi,q){
    //type:クエリの種類,x:添字に関する値
    ll type, x;
    cin >> type >> x;
    //クエリが1の時
    if(type == 1){
      //i:h=xiとした時の最初のhmodNを計算し格納
      ll i = x % n;
      //set内の最初の中身がi以上のイテレータはa[hmodN]=-1となる最初のindexを示す(ないならit=end())
      auto it = s.lower_bound(i);
      //a[i]~a[n-1]までにa[hmodN]=-1のものが存在しない場合は
      //setに格納されている値の中にi以上の値が存在せず、二分探索の結果it=s.end()になる
      //その場合、hmodNからa[0]~a[i-1]の間の一番最初のa[hmodN]=-1の場所をa[hmodN]=xiに置き換えるため
      //setの最初のイテレータの中身が書き換えるべき最初のa[hmodN]=-1の場所hmodNとなる
      if(it == s.end()){
        it = s.begin();
      }
      //*itで添字hmodNの値が格納されているイテレータの中身をとる
      //*it=hmodNなのでa[hmodN]=xiに書き換える処理を行う
      a[*it] = x;
      //a[hmodN]=-1だった場所をxiに書き換えたので-1の場所が一つ消えるため、
      //添字hmodNの値を示す*itのイテレータitをsetから削除する
      s.erase(it);
    }else {
      //クエリが0の時の処理
      //AximodNの値を出力
      printf("%lld\n",a[x%n]);
    }
  }
  return 0;
}
