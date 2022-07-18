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
  //d[i]:各条件でi人目がとった点数,num:何人合格させるか
  auto f = [&](vector<int> d, int num) {
    //まだ合格していない人のidのリスト(sortによって合格基準が高い方から順に並ぶ)
    vector<int> p;
    //全員に対して回す
    rep(i,n){
      //合格していないならpにまだ合格していない人のidを格納する
      if(!ok[i]){
        p.push_back(i);
      }
    }
    //比較関数(bool)
    auto cmp = [&](int i, int j){
      //i人目とj人目の点数が違う時に処理
      if(d[i] != d[j]){
        //点数について降順に並べる
        return d[i] > d[j];
      }
      //点数が同じ場合idが小さい順に並べる
      return i < j;
    };
    //点数を降順に,点数が同じならidが小さい順にsortさせる(比較関数cmpを通してsortする)
    sort(all(p),cmp);
    //sort終了後,先頭num人が合格した人になるため、合格させる人数分まわす
    rep(i,num){
      //secondが人のidになっているのでその人をbool配列上で合格にさせる
      ok[p[i]] = true;
    }
  };
  //上からx人を合格させる(関数の呼び出し)
  f(a,x);
  //未合格者の上からy人を合格させる(関数の呼び出し)
  f(b,y);
  //数学の点数に英語の点数を足し、aを合計点とする
  rep(i,n){
    a[i] += b[i];
  }
  //未合格者の上からz人を合格させる(関数の呼び出し)
  f(a,z);
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
