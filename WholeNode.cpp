#include "WholeNode.h"
#include <iostream>
using namespace std;


//클래스

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
//malloced는 아직 없음. available만 첫 노드를 연결해놓은 것
//아래쪽은 사용할일 없는 생성자
//생성자

WholeNode::~WholeNode() {}
//소멸자. 아마도 동적할당 해제를 여기서 다 해야할듯.
//미구현

void WholeNode::MENU() {
	while (Select != 100) {
		MemoryAmount = -1;
		cout << "===\n메뉴를 선택하세요\n1.메모리 할당\n2.메모리 해제\n3.상태 출력\n4.프로그램 종료\n ===\n> ";
		cin >> Select;
		if (Select < 1 || Select > 4) {
			cin.clear();//입력버퍼 초기화
			cout << "다시 입력해주세요";
		}
		//메뉴 선택
		switch (Select) {
		case 1://메모리 할당
			while (MemoryAmount <= 0) {
				cout << "할당할 메모리 용량 : ";
				cin >> MemoryAmount;
				if (MemoryAmount <= 0) {
					cout << "0과 음수는 할당이 불가능합니다." << endl;//예외해도되고
					MemoryAmount = -1;
				}
			}
			cin.clear();
			NewMemory();
			PrintNow();
			break;
		case 2://메모리 할당 해제

			break;
		case 3://전체적인 화면 출력

			break;
		case 4:
			cout << "프로그램을 종료합니다";
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
	//각각 첫 노드를 가리킴

	Node* re_a = acur;
	this->Sizetemp = 10000000;

	if (malloced != NULL) {
		while (mcur->next != NULL) {
			mcur = mcur->next;
		}
	}
	//malloced는 일단 제일 뒤의 위치 알아냄


	while (acur != NULL) {
		//a커서 일단 끝까지 돌아봄
		if (re_a->size >= MemoryAmount) {
			if (re_a->start <= acur->start) {
				this->Sizetemp = 30;//노드를 찾았다는 표시
				re_a = acur;
			}
			//First-fit
			//if (re_a->size - MemoryAmount <= Sizetemp) {
			//	this->Sizetemp = re_a->size - MemoryAmount;
			//	//다음 크기와 비교하는 것과 동시에 노드를 찾았다고 표시
			//	re_a = acur;
			//}
			//Best-fit
		}
		preacur = acur;
		acur = acur->next;
	}
	if (malloced == NULL && preacur->size >= MemoryAmount) Sizetemp = 0;
	//이렇게 변경할 available 노드 찾음
	if (Sizetemp == 10000000) { cout << "더 이상 저장할 공간이 없습니다." << endl; return; }
	//노드 찾았다는 표시인 Sizetemp가 여전히 10000000인경우 공간이 없는 것이므로 빠져나간다.

	Node* newnode = new Node();
	newnode->name = (this->name)++;
	newnode->size = this->MemoryAmount;
	newnode->start = preacur->start;
	newnode->next = NULL;
	//노드를 찾았으면 malloced에 추가할 노드를 생성하고 데이터 입력
	preacur->start += MemoryAmount;
	preacur->size -= MemoryAmount;
	//찾은 노드의 내용을 변경

	if (Sizetemp == 0) { newnode->pre = NULL; malloced = newnode; }
	else { newnode->pre = mcur; mcur->next = newnode; }
	//연결
}

void WholeNode::PrintNow() {
	Node* mcur = this->malloced;
	Node* acur = this->available;

	cout << "남은 메모리 현황" << endl;
	while (acur != NULL) {
		cout << "  start : "; cout.setf(6); cout << acur->start;
		cout << ", size : "; cout.setf(5); cout << acur->size << endl;
		acur = acur->next;
	}
	cout << "할당한 메모리 현황" << endl;
	while (mcur != NULL) {
		cout << static_cast<char>(mcur->name); cout << " "; cout << "start : "; cout.setf(6); cout << mcur->start;
		cout << ", size : "; cout.setf(5); cout << mcur->size << endl;
		mcur = mcur->next;
	}
}

//추가하고 간단히 출력하는 것 구현완료
//malloced와 available의 구조가 살짝 다른거 기억해야 삭제할때 도움될것
//malloced는 NULL일 수 있지만, available에는 무조건 첫 노드가 있어야 함!!