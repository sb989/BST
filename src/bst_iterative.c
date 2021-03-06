#include "bst_iterative.h"

static int count = 0;

Node * insertIter(Node *root,int value)
{
  Node *parent,*curr;
  if(root)
    parent = root->parent;
  else
    parent = NULL;
  curr = root;
  while(1)
  {
    if(!curr)
    {
      curr = newNode();
      curr->parent = parent;
      if(parent)
      {
        if(parent->value > value)
        {
          parent->left = curr;
        }
        else if(parent->value < value)
        {
          parent->right = curr;
        }
      }

      curr->value = value;
      if(!root)// if the root given is null return the curr node
        return curr;// only happens when the first element is added
      break;
    }
    if(curr->value > value)
    {
      parent = curr;
      curr = curr->left;
      count = count +1;
    }
    else if(curr->value < value)
    {
      parent = curr;
      curr = curr->right;
      count = count +1;
    }
  }
  //printf("count for bst iterative is %d\n",count);
  return root;
}

int getBstCount()
{
  return count;
}

void setBstCount(int c)
{
  count = c;
}

Node * deleteIter(int value,Node *n)
{
  Node * curr,*parent,*temp;
  if(!n)
    return NULL;
  if(n->parent)
    parent = n->parent;
  curr = n;
  while(1)
  {
    if(curr->value == value)
    {
      if(!curr->left && !curr->right)
      {
        if(isLeftChild(curr))
          parent->left = NULL;
        else if(isRightChild(curr))
          parent->right = NULL;
        deleteNode(curr);
        break;
      }
      else if(curr->right)
      {
        temp = findMinIter(curr->right);
        if(temp->right)
        {
          if(isRightChild(temp))
            temp->parent->right = temp->right;
          if(isLeftChild(temp))
            temp->parent->left = temp->right;
          temp->right->parent = temp->parent;
          curr->value = temp->value;
          deleteNode(temp);
          break;
        }
        else
        {
          if(isRightChild(temp))
            temp->parent->right = NULL;
          else if(isLeftChild(temp))
            temp->parent->left =NULL;
          curr->value = temp->value;
          deleteNode(temp);
          break;
        }
      }
      else if(!curr->right)
      {
        temp = curr->left;
        if(isLeftChild(curr))
        {
          curr->parent->left = curr->left;
        }
        else if(isRightChild(curr))
        {
          curr->parent->right = curr->left;
        }
        curr->left->parent = curr->parent;
        deleteNode(curr);

      }
    }
    else if(curr->value >value)
    {
      curr = curr->left;
    }
    else if(curr->value < value)
    {
      curr = curr->right;
    }
    else
    {
      printf("value not in tree \n");
      break;
    }
  }
  return n;
}

Node * findNextIter(Node * root, int value)
{
    Node *curr,*ancestor;
    curr = root;
    while(1)
    {
      if(curr->value == value)
      {
        if(curr->right)
        {
          return findMinIter(curr->right);
        }
        else if(curr->parent && isLeftChild(curr))
        {
          return curr->parent;
        }
        else if(curr->parent && isRightChild(curr))
        {
          ancestor = largerAncestorIter(curr,value);
          if(ancestor)
            return ancestor;
          else
            return NULL;
        }
        else
        {
          printf("%d does not have a successor in this tree\n",value);
          return NULL;
        }
      }
      else if(curr->value < value)
      {
        if(curr->right)
          curr = curr->right;
        else
        {
          printf("%d does not have a successor in this tree\n",value);
          return NULL;
        }
      }
      else if(curr->value > value)
      {
        if(curr->left)
          curr = curr->left;
        else
        {
          printf("%d does not have a successor in this tree\n",value);
          return NULL;
        }
      }

    }
    //return root;
}

Node * smallerAncestorIter(Node *n, int value)
{
  Node *curr;
  curr = n;
  while(1)
  {

    if(curr->value < value)
    {
      return curr;
    }
    else if(curr->value >= value && curr->parent)
    {
      curr = curr->parent;
    }
    else
    {
      printf("%d has no ancestor that is smaller\n",value);
      return NULL;
    }
  }
}

Node * findPrevIter(Node * root,int value)
{
  Node * curr,*ancestor;
  curr = root;
  while(1)
  {
    if(curr->value == value)
    {
      if(curr->left)
      {
        return findMaxIter(curr->left);
      }
      else if(curr->parent && isRightChild(curr))
      {
        return curr->parent;
      }
      else if(curr->parent && isLeftChild(curr))
      {
        ancestor = smallerAncestorIter(curr,curr->value);
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
    else if(curr->value > value)
    {
      curr = curr->left;
    }
    else if(curr->value < value)
    {
      curr = curr->right;
    }
    else
    {
      printf("%d does not have a predecessor in this tree.\n",value);
      return NULL;
    }

  }
}

Node * largerAncestorIter(Node *n,int value)
{
  Node *curr;
  curr = n;
  while(1)
  {
    if(curr->value >value)
    {
      return curr;
    }
    else if(curr->value <= value && curr->parent)
    {
      curr = curr->parent;
    }
    else
    {
        printf("%d has no ancestor that is larger\n",value);
        return NULL;
    }
  }
  return curr;
}

Node * findMinIter(Node *n)
{
  Node * curr,*parent;
  curr = n;
  parent=NULL;
  while(curr)
  {
    parent = curr;
    curr = curr->left;
  }
  return parent;
}

Node * findMaxIter(Node *n)
{
  Node * curr,*parent;
  curr = n;
  parent=NULL;
  while(curr)
  {
    parent = curr;
    curr = curr->right;
  }
  return parent;
}
