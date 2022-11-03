#include <iostream>
#include "WholeNode.h"
using namespace std;

int main() {
	int MaxSize = -1;
	WholeNode All;
	cout << "메모리를 할당할 공간을 입력하세요 : ";
	while (MaxSize <= 0) {
		cin >> MaxSize;
		cin.clear();
	}

	All = WholeNode(MaxSize);
	//전체적인 관리공간 생성(클래스)

	All.MENU();

	return 0;
}