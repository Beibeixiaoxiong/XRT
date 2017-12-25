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
 int main()
{
Graphlnk G(30);
cout<<"读取文件插入站点" <<endl;
G.insertVertex();
cout<<"总站点数为"<<G.numVertices<<endl;
int i,j,weight;
ifstream fin("C:\\2.txt", std::ios::in);
char line[1024]={0};
string x="";
string y="";
string m="";
string n="";
int z;
while(fin.getline(line, sizeof(line)))
{
stringstream word(line);
word >> x;//路由起点 
word >> y;//路由终点 
word >> z;//权值 
word >> m;//网络号 
word >> n;//子网掩码 
i=G.getVertexPos(x);
j=G.getVertexPos(y);
weight=z;
G.insertEdge(i,j,weight,m,n);
}

fin.clear();
fin.close();
cout<<"总边数数为"<<G.numEdges<<endl;
int h;
	 int r;
	int *dist= new int[G.numVertices];
	 int *path= new int[G.numEdges];
	 string v,u;int a=1,b;
	//输出路由表 

	while(a)
	{
	 cout<<"1.输入路由号显示路由表  2.删除一个路由表  3.删除一条边 4.退出"<<endl; 
	 cin>>b;
	 if(b==1)
	 {	  
	 cout<<"输入路由号"<<endl; 
	 cin>>v;
	 r=G.getVertexPos(v);
	 while(r==-1)
	 {
	 	cout<<"没有该路由"<<endl;
	 	cout<<"输入路由器"<<endl;
	    cin>>v;
	    r=G.getVertexPos(v);
	 }
	  
	 ShortestPath(G, r, dist, path);
}
if(b==2)
{
	
 //删除一个路由器 
	cout<<"删除路由器"<<endl;
	cin>>v;
	int w=G.getVertexPos(v);
	while(!G.removeVertex(w))
	{
		cout<<"没有该路由"<<endl;
		cout<<"删除路由器"<<endl;
	    cin>>v;
		w=G.getVertexPos(v);
	}	
	cout<<"已生成新的路由表"<<" "<<"输入路由器查看路由表"<<endl;
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
}
if(b==3)
{
	 //删除一条边 
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
	
}
if(b==4)
 {
a=0;
cout<<"已退出"<<endl;
}

} 
	 
}
