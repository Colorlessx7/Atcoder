#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i < N; i++)
typedef long long ll;
using P = pair<int,int>;
int main(){
    int x, n;
    cin >> x >> n;
    vector<int> d(102);//0~101までが数列に登場するか　default = 0
    rep(i,n){
        int p;
        cin >> p;
        d[p] = 1;//登場したので1に
    }
    P ans(99999,-1);//pair型 xとの差の絶対値、0~101までの数字
    for(int i = 0; i <= 101; i++){
        if(d[i] == 1){
            continue;//登場した数字はスルー
        }
        int dif = abs(x - i);//差の絶対値をとる
        ans = min(ans,P(dif,i));//pair型のminは左を比較して一緒だったら右を比較する
    }
    cout << ans.second << endl;
    return 0;
}
