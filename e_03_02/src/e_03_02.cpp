/*
演習3-2 指定された要素を満たす要素を配列から線形探索する関数の作成

作成日 2017年5月16日

作成者 平澤敬介
*/

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

//関数宣言 mainの下にまとめます
int serch_if(const int a[],int num,bool (*cond1)(int),bool (*cond2)(int,int),bool (*cond3)(int,int));
bool cond1(int num);
bool cond2(int num1,int num2);
bool cond3(int num1,int num2);

int main()
{
	srand(time(NULL));

	const int num = 100;				//全要素数 100で固定

	int serch[num] = {0};	            //配列 0 ～ 99 の100個用意します

	//配列を乱数で埋め尽くします
	for(int i=0; i < num; i++) {

		serch[i] = rand() % 100;	//0 ～ 9999 までの範囲

		//10以下の時
		if(i < 10) {

			//空白文字を表示
			cout << " ";
		}

		//配列の要素をすべて表示します
		cout << "serch[" << i << "] = " << serch[i] << "\n";
	}

	int answer = serch_if(serch,num,cond1,cond2,cond3);	//関数呼び出し部分 関数を3つ定義します

	//見つからなかったときの返却値は -1 なので +1 すれば 0 -> false になる
	if(answer + 1) {

		//発見したとき配列の番号を表示
		cout << "その要素は " << answer << "番目にあります\n";

	//if文がfalseを返したとき
	} else {

		//ない場合
		cout << "その要素はありません\n";
	}

	return 0;
}

//関数 指定された要素を満たす要素を配列から線形探索する
//仮引数 探す配列 要素数 判定する関数 3つ
//返却値 検出した値のある添字　ない場合は-1

int serch_if(const int a[],int num,bool (*cond1)(int),bool (*cond2)(int,int),bool (*cond3)(int,int)) {

	int answer = -1;			//返却値 ない場合のことを考え -1

	int select;					//任意で探索条件を変えるための変数

	//探索条件を表示します 頭の 1 2 3 で選択します
	cout << "探索条件\n"
		<< "1.偶数の探索\n"
		<< "2.前後で同じ要素になっているかの探索\n"
		<< "3.前後の要素の差が10以上かの探索\n";

	//1 2 3以外が入力されたときやり直し
	do{

		cin >> select;	//探索条件の決定

	//1 2 3以外の時入力しなおし
	}while(select < 0|| 3 < select);


	switch(select) {

	case 1 : //偶数の探索

		//全要素すべてを判別します
		for(int i=0; i < num; i++) {

			//偶数を発見したならば
			if((*cond1)(a[i])) {

				answer = i;			//配列の展示を返却します

				i = num;			//ループから抜けます
			}
		}

		//switch文から出ます
		break;

	case 2 : //前後で同じ数字かどうかの判別

		//全要素すべてを判別します
		//先頭要素は除きます
		for(int i=1; i < num; i++) {

			//前後で同じ数字ならば
			if((*cond2)(a[i],a[i-1])) {

				answer = i;			//配列の展示を返却します

				i = num;			//ループから抜けます
			}
		}

		//switch文から出ます
		break;

	case 3 : //前後で差が10以上かどうかの判別

		//全要素すべてを判別します
		//先頭要素は除きます
		for(int i=1; i < num; i++) {

			//前後で差が10以上ならば
			if((*cond3)(a[i],a[i-1])) {

				answer = i;			//配列の展示を返却します

				i = num;			//ループから抜けます
			}
		}

		//switch文から出ます
		break;
	}
	return answer;
}

//関数 偶数なのかどうかを判別します
//仮引数 探す整数値
//返却値 true or false

bool cond1(int num) {

	//2で割った余りが0ならば偶数
	return num % 2 == 0;
}

//関数 配列で前の要素と同じかを判別します
//仮引数 探す整数値 と 1つ前の値
//返却値 true or false

bool cond2(int num1,int num2) {

	//同じ数字の時 true
	return num1 == num2;
}

//関数 配列で前の要素と差が10以上あるかを判別します
//仮引数 探す整数値 と 1つ前の値
//返却値 true or false

bool cond3(int num1,int num2) {

	//同じ数字の時 true
	return num1 - num2 >= 10;
}