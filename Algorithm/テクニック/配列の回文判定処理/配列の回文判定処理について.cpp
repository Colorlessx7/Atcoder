/*配列の回文判定処理について

文字列などの配列の回文判定処理では、文字列の先頭と末尾にそれぞれl,rというカーソルを置く
文字列をsとした時、s[l] == s[r]であれば処理継続、そうでないなら処理終了とする
その後lを++l; rを--r;　とすることで次の判定に移る
この処理をlがrを越すまで　(l >= r)までループさせる

例題　ABC237C　aaakasakaなどの文字列の左端に'a'を任意の数挿入し、それが回文になるか判定*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n = s.size();
    int l = 0,r = n - 1;                              //文字列の先頭と末尾にそれぞれl,rというカーソルを置く
    while(l < r && s[l] == 'a' && s[r] == 'a'){       //事前処理　aaakasakaをaakasakに
        ++l; --r;
    }
    while(l < r && s[r] == 'a'){                      //事前処理　右端のaは無視できるので　kasakaだったらkasakに　左端は無視できないからaakasakは不変
        --r;
    }
    while(l < r && s[l] == s[r]){                     //処理　見るべき部分の回文判定
        ++l; --r;
    }
    if(l >= r){                                       //カーソルが回文判定部分の半分を超えて交差したかの判定
        cout << "Yes" << endl;
    }else {
        cout << "No" << endl;
    }
    return 0;
}
