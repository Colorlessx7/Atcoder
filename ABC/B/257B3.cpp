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
using ll = long long;
using P = pair<int,int>;
using TP = tuple<int,int,int>;
void chmin(int &x, int y){ x = min(x,y); }
void chmax(int &x, int y){ x = max(x,y); }
int main(){
  int n, k, q;
  cin >> n >> k >> q;
  //a[i]:左からi個目の駒の座標
  vector<int> a(k);
  rep(i,k){
    cin >> a[i];
  }
  //番兵法
  //存在しないn+1マスに駒を置いておくことによって
  //駒が右端のマスに存在するかの判定を無視できる
  a.push_back(n+1);
  //クエリ処理
  rep(_,q){
    //l:左から何番目の駒を動かすか
    int l;
    cin >> l;
    //駒の順番を配列aで0indexedで管理しているので-1
    l--;
    //左からl番目の駒の1つ右のマスに駒が存在する場合操作できないのでコンティニュー
    if(a[l]+1 == a[l+1]){
      continue;
    }
    //条件を満たすなら左からl番目の駒を1つ右にずらす
    a[l]++;
  }
  //全ての駒について処理
  //(左からk個の駒を出力するので番兵の駒は出力されない)
  rep(i,k){
    //駒の座標を出力
    cout << a[i] << endl;
  }
  return 0;
}
//bool配列で駒のシミュを行うのでなく、駒の座標の情報をそのまま動かす解法
//番兵法にてプログラムを改善したver
