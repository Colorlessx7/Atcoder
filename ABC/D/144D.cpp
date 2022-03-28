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
int main(){
    double a, b, x;
    cin >> a >> b >> x;
    //2次元で考えるため立法センチメートルとして与えられたxをaで割った値を用意する
    double s = x / a;
    double rad;
    //場合分け 
    //水の量がa*bの長方形の半分(対角線で半分)以上かどうか
    if(s >= a*b/2){
        double h = (a*b-s)*2/a;
        //atan2(単位円の半径をr,円内の3角形の横をx,縦をyとすると
        //atan2(y,x)とすることで逆正接のθをradで得られる)
        rad = atan2(h,a); 
    }else {
        double w = s*2/b;
        rad = atan2(b,w);
    }
    //πはcos^-1(-1)で求められる
    double PI = acos(-1);
    //三角関数の返り値はradなのでdegに直す
    double deg = rad/(2*PI)*360;
    //printf指定子で小数点以下10桁まで出力
    printf("%.10f\n",deg);
    return 0;
}
//まず考えやすくするために3次元の直方体を二次元の長方形として考える
//(底面の正方形の1辺を軸として傾けるため水面が平らになって角度がつかず2次元で考えても問題ない)
//c++の角度に関するstlはradで返ってくるためdegに直す必要がある
//
