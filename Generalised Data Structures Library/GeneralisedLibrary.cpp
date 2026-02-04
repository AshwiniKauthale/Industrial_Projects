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

    return 0;
}