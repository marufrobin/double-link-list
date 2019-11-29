/*Name: Maruf Ahmed Robin
 ID: 1512169642
 Section: 01
*/



#include <iostream>
#include "src\doublelinklist.cpp"
using namespace std;

int main()
{

    doublelinklist<int > s;
    s.InsertItemAtFront(4);
    s.InsertItemAtFront(5);


    s.InsertItemAtRear(3);
    s.InsertItemAtRear(2);


    s.InsertItemAtRear(1);
    s.Print();
    int x;
    cout<<"Enter a Item to Retrieve: "<<endl;
    cin>>x;
    bool found ;
    s.RetrieveItem(x, found);
    if(found==true)
        cout<<"Item found it"<<endl;
    else
        cout<<"Item not found it "<<endl;


    s.PrintReverse();
     s.DeleteItem(3);

     s.Print();
   s.DeleteItemAtFront();

    s.Print();
s.lengthIs();
    s.DeleteAllItem();

    cout<< "Delete all the Nodes From the list "<<endl;
    s.Print();

    return 0;
}
