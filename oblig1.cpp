#include <iostream>

using namespace std;
const int LEN = 20;
//deklarasjon av funksjoner
void skrivMeny();
char les(char t[]);
int  les(const char t[], const int min, const int max);
void les(const char t[], char s[], const int LEN);

class Dyr {				//class dyr
private:
	char navn[LEN];		//private data
public:
	Dyr() {				//construtor uten parameter
		les("skriv inn navn ", navn, LEN); //leser inn navn
	}

	Dyr(char t[LEN]) {  //const med parameter
		strcpy_s(navn, t); 
	}
	void dskriv() {							             //skriv funskjonen
		cout <<"navn er "<< navn << endl;
}
};
class DyrILuft : public Dyr {							  //class dyriluft
private:
	int antvinger;										  //private data
public:
	DyrILuft() {								//construtor uten parameter
		antvinger = les("skriv inn antall vinger", 2, 6); //leser antvinger
	}
	void dilskriv() {									 //skriv funksjonen
		Dyr::dskriv();								     
		cout <<"antall vinger er "<<antvinger << endl;
	}
};
class Insekt : public DyrILuft {					//class insekt
private:
	int bein;										//private data
public:
	Insekt() {							     //construtor uten parameter
		bein = les("hvor mange bein har den", 4, 750);
	}
	void iskriv() {									  //skriv funskjonen		
		DyrILuft::dilskriv();						  //sender skriv oppover
		cout <<"den har "<< bein <<" bein"<< endl;	
	}

};
class Fugl : public DyrILuft {						  //class fugl
private: 
	int storelsepaavinger;							//private data
public:
	Fugl(){									//construtor uten parameter
storelsepaavinger = les("skriv inn storelse paa vingene til fugl cm",3,3600);
	}
	void askriv() {									//skriv funskjonen
		DyrILuft::dilskriv();
		cout <<"storelse paa vingene er "<< storelsepaavinger << endl;
	}
};
class DyrIVann : public Dyr {					//class dyrivann
private:
	int størelse;								//private data
public:
	DyrIVann(){									//construtor uten parameter
		størelse = les("størrelse paa dyret ", 10, 1000);
	}
	DyrIVann(char t[LEN]) :Dyr(t) {				//sender navn oppover
		størelse = les("størrelse paa dyret ",10,1000);//og leser sin egen data
	}
	void divskriv() {		//skriv funskjonen
		Dyr::dskriv();
		cout <<"størelse på dyert er "<<størelse << endl;
	}
};
class Fisk : public DyrIVann {						 //class fisk
private:
	char farge[LEN];								//private data
	
public:
	Fisk(){										//construtor uten parameter
		les("hva er fargen til fisken",farge, LEN);	

	}
	Fisk(char t[LEN]):DyrIVann(t){
		les("farge til fisken er?", farge, LEN);	//sender navn oppover
													//og leser sin egen data

	}
	void fskriv() {								//skriv funskjonen
		DyrIVann::divskriv();
		cout <<"farge til fisken er "<< farge<< endl;
	}
};
class Skalldyr : public DyrIVann {				//class skalldyr
private:										//private data
	int vekt;									
public:
	Skalldyr() {						//construtor uten parameter
		vekt=les("hvor mye veier den i gram",1 ,20000);
	}
	void sskriv() {								//skriv funskjonen
		DyrIVann::divskriv();
		cout <<"den veier "<< vekt << endl;
	}
};


int main() {
	char ch = 'w';
	skrivMeny();                   //skriver ut menyen
	while (ch != 'Q') {
		ch = les("onske");
		switch (ch) {				//switch med alle valg

		case 'F': {
			char navn[LEN];			
			les("skriv inn fisk navn", navn, LEN);//leser navn
			if (strlen(navn) == 0) //if blank tekst
			{
				Fisk f1;		//lager f1 obj
				f1.fskriv();	//skriver f1 ut
			}
			else {					//if not blank tekst
				Fisk f2(navn);		//lager f2 obj
				f2.fskriv();		//skrier den ut
			}
								}   break;

		case 'S': {Skalldyr s1;     //lager s1 obj
					s1.sskriv();    //skriver den ut
								 }	break;

		case 'I': { Insekt i1;      //lager i1 obj
			        i1.iskriv();    //skriver den ut
								 }   break;

		case 'A': {Fugl a1;         //lager a1 obj
			       a1.askriv();     //skriver den ut
		}   break;
		
		default:    skrivMeny();    break; //hvis feel kommand skriv ut meny
		}
	
	}
	return 0;
}
//definisjon av funksjoner
void skrivMeny() {          //  Presenterer lovlige menyvalg:
	cout << "\n\nhvilken dyreart vil du regirstrere:\n";
	cout << "\tF = fisk\n";
	cout << "\tS = skalldyr\n";
	cout << "\tI = insekt\n";
	cout << "\tA = fugl\n";
	cout << "\tQ = Quit/avslutt\n";
}

char les(char t[]) {        //  Henter ett ikke-blankt upcaset tegn:
	char ch;
	cout << '\n' << t << ":  ";   //  Skriver medsendt ledetekst.
	cin >> ch;   cin.ignore();    //  Leser ETT tegn. Forkaster '\n'.
	return (toupper(ch));         //  Upcaser og returnerer.
}

int les(const char t[], const int min, const int max) {
	int n;
	do {												// Skriver ledetekst:
		cout << '\t' << t << " (" << min << '-' << max << "): ";
		cin >> n;   cin.ignore();						// Leser inn ett tall.
	} while (n < min || n > max);			 // Sjekker at i lovlig intervall.
	return n;									   // Returnerer innlest tall.
}
												//  Leser en ikke-blank tekst:

void les(const char t[], char s[], const int LEN) {
		cout << '\t' << t << ": ";	cin.getline(s, LEN); //Ledetekst og leser.
}

