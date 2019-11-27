#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// clasa Persoana (id, nume)
// clasa Abonat:Persoana (nr_telefon)
// clasa Abonat_Skype:Abonat (id_skype)
// clasa Abonat_Skype_Romania:Abonat_Skype (adresa_mail)
// clasa Abonat_Skype_Extern:Abonat_Skype (tara)
// clasa Agenda
//  - lista de abonati
//  - operatorul de indexare [] = abonatul cu numele precizat


// toate clasele: constructori de init parametrizati, copiere, destructor, overload >> << =
// clasele derivate: constructori cu base
// metode pur virtuale
// tratarea exceptiilor
// citirea a n obiecte, memorarea, afisarea lor.

class Persoana
{
protected:
    int id;
    string nume;
public:
    Persoana(int id, string nume) : id(id), nume(nume) { }
    Persoana(const Persoana& p) : id(p.id), nume(p.nume) { }
    virtual ~Persoana() { }

    const string &GetNume() { return nume; }

    friend ostream& operator<<(ostream&, const Persoana&);
    friend istream& operator>>(istream&, Persoana&);
    Persoana& operator =(const Persoana& p)
    {
        if (this != &p)
        {
            id = p.id;
            nume = p.nume;
        }
        return *this;
    }
    virtual Persoana* Clonare()=0;
    virtual void Afisare()=0;
};
ostream& operator<<(ostream& out, const Persoana& persoana) {
    out<<"[Persoana id:"<<persoana.id<<" nume:"<<persoana.nume<<"]";
    return out;
}

istream& operator>>(istream& in, Persoana& persoana) {
    in>>persoana.id>>persoana.nume;
    return in;
}

class Abonat : public Persoana
{
protected:
    string nr_telefon;
public:
    Abonat(int id, string nume, string nr_telefon) : Persoana(id, nume), nr_telefon(nr_telefon) { }
    Abonat(const Abonat& a) : Persoana(a.id, a.nume), nr_telefon(a.nr_telefon) { }
    virtual ~Abonat() { }
    friend ostream& operator<<(ostream&, const Abonat&);
    friend istream& operator>>(istream&, Abonat&);
    Abonat& operator =(const Abonat& a)
    {
        if (this != &a)
        {
            id = a.id;
            nume = a.nume;
            nr_telefon = a.nr_telefon;
        }
        return *this;
    }
    virtual Persoana* Clonare() {
        return new Abonat(*this);
    }
    virtual void Afisare() {
        cout<<*this;
    }
};
ostream& operator<<(ostream& out, const Abonat& abonat) {
    out<<"[Abonat id:"<<abonat.id<<" nume:"<<abonat.nume<<" nr_telefon:"<<abonat.nr_telefon<<"]";
    return out;
}

istream& operator>>(istream& in, Abonat& abonat) {
    in>>abonat.id>>abonat.nume>>abonat.nr_telefon;
    return in;
}

class Abonat_Skype : public Abonat {
protected:
    string id_skype;
public:
    Abonat_Skype(int id, string nume, string nr_telefon, string id_skype) : Abonat(id, nume, nr_telefon), id_skype(id_skype) { }
    Abonat_Skype(const Abonat_Skype& a) : Abonat(a.id, a.nume, a.nr_telefon), id_skype(a.id_skype) { }
    virtual ~Abonat_Skype() { }
    friend ostream& operator<<(ostream&, const Abonat_Skype&);
    friend istream& operator>>(istream&, Abonat_Skype&);
    Abonat_Skype& operator =(const Abonat_Skype& a)
    {
        if (this != &a)
        {
            id = a.id;
            nume = a.nume;
            nr_telefon = a.nr_telefon;
            id_skype = a.id_skype;
        }
        return *this;
    }
    virtual Persoana* Clonare() {
        return (Persoana *)new Abonat_Skype(*this);
    }
    virtual void Afisare() {
        cout<<*this;
    }
};

ostream& operator<<(ostream& out, const Abonat_Skype& abonatSkype) {
    out<<"[Abonat_Skype id:"<<abonatSkype.id<<" nume:"<<abonatSkype.nume<<" nr_telefon:"<<abonatSkype.nr_telefon<<" id_skype:"<<abonatSkype.id_skype<<"]";
    return out;
}

istream& operator>>(istream& in, Abonat_Skype& abonat) {
    in>>abonat.id>>abonat.nume>>abonat.nr_telefon>>abonat.id_skype;
    return in;
}

