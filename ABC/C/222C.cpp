#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
//firstが数字で降順、secondが数字のIDでfirstが同じ時昇順にしたいときの比較関数
bool name_compare(pair<int, int> a, pair<int, int> b){
    // 基本はfirstで比較
    if(a.first != b.first){
        //降順にする処理 　return a.first < b.first;だと昇順になる
        return a.first > b.first;
    }
    // それ以外はsecondで比較
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        //この問題だと発生しないがどちらも同じ場合
        return true;
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    //GCPの各文字を格納する配列
    vector<vector<char>> a(2 * n,vector<char>(m));
    //firstが勝利数、secondがID
    vector<pair<int,int>> str(2 * n);
    rep(i,2 * n){
        rep(j,m){
            cin >> a[i][j];
        }
    }
    rep(i,2 * n){
        //勝利数0初期化 IDは今後の処理が楽になるよう0~2n-1にしてある
        str[i].first = 0;
        str[i].second = i;
    }
    //i:マッチ回数 j:勝負数
    rep(i,m){
        rep(j,n){
            //sortされた後のIDとじゃんけんの手の二次元配列で人のずれがあるので修正
            int x = str[2 * j].second;
            int y = str[2 * j + 1].second;
            //勝負者の次の手を格納
            char aa = a[x][i];
            char bb = a[y][i];
            //配列的に考えて0,2,4~番目の人が勝ったらその人の勝利数+1
            //1,3,5~番目が勝ったらその人の勝利数+1
            //同じ手が出た場合は変わらないのでスルー
            if((aa=='G'&&bb=='C')||(aa=='C'&&bb=='P')||(aa=='P'&&bb=='G')){
                str[2 * j].first++;
            }else if((aa=='G'&&bb=='P')||(aa=='P'&&bb=='C')||(aa=='C'&&bb=='G')){
                str[2 * j + 1].first++;
            }
        }
        //sort 左2つでsort範囲の指定 右1つでソート方法として関数を提示
        //勝利数が多い順番 勝利数が同じならばIDが小さい順番
        sort(str.begin(),str.end(),name_compare);
    }
    //全てのIDを+1して問題通りに
    rep(i,2 * n){
        str[i].second++;
    }
    //順位によって並んだIDを表示
    rep(i,2 * n){
        cout << str[i].second << endl;
    }
    return 0;
}
