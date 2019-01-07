//�ýṹ�嶨���ڽӱ��бߵ���Ϣ
struct Edge
{
	int dist;//�±�
	WType weight;//Ȩֵ
	Edge *next;//ָ����һ����ӱߵ�ָ��
	Edge(){};
	Edge(int n,WType w)//���캯��
	{
		dist=n;
		weight=w;
		next=NULL;
	}
};
//��������Ϣ
struct VerticeType
{
	VerType data;//�������
	Edge*firstAdj;//��һ���ڽӱ�
};
class AdjList
{
private:	
	VerticeType Vertice[MaxNode];//MaxNodeΪ������������
	int numOfVertice;//�����Ŀ
	int numOfEdge;//����
	int typeFlag;//��������ͼ��������ͼ������0Ϊ����ͼ��1 Ϊ����ͼ
public:
	AdjList(int flag=0);//���캯��
	~AdjList(void);//��������
	int AdjListEmpty()//�ڽӱ��п�
	{
		return (numOfVertice==0);
	}
	int AdjListFull()//�ڽӱ�����
	{
		return(numOfVertice==MaxNode);
	}
	int NumOfVer()
	{
		return numOfVertice;
	}
	int NumOfEdge()
	{
		return numOfEdge;
	}
	VerType GetItem(const int i);//��ȡ���Ϊi�Ľ������
	WType GetWeight(int v1,int v2);//��ȡ��<v1,v2>��Ȩ
	void InsertVertice(VerType item);//����һ�����
	void InsertEdge(int v1,int v2,WType w);//�����<v1,v2>ȨֵΪw
	void DeleteVertice(int v);//ɾ���±�Ϊv�Ľ��
	void DeleteEdge(int v1,int v2);//ɾ����<v1,v2>
	int GetFirstNeighbor(const int v);//���ؽ��v��һ�����ڱߵ��±꣬�����ڱ߷���-1
	int GetNextNeighbor(const int v1,const int v2);//���ؽ��v1����<v1,v2>��һ���ڽӱߵĽ���±꣬���򷵻�-1
	void DepthFirstSearch(const int v,int visited[],void visit(VerType item));//�ӽ��v��ʼ������ȱ�����ͨͼ
	void BroadFirstSearch(const int v,int visited[],void visit(VerType item));//�ӽ��v��ʼ������ȱ�����ͨͼ
	void DepthFirstSearch(void visit(VerType item));//�ӽ��v��ʼ������ȱ�������ͨͼ
	void BroadFirstSearch(void visit(VerType item));//�ӽ��v��ʼ������ȱ�������ͨͼ
	Edge*GetAdj(int v);//���ָ�����v�Ľ��ĵ�һ�ڽӱߵ�ָ��
	
};
AdjList::AdjList(int flag)
{
	typeFlag=flag;
	for(int i=0;i<MaxNode;i++)
		Vertice[i].firstAdj=NULL;
	numOfVertice=0;
	numOfEdge=0;
}
AdjList::~AdjList(void)
{
	for(int i=0;i<numOfVertice;i++)
	{
		Edge*p,*q;
		p=Vertice[i].firstAdj;
		while(p)
		{
			q=p->next;
			delete p;
			p=q;
		}
	}
}
VerType AdjList:: GetItem(const int i)//��ȡ���Ϊi�Ľ������
	{
		if (i<0||i>=numOfVertice)
		{
			cout<<"������i����";
			exit(0);
		}
		return Vertice[i].data;
	}
	WType AdjList:: GetWeight(int v1,int v2)//��ȡ��<v1,v2>��Ȩ
	{
		if(v1<0||v1>=numOfVertice||v2<0||v2>=numOfVertice)
		{
			cout<<"v1��v2��ֵ���Ϸ����޷��ҵ���<v1,v2>��Ȩ";
				exit(0);
		}
		Edge*first;
		first=Vertice[v1].firstAdj;
		while(first->next!=NULL && first->dist!=v2)
		{
			first=first->next;
		}
		if(first->dist==v2)
			return first->weight;
		else
		{
			cout<<"��<v1,v2>��Ȩ������";
			exit(0);
		}
	}
