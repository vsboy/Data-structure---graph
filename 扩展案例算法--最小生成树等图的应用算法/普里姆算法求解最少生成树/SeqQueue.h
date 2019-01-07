#include<iostream>
using namespace std;
class SeqQueue
{
private:
	DataType data[SeqQMaxSize];
	int front;
	int rear;
	int count;
public:
	SeqQueue(void)
	{ 
		front=0;
		rear=0;
		count=0;
	}
	~SeqQueue(void){}
	void QInsert(DataType & item);
	void QInsert(int  item);
	DataType QDelete(void);
	DataType QFront(void) const;
	int QueueEmpty(void) const
	{
		return front==rear;

	}
	void ClearQueue(void)
	{
		front=0;
		rear=0;
		count=0;
	}
	int GetSize(void) const
	{
		return count;
	}
};
void SeqQueue::QInsert(DataType & item)
{
	if (count==SeqQMaxSize)
	{
		cout<<"队列已满!"<<endl;
		exit(0);
	}
	data[rear]=item;
	rear=(rear+1)%SeqQMaxSize;
	count++;
}
void SeqQueue::QInsert(int item)
{
	if (count==SeqQMaxSize)
	{
		cout<<"队列已满!"<<endl;
		exit(0);
	}
	data[rear]=item;
	rear=(rear+1)%SeqQMaxSize;
	count++;
}
DataType SeqQueue::QDelete(void)
{
	DataType temp;
	if(count==0)
	{
		cout<<"队列已空！"<<endl;
		exit(0);
	}
	temp=data[front];
	front=(front+1)%SeqQMaxSize;
	count--;
	return temp;
}
DataType SeqQueue::QFront(void) const
{
	if(count==0)
	{
		cout<<"队列已空！"<<endl;
		exit(0);
	}
	 return data[front];
}
		
