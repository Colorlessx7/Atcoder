#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = N - 1; i >= 0; i--)
#define rep4(i,N) for(int i = N; i > 0; i--)
#define all(x) x.begin(),x.end() 
typedef long long ll;
using P = pair<int,int>;
int main(){
    double w, h, x, y;
    cin >> w >> h >> x >> y;
    double ans = h * w / 2;
    double w2 = w / 2;
    double h2 = h / 2;
    printf("%.10f ",ans);
    cout << ((x==w2)&&(y==h2) ? 1 : 0) << endl;
    return 0;
}
//数学的考察問題
//縦H,横Wの長方形の面積を半分に切る方法は
//その長方形の中心点から360度方向のどれかにとりあえず線を引くことでできる
//これにより今回の長方形を直線で切った場合の小さい方の面積は
//絶対に半分に切れるので自動的に面積h*wの半分になる(ans)
//半分に切れる直線の個数はこの長方形の中心点(w/2,h,2)が(x,y)と
//一致しているならその点から360度方向全部に直線が引けるので1
//一致していないなら(x,y)と中心点の2点を通る直線のみなので0となる
//これを実装する
