#include "dequeuePt.cpp"
#include <iostream>

using namespace std;

int main(){
  dequeue<int> C;

  C.insertT(-3);
  C.insertT(3);
  C.insertH(2);
  C.insertH(-2);
  C.insertH(0);

  C.removeH();
  C.removeT();
  int appoggio;
  for (int i = 0; i < C.size(); i++) {
	  appoggio = C.readT();
	  C.insertH(appoggio);
	  C.removeT();
	  cout << appoggio << " ";
  }


  
  
}
