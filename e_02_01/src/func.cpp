/*
���K2-1 �����Ȃ����� �i���̐����j�����E�ɃV�t�g�����l���A
2�ׂ̂���ł̏�Z�⏜�Z�̉��Z���ʂƈ�v���邱�Ƃ��m�F����

�쐬�� 2017�N5��15��

�쐬�� ���V�h��
*/

#include<iostream>

using namespace std;

//�֐� 2�i����10�i���ɕϊ����܂�
//������ 0 1 �̗��񂪓������z��
//�ԋp�l 10�i���ɕϊ������l

int out_put(unsigned* tmp) {

	int answer = 0;			//�ԋp����10�i���̒l
	int ex = 1;				//2�ׂ̂����\�����邽�߂̕ϐ�

	//���ɁA16bit �܂ł�ϊ��ΏۂƂ��܂�
	for(int i=0; i <= 15; i++) {

		answer += *(tmp + i) * ex;	//�ԋp����l�́A�z��̒l��1��
									//�����̓Y����2�ׂ̂�������Z���Ă���

		ex *= 2;					//2�����[�v���ɐώZ���āA���Z�Ɏg���܂�
	}
	return answer;
}