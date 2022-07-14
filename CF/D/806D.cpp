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
void solve(){
  //文字列の個数
  int n;
  cin >> n;
  //文字列n個を格納する配列
  vector<string> s(n);
  //key:文字列,value:存在するならtrue,存在しないならfalse
  map<string,bool> mp;
  //文字列の入力
  rep(i,n){
    cin >> s[i];
    //文字列s[i]が登場したのでtrueに
    mp[s[i]] = true;
  }
  //答えの出力(0or1)
  string ans;
  //各文字列について処理
  //O(N),全体でO(N*max_length*logN)となる(10^5*8*log10^5=4e6)
  rep(i,n){
    //ok:si=sj+skとなるsj,skが存在するならtrue,存在しないならfalse
    bool ok = false;
    //文字列s[i]の文字数
    int sisz = s[i].size();
    //文字列s[i]の長さについて処理
    //O(max_length)
    rep(j,sisz){
      //s[i]=pref+suffとして考える
      //pref:s[i]の先頭j文字(substr(0,j)で0文字目(先頭)からj文字を取り出す)
      string pref = s[i].substr(0,j);
      //suff:s[i]からprefを除いた文字列(substr(j)でj文字目から全てを取り出す)
      string suff = s[i].substr(j);
      //s[i]=pref+suffとなるpref,suffが両方とも与えられた文字列内に存在するなら処理
      //mapへのアクセスでo(logN)
      if(mp[pref] && mp[suff]){
        //si=sj+skとなるsj,skが存在したのでtrueに
        ok = true;
        //以降の文字列の切り分け方について処理する必要はないのでbreak
        break;
      }
    }
    //okがtrueならansの末尾に1を、falseなら0を格納
    ans += (ok ? '1' : '0');
  }
  //出力部
  cout << ans << endl;
}
int main(){
  int t;
  cin >> t;
  rep(i,t) solve();
  return 0;
}
