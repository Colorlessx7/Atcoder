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
    int n;
    cin >> n;
    vector<int> x(n),y(n);
    rep(i,n){
        cin >> x[i] >> y[i];
    }
    //順番が関係ないのでunorderedsetなら少し早くなるかも
    set<P> st;
    rep(i,n){
        //setに各座標を格納し、対角線が決まった場合の残りの座標が
        //存在するかの判定に使う
        st.emplace(x[i],y[i]);
    }
    int ans = 0;
    rep(i,n){
        rep(j,n){
            //対角線の座標1(xi,yi),2(xj,yj)
            //x1とかx2とかにするとstlかなんかの予約語と衝突するので回避
            int xi = x[i], xj = x[j];
            int yi = y[i], yj = y[j];
            //座標1の右斜め上に座標2が存在する状況のみ残りの座標を考える
            //(重複の回避)
            if(xi < xj && yi < yj){
                //setに(x1,y2)が存在しないならコンティニュー
                //==st.endなのは存在しない場合イテレータがst.endの場所に向かうため
                if(st.find(P(xi,yj)) == st.end()){
                    continue;
                }
                //setに(x2,y1)が存在しないならコンティニュー
                if(st.find(P(xj,yi)) == st.end()){
                    continue;
                }
                //対角線以外の座標が両方存在するので+1
                ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
//0(N^2)の解法
//問題の都合上対角線の座標2つ(x1,y1),(x2,y2)が決まると
//長方形ができる場合の残りの座標の位置が(x1,y2),(x2,y1)に確定する
//よって2重ループで二つ座標を決めちゃってそれに対応する残りの座標が両方とも
//存在するのなら答えを+1する