// clasa Abonat_Skype_Romania:Abonat_Skype (adresa_mail)
class Abonat_Skype_Romania : public Abonat_Skype {
protected:
    string adresa_mail;
public:
    Abonat_Skype_Romania(int id, string nume, string nr_telefon, string id_skype, string adresa_mail) : Abonat_Skype(id, nume, nr_telefon, id_skype), adresa_mail(adresa_mail) { }
    Abonat_Skype_Romania(const Abonat_Skype_Romania& a) : Abonat_Skype(a.id, a.nume, a.nr_telefon, a.id_skype), adresa_mail(a.adresa_mail) { }
    ~Abonat_Skype_Romania() { }
    friend ostream& operator<<(ostream&, const Abonat_Skype_Romania&);
    friend istream& operator>>(istream&, Abonat_Skype_Romania&);
    Abonat_Skype_Romania& operator =(const Abonat_Skype_Romania& a)
    {
        if (this != &a)
        {
            id = a.id;
            nume = a.nume;
            nr_telefon = a.nr_telefon;
            id_skype = a.id_skype;
            adresa_mail = a.adresa_mail;
        }
        return *this;
    }
    Persoana* Clonare() {
        cout<<"clonez abonat skype romania\n";
        return (Persoana *)new Abonat_Skype_Romania(*this);
    }
    void Afisare() {
        cout<<*this;
    }
};

ostream& operator<<(ostream& out, const Abonat_Skype_Romania& abonatSkypeRomania) {
    out<<"[Abonat_Skype_Romania id:"<<abonatSkypeRomania.id
       <<" nume:"<<abonatSkypeRomania.nume
       <<" nr_telefon:"<<abonatSkypeRomania.nr_telefon
       <<" id_skype:"<<abonatSkypeRomania.id_skype
       <<" adresa_mail:"<<abonatSkypeRomania.adresa_mail
       <<"]";
    return out;
}

istream& operator>>(istream& in, Abonat_Skype_Romania& abonat) {
    in>>abonat.id>>abonat.nume>>abonat.nr_telefon>>abonat.id_skype>>abonat.adresa_mail;
    return in;
}

// clasa Abonat_Skype_Extern:Abonat_Skype (tara)
class Abonat_Skype_Extern : public Abonat_Skype {
protected:
    string tara;
public:
    Abonat_Skype_Extern(int id, string nume, string nr_telefon, string id_skype, string tara) : Abonat_Skype(id, nume, nr_telefon, id_skype), tara(tara) { }
    Abonat_Skype_Extern(const Abonat_Skype_Extern& a) : Abonat_Skype(a.id, a.nume, a.nr_telefon, a.id_skype), tara(a.tara) { }
    ~Abonat_Skype_Extern() { }
    friend ostream& operator<<(ostream&, const Abonat_Skype_Extern&);
    friend istream& operator>>(istream&, Abonat_Skype_Extern&);
    Abonat_Skype_Extern& operator =(const Abonat_Skype_Extern& a)
    {
        if (this != &a)
        {
            id = a.id;
            nume = a.nume;
            nr_telefon = a.nr_telefon;
            id_skype = a.id_skype;
            tara = a.tara;
        }
        return *this;
    }
    Persoana* Clonare() {
        return (Persoana *)new Abonat_Skype_Extern(*this);
    }
    void Afisare() {
        cout<<*this;
    }
};

ostream& operator<<(ostream& out, const Abonat_Skype_Extern& abonatSkypeExtern) {
    out<<"[Abonat_Skype_Extern id:"<<abonatSkypeExtern.id
       <<" nume:"<<abonatSkypeExtern.nume
       <<" nr_telefon:"<<abonatSkypeExtern.nr_telefon
       <<" id_skype:"<<abonatSkypeExtern.id_skype
       <<" tara:"<<abonatSkypeExtern.tara
       <<"]";
    return out;
}

istream& operator>>(istream& in, Abonat_Skype_Extern& abonat) {
    in>>abonat.id>>abonat.nume>>abonat.nr_telefon>>abonat.id_skype>>abonat.tara;
    return in;
}

