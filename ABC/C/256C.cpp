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
  //配列で取った方がよかったかも
  int h1, h2, h3,w1,w2,w3;
  cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;
  int ans = 0;
  rep2(a,30){
    rep2(b,30){
      int c = h1 - (a + b);
      //注意点1:2つ決めた時に一意に定まるマスの値が0未満なら条件を満たさないのでコンティニュー
      if(c < 1){
        continue;
      }
      rep2(d,30){
        rep2(e,30){
          int f = h2 - (d + e);
          if(f < 1){
            continue;
          }
          int g = w1 - (a + d);
          if(g < 1){
            continue;
          }
          int h = w2 - (b + e);
          if(h < 1){
            continue;
          }
          int i = w3 - (c + f);
          //注意点2:右下のマスはw3とh3の二つの条件を満たす必要があるため
          //その判定もする必要がある
          if(i < 1 || i != h3 - (g + h)){
            continue;
          }
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
//工夫した全探索解
//9マスを条件通りに埋める方法が何個あるか解く問題だが、
//1マスの取り得る値の範囲が1~30の30通りで、30^9はTLEする
//2つ決めたら残り一つが一意に定まることを利用して左上4マスを決めて
//条件を満たすか判定し、条件を満たすものだけ答えに+1する
//この時、計算量は30^4で間に合う
