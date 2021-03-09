
#include <stdio.h>
#include <iostream>
using namespace std;
class adjMatrix
{
    int SIZE;
    int **A;
    int *visited;
    int *queue;
    int front = 0;
    int rear = 0;
    public:
        adjMatrix(int SIZE)
        {   
            //for assigning
            this->SIZE=SIZE;
            cout<<SIZE;
            A = new int* [SIZE+3];
            visited = new int [SIZE+3];
            queue = new int [SIZE+3];
            
            // A[i][j] == 0 where i=j
            for (int i = 0; i < SIZE; i++) 
            { 
                visited[i] = 0; 
                A[i] = new int [SIZE+2];
                for (int j = 0; j < SIZE; j++)
                { 
                    A[i][j] = 0; 
                } 
            }
            
        }
        
        //function to dispaly edge
        void displayMatrix()
        {
            cout<<"\n";
            for(int i=0;i<SIZE;i++){
                for(int j=0;j<SIZE;j++){
                    cout<<A[i][j];
                }
                cout<<"\n";
            }
        }
        
        //function to add edge
        void addEdge(int n1, int n2)
        {
            //not a node
            if(n1>SIZE or n2>SIZE or n1<1 or n2<1)
            {
                cout<<"node does not exist\n";
            }
            else
            {
                A[n1-1][n2-1] = 1;
                A[n2-1][n1-1] = 1;
            }
        }
        
        //for searching a node and showing its connected nodes
        void displayEdges(int node){
            if(node>SIZE or node<0){
                cout<<"node does not exist\n";
            }
            else{
                for(int i=0;i<SIZE;i++){
                    if(A[node-1][i] == 1){
                        cout<<"\n'"<<node<<"' node is connected to "<<i+1;
                    }
                }
            }
            
        }
        
        //to add a node or vertices
        void addNode(){
            SIZE=SIZE+1;
            cout<<SIZE;
            A[SIZE-1] = new int [SIZE];
            for(int i = 0;i<SIZE;i++){
                A[SIZE-1][i]=0;
                A[i][SIZE-1]=0;
            }
        }
        
        //to delete the node
        void deleteNode(int node){
    
            if(node > SIZE or node < 0) { 
                cout <<"\nnot present!"; 
            } 
            else{ 
                    for(int i=node;i<SIZE;i++){
                        for(int j = 0;j<SIZE;j++){
                            A[i-1][j] = A[i][j];
                        }
                    }
                    
                    for(int j =node; j<SIZE;j++){
                        for(int i= 0;i<SIZE-1;i++){
                            A[i][j-1] = A[i][j];
                        }
                    }
                    SIZE = SIZE-1;
                } 
        }
        
        void DFS_visit(int node){
            for(int i = 0; i<SIZE;i++){
                visited[i] =0;
            }
            DFS(node);
        }
        
        void DFS(int node){
            cout<<node<<"  ";
            visited[node-1]=1;
            for(int i=0;i<SIZE;i++){
                if(A[node-1][i]==1 and visited[i]==0){
                    DFS(i+1);
                }
                
            }
        }
        
        void enqueue(int data){
            queue[rear] = data;
            rear = rear+1;
        }
        
        void dequeue(){
            if(front == rear){
                return;
            }
            else{
                for(int i =0;i<SIZE;i++){
                    queue[i] = queue[i+1];
                }
                rear = rear-1;
            }
        }

        
        void BFS(int node){
            visited = new int [SIZE];
            visited[node-1]= 1;
            int now;
            enqueue(node);
            while(front != rear){
                now = queue[0];
                cout<<now<<"  ";
                dequeue();
                for(int i = 0; i<SIZE;i++){
                    if(A[now-1][i]==1 and visited[i] ==0){
                        enqueue(i+1);
                        visited[i] = 1;
                    }
                }
            }
            
        }
};

int main()
{
    int v, e;
    int search;
    int choice;
    int n1, n2;
    cout<<"Enter no. of vertices: ";
    cin>>v;
    adjMatrix graph(v);
    cout<<"\nEnter no of edges: ";
    cin>>e;
    for(int i = 0; i<e;i++){
       
        cout<<"Enter the first node that you want to connect  :";
        cin>>n1;
        cout<<"Enter the second node : ";
        cin>>n2;
        graph.addEdge(n1, n2);
    }
    while(1)
	{
        cout<<"\n";
		cout<<"1.Search\n";
		cout<<"2.Insert Node\n";
		cout<<"3.Insert Edge\n";
		cout<<"4.Delete\n";
		cout<<"5.DFS\n";
		cout<<"6.BFS\n";
		cout<<"7.Display\n";
		cout<<"8.Quit\n";
	    cout<<"Enter your choice : ";
		cin>>choice;

		switch(choice)
		{
    		case 1:
                cout<<"Enter the node to be searched: ";
                cin>>search;
                graph.displayEdges(search);
    			break;
    		case 2:
    		    graph.addNode();
    			break;
    		case 3:
    		    cout<<"Enter the first node that you want to connect  :";
                cin>>n1;
                cout<<"Enter the second node : ";
                cin>>n2;
                graph.addEdge(n1, n2);
                break;
    		case 4:
    		    cout<<"Enter the node to be deleted: ";
    		    cin>>search;
                graph.deleteNode(search);
    		    break;
    		case 5:
    		    graph.DFS_visit(1);
    		    break;
    		case 6: 
    		    graph.BFS(1);
    		    break;
    		case 7:
    		    graph.displayMatrix();
    		    break;
            case 8:
    		    exit(1);
                
    		default:
    			printf("Wrong choice\n");
		}/*End of switch */
	}/*End of while */
    return 0;
}






