#include "studente.h"

int main() {
	studente s1;
	studente s2("1", "2", "3", "4", "5");

	s1.setNome("Satana");
	s1.setMatricola("666");

	s2.setNome("Ciccio Cappuccio");
	s2.setMatricola("c1cc10");

	s1.setEsame(20, 0);
	s1.setEsame(18, 2);
	s1.setEsame(19, 4);

	s2.setEsame(27, 0);
	s2.setEsame(28, 1);
	s2.setEsame(26, 2);
	s2.setEsame(30, 3);
	s2.setEsame(30, 4);

	s1.printStudente();
	s2.printStudente();

	return 0;
}