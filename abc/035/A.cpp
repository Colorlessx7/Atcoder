#include<bits/stdc++.h>
using namespace std;

int main(){
    int W, H;
    cin >> W >> H;
    if((double)H / W == 0.75){
        cout << "4:3" << endl;
    }else {
        cout << "16:9" << endl;
    }
    return 0;
}
