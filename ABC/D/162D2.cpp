#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(ll i = 0; i < N; i++)
#define rep2(i,N) for(ll i = 1; i <= N; i++)
#define rep3(i,N) for(ll i = N - 1; i >= 0; i--)
#define rep4(i,N) for(ll i = N; i > 0; i--)
#define replr(i,l,r) for(ll i = l; i < r; i++)
#define reprl(i,l,r) for(ll i = l; i >= r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
using ll = long long;
using P = pair<ll,ll>;
void chmin(ll &x, ll y){ x = min(x,y); }
void chmax(ll &x, ll y){ x = max(x,y); }
int main(){
  ll n;
  cin >> n;
  string s;
  cin >> s;
  //RGBRGBを012012に変換する配列
  vector<ll> ch(n);
  //変換作業
  rep(i,n){
    if(s[i] == 'R'){
      ch[i] = 0;
    }
    if(s[i] == 'G'){
      ch[i] = 1;
    }
    if(s[i] == 'B'){
      ch[i] = 2;
    }
  }
  ll ans = 0;
  //r(0)がchに何個出てきたかの累積和
  vector<ll> r(n+1);
  //g(1)がchに何個出てきたかの累積和
  vector<ll> g(n+1);
  //b(2)がchに何個出てきたかの累積和
  vector<ll> b(n+1);
  //累積和を埋める処理
  rep(i,n){
    r[i+1] = r[i];
    g[i+1] = g[i];
    b[i+1] = b[i];
    if(ch[i] == 0){
      r[i+1]++;
    }
    if(ch[i] == 1){
      g[i+1]++;
    }
    if(ch[i] == 2){
      b[i+1]++;
    }
  }
  //i<j<kとして考える
  for(ll i = 0; i < n; i++){
    for(ll j = i + 1; j < n; j++){
      //そもそも見ている文字が同じならコンティニュー
      if(ch[i] == ch[j]){
        continue;
      }
      //j-i!=k-jの範囲外j-i==k-jのkを求めるための処理
      ll diff = j - i;
      //cnt:j-i==k-jのk
      ll cnt = j + diff;
      //i,jに出てこない文字を調べる
      ll check = 3 - ch[i] - ch[j];
      //j-i==k-jのkが文字列の範囲内でかつSi!=Sj,Sj!=Skなら
      //そのパターンは含まれないので-1
      if(cnt < n && ch[cnt] == check){
        ans--;
      }
      //Skに出てくるべき文字に対して累積和の情報を用いて答えに加算する
      //普通の配列の範囲が0~n-1として累積和の範囲が0~nとして
      //i,jを決めた時のkの範囲は(j+1)~(n-1)まででその範囲の和は
      //累積和配列では(j+1)~(n)となるので以下の計算で求められる
      if(check == 0){
        ans += (r[n] - r[j+1]);
      }else if(check == 1){
        ans += (g[n] - g[j+1]);
      }else {
        ans += (b[n] - b[j+1]);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
//累積和配列を作って愚直にやる方法(だるい)
//
