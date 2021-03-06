/*
演習9-1 char型に特殊化した挿入子を作成せよ

作成日 2017年5月25日

作成者 平澤敬介
*/

#include<iostream>
#include"class.h"

using namespace std;

int main()
{
	const Twin<int> tmp1(10, 100);		//テンプレートクラスのオブジェクト生成

	const Twin<char> tmp2('C', 'D');	//テンプレートクラスのオブジェクト生成

	//Twin tmp10(10,100);	//型の指示をしていないことに加え、定値化していないのでコンパイルエラー

	cout << "第一データメンバ :  " << tmp1.first_get() << "\n"
		<< "第二データメンバ :  " << tmp1.second_get() << "\n";

	cout << tmp1;						//Type型に該当する挿入子

	cout << tmp2;						//char型のみ対応する挿入子

	return 0;
}
