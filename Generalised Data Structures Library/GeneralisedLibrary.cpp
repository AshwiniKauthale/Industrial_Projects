///////////////////////////////////////////////////
//       Generalized Data Structure Library
///////////////////////////////////////////////////


/*
----------------------------------------------------------------------------------------------------
Type                    Name of class for node                  Name of class for Functionality
----------------------------------------------------------------------------------------------------
Singly Linear           SinglyLLLnode                            SinglyLLL           Done
Singly Circuler         SinglyCLLnode                            SinglyCLL           Done
Doubly Linear           DoublyLLLnode                            DoublyLLL           Done
Doubly Circuler         DoublyCLLnode                            DoublyCLL           Done
Stack                   Stacknode                                Stack               Done
Queue                   Queuenode                                Queue               Done
BST                     BSTnode                                  BinarySearchTree    Done
----------------------------------------------------------------------------------------------------
*/


#include<iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////////
//         Singly Linear Linked List using Generic Approach
//////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class SinglyLLLnode
{
    public:
        T data;
        SinglyLLLnode<T> *next;

        SinglyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class SinglyLLL
{
    private:
        SinglyLLLnode<T>* first;
        int iCount;

    public:
        SinglyLLL();

        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T,int);
        void DeleteAtPos(int);
};

template<class T>
SinglyLLL<T> :: SinglyLLL()
{
    cout<<"Object of SinglyLL gets created.\n";
    this->first = NULL;
    this->iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    InsertFirst
//    Input :            Data of node
//    Output :           Nothing
//    Description :      Use to insert node at first position
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: InsertFirst(T no)
{
    SinglyLLLnode<T>* newn = NULL;

    newn = new SinglyLLLnode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    InsertLast
//    Input :            Data of node
//    Output :           Nothing
//    Description :      Use to insert node at last position
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: InsertLast(T no)
{
    SinglyLLLnode<T>* newn = NULL;
    SinglyLLLnode<T>* temp = NULL;

    newn = new SinglyLLLnode<T>(no);

    if(this->iCount == 0)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
    this->iCount++;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    DeleteFirst
//    Input :            Nothing
//    Output :           Nothing
//    Description :      Use to delete node at first position
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: DeleteFirst()
{
    SinglyLLLnode<T>* temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        this->first = this->first -> next;
        delete temp;
    }

    this->iCount--;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    DeleteLast
//    Input :            Nothing
//    Output :           Nothing
//    Description :      Use to delete node at last position
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: DeleteLast()
{
    SinglyLLLnode<T>* temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }

        delete temp->next;
        temp->next = NULL;

    }
    this->iCount--;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    Display
//    Input :            Nothing
//    Output :           Nothing
//    Description :      Use to display node from linked list
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: Display()
{
    SinglyLLLnode<T>* temp = NULL;
    int iCnt = 0;

    temp = this->first;

    cout<<"\n";
    for(iCnt = 1; iCnt <= this->iCount; iCnt++)
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp->next;
    }

    cout<<"NULL\n";
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    Count
//    Input :            Nothing
//    Output :           Nothing
//    Description :      Use to count nodes of linked list
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyLLL<T> :: Count()
{
    return this->iCount;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    InsertAtPos
//    Input :            Data of node and position of node
//    Output :           Nothing
//    Description :      Use to insert node at given position
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: InsertAtPos(T no, int pos)
{
    SinglyLLLnode<T>* temp = NULL;
    SinglyLLLnode<T>* newn = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount + 1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyLLLnode<T>(no);

        temp = this->first;
        
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    DeleteAtPos
//    Input :            Position of node
//    Output :           Nothing
//    Description :      Use to delete node from given position
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: DeleteAtPos(int pos)
{
    SinglyLLLnode<T>* temp = NULL;
    SinglyLLLnode<T>* target = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;
        
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}


//////////////////////////////////////////////////////////////////////////////
//       Doubly Linear Linked List using Generic Approach
//////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class DoublyLLLnode
{
    public:
        T data;
        DoublyLLLnode *next;
        DoublyLLLnode * prev;

        DoublyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};
template<class T>
class DoublyLLL
{
    private:
        DoublyLLLnode<T> *first;
        int iCount;

    public:
        DoublyLLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

template<class T>
DoublyLLL<T>:: DoublyLLL()
{
    cout<<"Linked list gets created\n";
    this->first = NULL;
    this->iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    InsertFirst
//    Input :            Data of node
//    Output :           Nothing
//    Description :      Use to insert node at first position
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: InsertFirst(T no)
{
    DoublyLLLnode<T> *newn = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }
    this->iCount++;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    InsertLast
//    Input :            Data of node
//    Output :           Nothing
//    Description :      Use to insert node at last position
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T>:: InsertLast(T no)
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }
    this->iCount++;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    InsertAtPos
//    Input :            Data of node and position of node
//    Output :           Nothing
//    Description :      Use to insert node at given position
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T>:: InsertAtPos(T no,int pos)
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;

    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount + 1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount + 1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyLLLnode<T>(no);
        temp = this->first;

        for(iCnt = 1; iCnt < pos -1;iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    DeleteFirst
//    Input :            Nothing
//    Output :           Nothing
//    Description :      Use to delete node at first position
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: DeleteFirst()
{
    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        this->first = this->first->next;
        delete this->first->prev;
        this->first->prev = NULL;
    }
    this->iCount--;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    DeleteLast
//    Input :            Nothing
//    Output :           Nothing
//    Description :      Use to delete node at last position
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> ::DeleteLast()
{
    DoublyLLLnode<T> *temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    this->iCount--;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    DeleteAtPos
//    Input :            Position of node
//    Output :           Nothing
//    Description :      Use to delete node from given position
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: DeleteAtPos(int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    int iCnt = 0;
    if((pos < 1) || (pos > this->iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos -1;iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        this->iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    Display
//    Input :            Nothing
//    Output :           Nothing
//    Description :      Use to display node from linked list
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> ::Display()
{
    DoublyLLLnode<T> *temp = NULL;
    temp = this->first;

    cout<<"\nNULL<=>";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    Count
//    Input :            Nothing
//    Output :           Nothing
//    Description :      Use to count nodes of linked list
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyLLL<T> :: Count()
{
    return this->iCount;
}

//////////////////////////////////////////////////////////////////////////////
//        Singly Circuler Linked List using Generic Approach
//////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class SinglyCLLnode
{
    public:
        T data;
        SinglyCLLnode<T> *next;

        SinglyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class SinglyCLL
{
    private:
        SinglyCLLnode<T> * first;
        SinglyCLLnode<T> * last;
        int iCount;

    public:
        SinglyCLL();
        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void DeleteAtPos(int pos);
        void InsertAtPos(T, int pos);
};

template <class T>
SinglyCLL<T>::SinglyCLL()
{
    cout<<"Object of SinglyCLL gets created\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    InsertFirst
//    Input :            Data of node
//    Output :           Nothing
//    Description :      Use to insert node at first position
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    SinglyCLLnode<T> * newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;

        last->next = first;
    }
    else
    {
        newn->next = first;
        first = newn;

        last->next = first;
    }

    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    InsertLast
//    Input :            Data of node
//    Output :           Nothing
//    Description :      Use to insert node at last position
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::InsertLast(T no)
{
    SinglyCLLnode<T> * newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;

        last->next = first;
    }
    else
    {
        last->next = newn;
        last = newn;

        last->next = first;
    }

    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    DeleteFirst
//    Input :            Nothing
//    Output :           Nothing
//    Description :      Use to delete node at first position
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;

        first = NULL;
        last = NULL;
    }
    else
    {
        first = first -> next;
        delete last->next;

        last->next = first;
    }
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    DeleteLast
//    Input :            Nothing
//    Output :           Nothing
//    Description :      Use to delete node at last position
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::DeleteLast()
{
    SinglyCLLnode<T> * temp = NULL;

    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;

        first = NULL;
        last = NULL;
    }
    else
    {
        temp = first;

        while(temp -> next != last)
        {
            temp = temp -> next;
        }

        delete last;
        last = temp;

        last->next = first;
    }
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    Display
//    Input :            Nothing
//    Output :           Nothing
//    Description :      Use to display node from linked list
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::Display()
{
    if(first == NULL && last == NULL)
    {
        return;
    }

    SinglyCLLnode<T> * temp = first;

    cout<<"\n";
    do
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp -> next;
    } while (temp != last ->next);
    
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    Count
//    Input :            Nothing
//    Output :           Nothing
//    Description :      Use to count nodes of linked list
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyCLL<T>::Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    DeleteAtPos
//    Input :            Position of node
//    Output :           Nothing
//    Description :      Use to delete node from given position
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::DeleteAtPos(int pos)
{
    SinglyCLLnode<T> * temp = NULL;
    SinglyCLLnode<T> * target = NULL;
    
    int i = 0;
    
    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp -> next;
        }

        target = temp -> next;

        temp->next = target->next;
        delete target;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    InsertAtPos
//    Input :            Data of node and position of node
//    Output :           Nothing
//    Description :      Use to insert node at given position
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::InsertAtPos(T no, int pos)
{
    SinglyCLLnode<T> * temp = NULL;
    SinglyCLLnode<T> * newn = NULL;

    int i = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new SinglyCLLnode<T>(no);

        temp = first;

        for(i = 1; i < pos -1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp->next = newn;

        iCount++;
    }
}

//////////////////////////////////////////////////////////////////////////////
//    Doubly Circuler Linked List using Generic Approach
///////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class DoublyCLLnode
{
    public:
        T data;
        DoublyCLLnode *next;
        DoublyCLLnode *prev;

        DoublyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template<class T>
class DoublyCLL
{
    private:
        DoublyCLLnode<T> *first;
        DoublyCLLnode<T> *last;
        int iCount;

    public:
        DoublyCLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T no, int pos);
        void DeleteAtPos(int pos);
};

template<class T>
DoublyCLL<T>::DoublyCLL()
{
    cout<<"Linked list gets created.\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    InsertFirst
//    Input :            Data of node
//    Output :           Nothing
//    Description :      Use to insert node at first position
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    DoublyCLLnode<T>* newn = NULL;

    newn = new DoublyCLLnode<T>(no);

    if((this->first == NULL) && (this->last == NULL))
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }

    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount++;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    InsertLast
//    Input :            Data of node
//    Output :           Nothing
//    Description :      Use to insert node at last position
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::InsertLast(T no)
{
    DoublyCLLnode<T>* newn = NULL;
    DoublyCLLnode<T>* temp = NULL;

    newn = new DoublyCLLnode<T>(no);

    if((this->first == NULL) && (this->last == NULL))
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        newn->prev = this->last;
        this->last = newn;
    }
    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount++;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    InsertAtPos
//    Input :            Data of node and position of node
//    Output :           Nothing
//    Description :      Use to insert node at given position
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::InsertAtPos(T no,int pos)
{
    DoublyCLLnode<T>* newn = NULL;
    DoublyCLLnode<T>* temp = NULL;
    int iCnt = 0,iCount = 0;

    iCount = Count();

    if(pos < 1 || pos > this->iCount + 1)
    {
        cout <<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == iCount + 1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyCLLnode<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }

    this->first->prev = this->last;
    this->last->next = this->first;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    DeleteFirst
//    Input :            Nothing
//    Output :           Nothing
//    Description :      Use to delete node at first position
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::DeleteFirst()
{
    if((this->first == NULL) && (this->last == NULL))
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete first;

        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->first = this->first->next;
        delete first->prev;
    }
    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount--;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    DeleteLast
//    Input :            Nothing
//    Output :           Nothing
//    Description :      Use to delete node at last position
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::DeleteLast()
{
    DoublyCLLnode<T>* temp = NULL;
    DoublyCLLnode<T>* target = NULL;

    if((this->first == NULL) && (this->last == NULL))
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete first;

        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->last = this->last->prev;
        delete this->last->next;
    }
    this->last->next = this->first;
    this->first->prev = this->last;
    
    this->iCount--;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    DeleteAtPos
//    Input :            Position of node
//    Output :           Nothing
//    Description :      Use to delete node from given position
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::DeleteAtPos(int pos)
{
    DoublyCLLnode<T>* temp = NULL;
    int iCnt = 0,iCount = 0;

    iCount = Count();

    if(pos < 1 || pos > this->iCount)
    {
        cout <<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        this->iCount--;
    }

    this->first->prev = this->last;
    this->last->next = this->first;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    Display
//    Input :            Nothing
//    Output :           Nothing
//    Description :      Use to display node from linked list
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::Display()
{
    if(first == NULL)
    {
        cout<<"Linked list is empty\n";
        return;
    }

    DoublyCLLnode<T>* temp = first;

    cout<<"\n<=>";
    do
    {
        cout<<" | "<<temp->data<<" | <=>";
        temp = temp->next;
    } while(temp != first);

    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    Count
//    Input :            Nothing
//    Output :           Nothing
//    Description :      Use to count nodes of linked list
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyCLL<T>::Count()
{
    return iCount;
}


//////////////////////////////////////////////////////////////////////////////
//         Stack using Generic Approach
//////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class Stacknode
{
    public:
        T data;
        Stacknode<T> *next;

        Stacknode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class Stack
{
    private:
        Stacknode<T> *first;
        int iCount;

    public:
        Stack();
        void push(T);
        T pop();
        T peep();
        void Display();
        int Count();
};

template<class T>
Stack<T> :: Stack()
{
    cout<<"Stack gets created succesfully..\n";
    this->first = NULL;
    this->iCount = 0;
}

template<class T>
void Stack<T> :: push(T no)
{
    Stacknode<T> *newn = NULL;

    newn = new Stacknode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

template<class T>
T Stack<T> :: pop()
{
    T Value = 0;
    Stacknode<T> *temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;

    return Value;
}

template<class T>
T Stack<T> :: peep()
{
    T Value = 0;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    Value = this->first->data;

    return Value;
}

template<class T>
void Stack<T> :: Display()
{
    Stacknode<T> *temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return;
    }

    cout<<"\n";
    while(temp != NULL)
    {
        cout<<"|\t"<<temp->data<<"\t|\n";
        temp = temp->next;
    }
}

template<class T>
int Stack<T> :: Count()
{
    return this->iCount;
}


//////////////////////////////////////////////////////////////////////////////
//          Queue using Generic Approach
//////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class Queuenode
{
    public:
        T data;
        Queuenode<T> *next;

        Queuenode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class Queue
{
    private:
        Queuenode<T> *first;
        Queuenode<T> *last;
        int iCount;

    public:
        Queue();
        void enqueue(T);
        T dequeue();
        void Display();
        int Count();
};

template<class T>
Queue<T> :: Queue()
{
    cout<<"Queue gets created succesfully..\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

template<class T>
void Queue<T> :: enqueue(T no)
{
    Queuenode<T> *newn = NULL;

    newn = new Queuenode<T>(no);

    if((this->first == NULL) && (this->last == NULL))
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last  = this->last->next;
    }
    this->iCount++;
}

template<class T>
T Queue<T> :: dequeue()
{
    T Value = 0;
    Queuenode<T> *temp = this->first;

    if((this->first == NULL) && (this->last == NULL))
    {
        cout<<"Queue is empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;

    return Value;
}

template<class T>
void Queue<T> :: Display()
{
    Queuenode<T> *temp = this->first;

    if((this->first == NULL) && (this->last == NULL))
    {
        cout<<"Queue is empty\n";
        return;
    }

    cout<<"\n";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | -";
        temp = temp->next;
    }
    cout<<"\n";
}

template<class T>
int Queue<T> :: Count()
{
    return this->iCount;
}

//////////////////////////////////////////////////////////////////////////////
//    Binary Srarch Tree using Generic Approach
///////////////////////////////////////////////////////////////////////////////

template<class T>
class BSTnode
{
    public:
        T data;
        BSTnode<T> *lchild;
        BSTnode<T> *rchild;

        BSTnode(T no)
        {
            this->data = no;
            this->lchild = NULL;
            this->rchild = NULL;
        }
};

template<class T>
class BinarySearchTree
{
    private:
        int iCount;
        BSTnode <T>*first = NULL;

    public:
        BinarySearchTree();
        void Insert(T);
        
        void Inorder();
        void Preorder();
        void Postorder();

        void InorderR(BSTnode<T>*);
        void PreorderR(BSTnode<T>*);
        void PostorderR(BSTnode<T>*);

        int Count();
        int CountParentR(BSTnode<T>*);
        int CountLeafR(BSTnode<T>*);

        int CountParentBSTnode();
        int CountChildBSTnode();
};

template<class T>
BinarySearchTree <T> :: BinarySearchTree()
{
    this->iCount = 0;
    this->first =NULL;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    Insert
//    Input :            Data of the node
//    Output :           Nothing
//    Description :      Use to Insert the node into BST
//    Author :           Ashwini Vishnu Kauthale
//    Data :             23/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
void BinarySearchTree <T>:: Insert(T no)
{
    BSTnode <T>*newn = NULL;
    BSTnode <T>*temp = NULL;

    newn = new BSTnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
        this->iCount++;
    }
    else
    {
        temp = this->first;
        while(1)
        {
            if(no > temp->data)
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    iCount++;
                    break;
                }

                temp = temp->rchild;
            }
            else if(no < temp->data)
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    iCount++;
                    break;
                }

                temp = temp->lchild;
            }
            else if(no == temp->data)
            {
                cout<<"Unable to insert as element is duplicate\n";
                delete(newn);
                break;
            }
        }
    }

}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    Inorder
//    Input :            Nothing
//    Output :           Nothing
//    Description :      It internally call InorderR Function
//    Author :           Ashwini Vishnu Kauthale
//    Data :             23/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
void BinarySearchTree<T>::Inorder()
{
    InorderR(first);
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    InorderR
//    Input :            Base Address of root node
//    Output :           Nothing
//    Description :      Use to display nodes in Inorder
//    Author :           Ashwini Vishnu Kauthale
//    Data :             23/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
void BinarySearchTree<T>::InorderR(BSTnode<T>* temp)
{
    if(temp != NULL)
    {
        InorderR(temp->lchild);
        cout<<temp->data<<" ";
        InorderR(temp->rchild);
    }
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    Preorder
//    Input :            Nothing
//    Output :           Nothing
//    Description :      It internally call PreorderR Function
//    Author :           Ashwini Vishnu Kauthale
//    Data :             23/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
void BinarySearchTree<T>::Preorder()
{
    PreorderR(first);
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    PreorderR
//    Input :            Base Address of root node
//    Output :           Nothing
//    Description :      Use to display nodes in Preorder
//    Author :           Ashwini Vishnu Kauthale
//    Data :             23/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
void BinarySearchTree<T>::PreorderR(BSTnode<T>* temp)
{
    if(temp != NULL)
    {
        cout<<temp->data<<" ";
        PreorderR(temp->lchild);
        PreorderR(temp->rchild);
    }
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    Postorder
//    Input :            Nothing
//    Output :           Nothing
//    Description :      It internally call PostorderR Function
//    Author :           Ashwini Vishnu Kauthale
//    Data :             23/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
void BinarySearchTree<T>::Postorder()
{
    PostorderR(first);
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    PostorderR
//    Input :            Base Address of root node
//    Output :           Nothing
//    Description :      Use to display nodes in Postorder
//    Author :           Ashwini Vishnu Kauthale
//    Data :             23/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
void BinarySearchTree<T>::PostorderR(BSTnode<T>* temp)
{
    if(temp != NULL)
    {
        PostorderR(temp->lchild);
        PostorderR(temp->rchild);
        cout<<temp->data<<" ";
    }
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    Count
//    Input :            Nothing
//    Output :           It return Integer Value
//    Description :      Use to count the number of nodes from the BST
//    Author :           Ashwini Vishnu Kauthale
//    Data :             23/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
int BinarySearchTree <T>:: Count()
{
    return this->iCount;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    CountParentBSTnode
//    Input :            Nothing
//    Output :           Integer value
//    Description :      It internally call CountParentR
//    Author :           Ashwini Vishnu Kauthale
//    Data :             23/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
int BinarySearchTree<T>::CountParentBSTnode()
{
    return CountParentR(first);
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    CountParentR
//    Input :            Base Address of root node
//    Output :           Integer value
//    Description :      Use to count number of parent nodes form BST
//    Author :           Ashwini Vishnu Kauthale
//    Data :             23/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
int BinarySearchTree<T>::CountParentR(BSTnode<T>* temp)
{
    if(temp == NULL)
    {
        return 0;
    }

    int count = 0;

    if(temp->lchild != NULL || temp->rchild != NULL)
    {
        count = count +1;
    }

    return count + CountParentR(temp->lchild) + CountParentR(temp->rchild);
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    CountChildBSTnode
//    Input :            Nothing
//    Output :           Integer Count
//    Description :      It internally call CountLeafR
//    Author :           Ashwini Vishnu Kauthale
//    Data :             23/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
int BinarySearchTree<T>::CountChildBSTnode()
{
    return CountLeafR(first);
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    CountLeafR
//    Input :            Base Address of root node
//    Output :           Integer value
//    Description :      Use to count the number of leaf nodes
//    Author :           Ashwini Vishnu Kauthale
//    Data :             23/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
int BinarySearchTree<T>::CountLeafR(BSTnode<T>* temp)
{
    if(temp == NULL)
    {
        return 0;
    }

    int count = 0;

    if(temp->lchild == NULL && temp->rchild == NULL)
    {
        return 1;
    }

    return CountLeafR(temp->lchild) + CountLeafR(temp->rchild);
}

//////////////////////////////////////////////////////////////////////////////
//    Searching using Generic Approach
///////////////////////////////////////////////////////////////////////////////

template<class T>
class ArrayX
{
    public:

        T *Arr;
        int iSize;
        bool Sorted;

        ArrayX(T);
        ~ArrayX();
        void Accept();
        void Display();
        bool LinearSearch(T);
        bool BiDirectionalSearch(T);
        bool BinarySearch(T);
};

template<class T>
ArrayX <T> :: ArrayX(T no)
{
    this->iSize = no;
    Arr = new T [iSize];
    this->Sorted = true;
}

template<class T>
ArrayX <T> ::~ArrayX()
{
    delete []Arr;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    Accept
//    Input :            Nothing
//    Output :           Nothing
//    Description :      Use to accept the element of array
//    Author :           Ashwini Vishnu Kauthale
//    Data :             24/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
void ArrayX <T> :: Accept()
{
    int iCnt = 0;
    cout<<"Enter the elements\n";
    cin>>Arr[iCnt];

    for(iCnt = 1; iCnt < iSize; iCnt++)
    {
        cin>>Arr[iCnt];

        if(Arr[iCnt - 1] > Arr[iCnt])
        {
            this->Sorted = false;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    Display
//    Input :            Nothing
//    Output :           Nothing
//    Description :      Use to Display element of array
//    Author :           Ashwini Vishnu Kauthale
//    Data :             24/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
void ArrayX <T> :: Display()
{
    int iCnt = 0;

    cout<<"Elements of Array are: \n";

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    LinearSearch
//    Input :            Data of the node
//    Output :           Boolean
//    Description :      Use to check element is present or not
//    Author :           Ashwini Vishnu Kauthale
//    Data :             24/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
bool ArrayX<T> :: LinearSearch(T no)
{
    bool bFlag = false;
    int iCnt = 0;

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        if(Arr[iCnt] == no)
        {
            bFlag = true;
            break;
        }
    }

    return bFlag;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    BiDirectionalSearch
//    Input :            Data of the node
//    Output :           Boolean
//    Description :      Use to check element is present or not
//    Author :           Ashwini Vishnu Kauthale
//    Data :             24/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
bool ArrayX <T> :: BiDirectionalSearch(T no)
{
    int iStart = 0;
    int iEnd = 0;
    bool bFlag = false;

    for(iStart = 0,iEnd = iSize - 1;iStart <= iEnd; iStart++,iEnd--)
    {
        if((Arr[iStart] == no) || (Arr[iEnd] == no))
        {
            bFlag = true;
            break;
        }
    }

    return bFlag;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    BinarySearch
//    Input :            Data of the node
//    Output :           Boolean
//    Description :      Use to check element is present or not
//    Author :           Ashwini Vishnu Kauthale
//    Data :             24/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
bool ArrayX<T> :: BinarySearch(T no)
{
    if(Sorted == false)
    {
        return BiDirectionalSearch(no);
    }

    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;

    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if(Arr[iMid] == no)
        {
            bFlag = true;
            break;
        }
        else if(no < Arr[iMid])
        {
            iEnd = iMid - 1;
        }
        else if(no > Arr[iMid])
        {
            iStart = iMid + 1;
        }
    }
    return bFlag;
}

//////////////////////////////////////////////////////////////////////////////
//    Sorting using Generic Approach
///////////////////////////////////////////////////////////////////////////////

#define INC_ORDER 1
#define DEC_ORDER 2

template<class T>
class ArrayX
{
    public:
        T *Arr;
        int iSize;
        bool Sorted;

    ArrayX(int no);
    ~ArrayX();

    void Accept();
    void Display();

    void BubbleSort();
    void BubbleSortEfficient(int iOption);

    void SelectionSort();

    void InsertionSort();
};

template<class T>
ArrayX <T> ::ArrayX(int no)
{
    iSize = no;
    Arr = new T [iSize];
    Sorted = true;
}

template<class T>
ArrayX <T> ::~ArrayX()
{
    delete []Arr;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    Accept
//    Input :            Nothing
//    Output :           Nothing
//    Description :      Use to Accept the element of array
//    Author :           Ashwini Vishnu Kauthale
//    Data :             25/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
void ArrayX <T> :: Accept()
{
    int iCnt = 0;
    cout<<"Enter the elements : \n";
    cin>>Arr[iCnt];

    for(iCnt = 1; iCnt < iSize; iCnt++)
    {
        cin>>Arr[iCnt];

        if(Arr[iCnt -1] > Arr[iCnt])
        {
            Sorted = false;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    Display
//    Input :            Nothing
//    Output :           Nothing
//    Description :      Use to Display element of array
//    Author :           Ashwini Vishnu Kauthale
//    Data :             25/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
void ArrayX <T> :: Display()
{
    int iCnt = 0;

    cout<<"Elements of the array are : \n";

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    BubbleSort
//    Input :            Nothing
//    Output :           Nothing
//    Description :      Use to sort the given elements inti Ascending order
//    Author :           Ashwini Vishnu Kauthale
//    Data :             25/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
void ArrayX <T> :: BubbleSort()
{
    if(Sorted == true)
    {
        return;
    }

    int i  = 0, j = 0, temp = 0;

    for(i = 0; i < iSize - 1; i++)
    {
        for(j = 0; j < iSize - 1 - i;j++)
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;
            }
        }
    }

    Sorted = true;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    BubbleSortEfficient
//    Input :            Integer value
//    Output :           Nothing
//    Description :      Use to sort the given array in ascending or Descending based on option
//    Author :           Ashwini Vishnu Kauthale
//    Data :             25/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
void ArrayX <T> :: BubbleSortEfficient(int Option)
{
    if(Sorted == true)
    {
        return;
    }

    if(Option < INC_ORDER || Option > DEC_ORDER)
    {
        cout<<"Invalid Option for Sorting\n";
        cout<<"1 : Increasing\n";
        cout<<"2 : Decreasing\n";
        return;
    }

    int i = 0, j = 0, temp = 0;
    bool bFlag = false;

    bFlag = true;

    if(Option == INC_ORDER)
    {
        for(i = 0; ((i < iSize - 1) && bFlag == true); i++)
        {
            bFlag = false;

            for(j = 0; j < iSize - 1-i; j++)
            {
                if(Arr[j + 1] < Arr[j])
                {
                    temp = Arr[j];
                    Arr[j] = Arr[j + 1];
                    Arr[j + 1] = temp;

                    bFlag = true;
                }
            }
        }
    }
    else if(Option == DEC_ORDER)
    {
        for(i = 0; ((i < iSize - 1) && bFlag == true); i++)
        {
            bFlag = false;

            for(j = 0; j < iSize - 1-i; j++)
            {
                if(Arr[j + 1] > Arr[j])
                {
                    temp = Arr[j];
                    Arr[j] = Arr[j + 1];
                    Arr[j + 1] = temp;

                    bFlag = true;
                }
            }
        }
    }

    Sorted = true;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    SelectionSort
//    Input :            Nothing
//    Output :           Nothing
//    Description :      Use to sort the given array into Ascending order
//    Author :           Ashwini Vishnu Kauthale
//    Data :             25/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
void ArrayX <T> :: SelectionSort()
{
    if(Sorted == true)
    {
        cout<<"Array is already sortedn";
        return;
    }

    int i = 0, j = 0, temp = 0;
    int min_index = 0;

    for(i = 0; i < iSize - 1; i++)
    {
        min_index = i;
        for(j = i + 1; j < iSize; j++)
        {
            if(Arr[j] < Arr[min_index])
            {
                min_index = j;
            }

            temp = Arr[i];
            Arr[i] = Arr[min_index];
            Arr[min_index] = temp;
        }
    }

    Sorted = true;
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    InsertionSort
//    Input :            Nothing
//    Output :           Nothing
//    Description :      Use to sort the given array into Ascending order
//    Author :           Ashwini Vishnu Kauthale
//    Data :             25/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
void ArrayX <T> :: InsertionSort()
{
    int i = 0, j = 0, Selected = 0;

    for(i = 1; i < iSize; i++)
    {
        for(j = i - 1,Selected = Arr[i]; (j >= 0 && Selected < Arr[j]); j--)
        {
            Arr[j + 1] = Arr[j];
        }

        Arr[j + 1] = Selected;
    }

    Sorted = true;
}

//////////////////////////////////  End of Library  //////////////////////////////////////////

int main()
{
    cout<<"---------------Singly Linear Linked List-----------------\n\n";
    SinglyLLL<int> *obj = new SinglyLLL<int>();

    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();
    cout<<"Number of elements are : "<<obj->Count()<<"\n";

    obj->InsertLast(101);
    obj->InsertLast(111);
    obj->InsertLast(121);

    obj->Display();
    cout<<"Number of elements are : "<<obj->Count()<<"\n";

    obj->DeleteFirst();
    
    obj->Display();
    cout<<"Number of elements are : "<<obj->Count()<<"\n";
    
    obj->DeleteLast();

    obj->Display();
    cout<<"Number of elements are : "<<obj->Count()<<"\n";

    obj->InsertAtPos(105,4);

    obj->Display();
    cout<<"Number of elements are : "<<obj->Count()<<"\n";

    obj->DeleteAtPos(4);

    obj->Display();
    cout<<"Number of elements are : "<<obj->Count()<<"\n";

    delete obj;

//////////////////////////////////////////////////////////////////////////////////
    
    cout<<"\n---------------Doubly Linear Linked List-----------------\n\n";

    DoublyLLL <char>*dobj = new DoublyLLL<char>();

    dobj->InsertFirst('A');
    dobj->InsertFirst('B');
    dobj->InsertFirst('C');

    dobj->Display();
    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

    dobj->InsertLast('X');
    dobj->InsertLast('Y');
    dobj->InsertLast('Z');

    dobj->Display();
    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

    dobj->DeleteFirst();

    dobj->Display();
    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

    dobj->DeleteLast();

    dobj->Display();
    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

    dobj->InsertAtPos('$',4);

    dobj->Display();
    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

    dobj->DeleteAtPos(4);

    dobj->Display();
    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

    delete dobj;

/////////////////////////////////////////////////////////////////////////////////

    cout<<"\n--------------Singly Circuler Linked List----------------\n\n";

    SinglyCLL<double> *sobj = new SinglyCLL<double>();

    sobj->InsertFirst(53454.66781);
    sobj->InsertFirst(21.9876);
    sobj->InsertFirst(11.345);

    sobj->Display();
    cout<<"Number of elements are : "<<sobj->Count()<<"\n";
    
    sobj->InsertLast(101.5652);
    sobj->InsertLast(111.7875);
    sobj->InsertLast(121.80989);

    sobj->Display();
    cout<<"Number of elements are : "<<sobj->Count()<<"\n";
    
    sobj->DeleteFirst();

    sobj->Display();
    cout<<"Number of elements are : "<<sobj->Count()<<"\n";
    
    sobj->DeleteLast();

    sobj->Display();
    cout<<"Number of elements are : "<<sobj->Count()<<"\n";
    
    sobj->InsertAtPos(105.7786,4);

    sobj->Display();
    cout<<"Number of elements are : "<<sobj->Count()<<"\n";
    
    sobj->DeleteAtPos(4);

    sobj->Display();
    cout<<"Number of elements are : "<<sobj->Count()<<"\n";
    
    delete sobj;

///////////////////////////////////////////////////////////////////////////////////////

    cout<<"\n--------------Doubly Circuler Linked List----------------\n\n";

    DoublyCLL<float> *fobj = new DoublyCLL<float>();

    fobj->InsertFirst(51.54f);
    fobj->InsertFirst(21.56f);
    fobj->InsertFirst(11.89f);

    fobj->Display();
    cout<<"Number of elements are : "<<fobj->Count()<<"\n";


    fobj->InsertLast(101.67f);
    fobj->InsertLast(111.48f);
    fobj->InsertLast(121.90f);
    
    fobj->Display();
    cout<<"Number of elements are : "<<fobj->Count()<<"\n";

    fobj->DeleteFirst();

    fobj->Display();
    cout<<"Number of elements are : "<<fobj->Count()<<"\n";

    fobj->DeleteLast();

    fobj->Display();
    cout<<"Number of elements are : "<<fobj->Count()<<"\n";

    fobj->InsertAtPos(105.67f,4);

    fobj->Display();
    cout<<"Number of elements are : "<<fobj->Count()<<"\n";

    fobj->DeleteAtPos(4);

    fobj->Display();
    cout<<"Number of elements are : "<<fobj->Count()<<"\n";

    delete fobj;

    //////////////////////////////////////////////////////////////////////////////////////////////

    cout<<"\n--------------Stack using Generic Approach----------------\n\n";

    Stack <char>*Sobj = new Stack<char>();

    Sobj->push('A');
    Sobj->push('B');
    Sobj->push('C');
    Sobj->push('D');

    Sobj->Display();
    cout<<"Number of elements in Stack are : "<<Sobj->Count()<<"\n";

    cout<<"Return value of peep is : "<<Sobj->peep()<<"\n";

    Sobj->Display();
    cout<<"Number of elements in Stack are : "<<Sobj->Count()<<"\n";

    Sobj->Display();
    cout<<"Number of elements in Stack are : "<<Sobj->Count()<<"\n";
    cout<<"Poped element is : "<<Sobj->pop()<<"\n";

    Sobj->Display();
    cout<<"Number of elements in Stack are : "<<Sobj->Count()<<"\n";
    cout<<"Poped element is : "<<Sobj->pop()<<"\n";

    Sobj->push('E');

    Sobj->Display();
    cout<<"Number of elements in Stack are : "<<Sobj->Count()<<"\n";

    delete Sobj;

    ///////////////////////////////////////////////////////////////////////////////////////

    cout<<"\n--------------Queue using Generic Approach----------------\n\n";

    Queue<double> *qobj = new Queue<double>();

    qobj->enqueue(11.56789);
    qobj->enqueue(21.56789);
    qobj->enqueue(51.56789);
    qobj->enqueue(101.56789);

    qobj->Display();
    cout<<"Number of elements in Queue are : "<<qobj->Count()<<"\n";

    cout<<"Removed element is : "<<qobj->dequeue()<<"\n";
    qobj->Display();
    cout<<"Number of elements in Queue are : "<<qobj->Count()<<"\n";

    cout<<"Removed element is : "<<qobj->dequeue()<<"\n";
    qobj->Display();
    cout<<"Number of elements in Queue are : "<<qobj->Count()<<"\n";
    
    qobj->enqueue(121.56789);

    qobj->Display();
    cout<<"Number of elements in Queue are : "<<qobj->Count()<<"\n";

    delete qobj;

    ///////////////////////////////////////////////////////////////////////////////////////

    cout<<"\n--------------- Binary Search Tree ----------------\n\n";

    BinarySearchTree<int> *BSTobj = new BinarySearchTree<int>();

    int iRet = 0;

    BSTobj->Insert(21);
    BSTobj->Insert(11);
    BSTobj->Insert(51);
    BSTobj->Insert(67);
    BSTobj->Insert(40);
    BSTobj->Insert(10);
    BSTobj->Insert(13);
    BSTobj->Insert(38);

    cout<<"Inorder Traversal :";
    BSTobj->Inorder();

    cout<<"\n\n";

    cout<<"Inorder Traversal :";
    BSTobj->Preorder();

    cout<<"\n\n";

    cout<<"Inorder Traversal :";
    BSTobj->Postorder();

    cout<<"\n\n";
    
    cout<<"Number of BSTnodes are :"<<BSTobj->Count();

    cout<<"\n\n";

    cout<<"Number of Parent BSTnodes are :"<<BSTobj->CountParentBSTnode();

    cout<<"\n\n";

    cout<<"Number of Child BSTnodes are :"<<BSTobj->CountChildBSTnode();

    delete BSTobj;

    ///////////////////////////////////////////////////////////////////////////////////////

    cout<<"\n----------------------- Searching -------------------\n\n";
    int iValue = 0;
    float fNo = 0;

    cout<<"Enter the number of elements\n";
    cin>>iValue;

    cout<<"Enter the element that you want to find\n";
    cin>>fNo;

    ArrayX <float> * axobj = new ArrayX<float>(iValue);

    axobj->Accept();

    axobj->Display();

    cout<<"\n";

    if(axobj->LinearSearch(fNo))
    {
        cout<<"Element is present\n";
    }
    else
    {
        cout<<"There is no such element\n";
    }

    cout<<"\n";

    if(axobj->BiDirectionalSearch(fNo))
    {
        cout<<"Element is present\n";
    }
    else
    {
        cout<<"There is no such element\n";
    }

    cout<<"\n";

    if(axobj->BinarySearch(fNo))
    {
        cout<<"Element is present\n";
    }
    else
    {
        cout<<"There is no such element\n";
    }

    delete axobj;
    
    ///////////////////////////////////////////////////////////////////////////////////////

    cout<<"\n---------------------- Sorting--------------------\n\n";

    int iValue = 0;
    cout<<"Enter the number of elements : \n";
    cin>>iValue;

    ArrayX <int> *sortobj = new ArrayX<int>(iValue);

    sortobj->Accept();

    sortobj->Display();

    sortobj->BubbleSort();

    //  1 : Increasing
    //  2 : Decreasing

    sortobj->BubbleSortEfficient(INC_ORDER);


    sortobj->SelectionSort();

    sortobj->InsertionSort();

    cout<<"Data After sorting\n";
    
    sortobj->Display();

    delete sortobj;
    return 0;
}
