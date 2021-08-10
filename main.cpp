#include "main.h"

int main() {
begin:
	showMenu();
	switch (getMenuMouse()) {
	case 0:				//开始
		showDifficulty();
		if (getDiffMouse() == 0) {//简单模式
			level = 2;
		choosePic:
			showPics();
			switch (getPicMouse()) {
			case 1:				//pic1
				start(1);
				if (!isAgain()) {
					closegraph();
					goto begin;
				}
				else {
					goto choosePic;
				}
				break;
			case 2:				//pic2
				start(2);
				if (!isAgain()) {
					closegraph();
					goto begin;
				}
				else {
					goto choosePic;
				}
				break;
			case 3:				//pic3
				start(3);
				if (!isAgain()) {
					closegraph();
					goto begin;
				}
				else {
					goto choosePic;
				}
				break;
			case 4:				//pic4
				start(4);
				if (!isAgain()) {
					closegraph();
					goto begin;
				}
				else {
					goto choosePic;
				}
				break;
			}
		}
		else if (getDiffMouse() == 1) {	//标准模式
			level = 3;
			showPics();
			switch (getPicMouse()) {
			case 1:				//pic1
				start(1);
				if (!isAgain()) {
					closegraph();
					goto begin;
				}
				else {
					goto choosePic;
				}
				break;
			case 2:				//pic2
				start(2);
				if (!isAgain()) {
					closegraph();
					goto begin;
				}
				else {
					goto choosePic;
				}
				break;
			case 3:				//pic3
				start(3);
				if (!isAgain()) {
					closegraph();
					goto begin;
				}
				else {
					goto choosePic;
				}
				break;
			case 4:				//pic4
				start(4);
				if (!isAgain()) {
					closegraph();
					goto begin;
				}
				else {
					goto choosePic;
				}
				break;
			}
		}
		else if (getDiffMouse() == 2) {	//困难模式
			level = 4;
			showPics();
			switch (getPicMouse()) {
			case 1:				//pic1
				start(1);
				if (!isAgain()) {
					closegraph();
					goto begin;
				}
				else {
					goto choosePic;
				}
				break;
			case 2:				//pic2
				start(2);
				if (!isAgain()) {
					closegraph();
					goto begin;
				}
				else {
					goto choosePic;
				}
				break;
			case 3:				//pic3
				start(3);
				if (!isAgain()) {
					closegraph();
					goto begin;
				}
				else {
					goto choosePic;
				}
				break;
			case 4:				//pic4
				start(4);
				if (!isAgain()) {
					closegraph();
					goto begin;
				}
				else {
					goto choosePic;
				}
				break;
			}
		}
		break;
	case 1:				//商店
		break;
	case 2:				//排行榜
		break;
	case 3:				//游戏设置
		//musicSets();
		break;
	case 4:				//退出
		closegraph();
		exit(0);
		break;
	default:
		break;
	}
}