#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define replr(i,l,r) for(int i = l; i < r; i++)
#define reprl(i,l,r) for(int i = l; i >= r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
#define sz(v) (int)v.size()
using ll = long long;
using P = pair<int,int>;
using TP = tuple<int,int,int,int>;
template<typename Tx, typename Ty>Tx dup(Tx x, Ty y){return (x+y-1)/y;}
void chmin(int &x, int y){ x = min(x,y); }
void chmax(int &x, int y){ x = max(x,y); }
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  int n, x, y, z;
  cin >> n >> x >> y >> z;
  vector<int> a(n);
  vector<int> b(n);
  rep(i,n){
    cin >> a[i];
  }
  rep(i,n){
    cin >> b[i];
  }
  //ok[i]:i人目が合格したか(T:合格,F:不合格)
  vector<bool> ok(n);
  //上から順に合格認定をさせる関数
  //p:(fi:点数,se:人のid),num:何人合格させるか
  auto f = [&](vector<P> p, int num) {
    //点数を降順にsortさせる(配列を作る過程で点数に-1をかけているため
    //昇順にsortすると点数について降順に並ぶ)
    sort(all(p));
    //合格させる人数分まわす
    rep(i,num){
      //secondが人のidになっているのでその人をbool配列上で合格にさせる
      ok[p[i].second] = true;
    }
  };
  //fi:点数,se:人のidのpair配列
  vector<P> p;
  //全員分まわす
  rep(i,n){
    //数学の点数a[i]に-1をかけたものをfiに、idをseにして配列に格納
    p.emplace_back(-a[i],i);
  }  
  //まだ合格していない人について上からx人合格させる
  f(p,x);
  //pの中身を空に
  p = vector<P>();
  //全員分まわす
  rep(i,n){
    //まだ合格していない人のみ配列に格納する
    if(!ok[i]){
      //英語の点数b[i]に-1をかけたものをfiに、idをseにして配列に格納
      p.emplace_back(-b[i],i);
    }
  }
  //まだ合格していない人について上からy人合格させる
  f(p,y);
  //pの中身を空に
  p = vector<P>();
  //全員分まわす
  rep(i,n){
    //まだ合格していない人のみ配列に格納する
    if(!ok[i]){
      //合計の点数a[i]+b[i]に-1をかけたものをfiに、idをseにして配列に格納
      p.emplace_back(-a[i]-b[i],i);
    }
  }
  //まだ合格していない人について上からz人合格させる
  f(p,z);
  //全員分まわす
  rep(i,n){
    //合格している人のみ処理
    if(ok[i]){
      //合格者のidを1indexedに直して出力
      cout << i+1 << endl;
    }
  }
  return 0;
}
