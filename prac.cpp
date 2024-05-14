#include <iostream>
#include <string>
using namespace std;

string my_name = "Dalton";
string* my_name_pointer = &my_name;
string my_var1 = my_name;
my_var1 = "Bannana"
// string my_var1 = *my_name_pointer;
// string& my_var2 = *my_name_pointer;

int main(){
    cout << my_name << endl;
    cout << my_var1 << endl;
    // cout << &my_var2 << endl;
}


// struct Person{
//     string name = "";
//     int age = 0;
// };

// Person Dalton;
// // Person.name = "Dalton";

// void change_name_raw(string name){
//     name = name + "T";
// }

// void change_name_pointer(string* name){
//     *name = *name + "E";
// }

// int main(){
//     // cout << my_unref << endl;
//     cout << my_name << endl;
//     change_name_raw(my_name);
//     cout << my_name << endl;
//     change_name_pointer(&my_name);
//     cout << my_name << endl;

//     Dalton.name = "Big D"; 
//     cout << Dalton.name << endl;
// }