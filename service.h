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

/******************************************全局变量的声明******************************************/

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

//时间显示
void showTime();

//新增逆序数优化，保证每次都能完成拼图
void Right_judge();

//初始化随机数组
void randArray();

//暂停按键
bool ifstop();

//判定是否通关
void judgeGraphics();

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














