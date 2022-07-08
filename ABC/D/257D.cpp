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
  //n:頂点数
  int n;
  cin >> n;
  //(xi,yi):頂点iの座標,p[i]:頂点iのジャンプ台のパワー
  vector<int> x(n),y(n),p(n);
  rep(i,n){
    cin >> x[i] >> y[i] >> p[i];
  }
  //wa:高橋君のジャンプ力Sの下限(初めの0で初期化)
  ll wa = 0;
  //ac:高橋君のジャンプ力Sの上限
  //(PiS>=|xi-xj|+|yi-yj|より、Pが全て1で、xi,yiが全て最大の10^9
  //xj,yjが全て最小の-10^9の場合が予想されるSの最大パターンで絶対値内が2*10^9となり
  //S>=4*10^9となるため4*10^9で初期化する)
  ll ac = 4e9;
  //二分探索の実行(境界の差分が1の状態になるまで(waとacが隣接するまで))
  //O(N^3*logM)(N=200,M=4e9で7.682e7となり間に合う)
  while(abs(wa-ac) > 1){
    //wj:二分探索の中点
    ll wj = (wa+ac)/2;
    //S=wjとしたときに全ての頂点に何個かのジャンプ台を経由して辿れるかを判定する関数
    bool judge = [&]{
      //d[i][j]:S=wjとした時にi-j間をジャンプで行き来できるか(到達可:1,到達不可:0)
      vector d(n,vector<int>(n));
      //全頂点について2重ループO(N^2)
      rep(i,n){
        rep(j,n){
          //dist:頂点i,j間のマンハッタン距離
          //問題文の式のPiS>=|xi-xj|+|yi-yj|の右辺に対応
          ll dist = (ll)abs(x[i]-x[j])+abs(y[i]-y[j]);
          //問題文の式が条件を満たす(iからjに飛べる)なら処理
          if(wj*p[i] >= dist){
            //ジャンプできるなら1に
            d[i][j] = 1;
          }
        }
      }
      //ワーシャルフロイド法(bit演算で高速化を図る)O(N^3)
      //k:中継点,i始点,j終点
      rep(k,n){
        rep(i,n){
          rep(j,n){
            //i-k間、k-j間がどちらもS=wjで行き来可能ならd[i][j]を1にする
            d[i][j] |= d[i][k] & d[k][j];
          }
        }
      }
      //全頂点について別の頂点から辿って来れるかを確認するループ
      rep(i,n){
        //全頂点について別の頂点から辿って来れるかのflag(true初期化)
        bool ok = true;
        //頂点iから頂点j全部に0個以上の頂点を辿って到達可能かどうか判定
        rep(j,n){
          //iからjにS=wjで辿れない頂点が一つでも存在するなら処理
          if(d[i][j] != 1){
            //全頂点について別の頂点から辿って来れないのでfalse
            ok = false;
          }
        }
        //全頂点について別の頂点から辿って来れるなら処理
        if(ok){
          //trueを返す
          return true;
        }
      }
      //全頂点について別の頂点から辿って来れないのでfalseを返す
      return false;
    }();
    //S=wjとしてjudge結果がtrueなら処理
    if(judge){
      //S=wjとしても条件を満たすので成功ラインacをwjまで下げる
      ac = wj;
    }else {
      //S=wjとしてjudge結果がfalseなら処理
      //S=wjとして条件を満たさなかったので失敗ラインwaをwjまで上げる
      wa = wj;
    }
  }
  //最終的なS=acを出力
  cout << ac << endl;
  return 0;
}
//二分探索問題
//成功と失敗の判定はワーシャルフロイドを使い行う
