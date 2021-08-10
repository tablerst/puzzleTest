#pragma once
#include <graphics.h>
#include <easyx.h>
#include <string.h>
#include <iostream>
#define MAX_MAP 10									//�������Χ
using namespace std;
/******************************ҳ����ص�ȫ�ֱ�������***************************************/

extern IMAGE img_bk;								//IMAGE��ʵ�����������洢 ���˵�ҳ��ͼƬ
extern IMAGE img_shop;								//IMAGE��ʵ�����������洢 �̵�ҳ��ͼƬ
extern IMAGE img_showDifficulty;					//IMAGE��ʵ�����������洢 ѡ�����Ѷ�ҳ��ͼƬ
extern IMAGE img_choosePic;							//IMAGE��ʵ�����������洢 �̵���ѡ��õ�ͼƬ
extern IMAGE img_total;								//IMAGEʵ�����洢��ƴͼƬ
extern IMAGE img_blank;								//IMAGEʵ�����洢�׵�
extern IMAGE img[MAX_MAP][MAX_MAP];					//IMAGEʵ��������ֿ�ͼƬ
extern int FLAG;									//ʤ�����
extern int topPage;									//
/******************************ҳ����صĺ�������******************************************/

//1.չʾͼƬ
/**
	���ܣ�չʾ���˵�ҳ��
	��������
	����ֵ����
 */
void showMenu();		

/**
	���ܣ�չʾ����ѡ���ҳ��
	��������
	����ֵ����		
 */
void showDifficulty();	

/**
	���ܣ�չʾ��ʼ��ϷǰͼƬѡ��
	��������
	����ֵ����
 */
void showPics();

/**
	���ܣ�չʾ�̵�ͼƬѡ��
	��������
	����ֵ����
 */
void showShopPics();
/**
	���ܣ���ȡͼƬ��Ԥ�ص�ԭͼ��
	������
		int���͵�ͼƬ��ʶ����
		1  -->  pic1�����Ϸ���
		2  -->  pic2�����Ϸ���
		3  -->  pic3�����·���
		4  -->  pic4�����·���
	����ֵ����
 */
void getGraphics(int);

//�������ָ�ͼƬ
void lineFlush();

//��ʾ�ֿ�ͼƬ
void showGraphics();


//2.����
/**
	���ܣ���ȡ���˵�ҳ�������Ϣ
	��������
	����ֵ��
		����0 --> ����ˡ��̵ꡱ��ť
		����1 --> ����ˡ���ʼ����ť
		����2 --> ����ˡ����а񡱰�ť
		����3 --> ����ˡ���Ϸ���á���ť
		����4 --> ����ˡ��˳�����ť

 */
int getMenuMouse();	

/**
	���ܣ���ȡ����ѡ���ҳ�������Ϣ
	��������
	����ֵ��
		����0 --> ����ˡ��򵥡���ť
		����1 --> ����ˡ���׼����ť
		����2 --> ����ˡ����ѡ���ť

 */
int getDiffMouse();	

/**
	���ܣ���ȡ����ѡ���ҳ�������Ϣ
	��������
	����ֵ��
		����1 --> ����ˡ�pic1��ͼƬ�����Ϸ���
		����2 --> ����ˡ�pic2��ͼƬ�����Ϸ���
		����3 --> ����ˡ�pic3��ͼƬ�����·���
		����4 --> ����ˡ�pic4��ͼƬ�����·���

 */
int getPicMouse();			

/**
	���ܣ���ȡ�̵�ͼƬҳ�������Ϣ
	��������
	����ֵ��
		����1 --> ����ˡ�shoppic1��ͼƬ�����Ϸ���
		����2 --> ����ˡ�shoppic2��ͼƬ�����Ϸ���
		����3 --> ����ˡ�shoppic3��ͼƬ�����·���
		����4 --> ����ˡ�shoppic4��ͼƬ�����·���
 */
int getShopPicMouse();

//��ʼ��Ϸʱ����ȡ������
void getPlayingMouse();

//����img����
void reSetimg(IMAGE img[][MAX_MAP]);

//���ú�ͼƬλ�ü���Ӧ��ϵ
void setGraphics();

//��������
void musicSets();




