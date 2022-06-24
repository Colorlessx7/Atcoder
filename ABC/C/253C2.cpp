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
  int q;
  cin >> q;
  //多重集合S
  multiset<int> s;
  //クエリ処理
  rep(_,q){
    //クエリの種類
    int t;
    cin >> t;
    if(t == 1){
      //x:多重集合Sに入れる数字
      int x;
      cin >> x;
      //多重集合にxを格納
      s.insert(x);
    }else if(t == 2){
      //x:多重集合Sから消す数字の種類,c:多重集合から消すxの消す個数
      int x, c;
      cin >> x >> c;
      //多重集合からc回xを消す処理
      rep(i,c){
        //大前提としてs.erase(x)としてしまうとsの中のxが全て問答無用で消える
        //it:sの中の最初のxの場所を指すイテレータ(もしs内にxが存在しないならend()を指す)
        auto it = s.find(x);
        //itがend()を指したのでsの中にxが存在しないためループを終えて削除処理を終える
        if(it == s.end()){
          break;
        }
        //s.erase(iterator)でイテレータの指す値をsから削除する
        s.erase(it);
      }
    }else {
      //*でsetのイテレータが指す場所の値を使用できる
      //rbegin()が最大値を、begin()が最小値を指す
      int ans = *s.rbegin() - *s.begin();
      //イテレータに*をつけると値を取れるので(Sの最大値)−(Sの最小値)を出力
      cout << ans << endl;
    }
  }
  return 0;
}
