#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    string s;
    cin >> s;
    int n = s.size();
    //文字列の末尾を消すがその個数は偶数でないと偶文字列にならない
    //i:文字列の末尾を2文字消した後の文字数 2文字になるまで回す
    for(int i = n - 2; i >= 2; i -= 2){
        //文字列の末尾を2文字消す処理
        rep(j,2){
            s.pop_back();
        }
        //現在の文字列サイズの半分を計算
        int x = i / 2;
        //substr():文字列の分割 sが8文字だとaが先頭4文字、bが末4文字
        string a = s.substr(0,x);
        string b = s.substr(x,x);
        //a=bなら偶文字列 一番長いものなので発見時速終了 文字数iを返す
        if(a == b){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
//substrの使い方
//n番目以降の文字列を取り出す場合はsubstr(n)とします。
//n番目以降の文字列をm文字だけ取り出す場合はsubstr(n, m)とします。
