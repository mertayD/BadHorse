//
//  main.cpp
//  BadHorse
//
//  Created by Mertay Dayanc on 4/11/20.
//  Copyright © 2020 Mertay Dayanc. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

string* get_troublesome_pairs(string str, int length, int& n);
string* get_pairs(string str, int n, int length);
bool check(string to_test, string* pairs, int n);

//List1 holds the pairs on Left Hand Side of the list.
string* list1;
//List2 holds the pairs on Right Hand Side of the list.
string* list2;

int main(int argc, const char * argv[]) {
    int T;
    int test_size;
    cin >> T;
    cout<< T << endl;
    string str;
    string pair1;
    string pair2;
    for(int k = 1; k<=T; k++)
    {
        //Read test size everytime you start a new test
        cin >> test_size;
        //cout << "TEST NO : "<< k<<endl;
        //Create 2 lists with sizes equal to test size
        list1 = new string[test_size];
        list2 = new string[test_size];
        
        /*
         Read the input and fill the lists by accordingl. Names that are on the Left Hand
         Side will be on the list1 and the ones on the Right Hand Side will be on List 2
         */
        for(int j = 0; j< test_size; j++)
        {
            cin >> pair1;
            cin >> pair2;
            list1[j] = pair1;
            list2[j] = pair2;
        }
        
        //Variable to track if the test passed or not
        bool passed = true;
        
        /*
         This for loop (Outer loop) will be traversing the list from the beginning and in every
         iteration pairs in the current index will be compared with the ones that are already in
         the list (Elements with index less than i). So inner loop will be checking if list1[i]
         is not causing trouble with list1[j] where j is from i-1 to 0. This will be done for
         list2 as well. And if either list1[i] or list2[i] is causing problem, then we swap them
         and start checking starting from index j = i-1 to 0. If Swapping fixes the problem then
         we are good and keep checking until i equals test_size, if swapping doesn't fixes the we
         output "NO". If every check passes we toggle passed variable and return "YES"
         */
        for(int i = 0;  i< test_size; i++)
        {
            int n;
            
            string left_str = list1[i];
            string right_str = list2[i];
        
            //n that is declared above is passed by reference and it is initialized inside this
            //function.
            string* pairs1 = get_troublesome_pairs(left_str, test_size, n);
            string* pairs2 = get_troublesome_pairs(right_str, test_size, n);
            
            bool swap = false;
            
            for(int j = i-1; j>=0; j-- )
            {
                bool list1_check;
                bool list2_check;
                //If swap is toggled we swap list1[j] and list2[j]
                if(swap)
                {
                    string temp = list1[j];
                    list1[j] = list2[j];
                    list2[j] = temp;
                }
                
                //Check if they cause trouble.
                list1_check = check(list1[j], pairs1, n);
                list2_check = check(list2[j], pairs2, n);
                
                if(!(list1_check && list2_check))
                {
                    //If they cause trouble try swapping and start checking again from j = i-1 because we want to make sure we are not skipping any troublesome pair
                    if(!swap)
                    {
                        //cout << "swapped at index: " << j << endl;
                        //swap and start all over again
                        swap = true;
                        j = i-1;
                    }
                    else{
                        //Output "NO"
                        passed = false;
                        cout << "Case #" << k << ":" << "No"<< endl;
                        j = 0;
                        i=test_size;
                    }
                }
            }
        }
        if(passed)
        {
            //Output "YES"
            cout << "Case #" << k << ":" << "Yes"<< endl;
        }

        delete [] list1;
        delete [] list2;
    }
    return 0;
}

//Returns troublesome pairs and initializes n because it is passed by reference not passsed by value
string* get_troublesome_pairs(string str, int length, int& n)
{
    
    int count = 0;
    string* result = new string[length];

    for(int i = 0; i < length; i++)
    {
        if(list1[i].compare(str) == 0)
        {
            //cout<<"PAIR IS IN L2 " <<list2[i]<<endl;
            result[count] = list2[i];
            count++;
        }
    }
    
    for(int i = 0; i < length; i++)
    {
        if(list2[i].compare(str) == 0)
        {
            //cout<<"PAIR IS IN L1 " <<list1[i]<<endl;
            result[count] = list1[i];
            count++;
        }
    }
    n = count;
    if(count == 0)
    {
        return NULL;
    }
    else{
        return result;
    }
}

//Checks if string to_test are in trouplesome lists of list[i]
bool check(string to_test, string* pairs, int n)
{
    //cout << " TEST VALUE " << to_test << endl;
    for(int i = 0; i < n; i++)
    {
        //cout << " Pair VALUE " << pairs[i] << endl;

        if(pairs[i].compare(to_test) == 0)
        {
            //cout << " RETURN VALUE FALSE " << endl;
            return false;
        }
    }
    //cout << " RETURN VALUE TRUE " << endl;

    return true;
}
