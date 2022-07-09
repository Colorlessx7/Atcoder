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
  //予算
  int n;
  cin >> n;
  //数字の種類数
  int m = 9;
  //c[i]:xに数字i(i+1)を選んだ時のコスト
  vector<int> c(m);
  rep(i,m){
    cin >> c[i];
  }
  //l:xに数字i:(i+1)を選んだ時のコストが最小のものを格納(大きい値で初期化)
  int l = 1001001001;
  //最小を見つけて格納
  rep(i,m){
    l = min(l,c[i]);
  }
  //k:xの桁数(コストが最小のものをひたすら左からxとして並べた時の桁数がとりうる桁数の最大となる)
  int k = n / l;
  //最終的なxの値(初期化は何も決めていない状態)
  string ans;
  //桁数kについて左から数字を決めていくループ
  while(k){
    //xの右からk桁目についてiを数字が大きい順に処理し桁の数字を決めていく
    rep3(i,m){
      //xの右からk桁目をi:(i+1)とした時がxのとりうる最大だった時に処理
      //元々は(n-c[i])/l >= k-1 で、これは
      //k桁目をi:(i+1)とした時のコストc[i]を予算から引いた、k-1桁分に回せる残りの予算が
      //k-1桁分コストが最小の数字を並べた時にかかるコストよりも多い場合にk桁目にiを使える
      //iを大きい順に回しているのでこのif文を通った時点でxの最大はk桁目がiの時になり、それ以下を考えずに済む
      //移項が必要なのは、n-c[i]が負になる可能性があり、(n-c[i])/l=-1/5=0みたいな例が発生し、
      //予算が足りないのにif文が通る事態が発生するため移項して負の割り算をさせない必要がある
      //オーバーフローの可能性についてはk*l=nであるため右辺がオーバーフローする危険性はない
      if(n-c[i] >= (k-1)*l){
        //xの右からk桁目(ちょうどansにpushした先)をi:(i+1)とする
        ans += '1' + i;
        //予算からi:(i+1)を使った時のコストc[i]をひく
        n -= c[i];
        //xの右からk桁目についての処理が終わったのでこの桁についての処理を終了
        break;
      }
    }
    //残りの処理すべき桁数から1をひく
    k--;
  }
  cout << ans << endl;
  return 0;
}
//貪欲法
//xは桁数が大きいほどよく、桁数が一致しているなら左の方の桁が大きい数字である方が良い
//
