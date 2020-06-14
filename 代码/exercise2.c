#include<stdio.h>
#include<malloc.h>

typedef struct Memory
{
	int freename;
	int unfreename;
	int begin;
	int length;
	struct Memory* free;
	struct Memory* unfree;
};
void init(struct Memory* mem);
void alloc(struct Memory* mem);
void release(struct Memory* mem);
int searchAlloc(struct Memory* mem, int size);
int allocChangeFree(struct Memory* mem, int size);
void allocChangeUnfree(struct Memory* mem, int begin, int size);
void release(struct Memory* mem);
int searchRelease(struct Memory* mem, int name);
int(* releaseChangeUnfree(struct Memory* mem, int name))[2];
void releaseChangeFree(struct Memory* mem, int* beginAndSize);
int main() 
{
	struct Memory* Mem,*free,*m;
	int n;
	Mem = (struct Memory*)malloc(sizeof(struct Memory));
	init(Mem);
	free = (struct Memory*)malloc(sizeof(struct Memory));
	init(free);
	Mem->free = free;
	printf("请输入数字0,1,2执行存储器操作（0：退出程序 1：分配空间 2：回收空间\n");
	scanf("%d", &n);
	while (n != 0)
	{
		if (n == 1)
			alloc(Mem);
		else if (n == 2)
			release(Mem);
		else
			printf("请输入正确的数字\n");
		m = Mem->free;
		printf("空闲区号			起始位置			空闲区大小\n");
		while (m != NULL) 
		{
			printf("%d				%d				%d\n",m->freename,m->begin,m->length);
			m = m->free;
		}
		m = Mem->unfree;
		printf("非空闲区号			起始位置			非空闲区大小\n");
		while (m != NULL)
		{
			printf("%d 				%d				%d\n", m->unfreename, m->begin, m->length);
			m = m->unfree;
		}
		printf("请输入数字0,1,2执行存储器操作（0：退出程序 1：分配空间 2：回收空间）\n");
		scanf("%d", &n);
	}
	return 0;
}
void init(struct Memory* mem) {
	mem->freename = 1;
	mem->unfreename = 1;
	mem->begin = 0;
	mem->length = 128;
	mem->free = NULL;
	mem->unfree = NULL;
}
void alloc(struct Memory* mem) {
	struct Memory* p=mem->free,*prior=mem,*new;
	int size;
	int begin;
	new = (struct Memory*)malloc(sizeof(struct Memory));
	printf("请输入分配空间大小(K)\n");
	scanf("%d", &size);
	if (searchAlloc(mem, size))
	{
		begin = allocChangeFree(mem, size);
		allocChangeUnfree(mem, begin, size);
	}
	else
		printf("空间不足无法分配内存\n");
}
int searchAlloc(struct Memory* mem,int size) {
	struct Memory* p;
	p = mem->free;
	if (p != NULL)
	{
		while (p != NULL)
		{
			if (p->length >= size)
				return 1;
			else
				p = p->free;
		}
		if (p == NULL)
			return 0;
	}
	else
		return 0;
}
int allocChangeFree(struct Memory* mem, int size) {
	struct Memory* p,*prior=mem;
	int begin=0;
	p = mem->free;
	if (p != NULL)
	{
		while (p != NULL)
		{
			if (p->length >= size)
			{
				begin = p->begin;
				p->length -= size;
				p->begin += size;
				break;
			}
			else
			{
				p = p->free;
				prior = prior->free;
			}
		}
	}
	if (p->length == 0)
	{
		if (p->free != NULL)
		{
			prior->free = p->free;
			free(p);
			struct Memory* m = prior->free;
			while (m != NULL)
			{
				m->freename -= 1;
				m = m->free;
			}

		}
		else
			prior->free = NULL;
	}
	return begin;
}
void allocChangeUnfree(struct Memory* mem, int begin, int size)
{
	struct Memory* p = mem->unfree, * prior = mem, * new;
	new = (struct Memory*)malloc(sizeof(struct Memory));
	new->begin = begin;
	new->length = size;
	new->free = NULL;
	if (p == NULL)
	{
		new->unfreename = 1;
		new->unfree = NULL;
		prior->unfree = new;
	}
	else 
	{
		while (p != NULL)
		{
			if (p->begin > new->begin)
			{
				prior->unfree = new;
				new->unfreename = prior->unfreename + 1;
				new->unfree = p;
				p->unfreename += 1;
				if (p->unfree != NULL)
				{
					p = p->unfree;
					while (p!=NULL)
					{
						p->unfreename += 1;
						p = p->unfree;
					}
				}
				break;
			}
			else
			{
				p = p->unfree;
				prior = prior->unfree;
			}
		}
		if (p == NULL)
		{
			new->unfreename = prior->unfreename+1;
			new->unfree = NULL;
			prior->unfree = new;
		}
	}
}
void release(struct Memory*mem)
{
	struct Memory* p = mem->free, * prior = mem, * new;
	int name;
	int (*beginAndSize)[2];
	new = (struct Memory*)malloc(sizeof(struct Memory));
	printf("请输入回收作业序号\n");
	scanf("%d", &name);
	if (searchRelease(mem, name))
	{
		beginAndSize=releaseChangeUnfree(mem, name);
		releaseChangeFree(mem, beginAndSize);
	}
	else
		printf("输入错误，无该非空闲分区\n");
}
int searchRelease(struct Memory* mem, int name)
{
	struct Memory* p=mem->unfree;
	if (p != NULL)
	{
		while (p != NULL)
		{
			if (p->unfreename ==name)
				return 1;
			else
				p = p->unfree;
		}
		if (p == NULL)
			return 0;
	}
	else
		return 0;
}
int(* releaseChangeUnfree(struct Memory* mem, int name))[2]
{
	struct Memory* p = mem->unfree, * prior = mem;
	int(*beginAndSize)[2];
	beginAndSize = calloc(10, sizeof(int));
	if (p != NULL)
	{
		while (p != NULL)
		{
			if (p->unfreename == name)
			{
				(*beginAndSize)[0] = p->begin;
				(*beginAndSize)[1] = p->length;
				if (p->unfree == NULL)
					prior->unfree = NULL;
				else
				{
					prior->unfree = p->unfree;
					p = p->unfree;
					while (p != NULL)
					{
						p->unfreename -= 1;
						p = p->unfree;
					}
				}
				break;
			}
			else
			{
				p = p->unfree;
				prior = prior->unfree;
			}
		}
	}
	return beginAndSize;
}
void releaseChangeFree(struct Memory* mem, int(* beginAndSize)[2])
{
	struct Memory* p = mem->free, * prior = mem,*new;
	new = (struct Memory*)malloc(sizeof(struct Memory));
	new->begin = beginAndSize[0][0];
	new->length = beginAndSize[0][1];
	new->unfree = NULL;
	if (p == NULL)
	{
		new->free = NULL;
		new->freename = prior->freename;
		prior->free = new;
	}
	else
	{
		while (p != NULL)
		{
			if (p->begin > new->begin)
				break;
			else
			{
				p = p->free;
				prior = prior->free;
			}
		}
		if (p == NULL)
		{
			if ((prior->begin + prior->length) == new->begin)
			{
				prior->length += new->length;
			}
			else
			{
				new->free = NULL;
				new->freename = prior->freename + 1;
				prior->free = new;
			}
		}
		else
		{
			if (prior == mem)
			{
				if ((new->begin + new->length) == p->begin)
				{
					p->begin = new->begin;
					p->length += new->length;
				}
				else
				{
					new->freename = prior->freename;
					new->free = p;
					prior->free = new;
					while (p != NULL)
					{
						p->freename += 1;
						p = p->free;
					}
				}
			}
			else
			{
				if (((new->begin + new->length) == p->begin) && ((prior->begin + prior->length) == new->begin))
				{
					prior->length += new->length + p->length;
					p = p->free;
					prior->free = p;
					while (p != NULL)
					{
						p->freename -= 1;
						p = p->free;
					}
				}
				else if ((prior->begin + prior->length) == new->begin)
					prior->length += new->length;
				else if ((new->begin + new->length) == p->begin)
				{
					p->begin = new->begin;
					p->length += new->length;
				}
				else
				{
					new->freename = prior->freename + 1;
					new->free = p;
					prior->free = new;
					while (p != NULL)
					{
						p->freename += 1;
						p = p->free;
					}
				}
			}
		}
	}
}