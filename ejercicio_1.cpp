
#include <iostream>
using namespace std;
int main(){
    int i;
    for(i=0; i<10; i++)
        switch(i){
         case 1:
           std::cout <<"i is zero"<< endl;
            break;
case 2:
std::cout <<"i is one"<< endl;

break;

case 3:
           std::cout <<"i is three"<< endl;
            break;
case 4:
           std::cout <<"i is four"<< endl;
            break;
deafult:
           std::cout <<"i is five or more"<< endl;

}
return 0;
}
