#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *nextptr;
};
typedef struct Node node;
typedef node *nodeptr;
int DeleteNode(int data);
void InsertNode(int data);
void Display(void);
Node* root = NULL;
int main()
{
    size_t i=0;
    while (1)
    {
        cout << "Please select an option:" << endl
        << "1.Insert a node" << endl
        << "2.Delete a node" << endl
        << "3.Display the list" << endl
        << "4.End" << endl;
        cin >> i;
        int data;
        switch(i)
        {
            case 1:
                cout << "Please enter the number:" << endl;
                cin >> data;
                InsertNode(data);
                break;
            case 2:
                cout << "Please enter the number:" << endl;
                cin >> data;
                if ( !DeleteNode(data))
                cout << "Failed to delete node " << data << endl;
                break;
            case 3:
                Display();
                break;
            case 4:
                return 0;
            default:
                break;
        }
    }
    return 0;
}
void InsertNode(int data)
{
    nodeptr newptr;
    nodeptr previousptr;
    nodeptr currentptr;
    newptr= new node;
    if(newptr!=NULL)
    {
        newptr->data=data;
        newptr->nextptr=NULL;
        previousptr=NULL;
        currentptr=root;
        while(currentptr!=NULL)
        {
            previousptr=currentptr;
            currentptr=currentptr->nextptr;
        }
        if(previousptr==NULL)
        {
            newptr->nextptr=root;
            root=newptr;
        }
        else
        {
            previousptr->nextptr=newptr;
            newptr->nextptr=currentptr;
        }
    }
    else
    {
        cout<<data<<"not inserted"<<endl;
    }
}
int DeleteNode(int data)
{
    nodeptr tempptr;
    nodeptr previousptr;
    nodeptr currentptr;
    if(root==NULL)
    {
        return 0;
    }
    if(data==(root)->data)
    {
        tempptr=root;
        root=(root)->nextptr;
        return 1;
    }
    else
    {
        previousptr=root;
        currentptr=(root)->nextptr;
        while(currentptr!=NULL&&currentptr->data!=data)
        {
             previousptr=currentptr;
             currentptr=currentptr->nextptr;
        }
        if(currentptr!=NULL)
        {
            tempptr=currentptr;
            previousptr->nextptr=currentptr->nextptr;
            return 1;
        }
        else
        {
            return 0;
        }
    }
            
}
void Display(void)
{
    nodeptr currentptr;
    currentptr=root;
    if(currentptr==NULL)
    {
        cout<<"link is empty";
    }
    else
    {
        while(currentptr!=NULL)
        {
            cout<<currentptr->data<<"->";
            currentptr=currentptr->nextptr;
        }
        cout <<"\n";
    }
}
