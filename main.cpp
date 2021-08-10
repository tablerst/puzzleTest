#include "main.h"
int main() {
begin:
	showMenu();
	switch (getMenuMouse()) {
	case 0:				//开始
		showDifficulty();
		switch (getDiffMouse()) {
		case 0://简单模式
			level = 2;
		choosePic:
			showPicBk(0);
			loadPicFromArray();
			showPic(0);
		choosePage:
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
			case 5:	//下一页
				page = 1;
				showPicBk(page);
				showPic(page);
				goto choosePage;
				break;
			case 6://上一页
				page = 0;
				showPicBk(page);
				showPic(page);
				goto choosePage;
				break;
			}
		case 1://标准模式
			level = 3;
			//showPics();
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
		case 2://困难模式
			level = 4;
			//showPics();
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
		default:
			break;
		}
		break;
	case 1:				//商店
		shopStart();
		break;
	case 2:				//排行榜
		break;
	case 3:				//音乐设置
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