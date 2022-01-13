# Connect Nodes at Same Level

class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
       queue<Node*> q;
     
        if(root==NULL) 
            return;
        q.push(root);
         while(!q.empty())
         {
             int size=q.size();
             for(int i=1;i<=size;i++)
             {
                Node* curr= q.front();
                q.pop();
                Node* next= q.front();
                curr->nextRight=next;
                if(i==size)
                {
                   curr->nextRight=NULL; 
                }
                
                if(curr->left!=NULL)
                {
                 q.push(curr->left);
                }
                if(curr->right!=NULL)
                {
                 q.push(curr->right);
                }
            }
        }
    }    
      
};
