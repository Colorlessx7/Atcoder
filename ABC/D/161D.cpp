#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(ll i = 0; i < N; i++)
#define rep2(i,N) for(ll i = 1; i <= N; i++)
#define rep3(i,N) for(ll i = N - 1; i >= 0; i--)
#define rep4(i,N) for(ll i = N; i > 0; i--)
#define replr(i,l,r) for(ll i = l; i < r; i++)
#define reprl(i,l,r) for(ll i = l; i > r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
using ll = long long;
using P = pair<ll,ll>;
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  ll k;
  cin >> k;
  //ルンルン数の新しい方を格納(桁数が多い方)
  vector<ll> a;
  //最初のルンルン数1桁の設定(初期化)
  for(ll i = 1; i <= 9; i++){
    a.push_back(i);
  }
  //k番目のルンルン数の桁数分全て処理するまでループ
  //ループ開始地点に戻るたびにaに格納されているルンルン数の桁数が全て一つ増える
  while(1){
    //k番目(38行目から実際のkとは少し違う)のルンルン数ができたら処理
    if(k <= a.size()){
      //kは1indexed,配列は0indexedなのでk-1番目のルンルン数を出力して終了
      cout << a[k-1] << endl;
      return 0;
    }
    //これまでの処理で得られたルンルン数がk個に満たないならば
    //(k番目のルンルン数がaに格納されているルンルン数の桁数でなかった場合)
    //kからこれまでに見つかったルンルン数の個数をひく
    k -= a.size();
    //一つ前の桁数のルンルン数を格納する配列
    vector<ll> old;
    //swapでdpの時と同じようにoldからaに遷移させる
    //oldに格納されたルンルン数を使って末尾に数字を追加することで1つ桁の多いルンルン数を作成
    swap(a,old);
    //既存のルンルン数(1桁小さいルンルン数全部)から新しいルンルン数(1桁多いもの)を作成
    for(ll x : old){
      //一つ桁数の多いルンルン数を作る
      //ルンルン数としてカウントできるのは隣り合う桁の数字の絶対値の差が
      //1以下の場合なので既存のルンルン数の最後の１桁の数字の-1,0,+1したものを
      //末尾にくっつける方針で行う
      for(ll i = -1; i <= 1; i++){
        //dは既存のルンルン数の末尾にくっつける数
        //既存のルンルン数xの最後の1桁をx%10で取り出して
        //絶対値の差が1以下になるように-1,0,+1したもの(i)を足す
        ll d = x%10 + i;
        //dが0より小さいまたは10以上の場合は十進数として扱えないのでスルーする
        if(d < 0 || d > 9){
          continue;
        }
        //nxは新しい既存のと比べて桁数が1多いルンルン数
        //既存の処理しているルンルン数を10倍してdを足すと新しいルンルン数になる
        ll nx = x*10 + d;
        //新しいルンルン数が作れたのでaに格納
        a.push_back(nx);
      }
    }
  }
  return 0;
}
//ルンルン数の桁数ごとに分けて考える解法1
//1桁のルンルン数を全て作る、その中にk番目のルンルン数があるか判定、
//2桁のルンルン数を全て作る、その中にk番目のルンルン数があるか判定、
//...n桁のルンルン数を全て作る、その中にk番目のルンルン数があるか判定を繰り返す
//k番目のルンルン数が出たらそれを出力して終了