class Agenda {
private:
    int nr;
    Persoana **abonati;
public:
    Agenda(int nr) : nr(nr) {
        abonati = new Persoana*[nr];
        for (int i = 0; i < nr; i++) {
            abonati[i] = NULL;
        }
     }
    Agenda(const Agenda& p) : nr(p.nr) {
        abonati = new Persoana*[nr];
        for (int i = 0; i < nr; i++) {
            abonati[i] = NULL;
            if (p.abonati[i] != NULL) {
                abonati[i] = p.abonati[i]->Clonare();
            }
        }
    }
    ~Agenda() {
        for (int i = 0; i < nr; i++) {
            if (abonati[i] != NULL) {
                delete abonati[i];
            }
        }
        delete abonati;
    }
    void Seteaza(int numar, Persoana *abonat) {
        if (numar < 0 || numar >= nr) {
            throw "Nu pot seta!";
        }
        if (abonati[numar] != NULL) {
            delete abonati[numar];
        }
        abonati[numar] = abonat;
    }
    friend ostream& operator<<(ostream&, const Agenda&);
    friend istream& operator>>(istream&, Agenda&);
    Agenda& operator =(const Agenda& p)
    {
        if (this != &p)
        {
            // stergem ce avem vechi
            for (int i = 0; i < nr; i++) {
                if (abonati[i] != NULL) {
                    delete abonati[i];
                }
            }
            delete abonati;
            
            // setam valori noi
            nr = p.nr;
            abonati = new Persoana*[nr];
            for (int i = 0; i < nr; i++) {
                abonati[i] = NULL;
                if (p.abonati[i] != NULL) {
                    abonati[i] = p.abonati[i]->Clonare();
                }
            }
        }
        return *this;
    }
    Persoana *&operator[] (string nume) {
        for (int i = 0; i < nr; i++) {
            if (abonati[i] != NULL && abonati[i]->GetNume() == nume) {
                return abonati[i];
            }
        }
        throw "Nu exista numele!";
    } 
};

ostream& operator<<(ostream& out, const Agenda& agenda) {
    out<<"Numere in agenda: "<<agenda.nr<<"\n";
    for (int i = 0; i < agenda.nr; i++) {
        if (agenda.abonati[i] == NULL) {
            out<<i<<". - NU EXISTA -";
        } else {
            out<<i<<". ";
            agenda.abonati[i]->Afisare();
            out<<"\n";
        }
    }
    return out;
}
istream& operator>>(istream& in, Agenda& agenda) {
    int nrNou;
    in>>nrNou;
    agenda = Agenda(nrNou);
    return in;
}

int main() {

    int n;
    cout<<"Introduceti numar abonati: ";
    cin>>n;
    Agenda agenda(n);
    for (int i = 0; i < n; i++) {
        cout<<"Citire abonat "<<i + 1<<"\n";
        
        int abonatNr = -1;
        while (abonatNr < 0 || abonatNr > 2) {
            cout<<" * Tip abonat? (0 = Skype, 1 = Romania, 2 = Extern): ";
            cin>>abonatNr;
        }
        string nume;
        string nr_telefon;
        string id_skype;
        cout<<" * Nume? "; cin>>nume;
        cout<<" * Nr telefon? "; cin>>nr_telefon;
        cout<<" * Id Skype? "; cin>>id_skype;
        
        if (abonatNr == 0) {
            Abonat_Skype *abonatSkype = new Abonat_Skype(i, nume, nr_telefon, id_skype);
            agenda.Seteaza(i, abonatSkype);
        } else if (abonatNr == 1) {
            string adresa_mail;
            cout<<" * Adresa Mail? "; cin>>adresa_mail;
            Abonat_Skype_Romania *abonatRomania = new Abonat_Skype_Romania(i, nume, nr_telefon, id_skype, adresa_mail);
            agenda.Seteaza(i, abonatRomania);
        } else {
            string tara;
            cout<<" * Tara? "; cin>>tara;
            Abonat_Skype_Extern *abonatTara = new Abonat_Skype_Extern(i, nume, nr_telefon, id_skype, tara);
            agenda.Seteaza(i, abonatTara);
        }
    }

    cout<<agenda<<"\n\n";

    string cautare;
    while (true) {
        cout<<"CAUTARE ('quit' IESE): "; cin>>cautare;
        if (cautare == "quit") {
            break;
        }
        try {
            agenda[cautare]->Afisare();
            cout<<"\n";
        } catch (const char *eroare) {
            cout<<"EROARE: "<<eroare<<"\n";
        }
    }

    cout<<"Goodbye!\n";
    return 0;
}
