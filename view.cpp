#include "view.h"
#include "service.h"

IMAGE img_bk(0, 0);
IMAGE img_showDifficulty(0, 0);
IMAGE img_choosePic(0, 0);
IMAGE img_small(0, 0);								//IMAGE实例，储存缩放图

void showMenu() {
	loadimage(&img_bk, _T("bk.png"));
	initgraph(img_bk.getwidth(), img_bk.getheight());
	HWND hwnd = GetHWnd();
	MoveWindow(hwnd, 400, 100, img_bk.getwidth(), img_bk.getheight(), false);
	putimage(0, 0, &img_bk);
}

void reSetimg(IMAGE img[][MAX_MAP])
{
	int minxPic = img_total.getwidth() / MAX_MAP;
	int minyPic = img_total.getheight() / MAX_MAP;
	for (int i = 0; i < MAX_MAP; i++)
	{
		for (int j = 0; j < MAX_MAP; j++)
		{
			getimage(&img[i][j], i * minxPic, j * minyPic, minxPic, minyPic);
		}
	}
}

void showDifficulty() {
	loadimage(&img_showDifficulty, _T("diff.png"));
	initgraph(img_showDifficulty.getwidth(), img_showDifficulty.getheight());
	HWND hwnd = GetHWnd();
	MoveWindow(hwnd, 400, 100, img_showDifficulty.getwidth(), img_showDifficulty.getheight(), false);
	putimage(0, 0, &img_showDifficulty);
}

void showPics() {
	loadimage(&img_choosePic, _T("choosePic.png"));
	initgraph(img_choosePic.getwidth(), img_choosePic.getheight());
	HWND hwnd = GetHWnd();
	MoveWindow(hwnd, 400, 100, img_choosePic.getwidth(), img_choosePic.getheight(), false);
	putimage(0, 0, &img_choosePic);
}

void Set_rightview()
{
	putimage(img_total.getwidth() * 1.5, 0, &img_small);
	setlinecolor(WHITE);
	line(img_total.getwidth() * 1.5, img_total.getheight() / 2, img_total.getwidth() * 1.5, img_total.getheight());
	line(img_total.getwidth() * 1.5, img_total.getheight() * 0.667, img_total.getwidth() * 2, img_total.getheight() * 0.667);
	line(img_total.getwidth() * 1.5, img_total.getheight() * 0.833, img_total.getwidth() * 2, img_total.getheight() * 0.833);

	settextcolor(WHITE);
	settextstyle(30, 0, L"楷体", 0, 0, 0, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH);
	
	wchar_t s1[] = L"上为原图";
	wchar_t s2[] = L"游戏用时";
	wchar_t s3[] = L"暂停";

	outtextxy(img_total.getwidth() * 1.63, img_total.getheight() * 0.55, s1);
	outtextxy(img_total.getwidth() * 1.63, img_total.getheight() * 0.717, s2);
	outtextxy(img_total.getwidth() * 1.7, img_total.getheight() * 0.883, s3);
}

inline void lineFlush()								//画线条分割图片
{
	for (int i = 0; i < level; i++)
	{
		//setlinecolor(RED);			//可以更改线条颜色 默认白色
		line(i * width_temp, 0, i * width_temp, img_total.getheight());
		line(0, i * height_temp, img_total.getwidth(), i * height_temp);
	}
}



int getMenuMouse() {
	if (MouseHit()){
		FlushMouseMsgBuffer();
	}
	MOUSEMSG menuMsg ;
	while (true){
		menuMsg = GetMouseMsg();
		if (menuMsg.uMsg == WM_LBUTTONDOWN) {
			if ((menuMsg.x >= 76 && menuMsg.x <= 287) && (menuMsg.y >= 83 && menuMsg.y <= 145)) {//开始按钮		
				//closegraph();
				return 0;
			}
			else if ((menuMsg.x >= 413 && menuMsg.x <= 626) && (menuMsg.y >= 83 && menuMsg.y <= 145)) {//商店按钮		
				//closegraph();
				return 1;
			}
			else if ((menuMsg.x >= 76 && menuMsg.x <= 287) && (menuMsg.y >= 362 && menuMsg.y <= 430)) {//游戏设置按钮
				//closegraph();
				return 2;
			}
			else if ((menuMsg.x >= 413 && menuMsg.x <= 626) && (menuMsg.y >= 362 && menuMsg.y <= 430)) {//排行榜	
				//closegraph();
				return 3;
			}
			else if ((menuMsg.x >= 288 && menuMsg.x <= 414) && (menuMsg.y >= 641 && menuMsg.y <= 684)) {//退出按钮
				//closegraph();
				return 4;
			}
		}
	}
	
}

int getDiffMouse() {
	if (MouseHit()){
		FlushMouseMsgBuffer();
	}
	
	MOUSEMSG diffMsg ;
	while (true)
	{
		diffMsg = GetMouseMsg();
		if (diffMsg.uMsg == WM_LBUTTONDOWN) {
				if ((diffMsg.x >= 181 && diffMsg.x <= 545) && (diffMsg.y >= 191 && diffMsg.y <= 297)) {	//简单按钮		
					return 0;
				}
				else if ((diffMsg.x >= 181 && diffMsg.x <= 545) && (diffMsg.y >= 333 && diffMsg.y <= 432)) {//标准按钮		
					return 1;
				}
				else if ((diffMsg.x >= 181 && diffMsg.x <= 545) && (diffMsg.y >= 467 && diffMsg.y <= 567)) {//困难
					return 2;
				}
	}
	
		
	}
}

