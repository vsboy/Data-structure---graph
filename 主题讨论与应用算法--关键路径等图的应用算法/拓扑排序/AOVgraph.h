struct edge
{
	int head;//��ͷ���
	int tail;//��β���
};
struct tp
{
	int degree;//��������
	int sortflag;//�����Ƿ��Ѿ���������������ж���
};
class aovgraph
{
	char * vexs;//���㼯��
	int **adjm;//�ڽӾ���
	int n;//������Ŀ
	int e;//�ߵ���Ŀ
public:
	aovgraph(char a[],edge b[],int N,int E)//���캯��
	{
		int i,j,s,l;
		n=N;e=E;
		vexs=new char[n];
		for(i=0;i<n;i++)
			vexs[i]=a[i];
		adjm=new int *[n];
		for(i=0;i<n;i++)
			adjm[i]=new int [n];
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				adjm[i][j]=0;
		for(i=0;i<e;i++)
		{
			s=b[i].head;
			l=b[i].tail;
			adjm[s][l]=1;
		}
	}
	//��������
	void tpsort(tp a[],char result[])//a��¼�������Ⱥ��Ƿ��Ѿ�����õ㣻result����������
	{
		int i,j,k;
		//���ȼ���ÿһ����������
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				a[i].degree+=adjm[j][i];
			a[i].sortflag=0;
		}
		for(k=0;k<n;k++)
		{
			for(i=0;i<n;i++)
				if((a[i].degree==0) && (a[i].sortflag==0))//����õ����Ϊ0��δ���
				{
					result[k]=vexs[i];
					a[i].sortflag=1;
					//ɾ���õ�
					for(j=0;j<n;j++)
					{
						if(adjm[i][j]==1)
							a[j].degree--;
					}
					break;
				}
		}
	}

};


