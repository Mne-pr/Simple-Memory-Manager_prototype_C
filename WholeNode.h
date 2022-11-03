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
	//�޴�����
	int MemoryAmount = 0;
	//�Ҵ��� �޸� �뷮
	char name = 'A';
	//�Ҵ��� �޸� �������� �����ϱ� ���� �̸�
	int Sizetemp = 0;
	//�޸𸮸� �Ҵ��ϴ� �������� First-fit, Best-fit�� �����մϴ�.
};