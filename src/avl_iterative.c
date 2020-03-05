#include "avl_iterative.h"

static int count = 0;

Node * avlInsertIter(Node * root,int value)
{
  Node *parent,*curr;

  //count = 0;
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
      if(!root) // if the root given is null return the curr node
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
  root = insertBalance(curr);
  return root;
}

int getAvlCount()
{
  return count;
}

void setAvlCount(int c)
{
  count = c;
}

Node * avlDeleteIter(Node *n,int value)
{

    Node * curr,*parent,*temp;
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
  n = deleteBalance(curr);
  return n;
}

Node * insertBalance(Node *root)
{
  Node * curr,*child,*grandchild;
  curr = root;
  child = curr;
  grandchild = curr;
  int bf;
  while(curr)
  {
      bf = balanceFactor(curr);
      if(bf<=1 && bf>=-1 && curr->parent)
      {
        grandchild = child;
        child = curr;
        curr = curr->parent;
        continue;
      }
      else if(bf<=1 && bf>=-1 && !curr->parent)
      {
        break;
      }
      else
      {
        curr = avlBalance(curr,child,grandchild);
        break;
      }
  }
  while(curr->parent)
    curr = curr->parent;

  return curr;
}

Node *deleteBalance(Node * root)
{
  Node * curr,*child,*grandchild;
  curr = root;
  child = curr;
  grandchild = curr;
  int bf;
  while(curr)
  {
      bf = balanceFactor(curr);
      if(bf<=1 && bf>=-1 && curr->parent)
      {
        grandchild = child;
        child = curr;
        curr = curr->parent;
        continue;
      }
      else if(bf<=1 && bf>=-1 && !curr->parent)
      {
        break;
      }
      else
      {
        if(child ==curr || grandchild == curr)
        {
          if(bf > 0)
            child = curr->left;
          else
            child = curr->right;
          if(balanceFactor(child)>0)
            grandchild = child->left;
          else
            grandchild = child->right;

        }
        curr = avlBalance(curr,child,grandchild);
        //break;
      }
  }
  while(curr->parent)
    curr = curr->parent;

  return curr;

}

Node *avlBalance(Node * curr,Node * child,Node * grandchild)
{
  if(isLeftChild(child))
  {
    if(isLeftChild(grandchild))//left left case
    {
      curr = rotateRight(curr);
    }
    else//left right case
    {
      curr->left = rotateLeft(child);
      curr = rotateRight(curr);
    }
  }
  else
  {
    if(isLeftChild(grandchild))//right left case
    {
      curr->right = rotateRight(child);
      curr = rotateLeft(curr);
    }
    else//right right case
    {
      curr = rotateLeft(curr);
    }
  }
  return curr;
}


Node * rotateRight(Node * r)
{
  Node *parent,*t,*child;
  child = r->left;
  parent = r->parent;
  if(parent)
  {
    if(isLeftChild(r))
    {
      parent->left = child;
    }
    else if(isRightChild(r))
    {
      parent->right = child;
    }
  }

  t = child->right;
  child->right = r;
  r->left = t;
  r->parent = child;
  if(t)
    t->parent =r;
  child->parent = parent;
  return child;
}

Node * rotateLeft(Node *r)
{
  Node *parent,*t,*child;
  child = r->right;
  parent = r->parent;
  if(parent)
  {
    if(isLeftChild(r))
    {
      parent->left = child;
    }
    else if(isRightChild(r))
    {
      parent->right = child;
    }
  }

  t = child->left;
  child->left = r;
  r->right = t;
  r->parent = child;
  if(t)
    t->parent =r;
  child->parent = parent;
  return child;
}


int balanceFactor(Node *root)
{
  int left,right;
  left = height(root->left);
  right = height(root->right);
  //printf("the left height is %d the right height is %d \n",left,right);
  return (left - right);
}
