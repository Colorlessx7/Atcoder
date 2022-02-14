#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
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
int main(){
    int n;
    cin >> n;
    vector<tuple<string,int,int>> sp(n);
    rep(i,n){
        string s;
        int x;
        cin >> s >> x;
        int f = i + 1;
        sp[i] = make_tuple(s,x,f);
    }
    sort(sp.begin(),sp.end(),name_compare);
    rep(i,n){
        cout << get<2>(sp[i]) << endl;
    }
    return 0;
}
