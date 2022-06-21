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
  int n;
  cin >> n;
  //a[i]:時刻iが区間の範囲になっている区間が何個存在するか
  vector<int> a(200001);
  //区間情報入力
  rep(i,n){
    int l, r;
    cin >> l >> r;
    //lで区間が始まるのでa[l]に1を足す(イベントの開始)
    a[l]++;
    //rで区間が終わるのでa[l]から1を引く(イベントの終了)
    a[r]--;
  }
  //累積和を取ることで各イベントの開始と終わりだけの情報だったのが
  //時刻iが区間の範囲になっている区間が何個存在するかに変わる
  rep2(i,200001){
    a[i] += a[i-1];
  }
  //各時刻i=1~200000について回す
  rep2(i,200001){
    //時刻i-1から時刻iで区間の数が0から1以上に変化したときに処理(合体区間の開始点)
    if(a[i-1]==0&&a[i]!=0){
      //[l,r)をl_rと出力する時のl_を出力
      printf("%d ",i);
    }
    //時刻i-1から時刻iで区間の数が1以上から0に変化したときに処理(合体区間の終了点)
    if(a[i-1]!=0&&a[i]==0){
      //[l,r)をl_rと出力する時のrを出力
      printf("%d\n",i);
    }
  }
  return 0;
}
//バラバラな半開区間を合体させる問題
//imos法解
