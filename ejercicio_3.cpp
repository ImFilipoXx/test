
#include <iostream>
using namespace std;
int main(){
char choice;
std::cout<<"Help on:"<< endl;
std::cout<<"1.if"<<endl;
std::cout<<"2.switch"<<endl;
std::cout<<"Choose one"<<endl;
std::cin >> choice;

switch(choice) {
case '1':
std::cout<<"The if\n:"<<endl;
std::cout<<"if(condition) statement;"<<endl;
std::cout<<"else statement"<<endl;
break;
case '2':
std::cout<<"The witch:\n:"<<endl;
std::cout<<"switch(expresion) {"<<endl;
std::cout<<"case constant:"<<endl;
std::cout<<"statement sequence"<<endl;
std::cout<<"break;"<<endl;
std::cout<<" /"<<"/ ..."<<endl;
std::cout<<"}:"<<endl;
break;
deafult:
std::cout<<"Selection not found"<<endl;
}

return 0;
}





