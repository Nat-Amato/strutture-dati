 #include "esame.h"

esame::esame() {
	
}

esame::esame(string n) {
	nome = n;
}

esame::esame(string n, int v) {
	nome = n;
	voto = v;
	sostenuto = true;
}

string esame::getEsame() {
	return nome;
}

int esame::getVoto() {
	return voto;
}

void esame::setEsame(string n) {
	nome = n;
}

void esame::setVoto(int v) {
	if (!nome.empty()) {
		voto = v;
		sostenuto = true;
	}
}

bool esame::isSostenuto() {
	return sostenuto;
}