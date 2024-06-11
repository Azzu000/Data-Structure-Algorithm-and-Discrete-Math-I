/*By Ruiqi Huang
* 
* 2/16/2023
* 
*The driver class used to test SkipList. 
*/

#include "skiplist.h"

//This tests all the functions individually
void MyTest() {
    //creating a skiplist with depth of 4
    SkipList list1(4);

    //Test Add function
    cout << "Testing Add Function: " << endl;
    list1.Add(1);
    list1.Add(2);
    list1.Add(3);
    list1.Add(4);
    list1.Add(5);
    list1.Add(6);
    list1.Add(7);
    list1.Add(8);
    cout << "Should give duplicate error." << endl;
    //tried to add duplicate
    list1.Add(6);

    //test ostream
    cout << list1 << endl;

    //Test Remove function
    cout << "Testing Remove Function:" << endl;
    list1.Remove(2);
    list1.Remove(8);

    //tried to remove something not in list
    cout << "Should give an error saying that the data does not exist. " << endl;
    list1.Remove(33);

    cout << list1 << endl;

    //Test Contain function
    if (list1.Contains(1) == true) {
        cout << "The list contains 1. (SHould be true)" << endl;
    }
    else {
        cout << "The list does not contain 1." << endl;
    }

    if (list1.Contains(66) == true) {
        cout << "The list contains 1." << endl;
    }
    else {
        cout << "The list does not contain 1. (Should be false)" << endl;
    }


}

void MyTest1() {
    //Testing behavior fo SkipList with randomly generated values
    SkipList list1(5);
    for (int i = 0; i < 20; ++i) {
        int num = rand() % 200;
        list1.Add(num);
        cout << "After adding " << num << ": " << endl;
        cout << list1 << endl;
    }
}

void testAll() {
    MyTest();
    MyTest1();
}


int main(){
    testAll();
	return 0;
};