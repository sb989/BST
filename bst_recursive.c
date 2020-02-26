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

Node * insertRec(int value,Node *n)
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
    temp = insertRec(value,n->left);
    if(!n->left)
    {
      n->left = temp;
      temp->parent = n;
    }
    return n;
  }
  else if(n->value < value)
  {
    temp = insertRec(value,n->right);
    if(!n->right)
    {
      n->right = temp;
      temp->parent = n;
    }
    return n;
  }
}

void deleteRec(int value,Node *n)
{
  Node * temp,*parent;
  parent = n->parent; // parent of node n

  if(n->value == value)//do this if the values are equal
  {
    if(!n->left && !n->right)//if it has no children just delete the node
    {
      childToNull(n);//sets parents pointer to child to null
      deleteNode(n);//delete the node
    }

    else if(n->right)// as long as it has a right child do this
    {
      temp = findMinRec(n->right);//find the smallest node on the right side
      n->value = temp->value;//set this nodes value equal to that nodes value
      parent = temp->parent;
      if(temp->right)
      {//make parent point to right child; make right child point to parent
        parent->left = temp->right;
        //temp must be the parents left child;it is the smallest in the subtree
        temp->right->parent = parent;
      }
      else
      {
        childToNull(n);//sets parents pointer to child to null
      }
      deleteNode(temp);//delete the node for the smallest pointer
    }

    else// if the right child is null
    {
      if(n==parent->left)
      {
        parent->left = n->left;
      }
      else if(n==parent->right)
      {
        parent->right = n->left;
      }
      n->left->parent = parent;
      deleteNode(n);
    }

  }
  else if (n->value != value && !n->left && !n->right)
  {
    printf("value is not in tree.\n");
  }
  else if(n->value > value)
  {
    deleteRec(value,n->left);
  }
  else if(n->value < value)
  {
    deleteRec(value,n->right);
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
  Node * temp = binarySearchRec(root,value);
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

void printBstRec(Node *n)
{
  if(!n)
    return;
  printBstRec(n->left);
  printf("%d\n",n->value);
  printBstRec(n->right);
}
