/*
演習11-3 コマンドラインから与えられた文字列のソートやシャッフルを行え

作成日 2017年5月31日

作成者 平澤敬介
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include<cstdlib>

using namespace std;

//関数宣言
vector<string> strptary_to_vec(const char** ptr,int num);
template <class InputIterator>
void print(InputIterator first,InputIterator last);

int main(int argc, const char** argv)
{
	cout << argc << "\n";			//コマンドラインの文字列の数 1つのみ
	cout  << *argv << "\n";			//コマンドライン引数のパラメータ ソースコードのアドレス

	cout << "eclipse では文字列が一つしかないのでシャッフルもソートもできません\n";

	vector<string> main_cmd = strptary_to_vec(argv, argc);		//テキストに沿って記述します

	//コンテナにある文字列分繰り返し表示を行います
	for(vector<string>::size_type i=0; i < main_cmd.size(); i++) {

		//コマンドラインに1つしか文字列が無いので1回のみ
		cout << i << "番目 : " << main_cmd[i] << "\n";
	}

	cout << "文字列をプッシュし直します\n";

	//新たにプッシュ用の文字列を定義
	const char* test1[] = { "eclipse_cmdline",
							"Visual_Studio_cmdline",
							"eclipse_Vsual_Studio",
							"Visual_Studio",
							"eclipse"};

	main_cmd = strptary_to_vec(test1, sizeof(test1) / sizeof(test1[0]));		//新たにコンテナに文字列をプッシュしなおします

	//コンテナにある文字列分繰り返し表示を行います
	for(vector<string>::size_type i=0; i < main_cmd.size(); i++) {

		//コマンドラインに1つしか文字列が無いので1回のみ
		cout << i << "番目 : " << main_cmd[i] << "\n";
	}

	cout << "文字列をシャッフル\n";

	vector<string> main_cmd_copy(main_cmd);	//作業用 にコピー

	//シャッフルを呼び出す 文字列が3つだとシャッフルされない last - first -1 回 swap されるから
	random_shuffle(main_cmd_copy.begin(),main_cmd_copy.end());

	//コンテナにある文字列分繰り返し表示を行います
	for(vector<string>::size_type i=0; i < main_cmd_copy.size(); i++) {

		//コマンドラインに1つしか文字列が無いので1回のみ
		cout << i << "番目 : " << main_cmd_copy[i] << "\n";
	}

	cout << "文字列をソート\n";

	//昇順にソート
	sort(main_cmd_copy.rbegin(),main_cmd_copy.rend());

	//ソートされた文字列群の表示
	print(main_cmd_copy.begin(),main_cmd_copy.end());

	return 0;
}

//関数 表示を行う
//仮引数 コンテナ
//返却値 無し

template <class Type>
struct put1 :public unary_function<const Type&, void> {

	void operator () (const Type& tmp) {

		static int cnt = 0;		//呼び出した順番をカウント

		cout << cnt++ << "番目 : ";

		//ポインタの指す文字列を表示
		cout << tmp << "\n";
	}
};

//関数 全要素を表示する
//仮引数 vector の オブジェクト
//返却値 無し
template <class InputIterator>
void print(InputIterator first,InputIterator last) {

	//反復子により先頭から末尾まで走査する
	for_each(first,last,put1<typename iterator_traits<InputIterator>::value_type>() );

		cout << "\n";
}

//関数 与えられたポインタから文字列をプッシュする
//仮引数 文字列と文字列数
//返却値 コンテナ

vector<string> strptary_to_vec(const char** ptr,int num) {

	vector<string> tmp;				//string型のコンテナを用意

	//与えられた文字数列分繰り返しプッシュします
	for(int i=0; i < num; i++) {

		//ポインタのポインタが指す文字列をプッシュ
		tmp.push_back(ptr[i]);
	}
	return tmp;
};
