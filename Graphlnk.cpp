#include"Graph.h"
int Graphlnk::getWeight(int v1,int v2)
{
	if( v1 != -1 && v2 != -1)//两个结点都存在
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
 	Node int main()
{
Graphlnk G(30);
cout<<"读取文件插入站点" <<endl;
G.insertVertex();
cout<<"总站点数为"<<G.numVertices<<endl;
int i,j,weight;
ifstream fin("C:\\2.txt", std::ios::in);
char line[1024]={0};
string x = "";
string y="";
int z;
while(fin.getline(line, sizeof(line)))
{
stringstream word(line);
word >> x;
word >> y;
word >> z;
i=G.getVertexPos(x);
j=G.getVertexPos(y);
weight=z;
G.insertEdge(i,j,weight);
}

fin.clear();
fin.close();
cout<<"总边数数为"<<G.numEdges<<endl;
 
	//查询函数
	int *dist= new int[G.numVertices];
	 int *path= new int[G.numEdges];
	 string v,u;
	 cout<<"输入路由器"<<endl;
	 cin>>v;
	 int h;
	 int r=G.getVertexPos(v);
	 if(r==-1)
	 {
	 	cout<<"没有该路由"<<endl;
	 }
	 else
	 {	 
	 ShortestPath(G, r, dist, path);
     }
	cout<<"删除路由器"<<endl;
	cin>>v;
	int w=G.getVertexPos(v);
	G.removeVertex(w);
	cout<<"输入路由器"<<endl;
	 cin>>v;
	  r=G.getVertexPos(v);
	 if(r==-1)
	 {
	 	cout<<"没有该路由"<<endl;
	 }
	 else
	 {	 
	 ShortestPath(G, r, dist, path);
     }
     cout<<"删除一条边"<<endl;
		cin>>v;
		cin>>u;
		r=G.getVertexPos(v);
		h=G.getVertexPos(u);
		while(!G.removeEdge(r,h))
		{
			cout<<"删除一条边"<<endl;
			 cin>>v;
		cin>>u;
		r=G.getVertexPos(v);
		h=G.getVertexPos(u);
		}
		cout<<"输入路由器"<<endl;
	 cin>>v;
	  r=G.getVertexPos(v);
	 if(r==-1)
	 {
	 	cout<<"没有该路由"<<endl;
	 }
	 else
	 {	 
	 ShortestPath(G, r, dist, path);
     }	
	 
}Table[i].adj=NULL;
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
	 return true;
  } return false;
}
bool Graphlnk::removeVertex(int v)
{
	if(v<0||v>=numVertices) 
{
	cout<<"该结点错误"<<endl;	
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
