#include <iostream>

using namespace std;

typedef struct node
{
  int data;
  node* link;
} node;

node *p = NULL;
node *q = NULL;
node *root = NULL;

int pos = -1;

class QList
{
  int num;
  
  public:

  void create()
  {
    char choice = 'y';
    int n;
    p = new node;
    root = p;

    while (choice != 'n')
    {
      cout << "Enter a number: ";
      cin >> n;
      p->data = n;
      
      q = new node;
      p->link = q;
      p = q;

      cout << "Do you want to create new nodes? (y/n): ";
      cin >> choice;
      p->link = NULL;
    }
  }

  void deleteAtPosition()
  {
    cout << "Enter a position to delete: ";
    cin >> pos;
    p = root;

    while (pos > 2)
    {
      p = p->link;
      pos--;
    }

    if (pos == 1)
    {
      p = p->link;
      root = p;
    }
    else p->link = p->link->link;
  }

  void insertAtPos()
  {
    cout << "Enter your position: ";
    cin >> pos;

    p = root;

    while (pos > 2)
    {
      p = p->link;
      pos--;
    }

    q = new node;
    cout << "Enter a number: ";
    cin >> num;
    q->data = num;
    q->link = p->link;
    p->link = q;
  }

  void display()
  {
    if (p == NULL)
    {
      cout << "The list is empty\n";
      system("pause");
      return;
    }

    p = root;

    cout << "The available nodes are:\n";

    while (p->link != NULL)
    {
      cout << p->data << " ";
      p = p->link;
    }

    cout << '\n';
    system("pause");
  }

  void insertAtBeg()
  {
    cout << "Enter a number: ";
    cin >> num;

    p = new node;
    p->link = root;
    p->data = num;
    root = p;
  }

  void insertAtEnd()
  {
    cout << "Enter a number: ";
    cin >> num;

    p = root;

    while (p->link != NULL)
    {
      p = p->link;
    }

    q = new node;
    p->link = q;
    p->data = num;
    q->link = NULL;
  }

};

int main()
{
  QList listOne;
  int choice = 0;

  do
  {
    system("cls");

    cout << "Linked List Operations\n";
    cout << "\t1. Create new nodes\n";
    cout << "\t2. Insert at beginning\n";
    cout << "\t3. Insert at end\n";
    cout << "\t4. Insert at specific position\n";
    cout << "\t5. Display\n";
    cout << "\t6. Delete\n";
    cout << "\t7. Exit\n";

    cout << "Please make your choice: ";
    cin >> choice;

    switch (choice)
    {
      case 1:
        listOne.create();
        break;
      case 2:
        listOne.insertAtBeg();
        break;
      case 3:
        listOne.insertAtEnd();
        break;
      case 4:
        listOne.insertAtPos();
        break;
      case 5:
        listOne.display();
        break;
      case 6:
        listOne.deleteAtPosition();
        break;
      case 7:
        cout << "Exiting...\n";
        break;
      default:
        cout << "Invalid choice, please try again.\n";
        break;
    }
  } while (choice != 7);

  return 0;
}