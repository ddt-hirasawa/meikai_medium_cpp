/*
���K2-1 �����Ȃ����� �i���̐����j�����E�ɃV�t�g�����l���A
2�ׂ̂���ł̏�Z�⏜�Z�̉��Z���ʂƈ�v���邱�Ƃ��m�F����

�쐬�� 2017�N5��15��

�쐬�� ���V�h��
*/

#include<iostream>

using namespace std;


int count_bits(unsigned tmp);
int int_bits();
void print_bits(unsigned tmp,unsigned* sub);

//�֐��̐錾 func.cpp�ɏ��ɂ܂Ƃ߂܂�
int out_put(unsigned*);

int main()
{
	unsigned tmp;				//32�� 0 1 �̗����\���ł���ϐ�

	unsigned sub[100] = {0};	//01 �̒l�����Z�Ɏg�������̂Ŋi�[���܂��B

	unsigned sub1[100] = {0};	//01 �̒l�����Z�Ɏg�������̂Ŋi�[���܂��B

	unsigned sub2[100] = {0};	//01 �̒l�����Z�Ɏg�������̂Ŋi�[���܂��B

	tmp = 100;					//����10�i����20�Ƃ��܂�

	//�錾 20��2�i���\�L
	cout << "tmp : ";

	//�֐��̌Ăяo������ 0 1 �̗����\��
	print_bits(tmp,sub);

	//�m�F�̂��߁A�z��� 0 1 ����ׂĕ\�L���܂�
	for(int i=15; i >= 0; i--) {

		// 0 1 �̒l��\����������
		cout << sub[i];
	}
	//10�i���ɖ߂����l��\�����܂�
	cout << " 10�i�� : " << out_put(sub);

	//��؂�܂�
	cout << "\n";

	tmp <<= 1;					//���ɂP��bit���V�t�g���܂�

	//�錾 20��2�ׂ̂���ł̏�Z��2�i���\�L
	cout << "tmp : ";

	//�֐��̌Ăяo������ 0 1 �̗����\��
	print_bits(tmp,sub1);

	//�m�F�̂��߁A�z��� 0 1 ����ׂĕ\�L���܂�
	for(int i=15; i >= 0; i--) {

		// 0 1 �̒l��\����������
		cout << sub1[i];
	}
	//10�i���ɖ߂����l��\�����܂�
	cout << " 10�i�� : " << out_put(sub1);
	//��؂�܂�
	cout << "\n";

	tmp >>= 2;					//�E��2��bit���V�t�g���܂�

	//�錾 20��2�ׂ̂���ł̏��Z��2�i���\�L
	cout << "tmp : ";

	//�֐��̌Ăяo������ 0 1 �̗����\��
	print_bits(tmp,sub2);

	//�m�F�̂��߁A�z��� 0 1 ����ׂĕ\�L���܂�
	for(int i=15; i >= 0; i--) {

		// 0 1 �̒l��\����������
		cout << sub2[i];
	}
	//10�i���ɖ߂����l��\�����܂�
	cout << " 10�i�� : " << out_put(sub2);
	//��؂�܂�
	cout << "\n";

	return 0;
}

int count_bits(unsigned tmp) {

	int bits = 0;		//�J�E���^ bit �� 0 �� 1 0�ŏ������q�J�E���g���܂�

	const int one = 1;

	//�E�Ƀr�b�g���ړ����Ă����A0�ɂȂ�܂ŌJ��Ԃ��܂�
	while(tmp) {

		//�r�b�g�� 1 �̕������������Ƃ�
		if(tmp & 1U) {

			// 1 ������܂����B�J�E���g���܂�
			bits++;
		}

		//tmp ��bit ���E��1���炵�܂�
		tmp >>= one;
	}
	//�J�E���g����bit����ԋp���܂�
	return bits;
}

//�֐� int �^�̃r�b�g����\�����܂� �����̒��� 0 �� 1 �̌�
//������ ����
//�ԋp�l �����̂��ׂẴr�b�g��

int int_bits() {

	return count_bits(~0U);
}

//�֐� ���� tmp ��bit�\����\��
//������ ���ׂ������� tmp
//�ԋp�l ����

void print_bits(unsigned tmp,unsigned* sub) {

	int max = int_bits() - 1;		//�r�b�g�̌���ϐ��Ƃ��Ă��炢�܂��B
									//-1 �� ���l�� 0 �` 999 ��1000�ʂ�ƍl���邩��

	//�S�r�b�g�����������邽�߃��[�v���܂�
	for(; max >= 0; max--) {

		//�\������Ƃ��Abit �� 1 ���w���Ƃ� �R���\�[����1��\��
		sub[max] = ((tmp >> max) & 1U ? 1 : 0);
	}
}