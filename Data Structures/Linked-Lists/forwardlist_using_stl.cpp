#include<iostream>
#include<vector>
#include<forward_list>/*header file required for forward list implementation*/
using namespace std;
//display functions
void displayint(forward_list <int> f)
{   // Traversal of forward list
    for(forward_list <int> :: iterator i=f.begin();i!=f.end();i++)
        cout<<*i<<" ";
    cout<<endl;
}
void displaychar(forward_list <char> f)
{
    for(forward_list <char> :: iterator i=f.begin();i!=f.end();i++)
        cout<<*i<<" ";
    cout<<endl;
}
bool greaterthan3(int val)
{
  return(val>3);
}
/* Forward lists are used to implement singly linked lists in STL*/

int main()
{
    /*constructors*/
    vector <int> num(4,5);
    forward_list<int> fl1;                          //empty constructor
    forward_list<char> fl2(5,'a');                  //fill constructor
    forward_list<char> fl3(fl2);                    //copy constructor
    forward_list<int> fl4={1,2,3,4};                 //initializer_list constructor
    forward_list<int> fl5(num.begin(),num.end());   //range constructor
    cout<<"fl1: ";
    displayint(fl1);
    cout<<"fl2: ";
    displaychar(fl2);
    cout<<"fl3: ";
    displaychar(fl3);
    cout<<"fl4: ";
    displayint(fl4);
    cout<<"fl5: ";
    displayint(fl5);
    /* Insertion*/
    cout<<"Inserting element in fl5: ";
    fl5.insert_after(fl5.begin(),9);//inserting single element after given position
    displayint(fl5);
    cout<<"Inserting element in fl4: ";
    forward_list<int>::iterator iter=fl4.begin();
    iter++;iter++;iter++;
    fl4.insert_after(iter,{5,6,7});//inserting multiple elements at given position
    displayint(fl4);
    cout<<"Inserting element in fl1: ";
    fl1.insert_after(fl1.before_begin(),2,10);//inserting same element multiple times
    displayint(fl1);
    cout<<"Inserting element at front of fl1: ";
    fl1.push_front(3);//Insert elements at the front
    displayint(fl1);
    /*Deletion*/
    cout<<"Deleting element at front of fl1: ";
    fl1.pop_front();//Delete element at the front
    displayint(fl1);
    cout<<"Deleting element at index 2 in fl5: ";
    forward_list <int> :: iterator i=fl5.begin();
    i++;
    fl5.erase_after(i);//deleting single element after given position
    displayint(fl5);
    cout<<"Deleting elements in given range in fl4: ";
    forward_list <int> :: iterator it=fl4.begin();
    it++;it++;it++;it++;
    fl4.erase_after(it,fl4.end());//deleting multiple elements in given exclusive range
    displayint(fl4);
    cout<<"Deleting element with a value 5 in fl5: ";
    fl5.remove(5);//deleting element with specific value
    displayint(fl5);
    cout<<"Deleting element greater than 3 in fl4: ";
    fl4.remove_if(greaterthan3);//delete elements satisfying given condition
    displayint(fl4);
    /*Reversal*/
    cout<<"Reversing list fl4: ";
    fl4.reverse();
    displayint(fl4);
    return 0;
}
/* Operation        Complexity
   Insertion        O(1)
   Deletion         O(1)
   Traversal        O(n)
   Reversal         O(n)
*/

