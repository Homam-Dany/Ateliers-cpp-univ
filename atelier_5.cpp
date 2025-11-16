//--------------------------------- exercice 1 : --------------------------------------------
#include<iostream>
#include<cstring>
#include <vector>
#include<algorithm>
#include<set> 
using namespace std;

//----------------------------------------------------
//fonction qui recherche et un booleen pour verifie si la valeur exist ou non:
bool rechercher(const set<int>& s, int valeur)
{
    return s.count(valeur) > 0 ; // return 1a valeur existe 0 si non 
}

//-------------------------------------------------------
// fonction qui cherche avec iterateur debut et fin :
bool chercherIt(set<int>::iterator debut , set<int>::iterator fin , int valeur)
{
    return find(debut , fin , valeur) != fin ;
}  
//-------------------------------------------------
// template fonction :
template<typename It , typename T>
bool rechercherTemplate(It debut , It fin , T valeur ){
    return find(debut , fin , valeur ) != fin;
}
//------------------------------------------------
// exemple d'appel:
 int main ()
 {
   
set<int> s; // pour stocker les entiers sans doublons
// remplir le set de 1 a 100:
for ( int i=0 ; i<=100 ; i++){
    s.insert(i); // ajouter chaque nombre au set 
    cout << "Le remplissage ca fait avec succes!" << endl;
}
    cout << "Le remplissage ca fait avec succes!" << endl;
    return 0;
}
/* exemple d'appel :
vector<string> V = { "Je suis " , "Homam " , " Dany "};
cout << rechercherTemplate(V.begin() , V.end() , string("Homam")) << endl ;
*/

//--------------------------------------------Exercice 2 : ---------------------------------------------
#include <iostream>
#include <stdexcept>  // pour les exceptions
using namespace std;

class Test {
public:
    static int tableau[];

    static int division(int indice, int diviseur) {
        if (indice < 0 || indice >= 10)
            throw out_of_range("Indice hors limites !");
        if (diviseur == 0)
            throw runtime_error("Division par zero !");

        return tableau[indice] / diviseur;
    }
};

int Test::tableau[] = {17, 12, 15, 38, 29, 157, 89, -22, 0, 5};

int main() {
    int x, y;

    try {
        cout << "Indice : ";
        cin >> x;
        cout << "Diviseur : ";
        cin >> y;

        cout << "Resultat = " << Test::division(x, y) << endl;
    }
    catch (exception& e) {
        cout << "Erreur : " << e.what() << endl;
    }

    return 0;
}


//-----------------------------Exercice 3 :--------------------------------------------
class vect {
protected:
    int nelem;
    int* adr;
public:
    vect(int n) {
        nelem = n;
        adr = new int[n];
    }
    ~vect() {
        delete[] adr;
    }
    int& operator[](int i) {
        return adr[i];
    }
};

class vectok : public vect {
public:
    vectok(int n) : vect(n) {}

    // Constructeur par copie
    vectok(const vectok& v) : vect(v.nelem) {
        for (int i = 0; i < nelem; i++)
            adr[i] = v.adr[i];
    }

    // Opérateur =
    vectok& operator=(const vectok& v) {
        if (this != &v) {
            nelem = v.nelem;
            delete[] adr;
            adr = new int[nelem];
            for (int i = 0; i < nelem; i++)
                adr[i] = v.adr[i];
        }
        return *this;
    }
};
//prog d'essaie :
int main() {
    vectok a(3);
    a[0] = 5; a[1] = 10; a[2] = 15;

    vectok b = a; // utilisation du constructeur par copie

    b[1] = 99; // ne doit PAS changer a[1]

    cout << a[1] << " " << b[1] << endl;

    return 0;
}
//----------------------------------------exercice 4 :------------------------------------------
#include <iostream>
using namespace std ;
class A
{ int n ;
float x ;
public :
A (int p = 2)
{ n = p ; x = 1 ;
cout << "** construction objet A : " << n << " " << x << "\n" ;
}
} ;
class B
{ int n ;
float y ;
public :
B (float v = 0.0)
{ n = 1 ; y = v ;
cout << "** construction objet B : " << n << " " << y << "\n" ;
}
} ;
class C : public B, public A
{ int n ;
int p ;
public :
C (int n1=1, int n2=2, int n3=3, float v=0.0) : A (n1), B(v)
{ n = n3 ; p = n1+n2 ;
cout << "** construction objet C : " << n << " " << p <<"\n" ;
}
} ;
main()
{ C c1 ;
C c2 (10, 11, 12, 5.0) ;
}
// resultat : 
// const A : 1 1 
// const B : 1 0 
// const C : 6 0 

//-----------------------------exercice 5 : ---------------------------------------------\
#include <iostream>
using namespace std;

// Template qui calcule le carré d'une valeur
template <class T>
T carre(T x) {
    return x * x;
}

int main() {
    cout << "Carre de 5 = " << carre(5) << endl;          // int
    cout << "Carre de 2.5 = " << carre(2.5f) << endl;    // float
    cout << "Carre de 3.14 = " << carre(3.14) << endl;   // double

    return 0;
}


//-----------------------------------------exercice 6 : -------------------------------------------------------
#include <iostream>
using namespace std;

template <class T>
class point {
    T x, y;
public:
    point(T abs, T ord) {
        x = abs;
        y = ord;
    }

    void affiche();
};

// Définition de affiche()
template <class T>
void point<T>::affiche() {
    cout << "Coordonnees : " << int(x) << " " << int(y) << "\n";
}

int main() {
    point<char> p(60, 65);
    p.affiche();

    return 0;
}


//----------------------------------------------exercice 7 : -----------------------------------------------------------
// Resultat final :
// dans f : 999 suite main 