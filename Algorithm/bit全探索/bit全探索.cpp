/*ABC079Cから*/
for(int x = 0; x < 8; x++){                   //bitの値設定
        sum = keta[0];　　　　　　　　　　　　　　 //比較に用いる合計の初期化
        s = char('0' + keta[0]);　　　　　　　　 //最後に出力する部分の初期化と設定
        for(int i = 0; i < 3; i++){           //bitの桁の設定
            if(x & (1<<i)){                   //桁のbit判定bitにi番目のフラグが立っているか
                sum += keta[i+1];
                s += '+';
                s += char(keta[i+1] + '0');
            }else {
                sum -= keta[i+1];
                s += '-';
                s += char(keta[i+1] + '0');
            }
        }
        if(sum == 7){                         //ループを抜ける処理
            break;
        }
    }
