#include "main.h"

int main() {
begin:
	showMenu();
	switch (getMenuMouse()) {
		case 0:				//��ʼ
			showDifficulty();
			if (getDiffMouse() == 0) {//��ģʽ
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
			else if (getDiffMouse() == 1) {	//��׼ģʽ
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
			else if (getDiffMouse() == 2) {	//����ģʽ
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
		case 1:				//�̵�
			break;
		case 2:				//���а�
			break;
		case 3:				//��Ϸ����
			//musicSets();
			break;
		case 4:				//�˳�
			closegraph();
			exit(0);
			break;
		default:
			break;
	}
}