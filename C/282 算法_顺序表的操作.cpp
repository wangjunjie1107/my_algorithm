//初始化顺序表
void SeqListInit(SeqListType *SL)
{
	SL->ListLen = 0;//初始化时，设置顺序表长度为0 
}

//返回顺序表的元素数量 
int SeqListLength(SeqListType *SL)
{
	return (SL->ListLen); 
} 

//向顺序表中添加元素
int SeqListAdd(SeqListType *SL, DATA data)
{
	if(SL->ListLen >= MAXSIZE)//顺序表已满
	{
		printf("顺序表已满，不能再添加结点了\n");
		return 0; 
	} 
	SL->ListData[++SL->ListLen] = data;
	return 1;
}

//向顺序表中插入元素
int SeqListInsert(SeqListType *SL, int n, DATA data)
{
	int i;
	
	//顺序表结点数量已超过最大数量 
	if(SL->ListLen >= MAXSIZE)
	{
		printf("顺序表已满，不能插入结点\n");
		return 0;	//返回0表示结点插入不成功	
	}
	
	//插入结点序号不正确 
	if(n < 1 || n > SL->ListLen - 1)
	{
		printf("插入元素序号错误，不能插入元素！\n");
		return 0;  //返回0，表示插入不成功 
	} 
	
	//将顺序表的数据向后移动 
	for(i = SL->ListLen; i >= n; i--)
	{
		SL->ListData[i + 1] = SL->ListData[i];  
	} 
	
	SL->ListData[n] = data;	//插入结点
	SL->ListLen++;			//顺序表数量加1
	return 1;    			//返回1，表示成功插入 
}

//删除顺序表中的元素
int SeqListDelete(SeqListType *SL, int n)
{
	int i;
	
	//删除元素序号不正确 
	if(n < 1 || n > SL->ListLen)
	{
		printf("删除结点序号错误，不能删除结点！\n");
		return 0;  //返回0，表示删除不成功	
	}
	
	//将顺序表中的元素往前移动 
	for(i = n; i < SL->ListLen; i++)
	{
		SL->ListData[i] = SL->ListData[i + 1];
	}
	
	SL->ListLen--;	//顺序表元素减1 
	
	return 1; // 返回成功删除 
 } 

//根据序号返回元素
DATA *SeqListFindByNum(SeqListType *SL, int n)
{
	//元素序号不正确 
	if(n < 1 || n > SL->ListLen + 1)
	{
		printf("结点序号错误，不能返回结点！\n");
		return NULL;  //返回NULL，表示查找不成功	
	}
	
	return &(SL->ListData[n]); //通过指针返回，比较有通用性 
} 

//按关键字查找结点 

int SeqListFindByCont(SeqListType *SL, char *key)
{
	int i;
	
	for(i = 1; i <= SL->ListLen; i++)
	{
		//如果找到所需结点 
		if(strcmp(SL->ListData[i].key, key) == 0)
		{
			return i; //返回结点序号 
		}
	} 
	
	return 0; //遍历后仍没有找到，则返回0 		
} 






