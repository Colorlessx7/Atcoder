#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n,q;
    string s;
    cin >> n >> s >> q;
    //前半後半が入れ替わるかのフラグ
    bool f1 = 0;
    //全体の文字数
    int n2 = n * 2;
    rep(i,q){
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1){
            //string配列で扱いやすいようデクリメント
            --a; --b;
            //反転フラグが立っているならただしく入れ替えるため
            //インデックスを調整(aは+n,bは-nしてるのと一緒)
            if(f1){
                a = (a+n)%n2;
                b = (b+n)%n2;
            }
            //swap処理
            swap(s[a],s[b]);
        }else {
            //フラグ反転
            f1 = !f1;
        }
    }
    //出力前に反転フラグが立っている場合文字列の分割と結合を行う
    if(f1){
        string s1 = s.substr(0,n);
        string s2 = s.substr(n);
        s = s2 + s1;
    }
    cout << s << endl;
    return 0;
}
