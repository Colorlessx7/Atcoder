//ABC237Dより 

#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define rep2(i,N) for(int i = 1; i <= N; i++)
#define rep3(i,N) for(int i = n - 1; i >= 0; i--)
#define rep4(i,N) for(int i = n; i > 0; i--)
#define all(x) x.begin(),x.end() 
typedef long long ll;
using P = pair<int,int>;
int main(){
    int n;
    string s;
    cin >> n >> s;
    //双方向リストに最初に0を格納
    list<int> a{0};
    //イテレータを0の場所にセット
    auto itr = a.end();
    rep(i,n){
        //siがLならイテレータを1つ戻す
        if(s[i] == 'L'){
            --itr;
        }
        //その後値を挿入する
        a.insert(itr, i+1);
    }
    for(int i : a){
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}
//双方向リストによる解
//双方向リストのイテレータを用意し、初めは末尾の位置にいるものとする
//また、イテレータに対して挿入操作を行った場合、見ている位置の直前に値が挿入されるものとする 
//与えられる操作を次のように実行することで、正しい答えを得ることができる
//siがLならイテレータを1つ戻してから値を挿入する
//siがRなら値を挿入する
