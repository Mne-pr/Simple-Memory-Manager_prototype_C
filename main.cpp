#include <iostream>
#include "WholeNode.h"
using namespace std;

int main() {
	int MaxSize = -1;
	WholeNode All;
	cout << "�޸𸮸� �Ҵ��� ������ �Է��ϼ��� : ";
	while (MaxSize <= 0) {
		cin >> MaxSize;
		cin.clear();
	}

	All = WholeNode(MaxSize);
	//��ü���� �������� ����(Ŭ����)

	All.MENU();

	return 0;
}