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
int solve(){
  //座標(x1,y1)から座標(x2,y2)まで何手で行けるか
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  //始点と終点が等しいなら0回
  if(x1 == x2 && y1 == y2){
    return 0;
  }
  //左下-右上方向の移動 斜め一直線上なので1回(問題の条件式1)
  if(x1 + y1 == x2 + y2){
    return 1;
  }
  //左上-右下方向の移動 斜め一直線上なので1回(問題の条件式2)
  if(x1 - y1 == x2 - y2){
    return 1;
  }
  //x軸,y軸方向合わせて絶対値3マス分の距離は動けるので1回(問題の条件式3)
  if(abs(x1 - x2) + abs(y1 - y2) <= 3){
    return 1;
  }
  //始点と終点のパリティ(偶奇)が一致しているなら2回(条件式1,2の斜め2回で到着可)
  if((x1 + y1)%2 == (x2 + y2)%2){
    return 2;
  }
  //マンハッタン距離が6以下なら2回(条件式3を2回行う)
  if(abs(x1 - x2) + abs(y1 - y2) <= 6){
    return 2;
  }
  //条件式1,3で飛ぶ場合
  if(abs((x1 + y1) - (x2 + y2)) <= 3){
    return 2;
  }
  //条件式2,3で飛ぶ場合
  if(abs((x1 - y1) - (x2 - y2)) <= 3){
    return 2;
  }
  //全てくぐり抜けたら3回必要
  return 3;
}
int main(){
  cout << solve() << endl;
  return 0;
}
//ひたすら場合分けする問題
//マンハッタン距離と45度回転は要勉強
