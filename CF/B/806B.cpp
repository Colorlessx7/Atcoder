#include<bits/stdc++.h>
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
template<typename Tx, typename Ty>Tx dup(Tx x, Ty y){return (x+y-1)/y;}
void chmin(int &x, int y){ x = min(x,y); }
void chmax(int &x, int y){ x = max(x,y); }
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
//O(N)
void solve(){
  //問題の回答数
  int n;
  //回答した問題の種類の情報
  string s;
  cin >> n >> s;
  //既出かどうかを管理する配列flag[i]:trueなら既出,falseなら未回答
  vector<bool> flag(26);
  //得点
  int ans = 0;
  //全問題について処理O(N)
  rep(i,n){
    //問題の情報(文字)を数字に直して管理(x=0~25,s[i]=A~Z)
    int x = s[i] - 'A';
    //i番目の問題xが既出なら処理
    if(flag[x]){
      //既出だったので得点を+1
      ans++;
    }else {
      //i番目の問題xが既出でないなら処理
      //問題xが既出になるようbool配列の更新
      flag[x] = true;
      //初回の回答だったので得点を+2
      ans += 2;
    }
  }
  cout << ans << endl;
}
int main(){
  int t;
  cin >> t;
  rep(i,t) solve();
  return 0;
}
//初回答の問題が2点、既出の問題が1点もらえるとき最終的な得点を答える
