struct edge
{
	int head;//弧头序号
	int tail;//弧尾序号
};
struct tp
{
	int degree;//顶点的入度
	int sortflag;//区别是否已经是输出的拓扑序列顶点
};
class aovgraph
{
	char * vexs;//顶点集合
	int **adjm;//邻接矩阵
	int n;//顶点数目
	int e;//边的数目
public:
	aovgraph(char a[],edge b[],int N,int E)//构造函数
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
	//拓扑排序
	void tpsort(tp a[],char result[])//a纪录顶点的入度和是否已经输出该点；result是拓扑序列
	{
		int i,j,k;
		//首先计算每一个顶点的入度
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				a[i].degree+=adjm[j][i];
			a[i].sortflag=0;
		}
		for(k=0;k<n;k++)
		{
			for(i=0;i<n;i++)
				if((a[i].degree==0) && (a[i].sortflag==0))//如果该点入度为0且未输出
				{
					result[k]=vexs[i];
					a[i].sortflag=1;
					//删除该点
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


