#include <iostream>

using namespace std;

int main() {
//    string firstname = "John";
//    string lastname = "Smith";
//    string name = firstname + " " + lastname;
//    cout << name << endl;
    
      string user = "James";
      string text = "Welcome to our Wareagle Chat Group!";
      string buffer = "(*" + user + "*)" + text;

      string user2 = "Kate";
      string text2 = "Hi there!";
      buffer.insert(0,  "(*" + user2 + "*)" + text2);

      string user3 = "Matt";
      string text3 = "War Eagle!";
      string text4 = "Hey!";

      buffer.insert(0, "(*" + user3 + "*)" + text3 + "\n" + text4);

      cout << buffer << endl;
      cout << buffer.size() << endl; // 84

      string::size_type beg1 = buffer.find("(*");
      string::size_type beg2 = buffer.find("(*", beg1+1);
      string::size_type beg3 = buffer.find("(*", beg2+1);
 
      string::size_type end1 = buffer.find("*)");
      string::size_type end2 = buffer.find("*)", end1+1);
      string::size_type end3 = buffer.find("*)", end2+1);
      
      cout << buffer.substr(beg1+2,end1-beg1-2) << endl;
      cout << buffer.substr(beg2+2,end2-beg2-2) << endl;
      cout << buffer.substr(beg3+2,end3-beg3-2) << endl;

      cout << buffer.substr(end2+2, end2-beg2+3) << endl;
      return 0;

}
