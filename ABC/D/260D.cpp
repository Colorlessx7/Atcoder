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
  //重ねられたカードの一番上のカードの書かれてある数字の集合
  //(二分探索でどの山に重ねるかを探索するため)
  set<int> tops;
  //nxt[i]:数字iが書かれたカードの下に重なっているカードの数字(下にない場合-1)
  //num[i]:数字iが書かれたカードの下に重なっているカードの個数(数字iも枚数に含む)
  vector<int> nxt(n,-1), num(n);
  //ans[i]:数字iが書かれたカードが何ターン目に消されるか(消されない場合-1)
  vector<int> ans(n,-1);
  //全ての数字について回す(ni+1がターン数にもなる)
  //O(N),全体でO(NlogN)
  rep(ni,n){
    //p:i番目の数字
    int p;
    cin >> p;
    //配列で扱うため0indexed調整
    p--;
    //set内の初めてp以上になる値が格納されている場所のイテレータを二分探索で調べる
    //O(logN)
    auto it = tops.lower_bound(p);
    //二分探索で求めたイテレータがend()を示すならp以上になる値が存在しなかったので
    //引いたカードpをどれにも重ねずに表向きで場に置くためp以下のカードの束の枚数を1とする
    if(it == tops.end()){
      num[p] = 1;
      //場に見えている表向きのカードであって書かれた整数がX以上であるものがある時に処理
    }else {
      //場に見えている表向きのカードであって書かれた整数がX以上であるもののうち
      //書かれた整数が最小のものをさすイテレータがitなのでその中身をiとする
      int i = *it;
      //pの下に重ねられたのでitがさす値を場の一番上のカードの集合から削除する
      tops.erase(it);
      //iの上にpを重ねるのでpの下のカードを示すnum[p]にiを格納する
      nxt[p] = i;
      //iの上にpを重ねるのでpの束のカードの枚数はiの束の枚数にpの分+1したものになる
      num[p] = num[i] + 1;
    }
    //pの束の枚数がkになったら食べる処理をする
    if(num[p] == k){
      //食べるのでその束がなくなるため一番上の数字pを一番上のカードの集合から削除する
      tops.erase(p);
      //pが一番上のカードの束を上から順に辿っていく
      //今見ているカードの番号をiとする
      int i = p;
      //下に何もない状態まで上から探索していく
      while(i != -1){
        //カードiが消えるのでiが消えるターン数を代入する
        //niが0indexedなので1indexedにする(+1)とターン数として扱える
        ans[i] = ni+1;
        //iをiの下のカードの番号で更新する(ない場合-1になる)
        i = nxt[i];
      }
      //pの束が食べられない場合新しくpが一番上のカードとなるので
      //一番上のカードの数字の集合にpを格納する
    }else {
      tops.insert(p);
    }
  }
  //カードiが消えたターン数を出力する(消えない場合-1)
  rep(i,n){
    cout << ans[i] << '\n';
  }
  return 0;
}
//setで二分探索することによって高速化する問題
//普通に実装するとカードの追加更新でO(N),どこに重ねるかの探索でO(N)かかり、
//全体でO(N^2)かかるためTLEする
//どこに重ねるかの探索を二分探索でやればO(NlogN)になるのでそこを改善する
//処理に必要な情報は、見えている一番上のカードの一覧(二分探索とsortの手間回避でsetを使う)と
//カードの山の情報(p)と、束の枚数(num)と、束のリスト(nxt)を持っておけば良い
//もう一つの注意点として、束のリストを管理するときに、cards[i]=一番上のカードがiの山に含まれる
//カードの一覧という形で持つと、新規カードが上に重なった場合
//cards[new_i]=配列cards[i]+new_iという形になり、cards[i]のコピーが発生すると
//O(N)となりTLEしてしまうため、参照をもつかmove関数を使うか、別の手段を使うなりしないといけない
//(今回は別の手段で管理する)
//
//x以上で最小のものを高速で見つけるのは、set以外にもsegtreeや平衡二分探索木でもできる
