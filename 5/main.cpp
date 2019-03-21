#include <iostream>
#include "String.h"

using std::cout;
using std::endl;

int main()
{
    String s1("Hello,");
    String s2(" world!");
    cout << s1 << s2 << endl;
    s1.append(s2);
    cout << s1 << endl;
    String s = "Hello";
    s.append(s);
    cout << s << endl;
    String ss(s);
    cout << ss << endl;
    s += ss;
    cout << s << endl << s + ss << endl;
    String s5('s', 5);
    cout << s5 << endl;
    s = s5;
    cout << s << endl;
    String s3(s);
    cout << "size of \"";
    s3.print();
    cout << "\" is " << s3.size() << endl;
    s3.clear();
    cout << s3;
    return  0;
}
