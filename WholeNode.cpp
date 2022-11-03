#include "WholeNode.h"
#include <iostream>
using namespace std;


//Ŭ����

WholeNode::WholeNode(int MaxSize) {
	this->malloced = NULL;

	this->available = new Node;
	this->available->size = MaxSize;
	this->available->start = 0;
	this->available->pre = NULL;
	this->available->next = NULL;
}
WholeNode::WholeNode() {
	WholeNode(100);
}
//malloced�� ���� ����. available�� ù ��带 �����س��� ��
//�Ʒ����� ������� ���� ������
//������

WholeNode::~WholeNode() {}
//�Ҹ���. �Ƹ��� �����Ҵ� ������ ���⼭ �� �ؾ��ҵ�.
//�̱���

void WholeNode::MENU() {
	while (Select != 100) {
		MemoryAmount = -1;
		cout << "===\n�޴��� �����ϼ���\n1.�޸� �Ҵ�\n2.�޸� ����\n3.���� ���\n4.���α׷� ����\n ===\n> ";
		cin >> Select;
		if (Select < 1 || Select > 4) {
			cin.clear();//�Է¹��� �ʱ�ȭ
			cout << "�ٽ� �Է����ּ���";
		}
		//�޴� ����
		switch (Select) {
		case 1://�޸� �Ҵ�
			while (MemoryAmount <= 0) {
				cout << "�Ҵ��� �޸� �뷮 : ";
				cin >> MemoryAmount;
				if (MemoryAmount <= 0) {
					cout << "0�� ������ �Ҵ��� �Ұ����մϴ�." << endl;//�����ص��ǰ�
					MemoryAmount = -1;
				}
			}
			cin.clear();
			NewMemory();
			PrintNow();
			break;
		case 2://�޸� �Ҵ� ����

			break;
		case 3://��ü���� ȭ�� ���

			break;
		case 4:
			cout << "���α׷��� �����մϴ�";
			Select = 100;
			break;
		default:
			break;
		}
	}
}

void WholeNode::NewMemory() {
	Node* mcur = this->malloced;
	Node* acur = this->available;
	Node* preacur = acur;
	//���� ù ��带 ����Ŵ

	Node* re_a = acur;
	this->Sizetemp = 10000000;

	if (malloced != NULL) {
		while (mcur->next != NULL) {
			mcur = mcur->next;
		}
	}
	//malloced�� �ϴ� ���� ���� ��ġ �˾Ƴ�


	while (acur != NULL) {
		//aĿ�� �ϴ� ������ ���ƺ�
		if (re_a->size >= MemoryAmount) {
			if (re_a->start <= acur->start) {
				this->Sizetemp = 30;//��带 ã�Ҵٴ� ǥ��
				re_a = acur;
			}
			//First-fit
			//if (re_a->size - MemoryAmount <= Sizetemp) {
			//	this->Sizetemp = re_a->size - MemoryAmount;
			//	//���� ũ��� ���ϴ� �Ͱ� ���ÿ� ��带 ã�Ҵٰ� ǥ��
			//	re_a = acur;
			//}
			//Best-fit
		}
		preacur = acur;
		acur = acur->next;
	}
	if (malloced == NULL && preacur->size >= MemoryAmount) Sizetemp = 0;
	//�̷��� ������ available ��� ã��
	if (Sizetemp == 10000000) { cout << "�� �̻� ������ ������ �����ϴ�." << endl; return; }
	//��� ã�Ҵٴ� ǥ���� Sizetemp�� ������ 10000000�ΰ�� ������ ���� ���̹Ƿ� ����������.

	Node* newnode = new Node();
	newnode->name = (this->name)++;
	newnode->size = this->MemoryAmount;
	newnode->start = preacur->start;
	newnode->next = NULL;
	//��带 ã������ malloced�� �߰��� ��带 �����ϰ� ������ �Է�
	preacur->start += MemoryAmount;
	preacur->size -= MemoryAmount;
	//ã�� ����� ������ ����

	if (Sizetemp == 0) { newnode->pre = NULL; malloced = newnode; }
	else { newnode->pre = mcur; mcur->next = newnode; }
	//����
}

void WholeNode::PrintNow() {
	Node* mcur = this->malloced;
	Node* acur = this->available;

	cout << "���� �޸� ��Ȳ" << endl;
	while (acur != NULL) {
		cout << "  start : "; cout.setf(6); cout << acur->start;
		cout << ", size : "; cout.setf(5); cout << acur->size << endl;
		acur = acur->next;
	}
	cout << "�Ҵ��� �޸� ��Ȳ" << endl;
	while (mcur != NULL) {
		cout << static_cast<char>(mcur->name); cout << " "; cout << "start : "; cout.setf(6); cout << mcur->start;
		cout << ", size : "; cout.setf(5); cout << mcur->size << endl;
		mcur = mcur->next;
	}
}

//�߰��ϰ� ������ ����ϴ� �� �����Ϸ�
//malloced�� available�� ������ ��¦ �ٸ��� ����ؾ� �����Ҷ� ����ɰ�
//malloced�� NULL�� �� ������, available���� ������ ù ��尡 �־�� ��!!