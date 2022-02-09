#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
typedef long long ll;
int main(){
    int n1;
    cin >> n1;
    string n = to_string(n1);
    //Nを文字列として降順にソートする
    sort(n.rbegin(),n.rend());
    int x = n.size();
    string a;
    string b;
    //Nの先頭から奇数文字目からなる文字列をA偶数文字目からなる文字列をBとする
    rep(i,x){
        if(i % 2 == 0){
            a += n[i];
        }
        if(i % 2 == 1){
            b += n[i];
        }
    }
    //A,Bを先頭から見て、初めて異なる文字が登場する箇所について、その2文字を入れ替える
    rep(i,x / 2){
        if(a[i] != b[i]){
            swap(a[i],b[i]);
            break;
        }
    }
    //A,Bを整数とみなしA×Bを出力する
    int an = stoi(a);
    int bn = stoi(b);
    int ans = an * bn;
    cout << ans << endl;
    return 0;
}
/*次のようなアルゴリズムで答えを求めることができます。
Nを文字列として降順にソートする
Nの先頭から奇数文字目からなる文字列をA偶数文字目からなる文字列をBとする
A,Bを先頭から見て、初めて異なる文字が登場する箇所について、その2文字を入れ替える
A,Bを整数とみなしA×Bを出力する
2行目まで分かっていたが3行目がやや違っていた */
