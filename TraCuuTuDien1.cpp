#include<iostream>
#include<fstream>
#include<string>
#include<unistd.h>

using namespace std;

typedef struct Tuvung {
	string english;
	string tieng_viet;
}TuVung;

typedef struct Node {
	TuVung info;
	struct Node* next;
}NODE;
typedef NODE* NODEPTR;

void Init(NODEPTR &pHead);
void Input(TuVung &x, ifstream &t_a, ifstream &t_v);
void Output(TuVung x);
NODEPTR CreateNode(TuVung x);
void Insert_First(NODEPTR &pHead, TuVung x);
void Show_List(NODEPTR pHead);


int main(){
	ifstream t_a, t_v;
	NODEPTR a;
	TuVung x;
	Init(a);
	t_a.open("tieng_anh.txt");
	t_v.open("tieng_viet.txt");
	if (t_a.is_open() && t_v.is_open()){
		cout << "Mo thanh cong !!!" << endl;
		sleep(1);
		system("cls");
		Input(x,t_a,t_v);
		Output(x);
		Show_List(a);
	} else {
		cout << "Mo that bai" << endl;
	}
	return 0;
}

void Init(NODEPTR &pHead){
	pHead = NULL;
}

void Input(TuVung &x, ifstream &t_a, ifstream &t_v){
	t_a >> x.english;
	getline(t_v,x.tieng_viet);
}

void Output(TuVung x){
	cout << x.english << ": " << x.tieng_viet << endl;
}

NODEPTR CreateNode(TuVung x){
	NODEPTR newNode = new NODE;
	newNode->info = x;
	newNode->next = NULL;
	return newNode;
}

void Insert_First(NODEPTR &pHead, TuVung x){
	NODEPTR newNode = CreateNode(x);
	newNode->next = pHead;
	pHead = newNode;
}

void Show_List(NODEPTR pHead){
	NODEPTR current;
	while (current != NULL){
		Output(current->info);
		current = current->next; 
	}
}
