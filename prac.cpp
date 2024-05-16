#include <iostream>
#include <string>
using namespace std;

string my_name = "Dalton";
string second_name = "Emily";
string reference_name = my_name;

int main(){
    reference_name = second_name;
    reference_name += "I";
    cout << reference_name << endl;
    cout << my_name << endl;
}

// string* my_name_pointer = &my_name;
// string my_var1 = my_name;

// string my_var1 = *my_name_pointer;
// string& my_var2 = *my_name_pointer;

// void change_name_raw(string& name){
//     name += "T";
//     cout << name << endl;
// }