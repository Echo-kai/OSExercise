#include<stdio.h> 
#include<malloc.h>
//#define _CRT_SECURE_NO_WARNINGS
void add(struct PCB* new, struct PCB* pro);
void run(struct PCB* sch);
struct PCB {
	char name[10];             //������ 
	int time;			      //Ҫ������ʱ�� 
	int prinum;				 //������ 
	int statu;              //��ǰ״̬
	struct PCB* next;  	   //�������� 
};
int main() {
	struct PCB* pro, * new, * prior, * p, * m;
	int i = 0;
	pro = (struct PCB*)malloc(sizeof(struct PCB));
	while (i < 5)
	{
		new = (struct PCB*)malloc(sizeof(struct PCB));
		p = pro->next;
		printf("��Ϊ��%d�����������������������������Ҫ������ʱ��\n", i + 1);
		scanf("%s\t%d\t%d", new->name, &new->prinum, &new->time);
		new->statu = 0;
		new->next = NULL;
		if (i == 0)
		{ 
			pro->next = new;
		}
		else
		{
			add(new, pro);
		}
		i++;
	}
	m = pro->next;
	printf("������̴������\n");
	run(pro);
	return 0;
}
void run(struct PCB *sch)
{
	struct PCB* now,*print;
	now = (struct PCB*)malloc(sizeof(struct PCB));
	while (sch->next !=NULL)
	{
		printf("����%s��������\n",sch->next->name);
		now->next = sch->next;
		sch->next = sch->next->next;
		print = sch->next;
		if (print != NULL)
		{
			printf("����");
			while (print != NULL)
			{
				printf("%s ", print->name);
				print = print->next;
			}
			printf("���ھ���״̬\n");
		}
		else
			printf("�޽��̴��ھ���״̬\n");
		if ((now->next->time) - 1 != 0)
		{
			now->next->time -= 1;
			now->next->prinum -= 1;
			add(now->next, sch);
		}
		printf("����%s���н���\n",now->next->name);

	}
}
void add(struct PCB* new, struct PCB* pro)
{
	struct PCB* p = pro->next,*prior,*m;
	if (p != NULL&&new!=NULL)
	{
		if (p->prinum > new->prinum)
		{
			while ((p->prinum > new->prinum)&&p!=NULL)
			{
				prior = p;
				p = p->next;
				if (p == NULL || p->prinum <= new->prinum)
				{
					prior->next = new;
					new->next = p;
					break;
				}

			}
		}
		else
		{
			m = pro->next;
			pro->next = new;
			new->next = m;
		}
	}
	else
		return ;
}