int getPicMouse() {
	if (MouseHit()){
		FlushMouseMsgBuffer();
	}
	
	MOUSEMSG picMsg ;
	while (true)
	{
		picMsg = GetMouseMsg();
		if (picMsg.uMsg == WM_LBUTTONDOWN) {
			if ((picMsg.x >= 110 && picMsg.x <= 314) && (picMsg.y >= 147 && picMsg.y <= 386)) {	//pic1		
				closegraph();
				return 1;
			}
			else if ((picMsg.x >= 398 && picMsg.x <= 590) && (picMsg.y >= 147 && picMsg.y <= 386)) {//pic2		
				closegraph();
				return 2;
			}
			else if ((picMsg.x >= 110 && picMsg.x <= 314) && (picMsg.y >= 415 && picMsg.y <= 652)) {//pic3		
				closegraph();
				return 3;
			}
			else if ((picMsg.x >= 398 && picMsg.x <= 590) && (picMsg.y >= 415 && picMsg.y <= 652)) {//pic4		
				closegraph();
				return 4;
			}
		}
	}
}


int getShopPicMouse() {
	FlushMouseMsgBuffer();
	MOUSEMSG picMsg = GetMouseMsg();
	if (picMsg.uMsg == WM_LBUTTONDOWN) {
		if ((picMsg.x >= 204 && picMsg.x <= 362) && (picMsg.y >= 145 && picMsg.y <= 367)) {	//shoppic1		
			closegraph();
			return 1;
		}
		else if ((picMsg.x >= 436 && picMsg.x <= 608) && (picMsg.y >= 145 && picMsg.y <= 367)) {//shoppic2		
			closegraph();
			return 2;
		}
		else if ((picMsg.x >= 204 && picMsg.x <= 362) && (picMsg.y >= 413 && picMsg.y <= 658)) {//shoppic3		
			closegraph();
			return 3;
		}
		else if ((picMsg.x >= 436 && picMsg.x <= 608) && (picMsg.y >= 413 && picMsg.y <= 658)) {//shoppic4		
			closegraph();
			return 4;
		}
	}
}

void getPlayingMouse() {
	MOUSEMSG msg = GetMouseMsg();
	if (msg.uMsg == WM_LBUTTONDOWN)
	{
		if ((msg.x < img_total.getwidth()) && (msg.y < img_total.getheight()))
		{
			mousei = msg.x / width_temp;
			mousej = msg.y / height_temp;
			if ((mousei + 1 == flagi && mousej == flagj) ||
				(mousei == flagi && mousej + 1 == flagj) ||
				(mousei - 1 == flagi && mousej == flagj) ||
				(mousei == flagi && mousej - 1 == flagj))
			{
				//交换图片分块
				swap(map[mousej][mousei], map[flagj][flagi]);
			}
		}
	}
}

void showGraphics() {
	for (int i = 0; i < level; i++)
	{
		for (int j = 0; j < level; j++)
		{
			if (map[j][i] == level * level - 1)				//逆转赋值2
			{
				flagi = i;
				flagj = j;
				putimage(i * width_temp, j * height_temp, &img_blank);
			}
			else
			{
				int countj = map[j][i] % level;
				int counti = map[j][i] / level;
				putimage(i * width_temp, j * height_temp, &img[countj][counti]);
			}
		}
	}
	lineFlush();
}

void getGraphics(int judgePic) {
	switch (judgePic) {
	case 1:
		loadimage(&img_total, L"pic1.png");
		loadimage(&img_small, L"pic1.png", img_total.getwidth() * picturSmall, img_total.getheight() * picturSmall);
		loadimage(&img_blank, L"0.png", img_total.getwidth() / level, img_total.getheight() / level);
		initgraph(img_total.getwidth() * 2, img_total.getheight());
		setbkcolor(BLACK);
		cleardevice();
		break;
	case 2:
		loadimage(&img_total, L"pic2.png");
		loadimage(&img_small, L"pic2.png", img_total.getwidth() * picturSmall, img_total.getheight() * picturSmall);
		loadimage(&img_blank, L"0.png", img_total.getwidth() / level, img_total.getheight() / level);
		initgraph(img_total.getwidth() * 2, img_total.getheight());
		setbkcolor(BLACK);
		cleardevice();
		break;
	case 3:
		loadimage(&img_total, L"pic3.png");
		loadimage(&img_small, L"pic3.png", img_total.getwidth() * picturSmall, img_total.getheight() * picturSmall);
		loadimage(&img_blank, L"0.png", img_total.getwidth() / level, img_total.getheight() / level);
		initgraph(img_total.getwidth() * 2, img_total.getheight());
		setbkcolor(BLACK);
		cleardevice();
		break;
	case 4:
		loadimage(&img_total, L"pic4.png");
		loadimage(&img_small, L"pic4.png", img_total.getwidth() * picturSmall, img_total.getheight() * picturSmall);
		loadimage(&img_blank, L"0.png", img_total.getwidth() / level, img_total.getheight() / level);
		initgraph(img_total.getwidth() * 2, img_total.getheight());
		setbkcolor(BLACK);
		cleardevice();
		break;
	default:
		break;
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
	Set_rightview();
}