void AdjList::InsertVertice(VerType item)
{
	if(AdjListFull())
	{
		cout<<"�ڽӱ��������޷������µĶ���";
		exit(0);
	}
	Vertice[numOfVertice++].data=item;
}
void AdjList::InsertEdge(int v1,int v2,WType w)
{
	if(v1<0||v1>=numOfVertice||v2<0||v2>=numOfVertice)
		{
			cout<<"v1��v2��ֵ���Ϸ����޷������<v1,v2>";
				exit(0);
		}
	Edge*p;
	if(!typeFlag)//����ͼ
	{
		p=new Edge(v2,w);//�����(v1,v2)
		if(Vertice[v1].firstAdj==NULL)//��һ�β���
			Vertice[v1].firstAdj=p;
		else
		{	
			Edge*curr=Vertice[v1].firstAdj,*pre=NULL;
			while(curr!=NULL&&curr->dist<v2)
			{
				pre=curr;
				curr=curr->next;
			}
			if(pre==NULL)//���ڵ�һ�����֮��
			{
				p->next=Vertice[v1].firstAdj;
				Vertice[v1].firstAdj=p;
			}
			else//����pre֮��
			{
				p->next=pre->next;
				pre->next=p;
			}
		}
		p=new Edge(v1,w);//�����(v2,v1)
		if(Vertice[v2].firstAdj==NULL)//��һ�β���
			Vertice[v2].firstAdj=p;
		else
		{	
			Edge*curr=Vertice[v2].firstAdj,*pre=NULL;
			while(curr!=NULL&&curr->dist<v1)
			{
				pre=curr;
				curr=curr->next;
			}
			if(pre==NULL)//���ڵ�һ�����֮��
			{
				p->next=Vertice[v2].firstAdj;
				Vertice[v2].firstAdj=p;
			}
			else//����pre֮��
			{
				p->next=pre->next;
				pre->next=p;
			}
		}

		numOfEdge++;

	}
	else//����ͼ
	{
		 p=new Edge(v2,w);//�����<v1,v2>
		if(Vertice[v1].firstAdj==NULL)//��һ�β���
			Vertice[v1].firstAdj=p;
		else
		{	
			Edge*curr=Vertice[v1].firstAdj,*pre=NULL;
			while(curr!=NULL&&curr->dist<v2)
			{
				pre=curr;
				curr=curr->next;
			}
			if(pre==NULL)//���ڵ�һ�����֮��
			{
				p->next=Vertice[v1].firstAdj;
				Vertice[v1].firstAdj=p;
			}
			else//����pre֮��
			{
				p->next=pre->next;
				pre->next=p;
			}
		}
		numOfEdge++;
	}
}
void AdjList::DeleteVertice(int v)
{
	if (v<0||v>=numOfVertice)
		{
			cout<<"���Ϊv�Ľ�㲻���ڣ��޷�ɾ����";
			exit(0);
		}
		//ɾ���ڽӱ�������������v�Ĺ�����
	Edge*p,*q;
	p=Vertice[v].firstAdj;//ɾ��v�������ı�
	for(int i=v;i<numOfVertice-1;i++)//ɾ�����
	{
		Vertice[i].data=Vertice[i+1].data;
		Vertice[i].firstAdj=Vertice[i+1].firstAdj;
	}
	numOfVertice--;
	while(p!=NULL)
	{
		numOfEdge--;
		q=p->next;
		delete p;
		p=q;
	}
	//ɾ����������vv�ıߣ���Ҫע�����ԭ���ڽӱߵ���ŷ����ı�
	//�������ڽӱ�����бȱ�ɾ�������Ŵ�Ķ�Ҫ��ȥ1
	Edge*temp;
    for(int j=0;j<numOfVertice;j++)
	{
		p=Vertice[j].firstAdj;
		q=NULL;
		while(p!=NULL&&p->dist<v)
		{
			q=p;
			p=p->next;
		}
		if(q==NULL&&p->dist==v)//ɾ�����ǵ�һ���ڽӱ�
		{
			Vertice[j].firstAdj=p->next;
			delete p;
			if(typeFlag)
				numOfEdge--;
		}
		else if(p!=NULL&&p->dist==v)
		{
			q->next=p->next;
			delete p;
			if(typeFlag)
				numOfEdge--;
		}
	}
	for(int j=0;j<numOfVertice;j++)
		{
			p=Vertice[j].firstAdj;
			q=NULL;
			while(p!=NULL&&p->dist<=v)
			{
				q=p;
				p=p->next;
			}
			if(p!=NULL)
			{
				temp=p;
				while(temp!=NULL)
				{
					temp->dist--;
					temp=temp->next;
				}
			}
	}
}
void AdjList::DeleteEdge(int v1,int v2)
{
	if(v1<0||v1>=numOfVertice||v2<0||v2>=numOfVertice)
		{
			cout<<"v1��v2��ֵ���Ϸ����޷�ɾ����<v1,v2>";
				exit(0);
		}
	if(typeFlag)//����ͼɾ����<v1,v2>
	{
		Edge*p,*q;
		q=NULL;
		p=Vertice[v1].firstAdj;
		while(p&&p->dist!=v2)
		{
			q=p;
			p=p->next;
		}
		if(q==NULL&&p->dist==v2)//ɾ����һ�����
		{
			Vertice[v1].firstAdj=p->next;
			delete p;
				numOfEdge--;
		}
		if(q!=NULL&&p->dist==v2)//ɾ��p
		{
			q->next=p->next;
			delete p;
			numOfEdge--;
		}
	}
	else//����ͼ
	{
		Edge*p,*q;
		q=NULL;
		p=Vertice[v1].firstAdj;//ɾ����(v1,v2)
		while(p&&p->dist!=v2)
		{
			q=p;
			p=p->next;
		}
		if(q==NULL&&p->dist==v2)
		{
			Vertice[v1].firstAdj=p->next;
			delete p;
		}
		if(q!=NULL&&p->dist==v2)
		{
			q->next=p->next;
			delete p;
		}
		numOfEdge--;
		q=NULL;
		p=Vertice[v2].firstAdj;//ɾ����(v2,v1)
		while(p&&p->dist!=v1)
		{
			q=p;
			p=p->next;
		}
		if(q==NULL&&p->dist==v1)
		{
			Vertice[v2].firstAdj=p->next;
			delete p;
		}
		if(q!=NULL&&p->dist==v1)
		{
			q->next=p->next;
			delete p;
		}
	}
}
int AdjList::GetFirstNeighbor(const int v)
{
	if (v<0||v>=numOfVertice)
		{
			cout<<"���Ϊv�Ľ�㲻���ڣ��޷��ҵ����ĵ�һ���ڽӱߣ�";
			exit(0);
		}
	Edge*p=Vertice[v].firstAdj;
	if(p)
		return p->dist;
	return -1;
}
int AdjList::GetNextNeighbor(const int v1,const int v2)
{
	if(v1<0||v1>=numOfVertice||v2<0||v2>=numOfVertice)
		{
			cout<<"v1��v2��ֵ���Ϸ����޷��ҵ�<v1,v2>����һ�ڽӱ�";
				exit(0);
		}
	Edge*p=Vertice[v1].firstAdj;
	while (p)
	{
		if(p->next&&p->dist==v2)
			return p->next ->dist ;
		else
			p=p->next ;
	}
	return -1;
}
void AdjList::DepthFirstSearch(const int v,int visited[],void visit(VerType item))
{
	visit(GetItem(v));
	visited[v]=1;//����ǣ���ʾ�õ��Ѿ����ʹ���
	int adjV=GetFirstNeighbor(v);
	while(adjV!=-1)
	{
		if(!visited[adjV])
			DepthFirstSearch(adjV,visited,visit);//��adjV�����������ȱ���
		adjV=GetNextNeighbor(v,adjV);
	}
}
void AdjList::BroadFirstSearch(const int v,int visited[],void visit(VerType item))
{
	int u,adjV;
	SeqQueue queue;
	visit(GetItem(v));
	visited[v]=1;
	queue.QInsert(v);
	while(!queue.QueueEmpty())
	{
		u=queue.QDelete();
		adjV=GetFirstNeighbor(u);
		while(adjV!=-1)
		{
			if(!visited[adjV])
			{
				visit(GetItem(adjV));
				visited[adjV]=1;
				queue.QInsert(adjV);
			}
			adjV=GetNextNeighbor(u,adjV);
		}
	}
}
void AdjList::DepthFirstSearch(void visit(VerType item))//����ͼ�ͷ���ͨͼ������ȱ���
{
	int *visited=new int[NumOfVer()];
	for(int i=0;i<NumOfVer();i++)
		visited[i]=0;
	for(int i=0;i<NumOfVer();i++)
		if(!visited[i])
			DepthFirstSearch(i,visited,visit);
		delete []visited;
}
void AdjList:: BroadFirstSearch(void visit(VerType item))//����ͼ�ͷ���ͨͼ������ȱ���
{
	int *visited=new int[NumOfVer()];
	for(int i=0;i<NumOfVer();i++)
		visited[i]=0;
	for(int i=0;i<NumOfVer();i++)
		if(!visited[i])
			BroadFirstSearch(i,visited,visit);
		delete []visited;
}
Edge* AdjList::GetAdj(int v)
{
	if (v<0||v>=numOfVertice)
		{
			cout<<"���Ϊv�Ľ�㲻���ڣ��޷��ҵ�ָ�����ĵ�һ���ڽӱߵ�ָ�룡";
			exit(0);
		}
	Edge*p=Vertice[v].firstAdj;
	return p;
}





		






















