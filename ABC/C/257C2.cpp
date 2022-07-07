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
  //n:人数
  int n;
  //子供、大人の情報
  string s;
  cin >> n >> s;
  //w[i]:i人目の体重
  vector<int> w(n);
  rep(i,n){
    cin >> w[i];
  }
  //key:体重,value:体重がkeyの人の番号
  map<int,vector<int>> mp;
  //体重がw[i]の人の番号iをmapに格納
  rep(i,n){
    mp[w[i]].push_back(i);
  }
  //大人の数
  int now = 0;
  rep(i,n){
    if(s[i] == '1'){
      now++;
    }
  } 
  //Xを決めた時のf(X)の最大値
  //最初の状態は全員大人になるようにXを設定した時のもの
  int ans = now;
  //全体重について回す
  //ループが回るたびに体重p.firstまでが子供になるようにXを設定していく
  for(auto p : mp){
    //体重p.firstの人々の番号について回す
    for(int i : p.second){
      //sのi番目が1なら正解の子供ではないのでf(X)を-1する
      if(s[i] == '1'){
        now--;
      }else {
        //sのi番目が0なら正解の子供なのでf(X)を+1する
        now++;
      }
    }
    //正解f(X)の最大をansに格納
    chmax(ans,now);
  }
  cout << ans << endl;
  return 0;
}
