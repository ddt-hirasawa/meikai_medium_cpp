/*
演習9-3 Twin< Twin<Date> , Twin<Date>> を要素として持つクラス配列を作成せよ

作成日 2017年5月25日

作成者 平澤敬介
*/

#ifndef TWIN_H_
#define TWIN_H_

#include<utility>
#include<algorithm>
#include<cstring>
#include<iostream>

//テンプレートクラス


template <class Type> class Twin {
	Type tmp1;		//型の指定をしない変数
	Type tmp2;		//Typeをデータメンバとして定義

public:

	//テンプレートクラスのコンストラクタ
	//初期化子を含めすべて Type 表記
	Twin(const Type& tmp1_ = Type() , const Type& tmp2_ = Type()) :

		//初期化子は変化なし
		tmp1(tmp1_),tmp2(tmp2_) {
	}

	//デストラクタ
	~Twin(){

		//std::cout << "テンプレートクラス破棄されました\n";
	}

	//第一データメンバのゲッタ
	Type first_get() const {

		return tmp1;
	}

	//第一データメンバのセッタ
	Type& first_set() {

		return tmp1;
	}

	//第二データメンバのゲッタ
	Type second_get() const {

		return tmp2;
	}

	//第二データメンバのセッタ
	Type& second_set() {

		return tmp2;
	}

	//データメンバ 2値の決定 引数を代入する
	void set(const Type& set1,const Type& set2) {

		tmp1 = set1;		//第一データメンバ
		tmp2 = set2;		//第二データメンバ
	}

	//データメンバを比較し小さいほうを返却する
	Type min() const {

		//条件演算子による返却
		return tmp1 < tmp2 ? tmp1 : tmp2;
	}

	//判別関数 データメンバの一番目が2番目と比較し小さいかどうか
	bool ascending() const {

		return tmp1 < tmp2;
	}

	//ソート関数 昇順で並べ替え
	void sort() {

		//if文で検出し
		if(tmp1 < tmp2) {

			//コンパイラにより提供されるデフォルト関数
			std::swap(tmp1,tmp2);
		}
	}

	Twin operator + (Twin<Twin<Type> >& tmp) {

		tmp1 += tmp.tmp1;
		tmp2 += tmp.tmp2;

		return tmp;
	}
};

//挿入子
template <class Type> inline std::ostream& operator << (std::ostream& stream,const Twin<Type>& tmp) {

	return stream << "[ " << tmp.first_get() << "," << tmp.second_get() << " ]";
}

#endif /* TWIN_H_ */
