//tupleはstlの1つ メンバ変数を3つ以上持つことができる
//今回はstring,int,intに店の名前,店の得点,店の番号を格納
//リファレンスはhttps://cpprefjp.github.io/reference/tuple/tuple.html


//ABC128Bより

#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
//比較関数によるsort
bool name_compare(tuple<string,int,int> a, tuple<string,int,int> b){
    //tupleの0番目(左から3番目)の店の名前を辞書順で比較
    if(get<0>(a) != get<0>(b)){
        //昇順でsort
        return get<0>(a) < get<0>(b);
    }
    //店の名前が同じならtupleの1番目(左から2番目)の店の点数で比較
    if(get<1>(a) != get<1>(b)){
        //降順sort
        return get<1>(a) > get<1>(b);
        return get<1>(a) > get<1>(b);
    }else{
        return true;
    }
}
int main(){
    int n;
    cin >> n;
    vector<tuple<string,int,int>> sp(n);
    rep(i,n){
        string s;
        int x;
        cin >> s >> x;
        int f = i + 1;
        //tuple配列のi番目にmake_tupleでtuple要素の追加
        sp[i] = make_tuple(s,x,f);
    }
    sort(sp.begin(),sp.end(),name_compare);
    rep(i,n){
        //店番号を格納している2番目(左から3番目)の値をそれぞれ出力
        cout << get<2>(sp[i]) << endl;
    }
    return 0;
}
