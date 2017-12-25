#include"Graph.h"
int Graphlnk::getWeight(int v1,int v2)
{
	if( v1 != -1 && v2 != -1)
	{
		Edge *p = NodeTable[v1].adj;
		while (p!= NULL && p->dest!= NodeTable[v2].start)
		{
			p = p->link;
		}
		if(p != NULL) 
			return p->cost;
		else return DefaultVertices+1;
	}
}
 int Graphlnk::getNextNeighbor(int v,int w)
 {
 if(v!=-1)
 {
 Edge*p=NodeTable[v].adj;
 while(p!=NULL&&p->dest!=NodeTable[w].start)
 p=p->link;
 if(p!=NULL&&p->link!=NULL)
 return getVertexPos(p->link->dest);//返回位置 
}
return -1;
}; 
 //查询第一结点 
int Graphlnk::getFirstNeighbor(int v)
 {
 if(v!=-1)//有v这个站点 
 {
 	Edge*p=NodeTable[v].adj;
 	if(p!=NULL) return getVertexPos(p->dest);
	 }	
return -1;	 
 };
 //函数的实现 
Graphlnk::Graphlnk(int sz)
 {
 	maxVertices=sz;
 	numVertices=0;
 	numEdges=0;
 	NodeTable=new Vertex[sz];
 	for(int i=0;i<maxVertices;i++)
 	NodeTable[i].adj=NULL;
 	
 };
 bool Graphlnk::removeEdge(int v1,int v2)//图上删一条边 
 {
 	 if(v1!=-1&&v2!=-1)
	  {
	  	Edge*p=NodeTable[v1].adj,*q=NULL,*s=p;
	  	while(p!=NULL&&p->dest!=NodeTable[v2].start)
	  	{q=p;p=p->link;
		  }
		  if(p!=NULL){ //找到被删结点
		  if(p==s) NodeTable[v1].adj=p->link;
		  else q->link=p->link;
		  delete p; 
	   } 
 	else
	 {
	 	cout<<"两点间没有边"<<endl;
	 return false;
}
 	p=NodeTable[v2].adj; q=NULL; s=p;
 	while(p->dest!=NodeTable[v1].start)
 	{
 		q=p;p=p->link;
	 }
	 if(p==s) NodeTable[v2].adj=p->link;
	 else q->link=p->link;
	 delete p;
	 cout<<"删除成功"<<endl;
	 return true;
  }
  else
  {
 cout<<"结点错误，删边失败"<<endl;   
  return false;
}
}
bool Graphlnk::removeVertex(int v)
{
	if(v<0||v>=numVertices) 
{	
	return false;
}
Edge*p,*s,*t;
int i,j;
string k;
while(NodeTable[v].adj!=NULL)
{
	p=NodeTable[v].adj;
	k=p->dest;
	j=getVertexPos(k);
	s=NodeTable[j].adj;
	t=NULL;
	while(s!=NULL &&s->dest!=NodeTable[v].start)
	{
	t=s;s=s->link;
	}
	if(s!=NULL)
	{
		if(t==NULL) NodeTable[j].adj=s->link;
		else t->link=s->link;
		delete s;
	}
	NodeTable[v].adj=p->link;
	delete p;
	numEdges--;
}

numVertices--;
NodeTable[v].start=NodeTable[numVertices].start;
p=NodeTable[v].adj=NodeTable[numVertices].adj;
if(p!=NULL)
{
	
	s=NodeTable[getVertexPos(p->dest)].adj;
	while(s!=NULL)
	
	if(getVertexPos(s->dest)==numVertices)
	{
		
		s->dest=NodeTable[v].start;break;
	}
	else s=s->link;

}
cout<<"删除路由器成功"<<endl;
return true;
}
bool Graphlnk::insertVertex()//插入一个结点 
	{	 
ifstream fin("C:\\1.txt", std::ios::in);
char line[1024]={0};
 numVertices=0;
string x = "";
while(fin.getline(line, sizeof(line)))
{
stringstream word(line);
word >> x;
NodeTable[numVertices].start=x;
 numVertices++;
}

fin.clear();
fin.close();
cout<<"插入结点成功"<<endl;
return true;
	 };	 
bool Graphlnk::insertEdge(int v1,int v2,int cost,string v3,string v4)
{

	if(v1>=0&&v1<=numVertices&&v2>=0&&v2<=numVertices)//v1,v2合法 
		{
			string a;
			int b,c;
		 Edge*q,*p;
		 p=NodeTable[v1].adj;
		 while(p!=NULL&&p->dest!=NodeTable[v2].start)
		 p=p->link;
		 if(p!=NULL) 
		 {
		 return false;
		 } //找到此边不插入
		 p=new Edge(); q=new Edge();
		 p->dest=NodeTable[v2].start;    p->cost=cost; 
		 p->netnumber=v3;p->yanma=v4;
		 p->link=NodeTable[v1].adj;
		 NodeTable[v1].adj=p;//链入v1表 
		 q->dest=NodeTable[v1].start;    q->cost=cost;
		 q->netnumber=v3;q->yanma=v4;
		 q->link=NodeTable[v2].adj;
		 NodeTable[v2].adj=q; 
		 numEdges++;
		 return true;
		}
		return false;

	 } ;
