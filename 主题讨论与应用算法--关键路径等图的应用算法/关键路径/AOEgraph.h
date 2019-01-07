#include<iostream>
using namespace std;
struct arcinfo
{
	int head;//��ͷ
	int tail;//��β
	int weight;
};
class aoegraph
{
	char* vexs;//������Ϣ
	int **adjm;//�ڽӾ���
	int n;//������Ŀ
	int e;//�ߵ���Ŀ
public:
	aoegraph(char vexa[],arcinfo edge[],int N,int E)//���캯��
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
		//���¼������緢��ʱ��
		int i,j,k=0,min,max,sum=0,s,l;
		earlyVex[0]=0;
		for(int i=1;i<n;i++)//���i�����㣨�¼��������緢��ʱ��
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
		//����¼�����ٷ���ʱ��
		lastVex[n-1]=earlyVex[n-1];
		for(int i=n-2;i>=0;i--)//���i�����㣨�¼�����������ʱ��
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
		//�������ؼ��,�������(lastVex[j]-adjm[i][j])-�������(earlyVex[i])=0
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				if((adjm[i][j]!=0)&&((lastVex[j]-adjm[i][j]-earlyVex[i])==0))//�ؼ��
				{
					keyActive[k].head=i;
					keyActive[k].tail=j;
					keyActive[k].weight=adjm[i][j];
					k++;
				}
			}
		cout<<"��AOE���ؼ���У�"<<endl;
		for(int i=0;i<=k-1;i++)
		{
			s=keyActive[i].head;
			l=keyActive[i].tail;
			cout<<"<"<<vexs[s]<<","<<vexs[l]<<">"<<"Ȩֵ:"<<keyActive[i].weight<<endl;
			sum=sum+keyActive[i].weight;
		}
		cout<<"�ؼ�·��"<<endl;
		for(int i=0;i<=k-1;i++)
		{
			s=keyActive[i].head;
			l=keyActive[i].tail;
			cout<<vexs[s]<<"--->";
		}
		cout<<vexs[l];
		cout<<endl;
		cout<<"�ؼ�·������Ϊ"<<sum<<endl;
	}
};