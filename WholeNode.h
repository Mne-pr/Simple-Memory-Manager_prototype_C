#pragma once
#pragma once

struct Node {
	struct Node* next;
	struct Node* pre;
	int size;
	int start;
	int name;
};

class WholeNode {
public:
	WholeNode(int MaxSize);
	WholeNode();
	~WholeNode();

	void MENU();
	void NewMemory();
	void PrintNow();
private:
	struct Node* available;
	struct Node* malloced;
	int Select = 0;
	//메뉴선택
	int MemoryAmount = 0;
	//할당할 메모리 용량
	char name = 'A';
	//할당한 메모리 공간들을 구분하기 위한 이름
	int Sizetemp = 0;
	//메모리를 할당하는 과정에서 First-fit, Best-fit을 구분합니다.
};