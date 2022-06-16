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
  int n, k, m;
  cin >> n >> k >> m;
  vector<int> a(n-1);
  //これまでの合計点
  int sum = 0;
  //平均m点以上とるために必要な合計点
  int all = n * m;
  rep(i,n-1){
    cin >> a[i];
    sum += a[i];
  }
  //平均m点を超えるのに必要なn番目の点数
  int di = all - sum;
  //必要点数が満点以内か
  if(di <= k){
    //all点以上取ってるならもう0点でいいので0に
    if(di < 0){
      di = 0;
    }
    //必要点数を出力
    cout << di << endl;
  }else {
    //満点とっても無理なので-1出力
    cout << -1 << endl;
  }
  return 0;
}
