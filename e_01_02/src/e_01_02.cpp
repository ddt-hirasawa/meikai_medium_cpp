/*
演習1-2 クラスDate でありえない日にちを訂正するようにしてください
抽出子により、範囲内の値になるように調整します

作成日 2017年5月15日

作成者 平澤敬介
*/

#include<iostream>
#include"class.h"

using namespace std;

int main()
{
	//デフォルトコンストラクタ 0年1月1日で初期化
	Date now(0);

	//抽出子により、西暦、月、日のデータメンバをもらう
	//不正値が入力された場合、入力のやり直しが発生することで
	//補正とします。
	cin >> now;

	//抽出子により、不正値を省いた値がデータメンバとなり表示されます
	cout << now;

	return 0;
}
