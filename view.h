#pragma once
#include <graphics.h>
#include <easyx.h>
#include <string.h>
#include <iostream>
#define MAX_MAP 10									//定义最大范围
using namespace std;
/******************************页面相关的全局变量声明***************************************/

extern IMAGE img_bk;								//IMAGE类实例化，用来存储 主菜单页面图片
extern IMAGE img_shop;								//IMAGE类实例化，用来存储 商店页面图片
extern IMAGE img_showDifficulty;					//IMAGE类实例化，用来存储 选择困难度页面图片
extern IMAGE img_choosePic;							//IMAGE类实例化，用来存储 商店里选择好的图片
extern IMAGE img_total;								//IMAGE实例，存储待拼图片
extern IMAGE img_blank;								//IMAGE实例，存储白底
extern IMAGE img[MAX_MAP][MAX_MAP];					//IMAGE实例，储存分块图片
extern int FLAG;									//胜利标记
extern int topPage;									//
/******************************页面相关的函数声明******************************************/

//1.展示图片
/**
	功能：展示主菜单页面
	参数：空
	返回值：空
 */
void showMenu();

/**
	功能：展示困难选择度页面
	参数：空
	返回值：空
 */
void showDifficulty();

/**
	功能：展示开始游戏前图片选择
	参数：空
	返回值：空
 */
void showPics();

/**
	功能：展示商店图片选择
	参数：空
	返回值：空
 */
void showShopPics();
/**
	功能：读取图片并预载到原图中
	参数：
		int类型的图片标识数字
		1  -->  pic1（左上方）
		2  -->  pic2（右上方）
		3  -->  pic3（左下方）
		4  -->  pic4（右下方）
	返回值：空
 */
void getGraphics(int);

//画线条分割图片
void lineFlush();

//显示分块图片
void showGraphics();


//2.交互
/**
	功能：获取主菜单页面鼠标信息
	参数：空
	返回值：
		返回0 --> 点击了“商店”按钮
		返回1 --> 点击了“开始”按钮
		返回2 --> 点击了“排行榜”按钮
		返回3 --> 点击了“游戏设置”按钮
		返回4 --> 点击了“退出”按钮
 */
int getMenuMouse();

/**
	功能：获取困难选择度页面鼠标信息
	参数：空
	返回值：
		返回0 --> 点击了“简单”按钮
		返回1 --> 点击了“标准”按钮
		返回2 --> 点击了“困难”按钮
 */
int getDiffMouse();

/**
	功能：获取困难选择度页面鼠标信息
	参数：空
	返回值：
		返回1 --> 点击了“pic1”图片（左上方）
		返回2 --> 点击了“pic2”图片（右上方）
		返回3 --> 点击了“pic3”图片（左下方）
		返回4 --> 点击了“pic4”图片（右下方）
 */
int getPicMouse();

/**
	功能：获取商店图片页面鼠标信息
	参数：空
	返回值：
		返回1 --> 点击了“shoppic1”图片（左上方）
		返回2 --> 点击了“shoppic2”图片（右上方）
		返回3 --> 点击了“shoppic3”图片（左下方）
		返回4 --> 点击了“shoppic4”图片（右下方）
 */
int getShopPicMouse();

//开始游戏时，获取鼠标操作
void getPlayingMouse();

//重置img数组
void reSetimg(IMAGE img[][MAX_MAP]);

//设置好图片位置及对应关系
void setGraphics();

//音乐设置
void musicSets();




© 2021 GitHub, Inc.