# Tree Serialization and Deserialization

class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree using dfs
    vector<int> A;
    void dfs(Node* root)
    {
        if(root == NULL)
            return;
            
        dfs(root->left);
        A.push_back(root->data);
        dfs(root->right);
        
        return;
    }
    vector<int> serialize(Node *root) 
    {
        //Your code here
        dfs(root);
        return A;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       //Your code here
       struct Node* nn = new Node(-1);
       Node* temp = nn;
       int n = A.size();
       
       for(int i=0; i<n; i++)
       {
           temp ->right = new Node(A[i]);
           temp  = temp ->right;
       }
       
       return nn->right;
    }

};

