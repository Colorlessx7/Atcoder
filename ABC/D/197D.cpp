#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(ll i = 0; i < N; i++)
#define rep2(i,N) for(ll i = 1; i <= N; i++)
#define rep3(i,N) for(ll i = N - 1; i >= 0; i--)
#define rep4(i,N) for(ll i = N; i > 0; i--)
#define replr(i,l,r) for(ll i = l; i < r; i++)
#define reprl(i,l,r) for(ll i = l; i > r; i--)
#define all(x) x.begin(),x.end() 
#define allr(x) x.rbegin(),x.rend() 
typedef long long ll;
using P = pair<ll,ll>;
//複素数を扱えるstl
using C = complex<double>;
//stl:complexに値を入力する関数
C inc(){
    //複素数のstlだが、x座標を実数として
    //y座標を虚数として扱う
    double x, y;
    cin >> x >> y;
    return C(x,y);
}
int main(){
    int n;
    cin >> n;
    //P(0)の入力
    C s = inc();
    //P(n/2)の入力
    C t = inc();
    //正多角形の中心点の導出(複素数の足し算は実数同士・虚数同士を足す)    
    C o = (s+t)/2.0;
    //cosθが-1になるθは180度でstlの仕様上radで返ってくるのでradのπがわかる
    const double PI = acos(-1);
    //P(1)に移動するために必要な角度
    double rad = 2 * PI / n;
    //角度がP(0)から見て2*PI/nである、大きさ|r|=1の単位ベクトル
    C r(cos(rad), sin(rad));
    //最終的なP(1)の座標
    //複素数のベクトルa,bの掛け算は長さは|a|*|b|の大きさとなり
    //角度はaとbの角度を足し合わせたものとなる
    //基準である中心点oからrad方向に角度を移動した
    //大きさ|s-o|のベクトルがさす先の座標がP(1)の座標となる
    C ans = o + (s - o) * r;
    //実数部(x座標),虚数部(y座標)の順に出力
    printf("%.10f %.10f\n",ans.real(), ans.imag()); 
    return 0;
}
//二次元座標の幾何問題を複素数のstlであるcomplexを用いて解く
//stl:complexのリファレンス
//https://cpprefjp.github.io/reference/complex/complex.html
//
