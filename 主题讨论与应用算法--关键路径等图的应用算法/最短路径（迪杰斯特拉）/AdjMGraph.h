#include"MSPath.h"
#include"TPath.h"
class AdjMGraph//邻接矩阵
{
	char *vex;//顶点集合
	int *edge;//边集合
	int n;//顶点数目
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
		int getweight(int i,int j,int n);//获取弧<i,j>的权值
		void djspath(MSPath s[],TPath temp[],int n,int startvex,int weight[]);
		
};
int AdjMGraph::getweight(int i,int j,int n)
{
			int k;
			k=i*n+j;
			return(edge[k]);
}
void AdjMGraph::djspath(MSPath s[],TPath temp[],int n,int startvex,int weight[])//求解最短路径
{
	//参数的意义 
	//MSPath s[]--->存放求出的各条路径
	//TPath temp[]----->每一轮求解过程存放待比较长度的各条路径
	//int n----->顶点个数
	//int startvex---->起始点
	//int weight[]---->存放计算到达某一个顶点的各条路径的长度
	// 10000在本算法中的含义是无穷大
	int i,j,k,t,min,tempt,localtempt,tempweight,f,m;
	for(i=0;i<n;i++)//起始点的路径
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
			if(s[j].flag ==0)//如果这个点没有添加在已有顶点集合，求出到该点的各条路径长度存放在weight[]中
			{
				for(k=0;k<n;k++)//到达该列(j)的所有节点
				{
					t=k*n+j;//相当于二维数组egde[k][j]
					if(edge[t]!=-1 && s[k].flag ==1)//如果有路且与它相临的这个点已经在已有顶点集合
					{
						tempweight=edge[t]+s[k].pathlength ;//计算路径长度
						weight[k]=tempweight;
					}
				}
				//求解weight[]中的最短；长度存放在temp[j].pathlength；到达该顶点的顶点是temp[j].sourcevex
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
			min=10000;//求本轮的最短路径，找到的顶点是tempt,存放到s[]中
			for(m=0;m<n;m++)
				if(min>temp[m].pathlength)
				{
					min=temp[m].pathlength;
					tempt=m;//tempt是本轮找到的最短的顶点序号
				}
			if (min!=10000)  
			{	
				s[tempt].pathlength=temp[tempt].pathlength;//该轮找到一条最短路径
				s[tempt].flag=1;
				f=temp[tempt].sourcevex;//f到达tempt路径的顶点
				//下面是路径的拷贝；把起点到f的路径拷贝到s[tempt]
				for(m=1;m<n;m++)
					if (s[f].path[m]==-1)
						break;
					else
						s[tempt].path[m]=s[f].path[m];
				s[tempt].path[m]=tempt;//拷贝顶点自己
				for(m=0;m<n;m++)
					temp[m].clear();//清空temp；以备下一轮
			}
	}
	//查找没有最短路径的顶点
	for(m=0;m<n;m++)
		if(s[m].pathlength==0 && m!=startvex)
			s[m].pathlength;

}
