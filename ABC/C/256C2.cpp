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
//h[i]:上からi段目の横3つの合計
vector<int> h(3);
//w[i]:左からi列目の縦3つの合計
vector<int> w(3);
//a[i][j]:タイル(i,j)の数字
vector<vector<int>> a(3,vector<int>(3));
ll ans = 0;
//dfs(ij:今見ているマスの場所)
void dfs(int ij) {
  //i:縦何マス目か ijを3で切り捨てたものに対応(012,全部埋めた時だけ3)
  //j:横何マス目が ijを3で割った余りに対応(012)
  int i = ij / 3, j = ij % 3;
  //全部埋められたなら答えを+1する
  if (i == 3) {
    ans++;
    return;
  }
  //i=2の時は上2*3マスが埋まっているので下1段が条件を満たすような数字にできるかの
  //判定をして、できるなら次のマスにdfsで移動、できないなら遷移元に返す
  //(h[3]とw[3]の条件のどちらかがa[2][2]と合わないパターンは
  //main関数内のhとwの合計比較で除外しているので判定しなくて良い)
  if (i == 2) {
    //j列目の上2段から下一段を求める
    int x = w[j] - a[0][j] - a[1][j];
    //下一段が0以下なら不可能なのでdfsの遷移元に返す
    if (x <= 0) return;
    //下1段が1以上ならタイル(i,j)にxを設定し、次のマスを見るためにdfs
    a[i][j] = x, dfs(ij + 1);
    //一段目二段目の右端一マスの時処理
  } else if (j == 2) {
    //i行目の左2列から右一列を求める
    int x = h[i] - a[i][0] - a[i][1];
    //右1列が0以下なら不可能なのでdfsの遷移元に返す
    if (x <= 0) return;
    //右1列が1以上ならタイル(i,j)にxを設定し、次のマスを見るためにdfs
    a[i][j] = x, dfs(ij + 1);
  } else {
    //自分で決めるマス(左上2*2)の時処理
    //1~30までを適当にタイル(i,j)にxを設定し、次のマスを見るためにdfs
    for (int x = 1; x <= 30; x++) a[i][j] = x, dfs(ij + 1);
  }
  //x<=0でreturnするときはマスを自分で決める左上2*2のfor文の処理後の場所に戻る
}
int main() {
  for (int i = 0; i < 3; i++) cin >> h[i];
  for (int j = 0; j < 3; j++) cin >> w[j];
  //h三つの合計、w三つの合計はどちらとも題意よりaの9マスの合計となる
  //つまり合計が一致していないなる埋めようがない
  if (h[0] + h[1] + h[2] != w[0] + w[1] + w[2]) {
    cout << 0 << "\n";
    return 0;
  }
  //dfsの開始
  dfs(0);
  cout << ans << "\n";
}
//dfs解
//この問題のijはどのマスを見ているかに対応する(下の表を参照)
//012
//345
//678
//(全て埋めて9)
