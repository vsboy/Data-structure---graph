#include<iostream>
using namespace std;
struct arcinfo
{
	int head;//弧头
	int tail;//弧尾
	int weight;
};
class aoegraph
{
	char* vexs;//顶点信息
	int **adjm;//邻接矩阵
	int n;//顶点数目
	int e;//边的数目
public:
	aoegraph(char vexa[],arcinfo edge[],int N,int E)//构造函数
	{
		int s,l;
		n=N;
		e=E;
		vexs=new char[n];
		for(int i=0;i<n;i++)
			vexs[i]=vexa[i];
		adjm=new int*[n];
		for(int i=0;i<n;i++)
			adjm[i]=new int[n];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				adjm[i][j]=0;
		for(int j=0;j<e;j++)
		{
			s=edge[j].head;
			l=edge[j].tail;
			adjm[s][l]=edge[j].weight;
		}
		/*for(i=0;i<n;i++)
		{	for(j=0;j<n;j++)
				cout<<setw(3)<<adjm[i][j];
		cout<<endl;}*/
	}
	void keypath(int earlyVex[],int lastVex[],arcinfo keyActive[])
	{
		//求事件的最早发生时间
		int i,j,k=0,min,max,sum=0,s,l;
		earlyVex[0]=0;
		for(int i=1;i<n;i++)//求第i个顶点（事件）的最早发生时间
		{
			max=0;
			for(int j=0;j<n;j++)
			{
				if(adjm[j][i]!=0)
				{
					max=max>(adjm[j][i]+earlyVex[j])?max:(adjm[j][i]+earlyVex[j]);
				}
			}
			earlyVex[i]=max;
		}
		//求解事件的最迟发生时间
		lastVex[n-1]=earlyVex[n-1];
		for(int i=n-2;i>=0;i--)//求第i个顶点（事件）的最晚发生时间
		{
			min=100;
			for(int j=0;j<n;j++)
			{
				if(adjm[i][j]!=0)
				{
					min=min<(lastVex[j]-adjm[i][j])?min:(lastVex[j]-adjm[i][j]);
				}
				lastVex[i]=min;
			}
		}
		//下面求解关键活动,活动的最晚(lastVex[j]-adjm[i][j])-活动的最早(earlyVex[i])=0
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				if((adjm[i][j]!=0)&&((lastVex[j]-adjm[i][j]-earlyVex[i])==0))//关键活动
				{
					keyActive[k].head=i;
					keyActive[k].tail=j;
					keyActive[k].weight=adjm[i][j];
					k++;
				}
			}
		cout<<"该AOE网关键活动有："<<endl;
		for(int i=0;i<=k-1;i++)
		{
			s=keyActive[i].head;
			l=keyActive[i].tail;
			cout<<"<"<<vexs[s]<<","<<vexs[l]<<">"<<"权值:"<<keyActive[i].weight<<endl;
			sum=sum+keyActive[i].weight;
		}
		cout<<"关键路径"<<endl;
		for(int i=0;i<=k-1;i++)
		{
			s=keyActive[i].head;
			l=keyActive[i].tail;
			cout<<vexs[s]<<"--->";
		}
		cout<<vexs[l];
		cout<<endl;
		cout<<"关键路径长度为"<<sum<<endl;
	}
};