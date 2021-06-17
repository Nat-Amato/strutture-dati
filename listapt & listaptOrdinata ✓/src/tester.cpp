#include "linked_list.h"
#include "Ordered_list.h"
#include <iostream>

using namespace std;


int main(){
  Linked_list<string> list1;
  Linked_list<string>::position iter;

	string x;

	/* inserting three elements into the list list1 */
	x = "alberto";
  list1.insert(x, list1.begin());
	x = "adlerto";
  list1.insert(x, list1.begin());
	x = "aflerto";
  list1.insert(x, list1.begin());
	x = "adlerto";
  list1.insert(x, list1.begin());
	x = "aelerto";
  list1.insert(x, list1.begin());

  Ordered_list<string> list2(list1);

  cout << list1;
  list2.merge(list2);
  cout << list2.getList();


  return 0;
}
