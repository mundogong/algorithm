#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <tchar.h>

struct student
{
	int yearsold;
	char name[10];
	char tel[20];
	student * next;
}; 

student head = { 0 };

void addstudent(student * A) {
	printf("姓名:");
	scanf("%s", &(A->name));
	printf("年龄:");
	scanf("%d", &(A->yearsold));
	printf("电话:");
	scanf("%s", &(A->tel));
	A->next = 0;
	student * p = &head;
	while (1) {
		if (p->next == 0) {
			p->next = A;
			return;
		}
		p = p->next;
	}
}

void DelStudent(student * list) {
	fflush(stdin);
	printf("请输入学生姓名:");
	char input[100];
	student * last = list;
	student * now = 0;
	while (list->next != 0) {
		scanf("%s", input);
		now = list->next;
		if (strcmp(input, now->name) == 0) {
			last->next = now->next;
			return;
		}
		last = last->next;
	}
}

void traversal(student * list) {
	while (list->next != 0) {
		list = list->next;
		printf("---------------------------\n");
		printf("姓名:%s\n年龄:%d\n电话:%s\n", list->name, list->yearsold, list->tel);
		printf("---------------------------\n");
	}
}

void ExchangeStudent(student * a, student * b) {
	student temp;
	strcpy(temp.name, a->name);
	temp.yearsold = a->yearsold;
	strcpy(temp.tel, a->tel);

	strcpy(a->name, b->name);
	a->yearsold = b->yearsold;
	strcpy(a->tel, b->tel);

	strcpy(b->name, temp.name);
	b->yearsold = temp.yearsold;
	strcpy(b->tel, temp.tel);
}

void ByYearsort(student * now) {
	student * back;
	while (now->next != 0)
	{
		now = now->next;
		back = now->next;
		while (back != 0) {
			if (now->yearsold > back->yearsold) {
				ExchangeStudent(now, back);
			}
			back = back->next;
		}
	}
}

int main()
{
	system("color 1e");
	printf("学生信息管理系统\n");
	printf("-add		添加一个学生\n");
	printf("-del		删除一个学生\n");
	printf("-traversal	输出全部学生信息\n");
	printf("-sort		按年龄排序\n");
	printf("-exit		退出程序\n");

	char user_input[100];
	while (1) {
		scanf("%s", user_input);
		if (strcmp(user_input, "add") == 0) {
			student * sd = (student *)malloc(sizeof(student));
			addstudent(sd);
		}
		else if (strcmp(user_input, "traversal") == 0){
			traversal(&head);
		}
		else if (strcmp(user_input, "exit") == 0)
		{
			printf("now exit...\n");
			return 0;
		}
		else if (strcmp(user_input, "sort") == 0)
		{
			ByYearsort(&head);
		}
		else if (strcmp(user_input, "del") == 0)
		{
			DelStudent(&head);
		}
	}
}

