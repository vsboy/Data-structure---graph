struct RowColWeight//边信息三元组
{
	int row;
	int col;
	int weight;
};
struct MinWeight
{
	int dist;//最小权值边的下标
	WType w;//最小权值
};
void AdjListCreateGraph(AdjList &G,DataType V[],int n,RowColWeight E[],int e)//用一个存储边权信息的三元组来生成图
{
	int i;
	for( i=0;i<n;i++)
		G.InsertVertice(V[i]);//填充顶点信息
	//cout<<E[2].col;
	for(i=0;i<e;i++)
		G.InsertEdge(E[i].row,E[i].col,E[i].weight);
		
}
int FindRepeatV(int v ,int a[],int n)//判断元素v是否在a[]中存在
{
	int i;
	for(i=0;i<n;i++)
		if(v==a[i])
			return 1;
		return 0;
}
int GetMinWeight(AdjList &G,int v,MinWeight &m,int a[],int n)
//得到下标v的结点的邻接边中权值最小且不是生成树已有结点的哪个结点，即构不成回路的边
{
	Edge* p,*q;
	int flag=0;
	p=G.GetAdj(v);
	if (p==NULL)
	{
		cout<<"结点"<<v<<"无邻接边"<<endl;
		return 0;
	}
	else
	{	
		WType min;
		while(p!=NULL && flag==0)//找到第一个在邻接边集合中没有出现在生成树已有结点的哪个结点
		{
			if(FindRepeatV(p->dist,a,n)==0)
			{
				min=p->weight;
				q=p;
				flag=1;
			}
			p=p->next;
		}		
		while(p!=NULL)//比较后面结点权值与min的大小
		{
			if(p->weight<min && FindRepeatV(p->dist,a,n)==0)
			{	
				min=p->weight ;
				q=p;		
			}
			p=p->next;
		}
		if(flag==1)
		{
			m.dist =q->dist ;
			m.w =q->weight ;
			return 1;
		}
	}
return 0;
}
void  Search(int v ,WType w,RowColWeight E[],int e,int a[])//查找以v为一端的权值为w的边的所有另一端集合存放于a数组，无则返回0；
{
	int i,count=0;
	for(i=0;i<e;i++)
	{
		if(E[i].col==v&&E[i].weight==w)
		{
			a[count]=E[i].row;
			count++;
		}
		if(E[i].row==v&&E[i].weight==w)
		{
			a[count]=E[i].col;
			count++;
		}
	}
}


		
	


			





