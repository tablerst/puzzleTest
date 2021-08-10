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
#include <time.h>
using namespace std;
/******************************************结构体的声明******************************************/
struct Struct_Time										//用来存储计数时间，例如：11小时45分14秒 --> 11：45：14
{
	int h = 0;											//小时
	int m = 0;											//分钟
	int s = 0;											//秒
	int total = 0;										//总共
};

struct pic {
	IMAGE img;											//保存图片对象
	int state;											//记录图片状态

};
/******************************************全局变量的声明******************************************/
extern pic picArray[10];									//关卡图片状态
extern int check[MAX_MAP][MAX_MAP];						//检查数组
extern int map[MAX_MAP][MAX_MAP];						//序号储存
extern int random[MAX_MAP * MAX_MAP];					//随机化数组

extern int level;										//关卡难度
extern int width_temp;									//分块宽度
extern int height_temp;									//分块高度
extern int flagi;										//标记块行位置
extern int flagj;										//标记块列位置
extern int mousei;										//标记鼠标位置
extern int mousej;										//标记鼠标位置
extern int tend;										//时间
extern int tbegin;										//开始时间
extern double picturSmall;								//缩放因子
/**************************************函数声明*********************************/
void Right_judge();										//新增逆序数优化，保证每次都能完成拼图
void randArray();										//初始化随机数组
void judgeGraphics();									//判定是否通关

/**
	功能：判断是否重新选择图片开始游戏
	参数：空
	返回值：
		true --> 重新选择图片开始游戏
		false --> 返回主菜单
*/
bool isAgain();

/**
	功能：开始游戏操作
	参数：
		int类型的图片标识数字
		1  -->  pic1（左上方）
		2  -->  pic2（右上方）
		3  -->  pic3（左下方）
		4  -->  pic4（右下方）
	返回值：空
 */
void start(int judgePic);

/**
	功能：检测金币数是否足够，以及金币消耗
	参数：空
	返回值：空
 */
void chargeprice();

void setGraphics();				//设置好图片位置及对应关系

/**
	功能：开启商店
	参数：空
	返回值：空
 */
void shopStart();

/**
	功能：游戏计时
	参数：空
	返回值：空
*/
void showTime();

/**
	功能：保存关卡图片到数组里
	参数：空
	返回值：空
*/
void savePicToArray();



void loadPicFromArray();