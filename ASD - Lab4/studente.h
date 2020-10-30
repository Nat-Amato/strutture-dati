class studente{
 public:
	studente();
	void setMatricola(string);
	void setNome(string );
	string getMatricola();
	string getNome();

	void setEsame(int, int);
	double getMedia();

 private:
	esame esami;
	string matricola;
	string nome;
};
    















metodi:
        costruttore di default studente(): imposta i nomi di default dei 5 esami e i rispettivi flag sostenuto a false
        costruttore studente(nome1, nome2, nome3, nome4, nome5): imposta in nomi dei 5 esami usando i parametri nome1, ... e i rispettivi flag sostenuto a false
        setMatricola, setNome, getMatricola, getNome
        getNumEsami: restituisce 5 (numero massimo di esami da sostenere)
        setEsame(Voto,i): imposta il voto dell'esame i-esimo
        getVotoEsame(i), getNomeEsame(i), getSostenuto(i)
        getMedia(): restituisce la media degli esami sostenuti
        printStudente(): visualizza tutte le informazioni dello studente compresi gli esami sostenuti e i rispettivi voti
    campi di esemplare
        matricola: string
        nome: string
        esami: vettore di 5 esami
        const numesami: intero
