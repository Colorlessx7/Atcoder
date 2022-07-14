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
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
void solve(){
  //文字列
  string s;
  cin >> s;
  //文字列の文字数
  int n = s.size();
  //sを作るのに必要な日数
  int ans = 0;
  //文字が登場したかを管理
  vector<int> alp(26);
  //1日に使える文字をintで管理
  queue<int> place;
  //1日の間に文字が何種類出てきたか管理
  int cnt = 0;
  //全文字について処理
  rep(i,n){
    //x:i番目の文字を数字で管理
    int x = s[i] - 'a';
    //現在の日時でxをまだsの作成に使っていない場合に処理
    if(alp[x] == 0){
      //文字の種類数を+1
      cnt++;
      //現在のにちじで使っている文字としてxをplaceに格納
      place.push(x);
    }
    //現在の日時でxをsの作成に使ったのでalp[x]のフラグを立てる
    alp[x]++;
    //現在の日時で使った文字の種類が3を超えたなら処理
    if(cnt == 4){
      //日数を+1
      ans++;
      //日数が1進み、文字の種類3を昨日使ったことにしたので
      //今日使用した文字の種類数を1にする
      cnt = 1;
      //昨日使った文字3種類を今日使っていないようにする処理
      rep(j,3){
        //queueの先頭をとる
        int f = place.front();
        //今日fをまだ使用していないようにalp[f]のフラグを下ろす
        alp[f] = 0;
        //queueの先頭の要素を削除
        place.pop();
      }
    }
  }
  //queueの中身が残っている場合はカウントしていない日数が1つ残っていることになっているので
  //日数を+1
  if(place.size()){
    ans++;
  }
  cout << ans << endl;
}
int main(){
  int t;
  cin >> t;
  rep(i,t) solve();
  return 0;
}
