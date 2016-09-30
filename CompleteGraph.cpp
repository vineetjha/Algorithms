#include <iostream>

using namespace std;
struct node
{
   int vertex_no;
   int adj[20]; 
};
node V[20];
int v;
char color[20];

void dfs_visit(int i)
{
   color[i]='g';
//   cout << "Setting " << i << " to gray" << endl;
   for (int j=0; V[i].adj[j]!=0;j++)
   {
      //cout << "Checking " << V[i].adj[j] << " color" << endl;
      if(color[V[i].adj[j]]=='w')
          dfs_visit(V[i].adj[j]);
   }
   color[i]='b';
   //cout << "Setting " << i << " to BLACK" << endl;
}




int main()
{
   for(int i=0;i<20;i++)
      for(int j=0;j<20;j++)
         V[i].adj[j]=0;
      cout<<"Enter the number of vertices in the graph : ";
      cin>>v;
      cout<<"Graph contains following vertices : ";
      for(int i=1;i<=v;i++)
      { 
         cout<<i;
         if(i<v)
            cout<<", ";
      }
      cout<< endl;
      for(int i=1;i<=v;i++)
      {
         cout<<"\nEnter adjacents of vertex "<<i<<" one by one. \n( Press 0 when no more adjacents have to be added )" << endl;
         int n=100;
         int mark=0,j=0;
         while(n!=0)
         {
            cin>>n;
            if((n>v)||(n==i))
            {
               cout<<"Please enter a valid vertex";
               continue;
            }
            V[i].adj[mark]=n;
            mark++;
         } 
      }
      cout<<"The undirected graph you entered is as follows in adjanceny list representation:" << endl;
      for(int i=1;i<=v;i++)
      {
          cout<<i;
          for(int j=0;j<20;j++)
          {
             if(V[i].adj[j]==0)
              break;
             cout<<"-->"<<V[i].adj[j];
          }
          cout<<"\n";
      }

      //Using DFS to find out the connected components of the graph

      for(int i=1;i<=v;i++)
      {
          color[i]='w';
      }
         
     for(int i=1;i<=v;i++)
     {
        if(i>1)
        {
            cout<<"Connected component "<<i-1<<" :";
            for(int i=1;i<=v;i++)
            {
               if(color[i]=='b'){
                  cout<<i<<" ";
                  color[i]='z';
               }
            }
            cout<<"\n";
        }
        if(color[i]=='w')
           dfs_visit(i);
    }

}
