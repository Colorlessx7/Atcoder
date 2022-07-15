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
  //与えられた文字列
  string s;
  //答えの文字列が条件を満たすための最低のコスト数
  int p;
  cin >> s >> p;
  //sort操作用の文字列でsをコピー
  string w = s;
  //辞書順において降順になるようにsort
  sort(allr(w));
  //文字列sが持っているコストの合計
  int cost = 0;
  //sの文字数をnとする
  int n = s.length();
  //全ての文字について処理
  rep(i,n){
    //a~zのコストがが1~26なので文字のコストを計算しcostに加算
    cost += s[i] - 'a' + 1;
  }
  //key:アルファベット,value:文字列sからアルファベットkeyを削除する個数
  map<char,int> del;
  //全文字について処理
  rep(i,n){
    //貪欲法でコストが高いアルファベットから順に削除するように処理する
    //最低コストpをcostが上回っている限り処理
    if(cost > p){
      //アルファベットw[i]をsから削除する回数を1増やす(wのi番目の文字を削除する処理)
      del[w[i]]++;
      //w[i]を消すことによるコストの減少を計算し、costから減算する
      cost -= w[i] - 'a' + 1;
    }else {
      break;
    }
  }
  //答えの文字列
  string ans;
  //全文字について処理
  rep(i,n){
    //削除する回数が1以上であるなら処理
    if(del[s[i]] > 0){
      //削除する回数を1減らし、ansの何も追加しないことによりs[i]を削除したことにする
      del[s[i]]--;
      continue;
    }
    //s[i]を削除しない場合ansの末尾にs[i]を追加する
    ans += s[i];
  }
  cout << ans << '\n';
}
int main(){
  int t;
  cin >> t;
  rep(i,t) solve();
  return 0;
}
//貪欲法
//コストはa~zに1~26かかっている
