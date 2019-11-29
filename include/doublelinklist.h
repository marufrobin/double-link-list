#ifndef DOUBLELINKLIST_H
#define DOUBLELINKLIST_H

template <class ItemType>

class doublelinklist
{
    struct NodeType
    {
        ItemType info;
        NodeType* next;
        NodeType* prev;

    };
    public:
        doublelinklist();
        void MakeEmpty();
        bool isFull();
        bool isEmpty();
        int lengthIs();
        void RetrieveItem(ItemType &item, bool &found);
        void InsertItemAtFront(ItemType item);
        void InsertItemAtRear(ItemType item);
        void IsertItem(ItemType item, int position);
        void DeleteItem(int position);
        void DeleteItemAtFront();
        void DeleteAllItem();
        void Print();
        void PrintReverse();


    private:
        NodeType *front, *rear;


};

#endif // DOUBLELINKLIST_H
