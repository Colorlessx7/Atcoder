#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int a, b;
    cin >> a >> b;
    //最大公約数の最大値の可能性がある限界:f
    int f = b - a;
    int ans = 0;
    //最大公約数かどうか1~fまで試す
    for(int i = 1; i <= f; i++){
        //最大公約数の可能性があるiがa~bの範囲で何個倍数を持っているか:cnt
        int cnt = 0;
        //計算量削減のためループ開始をaにギリギリ近い位置にする
        //a,bが101~139でiが34ならy=2で34*2=68からスタート
        int y = a / i; 
        //最大公約数か(a~bまでに倍数が2つ以上あるか)調べるループ
        for(int j = y; i * j <= b; j++){
            //a~bの範囲外ならスルー
            if(i * j < a){
                continue;
            }
            cnt++;
            //a~b内に2個倍数があるならいはx,yの最大公約数と言える
            //2個より多く計算しても意味ないのでループを抜ける
            if(cnt >= 2){
                break;
            }    
        }
        //a~b範囲に倍数が2つあればiはx,yの最大公約数なので
        //iがインクリメントされるため自動的に最大公約数の最大値だから格納
        if(cnt >= 2){
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}
//A<=x<y<=Bを満たすx,yを選んだ時のgcd(x,y)の最大値を求める
//最大公約数の最大値がf=B-Aの値を超えることはない
//(101~139をa~bとして考えるときabの差38を超える39以上を最大公約数というには
//101以降に39以上のものを足した値がB以内である必要があるがこれは満たさない)
//101~139だと34*3=102~34*4=136で34が最大公約数となる
