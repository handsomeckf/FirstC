//文件名:exp2-1.cpp
#include <stdio.h>
#include <malloc.h>
#include "stdafx.h"
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;
#define MAXNUM  100
#define OK 0
#define ERROR -1
int flag = 0;//全局变量用于链表查找函数的状态判断
int i = 1;//用于链表查找函数计数
typedef struct {
	string name;

}ElemType;
typedef struct {
	ElemType  stu[MAXNUM];
	int length;
}SqList;
typedef struct Lnode {
	ElemType stu;
	Lnode* next;
}Lnode;
typedef struct {
	Lnode  *firststu;
	int length;
}LinkList;
void text2(SqList* class3stu);
void text3(SqList* class3stu);
void text4(SqList* class3stu);
int  InitSqList(SqList* list)//顺序表初始化
{
	int i;
	list->length = 0;
	for (i = 0; i < MAXNUM; i++)
		list->stu[i].name ="";
	return OK;
}
Lnode* Linklist_Find(Lnode*phead,ElemType x) //链表寻找，用于插入函数，找到要插入的节点
{
	int i = 1;
	if (phead == NULL) {
		return NULL;
	}
	else {
		Lnode* cur = new Lnode;
		cur = phead;
		while (cur) {
			if (cur->stu.name == x.name) {
				return cur;
			}
			else {
				cur = cur->next;
				i++;
			}
		}
			return NULL;
	}
}
Lnode* Linklist_Find2(Lnode* phead, ElemType x) //链表寻找，仅为查找作用为之前寻找函数的修改
{
	if (phead == NULL) {
		return NULL;
	}
	else {
		Lnode* cur = new Lnode;
		cur = phead;
		while (cur) {
			if (cur->stu.name == x.name&&cur->next!=NULL) {
				printf("%d个是\n", i); flag = 1;
				return cur;
			}
			else {
				cur = cur->next;
				i++;
			}
		}
		if (flag == 0) {
			printf("没有找打你所需要的\n");
			return NULL;
			i = 1;
		}
		return NULL;
	}
}
void Delect_Linklist(Lnode** phead) //链表删除
{
	ElemType x;
	printf("请输入想要删除同学的名字");
	cin >> x.name;
	if (*phead == NULL) { return; }
	else if ((*phead)->next == NULL&&(*phead)->stu.name==x.name) {
		free(*phead);
		*phead = NULL;
	}
	else {
		Lnode* cur = *phead;
		Lnode* pre=NULL;
		while (cur->stu.name != x.name&&cur->next!=NULL) {
			pre = cur;
			cur = cur->next;
		}
		if (cur) {
			pre->next = cur->next;
			free(cur);
			return;
		}
		else if (cur == NULL && pre) {
			pre = NULL;
			free(cur);
			return;
		}
		else if (cur == NULL && cur->stu.name != x.name) {
			printf("没有找到呀");
			return;
		}
	}
}
void Linklist_Insert(Lnode** phead, ElemType x) //链表插入
{
	if (*phead == NULL) { return; }
	Lnode* temp8 = *phead;
	ElemType temp9;
	printf("请输入想要插入的位置（学生姓名，插入在此学生之前）");
	cin >> temp9.name;
	temp8 = Linklist_Find(*phead, temp9);
	if (temp8) {
		Lnode* newnode = new Lnode;
		newnode->next = NULL;
		newnode->stu = x;
		Lnode* cur=*phead;
		while (cur->next != temp8) {
			cur = cur->next;
		}
		cur->next = newnode;
		newnode->next = temp8;
	}
}
void Print2(Lnode* phead) //链表打印
{
	Lnode* cur = phead;
	int i = 1;
	while (cur != NULL) {
		printf("%d号是%s\n", i++, cur->stu.name.c_str());
		cur = cur->next;
	}
}
void Input2(Lnode** phead) //链表输入
{
	ifstream s("name.text");
	Lnode* temp= new Lnode;
	int i = 0;
	while (s>>temp->stu.name) {
		Lnode* newnode = new Lnode;
		newnode->next = NULL;
		if (*phead == NULL) {
			newnode->stu.name= temp->stu.name;
			*phead = newnode;
		}
		else {
			Lnode* tail = *phead;
			while (tail->next != NULL) {
				tail = tail->next;
			}
			newnode->stu.name = temp->stu.name;
			tail->next = newnode;
		}
		
	}
}
void _text1(Lnode**phead) //插入函数
{
	ElemType temp10;
			printf("请输入想要插入的学生名字\n");
			cin >> temp10.name;
			Linklist_Insert(phead, temp10);

}
void _text2(Lnode**phead)//查询函数
{
	ElemType temp7;
	printf("请输入想要查询的学生名字\n");
	cin >> temp7.name;
	Lnode* tempNode;//找到所查询学生名字的第一个位置
	tempNode = Linklist_Find2(*phead, temp7);
	while (tempNode) //运用循环寻找之后是否还有此名字
	{
		tempNode = Linklist_Find2(tempNode->next, temp7);
	}
}
void _text3(Lnode** phead) //插入函数
{
	Delect_Linklist(phead);
	return;
}
void Print(SqList* class3stu) //顺序表打印
{
	for (int i = 0; i < class3stu->length - 1; i++) {
		printf("%d号是%s\n", i + 1, class3stu->stu[i].name.c_str());
	}
}
int InsertSqList(SqList* list, int pos, ElemType ele)//顺序表插入
{
	int  i, j;
	if (pos == 0 && (list->length == 0))
	{
		list->stu[pos] = ele;
		list->length++;
		return OK;
	}
	if (pos<0 || pos>list->length || (list->length == MAXNUM))
		return ERROR;
	if (pos == list->length) {
		list->stu[pos] = ele;
		list->length++;
	}
	else {
		for (i = list->length - 1; i >= pos; i--)
		{
			list->stu[i + 1] = list->stu[i];

		}
		list->stu[pos] = ele; list->length++;
	}
	return OK;
}
void Input(SqList* list) //顺序表从文件中读取
{
	ifstream s("name.text");
	int i = 0;
	while (s >> list->stu[i++].name) {
	};
	list->length = i;
}
void text1(SqList* class3stu) //顺序表文件中读取并打印
{
	InitSqList(class3stu);
	Input(class3stu);
	Print(class3stu);
}
void text2(SqList* class3stu) //顺序表插入函数
{
	int pos = 0;
	printf("请输入想要插入的位置");
	std::cin >> pos;
	ElemType temp3;
	printf("请输入想要插入的人名");
	std::cin >> temp3.name;
	InsertSqList(class3stu, pos - 1, temp3);
	printf("插入成功\n");
}
void text3(SqList* class3stu) //顺序表查找函数
{
	int i = 0; string temp4;
	printf("请输入想要查找同学的拼音");
	std::cin >> temp4;
	for (; i <= class3stu->length - 1; i++) {
		if (temp4 == class3stu->stu[i].name) {
			printf("第%d个是这位学生\n", i + 1);
			return;
		}
	}
	printf("没有找到这位同学(T T)\n");
}
void text4(SqList* class3stu) //顺序表删除函数
{
	int pos = 0;
	printf("请输入想要删除同学的序号");
	std::cin >> pos;
	for (int i = pos - 1; i < class3stu->length; i++) {
		class3stu->stu[i] = class3stu->stu[i + 1];
	}
	class3stu->length--;
	printf("删除成功\n");
}

