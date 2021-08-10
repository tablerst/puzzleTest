#include "service.h"
#include <stdio.h>
//初始化全局变量
int check[MAX_MAP][MAX_MAP] = { 0 };					//检查数组
int map[MAX_MAP][MAX_MAP] = { 0 };						//序号储存
int random[MAX_MAP * MAX_MAP] = { 0 };					//随机化数组
IMAGE img_total(0, 0);									//原图片
IMAGE img_blank(0, 0);									//白底
IMAGE img[MAX_MAP][MAX_MAP] = { (0,0) };				//储存分块图片
pic picArray[10] = { };									//关卡图片状态


int level = 3;											//关卡难度
int width_temp = 0;										//分块宽度
int height_temp = 0;									//分块高度
int flagi = 0;											//标记块行位置
int flagj = 0;											//标记块列位置
int mousei = 0;											//标记鼠标位置
int mousej = 0;											//标记鼠标位置
int FLAG = 0;											//胜利标记
int tend = 0;											//时间
int tbegin = 0;											//开始时间
double picturSmall = 0.5;								//缩放因子

inline void Right_judge() {
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

void randArray() {
	for (int i = 0; i < level * level - 1; i++)
		random[i] = i;
	random[level * level - 1] = level * level - 1;

	random_device rd;
	mt19937 g(rd());									// 随机数引擎
	shuffle(random, random + level * level - 1, g);			// 打乱顺序

	int cnt = 0;
	for (int i = 0; i < level; i++)
	{
		for (int j = 0; j < level; j++)
		{
			map[j][i] = random[cnt];					//逆转赋值1
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
		MessageBox(GetHWnd(), _T("过关了."), _T("消息提示."), MB_OK);
		FLAG = 1;
		//exit(0);
	}
}

bool isAgain() {
	UINT  dr = MessageBox(GetHWnd(), _T("是否重玩？"), _T("消息提示"), MB_YESNO);
	return (dr == IDYES) ? true : false;
}

void start(int judgePic)
{
	tbegin = clock();
	getGraphics(judgePic);
	setGraphics();
	randArray();
	showGraphics();

	while (1) {
		tend = clock();
		showTime();
		BeginBatchDraw();			//双缓冲防止闪烁
		getPlayingMouse();
		showGraphics();
		EndBatchDraw();				//双缓冲防止闪烁
		judgeGraphics();
		if (FLAG == 1)
		{
			FLAG = 0;
			break;
		}
	}
}

void setGraphics() {
	width_temp = img_total.getwidth() / level;
	height_temp = img_total.getheight() / level;
	//载入各分块的图片
	SetWorkingImage(&img_total);
	for (int i = 0; i < level; i++)
	{
		for (int j = 0; j < level; j++)
			getimage(&img[i][j], i * width_temp, j * height_temp, width_temp, height_temp);
	}
	SetWorkingImage();
	//校验数组初始化
	int cnt = 0;
	for (int i = 0; i < level; i++)
	{
		for (int j = 0; j < level; j++)
		{
			check[i][j] = cnt;
			cnt++;
		}
	}
	setRightView();
}


inline void showTime() {
	TCHAR s5[3600];
	_stprintf_s(s5, "%.2f秒", (tend - tbegin) / (double)CLOCKS_PER_SEC);
	outtextxy(img_total.getwidth() * 1.67, img_total.getheight() * 0.85, s5);
}


void shopStart() {
	showShop();
	buyPic();
}

void loadPicFromArray() {
	for (int i = 0; i < sizeof(picArray) / sizeof(picArray[0]); i++) {
		char picAddress[20] = "";
		sprintf_s(picAddress, "pic%d.png", i);
		loadimage(&picArray[i].img, (LPCSTR)picAddress, 150, 210);
		picArray[i].state = (i / 4 == 0) ? 1 : 0;						//前4个状态置1（表示可用）
	}
}



