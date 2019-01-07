#include"MSPath.h"
#include"TPath.h"
class AdjMGraph//�ڽӾ���
{
	char *vex;//���㼯��
	int *edge;//�߼���
	int n;//������Ŀ
	public:
		AdjMGraph(int a[],char b[],int n)
		{
			n=n;
			int m;
			m=n*n;
			vex=new char[n];
			for(int i=0;i<n;i++)
				vex[i]=b[i];
			edge=new int[m];
			for(int i=0;i<m;i++)
				edge[i]=a[i];
		}
		int getweight(int i,int j,int n);//��ȡ��<i,j>��Ȩֵ
		void djspath(MSPath s[],TPath temp[],int n,int startvex,int weight[]);
		
};
int AdjMGraph::getweight(int i,int j,int n)
{
			int k;
			k=i*n+j;
			return(edge[k]);
}
void AdjMGraph::djspath(MSPath s[],TPath temp[],int n,int startvex,int weight[])//������·��
{
	//���������� 
	//MSPath s[]--->�������ĸ���·��
	//TPath temp[]----->ÿһ�������̴�Ŵ��Ƚϳ��ȵĸ���·��
	//int n----->�������
	//int startvex---->��ʼ��
	//int weight[]---->��ż��㵽��ĳһ������ĸ���·���ĳ���
	// 10000�ڱ��㷨�еĺ����������
	int i,j,k,t,min,tempt,localtempt,tempweight,f,m;
	for(i=0;i<n;i++)//��ʼ���·��
	{
		s[i].path[0]=startvex;
	}
	s[startvex].flag=1;
	for(i=1;i<n;i++)
	{
		j=0;
		while(j<n)
		{ 
			if(j!=startvex)
			{for(m=0;m<n;m++)
				weight[m]=10000;
			if(s[j].flag ==0)//��������û����������ж��㼯�ϣ�������õ�ĸ���·�����ȴ����weight[]��
			{
				for(k=0;k<n;k++)//�������(j)�����нڵ�
				{
					t=k*n+j;//�൱�ڶ�ά����egde[k][j]
					if(edge[t]!=-1 && s[k].flag ==1)//�����·���������ٵ�������Ѿ������ж��㼯��
					{
						tempweight=edge[t]+s[k].pathlength ;//����·������
						weight[k]=tempweight;
					}
				}
				//���weight[]�е���̣����ȴ����temp[j].pathlength������ö���Ķ�����temp[j].sourcevex
				min=weight[0];
				localtempt=0;
				for(m=1;m<n;m++)
					if(min>weight[m])
					{
						min=weight[m];
						localtempt=m;
					}
					temp[j].pathlength=min;
					if(temp[j].pathlength==10000)
						temp[j].sourcevex=-1;
					else
						temp[j].sourcevex=localtempt;
				localtempt=-1;
			}
			}
			j++;
		}
			min=10000;//���ֵ����·�����ҵ��Ķ�����tempt,��ŵ�s[]��
			for(m=0;m<n;m++)
				if(min>temp[m].pathlength)
				{
					min=temp[m].pathlength;
					tempt=m;//tempt�Ǳ����ҵ�����̵Ķ������
				}
			if (min!=10000)  
			{	
				s[tempt].pathlength=temp[tempt].pathlength;//�����ҵ�һ�����·��
				s[tempt].flag=1;
				f=temp[tempt].sourcevex;//f����tempt·���Ķ���
				//������·���Ŀ���������㵽f��·��������s[tempt]
				for(m=1;m<n;m++)
					if (s[f].path[m]==-1)
						break;
					else
						s[tempt].path[m]=s[f].path[m];
				s[tempt].path[m]=tempt;//���������Լ�
				for(m=0;m<n;m++)
					temp[m].clear();//���temp���Ա���һ��
			}
	}
	//����û�����·���Ķ���
	for(m=0;m<n;m++)
		if(s[m].pathlength==0 && m!=startvex)
			s[m].pathlength;

}
