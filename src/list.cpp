#include "list.h"
Node::Node()
{
	data = NULL;
	next = NULL;
}
List::List()
{
	head = NULL;
}
List::~List()
{
	Node*tmp1 = head, *tmp2;
	if (head != NULL)
	{
		while (tmp1 != NULL)
		{
			tmp2 = tmp1->next;
			delete tmp1;
			tmp1 = tmp2;
		}
	}

}
  List::List(const List& list2)
  {
	  if (list2.head != NULL)
	  {
		head = new Node (list2.head->data,list2.head->next);
		Node *tmp = head;
		Node *tmp2 = list2.head->next;
		while (tmp2 != NULL)
		{
			tmp->next = new Node(tmp2->data, tmp2->next);
			tmp = tmp->next;
			tmp2 = tmp2->next;
		}
	  }
	  else
		  head = NULL;
 }
   Node& Node::operator=(const Node& node2)
   {
	   if(this!=&node2)
	   {
		   data = node2.data;
		   next = node2.next;
	   }
	   return *this;
	   
   }
   bool Node::operator==(const Node& node2) const
   {
	   if (data != node2.data)
		   return false;
	   else return true;
   }
   bool List::operator==(const List& list2) const
   {
	   Node *tmp1 = head, *tmp2 = list2.head;
	   bool f = true;
	   while (tmp1 && tmp2 && f)
	   {
		   if (tmp1->data != tmp2->data)
			   return false;
		   tmp1 = tmp1->next;
		   tmp2 = tmp2->next;
	   }
	   if (tmp1 || tmp2)
		   return false;
	   return f;

   }
   List& List::operator=(const List& list2)
   {
	   if (this != &list2)
	   {
		   Clean();
		   if (list2.head == NULL)
		   {
			   head = NULL;
		   }
		   else
		   {
			   head = new Node (list2.head->data,list2.head->next);
			   Node *tmp = head;
			   Node *tmp2 = list2.head->next;
			   while (tmp2 != NULL)
			   {
				   tmp->next = new Node(tmp2->data, tmp2->next);
				   tmp = tmp->next;
				   tmp2 = tmp2->next;
			   }
		   }
	   }
	   return *this;
   }
 void List::InsertToHead(const DataType& d)
 {
	 Node* tmp = head;
	 head = new Node (d,tmp);
 }
  void List::InsertToTail(const DataType& d)
  {
	  Node*tmp = head;
	  if (head==NULL)
		  head = new Node(d,NULL);
	  else
		  {
			  while (tmp->next!=NULL)
			  {
				  tmp=tmp->next;
			  }
			  tmp->next = new Node(d,NULL);
	      }
	  
  }
  void List::InsertAfter(Node* node, const DataType& d)
  {
	  if (head == NULL)
		  throw "Can't insert to empty list.";
	  if (node!=NULL)
	  {
		
	  Node*tmp = head;
	  while (tmp!=node)
	  {
		  tmp=tmp->next;
	  }
	  tmp->next = new Node(d,tmp->next);
	  }

  } 
  void List::Delete(const DataType& d)
  {
	  Node* tmp = head, *prev=NULL;
	  if (tmp != NULL)
	  {
	  while ((tmp != NULL)&&(tmp->data!=d))
	  {
		  prev = tmp;
		  tmp = tmp->next;
	  }
	  if(tmp!=NULL)
	  {
		  if(prev!=NULL)
			  prev->next = tmp->next; 
		  else 
			  head = tmp->next; 
		  delete tmp;
	  }
	  }
	  
  }
  Node* List::Search(const DataType& d)
  {
	  Node* tmp = head;
	  while (tmp!=NULL)
	  {
		  if(tmp->data==d)
			  return tmp;
		  else
		  {
			  tmp = tmp->next;
		  }
	  }
	  return tmp;
  }
  void List::Clean()
  {
	  if (head == NULL)
		  return;
	  Node *tmp = head, *n;
	  while (tmp->next != NULL)
	  {
		  n = tmp->next->next;
		  delete tmp->next;
		  tmp->next = n;
	  }
	  delete tmp;
	  head = NULL;
  }
  int List::GetSize()
  {
	  int size=0;
	  Node* tmp = head;
	  while (tmp!=NULL)
	  {
		   size+=1;
		  tmp=tmp->next; 
	  }
	  return size;
  }
  Node* List::GetHead() { return head;}
  void List::Inverse()
  {
	  if ((head == NULL) || (head->next == NULL))
		  return;
	  Node *tmp = head;
	  Node* head2;
	  head2 = new Node(tmp->data, NULL);
	  tmp = tmp->next;
	  while (tmp != NULL)
	  {
		  head2 = new Node(tmp->data, head2);
		  tmp = tmp->next;
	  }
	  Clean();
	  head = head2;
  }
  List List::Merge(Node* node, const List& list2)
  {
	  if (head != NULL)
	  {
		  List list3;
		  list3.head = new Node(head->data, NULL);
		  Node* tmp = list3.head;
		  Node* tmp1 = head;
		  
		  while ((tmp1->next!=NULL) && (tmp1 != node))
		  {
			  tmp->next = new Node(tmp1->next->data, NULL);
			  tmp = tmp->next;
			  tmp1 = tmp1->next;
		  }
		  if (node != NULL)
		  {
			  Node* tmp2 = list2.head;
			  while (tmp2 != NULL)
			  {
				  tmp->next = new Node(tmp2->data,NULL);
				  tmp = tmp->next;
				  tmp2 = tmp2->next;
			  }
			  while (tmp1->next!=NULL)
			  {
				  tmp->next = new Node(tmp1->next->data, NULL);
				  tmp = tmp->next;
				  tmp1 = tmp1->next;
			  }
		  }
		  return list3;
	  }
	  else
	  {
		  List l3(list2);
		  return l3;
	  }
	  
  }  
  List List::Merge(const List& list2)
  {
	  if (head != NULL)
	  {
		  if (list2.head == NULL)
			  return *this;
		  List list3(*this);
		  Node* tmp = list3.head, *tmp2 = list2.head;
		  while (tmp->next != NULL)
		  {
			  tmp = tmp->next;
		  }
		  tmp->next = new Node(list2.head->data,NULL);
		  tmp = tmp->next;
		  tmp2 = tmp2->next;
		  while (tmp2)
		  {
			  tmp->next = new Node(tmp2->data, NULL);
			  tmp = tmp->next;
			  tmp2 = tmp2->next;
		  }
		  return list3;
	  }
	  else
	  {
		  List l3(list2);
		  return l3;
	  }
  }
  ostream& operator<<(ostream& os, const List& l)
  {
	  List list;
	  Node*tmp = list.head;
	  while (tmp != NULL)
	  {
		  cout << tmp->data << " ";
		  tmp = tmp->next;
	  }
	  return os;

  }
