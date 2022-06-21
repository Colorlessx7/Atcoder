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
  //各区間をpairで持つ([first,second))
  vector<P> a(n);
  rep(i,n){
    cin >> a[i].first >> a[i].second;
  }
  //sortすることにより、区間[l,r)のlを昇順にして処理を行う
  sort(all(a));
  //バラバラな半開区間を合体させた半開区間を格納
  vector<P> ans;
  //区間[l,r)のlを昇順に全区間について回す
  for(auto [l,r] : a){
    //最初の区間a[0]か、今作っている区間ans[i]のrよりも新しい区間a[i]のlが大きい時に処理
    if(ans.size() == 0 || ans.back().second < l){
      //合体させた区間として[l,r)をansに格納
      ans.emplace_back(l,r);
    }else {
      //今作っている区間ans[i]と今見ている区間a[i]が同じ範囲なら処理
      //今作っている区間ans[i]のrを処理する
      //[1,4),[2,3)なら[1,4)に、[1,4),[2,5)なら[1,5)になる
      chmax(ans.back().second,r);
    }
  }
  //バラバラな半開区間を合体させたものを昇順に出力
  for(auto [l,r] : ans){
    printf("%d %d\n",l,r);
  }
  return 0;
}
//バラバラな半開区間を合体させる問題
