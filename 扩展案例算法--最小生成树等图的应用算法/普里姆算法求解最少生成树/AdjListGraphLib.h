struct RowColWeight//����Ϣ��Ԫ��
{
	int row;
	int col;
	int weight;
};
struct MinWeight
{
	int dist;//��СȨֵ�ߵ��±�
	WType w;//��СȨֵ
};
void AdjListCreateGraph(AdjList &G,DataType V[],int n,RowColWeight E[],int e)//��һ���洢��Ȩ��Ϣ����Ԫ��������ͼ
{
	int i;
	for( i=0;i<n;i++)
		G.InsertVertice(V[i]);//��䶥����Ϣ
	//cout<<E[2].col;
	for(i=0;i<e;i++)
		G.InsertEdge(E[i].row,E[i].col,E[i].weight);
		
}
int FindRepeatV(int v ,int a[],int n)//�ж�Ԫ��v�Ƿ���a[]�д���
{
	int i;
	for(i=0;i<n;i++)
		if(v==a[i])
			return 1;
		return 0;
}
int GetMinWeight(AdjList &G,int v,MinWeight &m,int a[],int n)
//�õ��±�v�Ľ����ڽӱ���Ȩֵ��С�Ҳ������������н����ĸ���㣬�������ɻ�·�ı�
{
	Edge* p,*q;
	int flag=0;
	p=G.GetAdj(v);
	if (p==NULL)
	{
		cout<<"���"<<v<<"���ڽӱ�"<<endl;
		return 0;
	}
	else
	{	
		WType min;
		while(p!=NULL && flag==0)//�ҵ���һ�����ڽӱ߼�����û�г��������������н����ĸ����
		{
			if(FindRepeatV(p->dist,a,n)==0)
			{
				min=p->weight;
				q=p;
				flag=1;
			}
			p=p->next;
		}		
		while(p!=NULL)//�ȽϺ�����Ȩֵ��min�Ĵ�С
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
void  Search(int v ,WType w,RowColWeight E[],int e,int a[])//������vΪһ�˵�ȨֵΪw�ıߵ�������һ�˼��ϴ����a���飬���򷵻�0��
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


		
	


			





