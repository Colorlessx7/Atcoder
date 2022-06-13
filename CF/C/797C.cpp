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
  int n;
  cin >> n;
  //タスクiの到着時間
  vector<int> s(n);
  //タスクiの終了時間
  vector<int> t(n);
  rep(i,n){
    cin >> s[i];
  }
  rep(i,n){
    cin >> t[i];
  }
  //タスクの処理時間
  vector<int> ans(n);
  rep(i,n){
    if(i == 0){
      //最初のタスクは終了時間-開始時間
      ans[i] = t[i] - s[i];
    }else {
      //それ以外は終了時間-max(ひとつ前のタスクの終了時間,現在のタスクの開始時間)
      ans[i] = t[i] - max(t[i-1],s[i]);
    }
  }
  //出力
  rep(i,n){
    if(i != n-1){
      printf("%d ",ans[i]);
    }else {
      printf("%d\n",ans[i]);
    }
  }
}
int main(){
  int t;
  cin >> t;
  rep(i,t) solve();
  return 0;
}
//各タスクに費やした時間を答える
//タスクの終了順は昇順で、終了時間は固定
//前のタスクの終了時間を迎えるまで次以降のタスクには触れない
//タスクの開始時間は前のタスクの終了時間と今のタスクの開始時間の遅い方となる
//これを実装する
