//用来存放找到的路径及长度
class AdjMGraph;
class MSPath
{
	//public:
	friend  class AdjMGraph;
	int *path;//存放最短路径的信息；如2 3 1 0 -1表示顶点2到顶点0的路径；-1表示改点不存在
	int pathlength;//路径长度
	int n;//顶点的数目
	int flag;//标示该序号的顶点是否是已经找到的最短路径的顶点
	public:
	MSPath(int ncount)
	{
		path=new int[ncount];
		for(int i=0;i<ncount;i++)
			path[i]=-1;
		pathlength=0;
		n=ncount;
		flag=0;
	}
	void printpath()//输出路径
	{
		for(int i=0;i<n;i++)
		{
			if(path[i]==-1)
				break;
			else
				cout<<path[i]<<"  ";
		}
		cout<<endl;
		cout<<"长度";
		cout<<pathlength<<endl;
	}
	int getpathlength()//取路径长度
	{
		return pathlength;
	}
	int getflag()//判断是否是查找过的点
	{
		return flag;
	}

};
	