 #ifndef _ESAME_H
 #define _ESAME_H
 
 #include 

 class esame{
 public:
   esame();
   esame(string);
   esame(string, int);
   	esame(string, int);
	string getEsame();
	void setEsame(string n);
	int getVoto();
	void setVoto(int v);
	bool isSostenuto();
 private:
   string nome;
	 bool sostenuto;
	 int voto;
 };

#endif // _ESAME_H 
