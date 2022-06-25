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
  vector<string> s(n);
  //全リールの情報の入力
  rep(i,n){
    cin >> s[i];
  }
  //全てのリールを止めた上で、表示されている文字が全て同じになるように
  //全てのリールを止めるまでに、スロットが回り始めてから最小で何秒かかるか
  //minを取るので大きい値で初期化
  const int INF = 1001001001;
  int ans = INF;
  //文字0~9について回す(表示される文字をiのみにすると仮定する)
  rep(x,10){
    //数字xを判定用に文字に直す
    char c = '0' + x;
    //num[i]:i秒目にxが登場するリールの個数
    vector<int> num(10);
    //numの設定,リールについて回す
    rep(i,n){
      //秒数について回す
      rep(j,10){
        //リールiのj秒目に文字cが登場したのでj秒目にcが登場するリールの個数のカウンタを加算
        if(s[i][j] == c){
          num[j]++;
        }
      }
    }
    //全てiにするのに何秒かかるか
    int now = 0;
    //秒について回す
    rep(i,10){
      //t:i秒目が最後に止めるリールの秒数と仮定した時に
      //i秒目のリールを全て止めるまでにかかる時間の計算
      //数字iが5つのリールで0秒のところに固まっている場合
      //0-10-20-30-40というふうに10秒ずつ待つ必要がある
      //最初だけは待つ必要がないので待つ回数はnum[i]-1になり、
      //*10したものに最後の1周期でリールを押すのにかかる時間iを足したものがかかる時間となる
      int t = i + 10*(num[i]-1);
      //tの一番大きいものが全てのリールをiで止めた時にかかる時間nowとなる
      chmax(now,t);
    }
    //全てのリールをiで止めた場合にかかる時間が他の文字で止める場合より
    //少ない場合にansを更新
    chmin(ans,now);
  }
  cout << ans << endl;
  return 0;
}
//一つ条件としてリールは1秒にどれか一つしか止められない
//同じ秒に同じ数字が固まっていると1周期待たないといけない
