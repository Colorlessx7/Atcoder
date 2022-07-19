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
using TP = tuple<int,int,int>;
template<typename Tx, typename Ty>Tx dup(Tx x, Ty y){return (x+y-1)/y;}
void chmin(int &x, int y){ x = min(x,y); }
void chmax(int &x, int y){ x = max(x,y); }
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  int n, k;
  cin >> n >> k;
  //ans[i]:数字iが書かれたカードが何ターン目に消されるか(消されない場合-1)
  vector<int> ans(n+1,-1);
  //key:カードの束の一番上のカード,value:その束のカードの数字のリスト(keyを含む)
  map<int,vector<int>> yama;
  //全ての数字について回す(iがターン数にもなる)
  //O(N),全体でO(NlogN)
  rep2(i,n){
    //p:i番目の数字
    int p;
    cin >> p;
    //map内のkeyが初めてp以上になる値が格納されている場所のイテレータを二分探索で調べる
    //O(logN)
    auto it = yama.lower_bound(p);
    //二分探索で求めたイテレータがend()を示すならp以上になる値が存在しない
    //pをすでに存在するカードの束に重ねる場合の処理
    if(it != yama.end()){
      //イテレータitが指すvalueの配列をyama[p]の配列として参照渡しを行う
      //これが処理された時点でitが指すvalueの配列が空に、
      //yama[p]のvalueの配列が参照渡し前ののitが指すvalueの配列と同じ形になる
      //move関数によって参照を渡すことにより計算量の悪化を防ぐ
      yama[p] = move(it -> second);
      //pが上に重ねられることによって元々のitが指すkeyの束がpの束になり
      //消えてしまうのでitが指す情報を削除する
      yama.erase(it);
      //場に見えている表向きのカードであって書かれた整数がX以上であるものがある時に処理
    }
    //map内のkeyが初めてp以上になる値があったとしてもなかったとしても
    //一番上がpの束が出来上がるので一番上がpの束のリストにpを追加する
    yama[p].push_back(p);
    //pの束の枚数がkになったら食べる処理をする
    if(yama[p].size() == k){
      //pの下に重なっているカードの数字全てについて処理
      //(ならし計算量でO(1))
      for(auto y : yama[p]){
        //ターンiで食べられるのでカードyの食べられるターンにiを格納
        ans[y] = i;
      }
      //pの山が食べられ消滅したのでpの束のリストをmapから削除する
      yama.erase(p);
    }
  }
  //カードiが消えたターン数を出力する(消えない場合-1)
  rep2(i,n){
    cout << ans[i] << '\n';
  }
  return 0;
}
