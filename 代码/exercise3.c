#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

void init(int mem[8][8]);
void display(int mem[8][8]);
void alloc(int mem[8][8]);
void recyle(int mem[8][8]);
int main()
{
	int operate, cylinder = 8, cylinderNum = 8, mem[8][8];
	
	init(mem);
	display(mem);
	printf("位示图初始化完成\n");
	printf("请根据提示选择需要进行的操作(1:分配空间 2:回收空间 3:显示位示图 0:退出程序）\n");
	scanf("%d", &operate);
	while (operate != 0)
	{
		if (operate == 1)
		{
			alloc(mem);
			display(mem);
		}
		else if (operate == 2)
		{
			recyle(mem);
			display(mem);
		}
		else
			display(mem);
		printf("请根据提示选择需要进行的操作(1:分配空间 2:回收空间 3:显示位示图 0:退出程序）\n");
		scanf("%d", &operate);
	}
	return 0;
}
void init(int mem[8][8])
{
	int i, j;
	for (i = 0;i < 8;i++)
	{
		for (j = 0;j < 8;j++)
			mem[i][j] = 0;
	}
}

void display(int mem[8][8])
{
	int i, j;
	for (i = 0;i < 8;i++)
	{
		for (j = 0;j < 8;j++)
			printf("%d  ", mem[i][j]);
		printf("\n");
	}
}
void alloc(int mem[8][8])
{
	int i, j, allocNum, canAllocNum = 0;
	printf("请输入需要分配的硬盘大小(以块为单位，大小不超过64块)\n");
	scanf("%d", &allocNum);
	for (i = 0;i < 8;i++)
	{
		for (j = 0;j < 8;j++)
		{
			if (mem[i][j] == 0)
				canAllocNum++;

		}
	}
	if (allocNum < canAllocNum)
	{
		printf("分配硬盘成功\n");
		printf("分配硬盘的物理地址为：\n");
		for (i = 0;i < 8;i++)
		{
			for (j = 0;j < 8;j++)
			{
				if (allocNum <= 0)
					break;
				if (mem[i][j] == 0)
				{
					mem[i][j] = 1;
					printf("第%d柱面   第%d磁道   第%d块物理记录\n", i, j / 4, j % 4);
					allocNum--;
				}
			}
		}

	}
	else
	{
		printf("分配失败，磁盘空间不足\n");
	}
}
void recyle(int mem[8][8])
{
	int cylinder, track, record, i, j;
	printf("\n请输入需要回收的物理地址\n");
	printf("柱面号(0~7):");
	scanf("%d", &cylinder);
	printf("磁道号(0~1):");
	scanf("%d", &track);
	printf("物理记录号(0~3):");
	scanf("%d", &record);
	i = cylinder;
	j = track * 4 + record;
	mem[i][j] = 0;
	printf("\n回收成功！\n");
	printf("回收的是第%d字节，第%d位\n", i, j);
}

