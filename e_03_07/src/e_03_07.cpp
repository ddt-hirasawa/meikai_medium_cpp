/*
演習3-7 qsort関数を使って、2つの配列をソートするプログラムの作成

作成日 2017年5月16日

作成者 平澤敬介
*/

#include<cstdlib>
#include<iostream>
#include<cstring>

using namespace std;

//関数宣言
int char_cmp(const char* tmp1,const char* tmp2);

int main()
{
	const int line = 4;	//行の要素数

	const int colu = 7;	//列の要素数

	char tmp1[][colu]	= { "LISP","C","Ada","Pascsl" }; 	//ポインタの文字列

	const char* tmp2[]	= { "LISP","C","Ada","Pascsl" }; 	//ポインタの文字列

	int len2 = sizeof(tmp2) / sizeof(tmp2[0]);							//ポインタ文字列の文字列数

	//ソート前
	cout << "2次元配列\n";
	for(int i=0; i < line; i++) {

		//配列の i 番目を表示し見やすくします
		cout << "tmp1[" << i << "] = ";

		//ナル文字で区切られるので 仮に 10文字を上限とします
		for(int j=0; j < colu; j++) {

			//配列の文字列を表示していきます
			cout << tmp1[i][j];
		}

		cout << "\n";
	}

	//ソート前
	cout << "ポインタ文字列\n";
	for(int i=0; i < len2; i++) {


		//先頭のポインタを表示することでナル文字まで表示
		cout << "tmp2[" << i << "] = " << *(tmp2 + i);

		//改行し次の文字列へ
		cout << "\n";
	}

	cout << "ソート後\n";

	qsort(&tmp1,line,sizeof(char*), reinterpret_cast<int (*)(const void*,const void*)> (char_cmp));

	cout << "2次元配列\n";
	for(int i=0; i < line; i++) {

		//配列の i 番目を表示し見やすくします
		cout << "tmp1[" << i << "] = ";

		//ナル文字で区切られるので 仮に 10文字を上限とします
		for(int j=0; j < colu; j++) {

			//配列の文字列を表示していきます
			cout << tmp1[i][j];
		}

		cout << "\n";
	}


	return 0;
}

//関数 文字列を比較する関数
//仮引数 比較する文字列2つ
//返却値 1 0 のどちらか

int char_cmp(const char* tmp1,const char* tmp2) {

	return strcmp(tmp1,tmp2);
}
