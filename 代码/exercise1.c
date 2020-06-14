#include<stdio.h> 
#include<malloc.h>
//#define _CRT_SECURE_NO_WARNINGS
void add(struct PCB* new, struct PCB* pro);
void run(struct PCB* sch);
struct PCB {
	char name[10];             //进程名 
	int time;			      //要求运行时间 
	int prinum;				 //优先数 
	int statu;              //当前状态
	struct PCB* next;  	   //就绪队列 
};
int main() {
	struct PCB* pro, * new, * prior, * p, * m;
	int i = 0;
	pro = (struct PCB*)malloc(sizeof(struct PCB));
	while (i < 5)
	{
		new = (struct PCB*)malloc(sizeof(struct PCB));
		p = pro->next;
		printf("请为第%d个进程输入进程名，进程优先数和要求运行时间\n", i + 1);
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
	printf("五个进程创建完成\n");
	run(pro);
	return 0;
}
void run(struct PCB *sch)
{
	struct PCB* now,*print;
	now = (struct PCB*)malloc(sizeof(struct PCB));
	while (sch->next !=NULL)
	{
		printf("进程%s正在运行\n",sch->next->name);
		now->next = sch->next;
		sch->next = sch->next->next;
		print = sch->next;
		if (print != NULL)
		{
			printf("进程");
			while (print != NULL)
			{
				printf("%s ", print->name);
				print = print->next;
			}
			printf("处于就绪状态\n");
		}
		else
			printf("无进程处于就绪状态\n");
		if ((now->next->time) - 1 != 0)
		{
			now->next->time -= 1;
			now->next->prinum -= 1;
			add(now->next, sch);
		}
		printf("进程%s运行结束\n",now->next->name);

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

