//tupleの場合 0要素昇順比較,1要素降順比較,2要素は出力なのでスルー

bool name_compare(tuple<string,int,int> a, tuple<string,int,int> b){
    if(get<0>(a) != get<0>(b)){
        return get<0>(a) < get<0>(b);
    }
    if(get<1>(a) != get<1>(b)){
        return get<1>(a) > get<1>(b);
    }else{
        return true;
    }
}

//pairの場合 0要素降順比較,1要素昇順比較

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