void manu()//顺序表界面
{
	SqList* class3stu;
	class3stu = new SqList;
	char temp;
	temp = '0';
	while (1)
	{
		if (temp == '0' || temp == '1' || temp == '2' || temp == '3' || temp == '4'||temp=='5')
		{
		printf("---------Menu is as following--------\n");
		printf(" press 1 return to input name from name.txt\n");
		printf(" press 2 return to insert name\n");
		printf(" press 3 return to lookup name \n");
		printf(" press 4 return to print all name \n");
		printf(" press 5 return to delete name\n");
		printf("press q to quit\n");
		}

		temp = getchar();//从键盘上输入一个数字后回车，getchar会返回两次，一次是数字，一次是'\n',所以要做上面的处理。
	
		switch (temp)
		{
		case '1':	text1(class3stu); printf("以上为打印名单\n"); 
			// add your code 
			break;
		case '2':text2(class3stu);
			break;
		case '3':text3(class3stu);
			// add your code 
			break;
		case '4':Print(class3stu);
			// add your code
			break;
		case '5':text4(class3stu); 
			break;
		case 'q':
			return;
		default:
			break;
		}

	}

	return;
}
void manu2() //链表界面
{
	LinkList* phead = new LinkList;
	phead->firststu = NULL;
	char temp;
	temp = '0';
	while (1)
	{
		if (temp == '0' || temp == '1' || temp == '2' || temp == '3' || temp == '4'||temp=='5')
		{
		printf("---------Menu is as following--------\n");
		printf(" press 1 return to input name from name.txt\n");
		printf(" press 2 return to insert name\n");
		printf(" press 3 return to lookup name \n");
		printf(" press 4 return to print all name \n");
		printf(" press 5 return to delete name\n");
		printf("press q to quit\n");
		}

		temp = getchar();//从键盘上输入一个数字后回车，getchar会返回两次，一次是数字，一次是'\n',所以要做上面的处理。
	
		switch (temp)
		{
		case '1':	Input2(&(phead)->firststu); Print2(phead->firststu); printf("以上为打印名单\n");
			// add your code 
			break;
		case '2':
			_text1(&phead->firststu);
			break;
		case '3':i = 1; _text2(&phead->firststu);
			// add your code 
			break;
		case '4':Print2(phead->firststu);
			// add your code
			break;
		case '5':Delect_Linklist(&phead->firststu);
			break;
		case 'q':
			return;
		default:
			break;
		}

	}
	return;
}
void manu3() //主界面函数
{
	char temp;
	temp = '0';
	while (1)
	{
		if (temp == '0' || temp == '1' || temp == '2')
		{
			printf("---------Menu is as following--------\n");
			printf(" press 1 to use mode Linklist\n");
			printf(" press 2 to use mode Sqlist\n");
			printf("press q to quit\n");
		}

		temp = getchar();//从键盘上输入一个数字后回车，getchar会返回两次，一次是数字，一次是'\n',所以要做上面的处理。

		switch (temp)
		{
		case '1':	manu2();
			break;
		case '2':
			manu();
			break;
		case'q':
			return;
		default:
			break;
		}
	}
}
void main() {
	manu3();
}