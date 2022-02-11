//setについて
//出典:https://qiita.com/bestfitat/items/84b8750ba87cd2ab2633
//setは重複を許さない順序付き集合 重複データは自動的に削除
//動的配列をsetに格納することもできる
//イテレータの型は面倒なのでautoを使用
//setのイテレータはランダム・アクセス不可で、前後にのみ移動できる。
//ix番目の要素に無理やりアクセスしたい場合は、begin()で取ってきたイテレータをix回インクリメントする
//insert : データの追加
//erase : データの削除 erase()で()内の格納されている値を削除

//ABC009Bより 2番目に高いものを出力　(例:100,200,300,300なら200を出力)

#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n;
    cin >> n;
    set<int> st;
    rep(i,n){
        int x;
        cin >> x;
        //問題の値をそれぞれsetに格納
        st.insert(x);
    }
    //auto:イテレータの型 setの一番小さい値を格納しているイテレータを代入
    auto y = st.begin();
    //2番目に大きい値を格納しているイテレータに飛ぶためのループ回数計算
    int f = st.size() - 2;
    //イテレータはランダムアクセス不可能
    //無理やりアクセスするためにイテレータをインクリメント
    rep(i,f){
        y++;
    }
    //(*y)でsetのyというイテレータ上の値を出力
    cout << (*y) << endl;
    return 0;
}
