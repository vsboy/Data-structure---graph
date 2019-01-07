//用来存放在每一轮求解最短路径时所求到的各条路径
class AdjMGraph;
class TPath
{
	friend class AdjMGraph;
	int pathlength;
	int sourcevex;//表示是由顶点sourcevex到达改点的路径
public:
	TPath(int x,int y)
	{
		pathlength=x;
		sourcevex=y;
	}
	void clear()
	{
		pathlength=10000;
		sourcevex=-1;
	}
};