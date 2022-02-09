#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    string x;
    int n;
    cin >> x >> n;
    vector<string> s(n);
    rep(i,n){
        cin >> s[i];
    }
    map<char,char> f,g;
    //アルファベットは26文字なので26回回す
    //fは問題で与えられた文字列を元の辞書順に戻すためのmap
    //元がabc 新がbacだとkeyがb,a,cでvalueがa,b,cとなる
    rep(i,26){
        f[x[i]] = 'a' + i;
    }
    //gは元の辞書順に対応させた文字列を問題で与えられた最初の文字列に戻すmap
    rep(i,26){
        g['a' + i] = x[i];
    }
    //Siを元の辞書順に従って書き替え
    rep(i,n){
        //範囲for文に参照型で回しているので直接書き替えらえれる
        //cはSiの文字列の1文字ずつ
        for(char& c : s[i]){
            c = f[c];
        }
    }
    //元の辞書順に対応させた状態だとsortできる
    sort(s.begin(),s.end());
    //Siを問題で与えられた形に戻す
    rep(i,n){
        for(char& c : s[i]){
            c = g[c];
        }
    }
    rep(i,n){
        cout << s[i] << endl;
    }
    return 0;
}
//辞書順に並び替えする問題 (辞書順が問題によって変更されている)
//abc~xyzが普通の辞書順の時、今回の問題ではbac~xzyみたいになっている
//入力された文字列(新しい辞書順参照)を元の辞書順の文字列に直して考える
//bacxzyが与えられたらabcxyzに戻して考える
