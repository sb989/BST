#include "bst_recursive.h"

Node * binarySearchRec(Node *root,int value)
{
  if(root->value > value && root->left)
  {
    binarySearchRec(root->left,value);
  }
  else if(root->value < value && root->right)
  {
    binarySearchRec(root->right,value);
  }
  else if(root->value == value)
  {
    return root;
  }
  else
  {
    printf("%d is not in the tree\n",value);
    return NULL;
  }
}

Node * largerAncestorRec(Node *n,int value)
{
  if(n->value > value)
    return n;
  else if(n->value <= value && n->parent)
  {
    //printf("the value of n is %d the value of ns parent is %d\n",n->value,n->parent->value);
    return largerAncestorRec(n->parent,value);
  }
  else
  {
    printf("%d has no ancestor that is larger\n",value);
    return NULL;
  }
}

Node * smallerAncestorRec(Node *n,int value)
{
  if(n->value < value)
    return n;
  else if(n->value >= value && n->parent)
  {
    return smallerAncestorRec(n->parent,value);
  }
  else
  {
    printf("%d has not ancestor that is smaller\n",value);
    return NULL;
  }
}

Node * insertRec(Node *n,int value)
{
  Node * temp;
  //printf("inserting\n");
  if(!n)
  {
    n = newNode();
    //printf("creating new node\n");
    n->value = value;
    //printf("creatine value\n");
    return n ;
  }
  else if(n->value > value)
  {
    temp = insertRec(n->left,value);
    if(!n->left)
    {
      n->left = temp;
      temp->parent = n;
    }
    return n;
  }
  else if(n->value < value)
  {
    temp = insertRec(n->right,value);
    if(!n->right)
    {
      n->right = temp;
      temp->parent = n;
    }
    return n;
  }
}

Node * deleteRec(Node *root,int value)
{
  Node * temp,*parent,*n;
  parent = root->parent; // parent of node n

  if(root->value == value)//do this if the values are equal
  {
    if(!root->left && !root->right)//if it has no children just delete the node
    {

      //root->parent = childToNull(root);//sets parents pointer to child to null
      deleteNode(root);//delete the node
      return NULL;
    }

    else if(root->right)// as long as it has a right child do this
    {
      temp = findMinRec(root->right);//find the smallest node on the right side
      //printf("smallest val is %d\n",temp->value);
      //set this nodes value equal to that nodes value
      //parent = temp->parent;
      if(temp->right)
      {//make parent point to right child; make right child point to parent
        //temp must be the parents left child;it is the smallest in the subtree
        printf("has right");
        if(isRightChild(temp))
          temp->parent->right = temp->right;
        if(isLeftChild(temp))
          temp->parent->left = temp->right;
        temp->right->parent = temp->parent;

        root->value = temp->value;
        deleteNode(temp);//delete the node for the smallest pointer
        return root;
      }
      else
      {
        root->right = childToNullRec(root,temp);
        root->value = temp->value;
        deleteNode(temp);
        return root;//sets parents pointer to child to null
      }


    }

    else if(!root->right)// if the right child is null
    {
      temp = root->left;
      if(isLeftChild(root))
      {
        parent->left = root->left;
      }
      else if(isRightChild(root))
      {
        parent->right = root->left;
      }
      root->left->parent = parent;
      deleteNode(root);
      return temp;
    }

  }
  else if(root->value > value)
  {
      root->left = deleteRec(root->left,value);
      return root;
  }
  else if(root->value<value)
  {
    root->right = deleteRec(root->right,value);
    return root;
  }
  else
  {
    printf("value not in tree\n");
  }
}

Node * findNextRec(Node *root,int value)
{
  Node *temp,*ancestor;
  temp = binarySearchRec(root,value);
  if(temp)
  {
    if(temp->right)
    {
      return findMinRec(temp->right);
    }
    else if(temp->parent && isLeftChild(temp))
    {
      return temp->parent;
    }
    else if(temp->parent && isRightChild(temp))
    {
      ancestor = largerAncestorRec(temp,temp->value);
      if(ancestor)
        return ancestor;
      else
      {
        printf("%d does not have a successor in this tree.\n",value);
        return NULL;
       }
    }
    else
    {
      printf("%d does not have a successor in this tree.\n",value);
      return NULL;
    }
  }
  else
  {
    printf("%d does not have a successor in this tree.\n",value);
    return NULL;
  }
}

Node * findPrevRec(Node *root,int value)
{
  Node * temp,*ancestor;
  temp = binarySearchRec(root,value);
  if(temp)
  {
    if(temp->left)
    {
      return findMaxRec(temp->left);
    }
    else if(temp->parent && isRightChild(temp))
    {
      return temp->parent;
    }
    else if(temp->parent && isLeftChild(temp))
    {
      ancestor = smallerAncestorRec(temp,temp->value);
      if(ancestor)
        return ancestor;
      else
      {
        printf("%d does not have a predecessor in this tree.\n",value);
        return NULL;
      }
    }
    else
    {
      printf("%d does not have a predecessor in this tree.\n",value);
      return NULL;
    }
  }
  else
  {
    printf("%d does not have a predecessor in this tree.\n",value);
    return NULL;
  }

}

Node *findMinRec(Node *n)
{
  if(!n->left)
  {
    return n;
  }
  else
  {
    return findMinRec(n->left);
  }
}

Node *findMaxRec(Node *n)
{
  if(!n->right)
  {
    return n;
  }
  else
  {
    return findMaxRec(n->right);
  }
}

Node * childToNullRec(Node * root,Node *n)
{
  Node * temp;
  //printBstRec(root);
  //printf("\n");
  if(root->left->value == n->value)
  {
    root->left = NULL;
    return root;
  }
  else if(root->right->value == n->value)
  {
    root->right = NULL;
    return root;
  }
  else if(root->value > n->parent->value)
  {
    //printBstRec(root);
    //printf("\n");
    temp = childToNullRec(root->left,n);
    //printBstRec(temp);
    //printf("\n");
    return temp;
  }
  else if(root->value < n->parent->value)
  {
    //printBstRec(root);
    //printf("\n");
    temp = childToNullRec(root->right,n);
    //printBstRec(temp);
    //printf("\n");
    return temp;
  }
}

void printBstRec(Node *n)
{
  if(!n)
    return;

  printBstRec(n->left);
  printf("%d\n",n->value);
  printBstRec(n->right);

}

void printLevelOrder(Node *root)
{
  int h,i;
  h = height(root);
  for(i=0;i<=h;i++)
  {
    printLevel(root,i);
    printf("\n");
  }
}

void printLevel(Node *root,int level)
{
  if(!root)
  {
    return;
  }
  if(level == 0)
  {
    printf("%d ",root->value);
  }
  else if(level>0)
  {
    printLevel(root->left,level-1);
    printLevel(root->right,level-1);
  }

}
