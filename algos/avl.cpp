#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define loop(i,a,n) for(int i=a;i<n;++i)
#define arrin(arr,n) for(int i=0; i < n; ++i) cin>>arr[i];
#define arrout(arr,n) for(int i=0; i < n; ++i) cout<<arr[i]<<" ";cout<<nl;
#define nl "\n"
#define _USE_MATH_DEFINES
// M_E : e  M_PI :pi  M_SQRT2:sqrt(2)
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;

struct compare
{
  bool operator()(const pair<int,int> & l, const pair<int,int> & r)
  {
      return l > r; //min: > ; max: <
  }
};

priority_queue<pair<int,int> ,vector<pair<int,int> >, compare > pq;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
   // int ls;
   // int rs;
    int size;
};

// A utility function to get maximum of two integers
int max(int a, int b);

// A utility function to get height of the tree
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

// A utility function to get maximum of two integers
int max(int a, int b)
{
    return (a > b)? a : b;
}

int siz (Node * curr)
{
	if (curr==NULL)
		return 0;
	return curr->size;
}

/* Helper function that allocates a new node with the given key and
    NULL left and right pointers. */
struct Node* newNode(int key)
{
    struct Node* node = (struct Node*)
                        malloc(sizeof(struct Node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  // new node is initially added at leaf
    node->size=1;
    //node->ls=0;
    //node->rs=0;

    return(node);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->size = siz(y->left)+siz(y->right)+1;
    x->size = siz(x->left)+siz(x->right)+1;
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    // Return new root
    return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    //  Update heights
    x->size = siz(x->left)+siz(x->right)+1;
    y->size = siz(y->left)+siz(y->right)+1;

    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Recursive function to insert key in subtree rooted
// with node and returns new root of subtree.
struct Node* insert(struct Node* node, int key)
{
    /* 1.  Perform the normal BST insertion */
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
    {
        node->left  = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
	}
    else // Equal keys are not allowed in BST
        return node;

    /* 2. Update height of this ancestor node */
    node->size= siz(node->left)+siz(node->right)+1;
    node->height = 1 + max(height(node->left),height(node->right));

    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = getBalance(node);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

struct Node * minValueNode(struct Node* node)
{
    struct Node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

// Recursive function to delete a node with given key
// from subtree with given root. It returns root of
// the modified subtree.
struct Node* deleteNode(struct Node* root, int key)
{
    // STEP 1: PERFORM STANDARD BST DELETE

    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the
    // root's key, then it lies in left subtree
    if ( key < root->key )
    {
        root->left = deleteNode(root->left, key);
    //    root->size=siz(root->left)+siz(root->right)+1;
 	}
    // If the key to be deleted is greater than the
    // root's key, then it lies in right subtree
    else if( key > root->key )
    {
        root->right = deleteNode(root->right, key);
 	//    root->size=siz(root->left)+siz(root->right)+1;
 	}
    // if key is same as root's key, then This is
    // the node to be deleted
    else
    {
        // node with only one child or no child
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct Node *temp = root->left ? root->left :
                                             root->right;

            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
             *root = *temp; // Copy the contents of
                            // the non-empty child
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            struct Node* temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->key = temp->key;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
    //        root->size=siz(root->left)+siz(root->right)+1;
        }
    }

    // If the tree had only one node then return
    if (root == NULL)
      return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->left),height(root->right));
    root->size=siz(root->left)+siz(root->right)+1;

    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
    // check whether this node became unbalanced)
    int balance = getBalance(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int count (Node* curr, int val)
{
	if (curr==NULL)
		return 0;
	if (val> curr->key)
		return siz(curr->left)+1+count(curr->right,val);
	else if (val== curr->key)
		return siz(curr->left)+1;
	else
		return count(curr->left,val);

}

int main()
{
  fastio();
  int n;
  cin >>n;
  ll ans=0;
  int a[n];
  Node* root=NULL;
  /*loop (i,0,n)
  	cin >>a[i];
  for (int i=n-1; i>=0; i--)
  {
  	while (!pq.empty() && pq.top()<=i)
  		pq.pop();
  	if (a[i]<=i+1)
  		pq.push(mp(a[i],i+1));
  	else
  	{

  	}
  }
  */
  loop (i,1,n+1)
  {
  	while (!pq.empty() && pq.top().first<i)
  	{
  		pair <int,int> pp=pq.top();
  		pq.pop();
  		root=deleteNode(root,pp.second);
  	}
  	int x;
  	cin >>x;
  	ans+=count(root,x);
  	pq.push(mp(x,i));
  	root=insert(root,i);
  	//cout <<pq.top()<<nl;
  }

  cout <<ans<<nl;
}

/*
8
1 2 3 4 5 6 7 8
7 2 6 6 5 1 4 9
0 1 1 2 3 3 1 0=12
*/
