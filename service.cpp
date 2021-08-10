#include "service.h"

//��ʼ��ȫ�ֱ���
int check[MAX_MAP][MAX_MAP] = { 0 };					//�������
int map[MAX_MAP][MAX_MAP] = { 0 };						//��Ŵ���
int random[MAX_MAP * MAX_MAP] = { 0 };					//���������
IMAGE img_total(0, 0);									//ԭͼƬ
IMAGE img_blank(0, 0);									//�׵�
IMAGE img[MAX_MAP][MAX_MAP] = { (0,0) };				//����ֿ�ͼƬ

int level = 6;											//�ؿ��Ѷ�
int width_temp = 0;										//�ֿ���
int height_temp = 0;									//�ֿ�߶�
int flagi = 0;											//��ǿ���λ��
int flagj = 0;											//��ǿ���λ��
int mousei = 0;											//������λ��
int mousej = 0;											//������λ��
int FLAG = 0;											//ʤ�����
int tend = 0;											//ʱ��
int tbegin = 0;											//��ʼʱ��
double picturSmall = 0.5;								//��������


inline void Right_judge(){										
	int Right_judgei = 0, Rightjudge[MAX_MAP * MAX_MAP], num = 0;
	memset(Rightjudge, 0, sizeof(Rightjudge));
	for (int i = 0; i < level; i++)
	{
		for (int j = 0; j < level; j++)
		{
			Rightjudge[num] = map[i][j];
			num++;
		}
	}
	for (int i = 0; i < level * level; i++)
	{
		for (int j = i; j < level * level; j++)
		{
			if (Rightjudge[i] > Rightjudge[j])
				Right_judgei++;
		}
	}
	if (Right_judgei % 2)
		swap(map[0][0], map[0][1]);
}

inline void showTime()
{
	TCHAR s5[3600];
	_stprintf_s(s5, L"%.2f��", (tend - tbegin) / (double)CLOCKS_PER_SEC);
	outtextxy(img_total.getwidth() * 1.67, img_total.getwidth() + 30, s5);
}

void randArray() {
	memset(random, 0, sizeof(random));
	for (int i = 0; i < level * level - 1; i++)
		random[i] = i;
	random[level * level - 1] = level * level - 1;

	random_device rd;
	mt19937 g(rd());									// ���������
	shuffle(random, random + level * level - 1, g);			// ����˳��

	int cnt = 0;
	for (int i = 0; i < level; i++)
	{
		for (int j = 0; j < level; j++)
		{
			map[j][i] = random[cnt];					//��ת��ֵ1
			cnt++;
		}
	}
	Right_judge();
}

void judgeGraphics() {
	int cnt = 0;
	for (int i = 0; i < level; i++)
	{
		for (int j = 0; j < level; j++)
		{
			if (map[i][j] == check[i][j])
				cnt++;
		}
	}
	if (cnt == level * level)
	{
		MessageBox(GetHWnd(), _T("������."), _T("��Ϣ��ʾ."), MB_OK);
		FLAG = 1;
		//exit(0);
	}
}

bool isAgain() {
	UINT  dr = MessageBox(GetHWnd(),_T("�Ƿ����棿"),_T("��Ϣ��ʾ"), MB_YESNO);
	if (dr == IDYES){
		return true;
	}
	else if (dr == IDNO){
		return false;
	}
}

bool ifstop()
{
	if (MouseHit())
		FlushMouseMsgBuffer();
	MOUSEMSG menuMsg;
	while (true) {
		menuMsg = GetMouseMsg();
		MOUSEMSG msgstop = GetMouseMsg();
		if ((msgstop.x > img_total.getwidth() * 1.5 && msgstop.x < img_total.getwidth() * 2)
			&& (msgstop.y > img_total.getheight() * 0.833 && msgstop.y < img_total.getheight()))
		{
			if (msgstop.uMsg == WM_LBUTTONDOWN)
			{
				UINT  dr = MessageBox(GetHWnd(), _T("���棿"), _T("��Ϣ��ʾ"), MB_YESNO);
				if (dr == IDYES) {
					return true;
				}
				else if (dr == IDNO) {
					return false;
				}
			}
		}
	}
}

void start(int judgePic )
{
	tbegin = clock();
	getGraphics(judgePic);
	setGraphics();
	randArray();
	showGraphics();

	while (1){
		tend = clock();
		showTime();
		BeginBatchDraw();			//˫�����ֹ��˸
		getPlayingMouse();
		showGraphics();
		EndBatchDraw();				//˫�����ֹ��˸
		judgeGraphics();
		
		if (FLAG == 1)
		{
			FLAG = 0;
			break;
		}
	}
	//system("pause");
}

