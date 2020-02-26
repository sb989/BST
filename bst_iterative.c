

void insertIter(value,Node *n)
{
  Node *parent,*curr;
  parent = n->parent;
  curr = n;
  while(true)
  {
    if(!curr)
    {
      curr = newNode();
      curr->parent = parent;
      if(parent->value > value)
      {
        parent->left = value;
      }
      else if(parent->value < value)
      {
        parent->right = value;
      }
      curr->value = value;
      break;
    }
    if(curr->value > value)
    {
      parent = curr;
      curr = curr->left;
    }
    else if(curr->value < value)
    {
      parent = curr;
      curr = curr->right;
    }
  }
}
