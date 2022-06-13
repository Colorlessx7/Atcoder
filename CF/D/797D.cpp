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
void chmin(int &x, int y){ x = min(x,y); }
void chmax(int &x, int y){ x = max(x,y); }
void solve(){
  //文字数、区間の文字数
  int a, b;
  cin >> a >> b;
  //文字列
  string s;
  cin >> s;
  //minを取る為最大初期化
  int ans = INT_MAX;
  //B,Wの個数管理
  map<char,int> mp;
  //文字列の長さをなめる
  for(int i = 0; i < a; i++){
    //区間として成立していないb-1文字目までの処理
    if(i < b-1){
      //新たに追加されたi番目の文字のカウンタを足す
      mp[s[i]]++;
    }else {
      //新たに追加されたi番目の文字のカウンタを足す
      mp[s[i]]++;
      //見ているb文字から溢れたi-b番目の文字のカウンタをひく
      mp[s[i-b]]--;
      //WをBにするため、Wが区間内に一番少ない区間でのWの個数が答えになる
      ans = min(ans,mp['W']);
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
