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
  //key:重さ,value:fi=keyの体重の大人の人数,se=keyの体重の子供の人数
  map<int,pair<int,int>> mp;
  //大人の数
  int large = 0;
  //人の情報の入力
  rep(i,n){
    //w:体重
    int w;
    cin >> w;
    //i人目が大人なら処理
    if(s[i] == '1'){
      //重さwの大人の人数を+1
      mp[w].first++;
      //大人の人数のカウンタを+1
      large++;
    }else {
      //重さwの子供の人数を+1
      mp[w].second++;
    }
  }
  //x:体重の種類数
  int x = mp.size();
  //累積和配列
  //l[i]:i番目の閾値にXを設定したときに正解になる大人の数(減少)
  //m[i]:i番目の閾値にXを設定したときに正解になる子供の数(増加)
  vector<int> l(x+1);
  vector<int> m(x+1);
  //累積和更新のためのindex
  int cnt = 1;
  //大人の正解者の累積和配列を大人の総数からスタートさせる
  l[0] = large;
  //累積和配列の作成(座標圧縮?)
  //例としてs=10101,w={60,50,50,50,60}とすると
  //w=50で子供2、大人1
  //w=60で子供0、大人2
  //Xは全部子供、50まで子供60から大人、全員大人の区分に分けられる
  //累積和配列はindex:0~xまで上の逆の順になっている
  //l[0]=0,m[0]=3
  //l[1]=2,m[1]=2
  //l[2]=2,m[2]=0
  for(auto p : mp){
    //子供の条件が広がったので体重がp.firstの子供が正解になるため
    //体重がp.firstの子供の数p.second.secondを累積和配列mに加算
    m[cnt] = m[cnt-1] + p.second.second;
    //大人の条件が狭まったので体重がp.firstの大人が不正解になるため
    //体重がp.firstの大人の数p.second.firstを累積和配列lから減算
    l[cnt] = l[cnt-1] - p.second.first;
    //indexを1進める
    cnt++;
  }
  //f(X)の最大(maxを取るため0初期化)
  int ans = 0;
  //全ての閾値iについて処理
  rep(i,x+1){
    //閾値iを設定したときの大人の正解がl[i]で子供の正解がm[i]なので
    //numが全体の正解数となる
    int num = l[i] + m[i];
    //正解数が多いやつをansに格納
    chmax(ans,num);
  }
  cout << ans << endl;
  return 0;
}
