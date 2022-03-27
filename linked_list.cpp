
#include<iostream>
#include<string>
using namespace std;
struct Node
{
	int value;
	Node* next;
};
class linked_List {

	Node* first, * last;
	int length;
public:
	linked_List() {
		first = last = NULL;
		length = 0;
	}
	bool IsEmpty();
	void insertFirst(int val);
	void insertLast(int val);
	void insertAtPos(int val, int pos);
	void create_or_insert(int val, int choice);
	void display();
	int size();
};
linked_List l;
int main() {
	int choice = 0;
	do
	{
		cout << "choose what to do :-\n";
		cout << "1- create or insert an  element.\n";
		cout << "2- Is The list empty or not.\n";
		cout << "3- Display the list.\n";
		cout << "4- stop and exit\n";
		cout << "\n******************\n\n";
		cin >> choice;
		cout<<"\n";
		while (choice < 1 || choice>4) {
				cout << "vaild choice !! try again\n";
				cin >> choice;
			} 
		switch (choice)
		{
		case(1):
		{  int insertoption,value;
			cout << "1- insert at first\t2- insert at last\t 3- insert at postion\n";
			cin >> insertoption;
				cout << "Enter The value:-\n";
				cin >> value;
				l.create_or_insert(value, insertoption);
			break;
		}
		case(2):
		{
			if (l.IsEmpty())
				cout << "The list is empty\n";
			else
				cout << "The list is not empty and has " << l.size() << " of elements\n";
			break;
		}
		case(3):
			l.display();
			break;
		}
	} while (choice != 4);
	cout << "Thank You!\n";
	return 0;
}
void linked_List::create_or_insert(int val, int choice) {
	int insertpos; // which postion to insert
	switch (choice)
	{
	case(1):
	{
		l.insertFirst(val);
		break;
	}
	case(2):
	{
		l.insertLast(val);
		break;
	}
	case(3):
	{
		cout << "enter which postion please:\n";
		cin >> insertpos;
		l.insertAtPos(val, insertpos);
		break;
	}
	}
}
bool linked_List::IsEmpty()
{
	return first == NULL;
}
void linked_List::insertFirst(int val)
{
	Node* newNode = new Node;
	newNode->value = val;
	if (first == NULL)
	{
		first = last = newNode;
		newNode->next = NULL;
	}
	else {
		newNode->next = first;
		first = newNode;
	}
	length++;
	cout << "you added item at first sucessfully!The list is now  " << l.size() << " of elements\n";

}

void  linked_List::insertLast(int val)
{
	Node* newNode = new Node;
	newNode->value = val;
	if (first == NULL) {
		first = last = newNode;
		newNode->next = NULL;
	}
	else
	{
		last->next = newNode;
		newNode->next = NULL;
		last = newNode;
	}
	length++;
	cout << "you added item at last sucessfully!The list is now  " << l.size() << " of elements\n";
}
void linked_List::insertAtPos(int val, int pos) {
	if (pos<0 || pos>length )
		cout << pos << " Out of Range\n";
	else {
		Node* newNode = new Node;

		newNode->value = val;

		if (length == 0)
			insertFirst(val);
		else if (pos == length)
			insertLast(val);
		else
		{
			Node* temp = first;
			for (int i = 1; i < pos ; i++)
				temp = temp->next;
			newNode->next = temp->next;
			temp->next = newNode;
		}
		length++;
		cout << "you added item at " << pos << " sucessfully!The list is now  " << l.size() << " of elements\n";
	}
}
void linked_List::display()
{
	Node* cur = first;		//current element to print 
	while (cur != NULL)
	{
		cout << cur->value << " ";
		cur = cur->next;
	}
	cout << endl;
}
int linked_List::size()
{
	return length;
}
