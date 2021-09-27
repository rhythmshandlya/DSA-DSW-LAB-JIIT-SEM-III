#include <iostream>
#include <forward_list>
#include <algorithm>

using namespace std;

int main()
{
    forward_list<int> fl;
    //No push_back in forward_list
    for (int i = 0; i < 10; i++)
        fl.push_front(i);

    for (forward_list<int>::iterator it = fl.begin(); it != fl.end(); it++)
        cout << *it << "->";
    cout << endl;

    //10 is the new size of the list 5 is the val to be assigned
    fl.assign(5, 5);

    for (forward_list<int>::iterator it = fl.begin(); it != fl.end(); it++)
        cout << *it << "->";
    cout << endl;

    //No fl.size();

    return 0;
}
/*
Element access
front : Access first element (public member function )

Modifiers
assign : Assign content (public member function )
emplace_front : Construct and insert element at beginning (public member function )
push_front : Insert element at beginning (public member function )
pop_front : Delete first element (public member function )
emplace_after : Construct and insert element (public member function )
insert_after : Insert elements (public member function )
erase_after : Erase elements (public member function )
swap : Swap content (public member function )
resize : Change size (public member function )
clear : Clear content (public member function )

Operations
splice_after : Transfer elements from another forward_list (public member function )
remove  : Remove elements with specific value (public member function )
remove_if : Remove elements fulfilling condition (public member function template )
unique : Remove duplicate values (public member function )
merge : Merge sorted lists (public member function )
sort : Sort elements in container (public member function )
reverse : Reverse the order of elements (public member function )
*/