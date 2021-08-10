#pragma once
#include <iostream>
#include <graphics.h>
#include <Windows.h>
#include <algorithm>
#include <easyx.h>
#include <cstdlib>
#include <random>
#include <cmath>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "view.h"
using namespace std;

/******************************************ȫ�ֱ���������******************************************/

extern int check[MAX_MAP][MAX_MAP];						//�������
extern int map[MAX_MAP][MAX_MAP];						//��Ŵ���
extern int random[MAX_MAP * MAX_MAP];					//���������

extern int level;										//�ؿ��Ѷ�
extern int width_temp;									//�ֿ���
extern int height_temp;									//�ֿ�߶�
extern int flagi;										//��ǿ���λ��
extern int flagj;										//��ǿ���λ��
extern int mousei;										//������λ��
extern int mousej;										//������λ��
extern int tend;										//ʱ��
extern int tbegin;										//��ʼʱ��
extern double picturSmall;								//��������

/**************************************��������*********************************/

//ʱ����ʾ
void showTime();

//�����������Ż�����֤ÿ�ζ������ƴͼ
void Right_judge();

//��ʼ���������
void randArray();

//��ͣ����
bool ifstop();

//�ж��Ƿ�ͨ��
void judgeGraphics();

/**
	���ܣ��ж��Ƿ�����ѡ��ͼƬ��ʼ��Ϸ
	��������
	����ֵ��
		true --> ����ѡ��ͼƬ��ʼ��Ϸ
		false --> �������˵�
*/
bool isAgain();		

/**
	���ܣ���ʼ��Ϸ����
	������
		int���͵�ͼƬ��ʶ����
		1  -->  pic1�����Ϸ���
		2  -->  pic2�����Ϸ���
		3  -->  pic3�����·���
		4  -->  pic4�����·���
	����ֵ����
 */
void start(int judgePic);














