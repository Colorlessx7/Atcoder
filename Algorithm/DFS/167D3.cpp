#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int main() {
  int n; ll k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  //辿りうる頂点を列挙する配列
  vector<int> s;
  //ordがすでに到着しているなら最初の頂点からの移動回数
  //到着していないなら-1が格納される配列
  vector<int> ord(n+1,-1);
  int c = 1, l = 0;
  //{}は他と同様に括弧外と括弧内で変数が違うものになる
  {
      //最初の頂点1をvに
    int v = 1;
    while (ord[v] == -1) {
      //その頂点に到達するまでの移動回数をセット  
      ord[v] = s.size();
      //現在の頂点は移動する可能性が発生したので辿りうる頂点として格納
      s.push_back(v);
      //テレポート先の頂点をvにセット
      v = a[v-1];
    }
    //閉区間の長さ
    c = s.size() - ord[v];
    //l:閉区間外(最初の部分)の長さ
    l = ord[v];
  }
  //閉区間外の最初の部分で移動が終わるなら単純にk番目の頂点を出力
  if (k < l) cout << s[k] << endl;
  else {
    //閉区間外の最初の部分を引いて閉区間のみとして考える  
    k -= l;
    //最後の一周未満の移動を考えるために余りを求める
    k %= c;
    //閉区間外の分と最後の一周で移動する分を足した順番にある頂点を出力
    cout << s[l+k] << endl;
  }
  return 0;
}
//綺麗な書き方ver
