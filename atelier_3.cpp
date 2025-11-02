//----------------------------------------------- exercice 1 :---------------------------------------------------------------------------
#include <iostream>
using namespace std;

// Déclaration de la classe Pile
class Pile
{
private:
    int *tab;     // pointeur vers un tableau d'entiers (notre pile)
    int taille;   // nombre d'éléments actuellement dans la pile
    int capacite; // taille totale du tableau (la capacité max actuelle)

public:
    Pile()
    {
        capacite = 5;            // on commence avec 5 cases
        tab = new int[capacite]; // on réserve un tableau de 5 entiers
        taille = 0;              // la pile est vide au départ
    }

    // Destructeur : ce qui s'exécute quand la pile est détruite
    ~Pile()
    {
        delete[] tab; // on libère la mémoire qu'on avait réservée
    }

    // Fonction pour ajouter un élément sur la pile
    void push(int valeur)
    {
        if (taille == capacite)
        { // si la pile est pleine
            cout << "Pile pleine, on augmente la taille...\n";
            capacite *= 2;                    // on double la taille du tableau
            int *nouveau = new int[capacite]; // nouveau tableau plus grand

            // on copie les anciens éléments dedans
            for (int i = 0; i < taille; i++)
                nouveau[i] = tab[i];

            delete[] tab;  // on supprime l’ancien tableau
            tab = nouveau; // et on le remplace
        }

        tab[taille] = valeur; // on met la nouvelle valeur
        taille++;             // la pile a un élément de plus
    }

    // Fonction pour enlever le dernier élément ajouté
    int pop()
    {
        if (taille == 0)
        { // si la pile est vide
            cout << "Erreur : pile vide !\n";
            return -1; // valeur spéciale pour dire erreur
        }
        taille--;           // on enlève 1 élément
        return tab[taille]; // on retourne la valeur retirée
    }

    // Fonction pour savoir si la pile est vide
    bool estVide()
    {
        return (taille == 0);
    }
};

int main()
{
    Pile p; // on crée une pile appelée p

    // On ajoute des nombres sur la pile
    p.push(10);
    p.push(20);
    p.push(30);

    // On enlève les éléments un par un
    while (!p.estVide())
    { // tant que la pile n'est pas vide
        cout << "On retire : " << p.pop() << endl;
    }

    return 0;
}

// ------------------------------------------------------exercice 2:---------------------------------------------------------------

#include <iostream>
using namespace std;

class Fichier
{
private:
    char *P;      // pointeur vers une zone mémoire (comme le contenu du fichier)
    int longueur; // taille de la mémoire allouée

public:
    // Constructeur (appelé quand on crée un Fichier)
    Fichier()
    {
        P = nullptr;  // au départ, rien n'est alloué
        longueur = 0; // donc longueur = 0
        cout << "Constructeur appele ✅" << endl;
    }

    // allouer une zone mémoire
    void Creation(int taille)
    {
        longueur = taille;      // on enregistre la taille demandée
        P = new char[longueur]; // on réserve un tableau de "taille" octets
        cout << "Mémoire de " << longueur << " octets allouée ✅" << endl;
    }

    // remplir la mémoire avec des valeurs arbitraires
    void Remplir()
    {
        if (P == nullptr)
        {
            cout << "Erreur : aucune mémoire allouée !" << endl;
            return;
        }
        // on remplit la mémoire avec des lettres
        for (int i = 0; i < longueur; i++)
        {
            P[i] = 'A' + (i % 26); // A, B, C... Z puis recommence
        }
        cout << "Mémoire remplie ✅" << endl;
    }

    // afficher le contenu de la mémoire
    void Affiche()
    {
        if (P == nullptr)
        {
            cout << "Rien à afficher !" << endl;
            return;
        }

        cout << "Contenu du fichier : ";
        for (int i = 0; i < longueur; i++)
        {
            cout << P[i]; // on affiche chaque caractère
        }
        cout << endl;
    }

    // Destructeur : libère la mémoire automatiquement à la fin
    ~Fichier()
    {
        delete[] P; // libération de la mémoire
        cout << "Destructeur appele, mémoire libérée 🗑" << endl;
    }
};

int main()
{
    // Création d’un objet Fichier
    Fichier f1;

    // Appel des méthodes une par une
    f1.Creation(10); // on alloue 10 cases
    f1.Remplir();    // on met des lettres dedans
    f1.Affiche();    // on affiche le contenu

    // quand le programme se termine, le destructeur est appelé automatiquement
    return 0;
}

//------------------------------------------------ exercice 3 :-------------------------------------------------------------------

#include <iostream>
using namespace std;

// Structure représentant un élément de la liste
struct Element
{
    int valeur;       // la donnée (par exemple un nombre)
    Element *suivant; // pointeur vers le prochain élément
};

// Classe Liste
class Liste
{
private:
    Element *tete; // pointeur vers le premier élément de la liste

public:
    // Constructeur : liste vide au départ
    Liste()
    {
        tete = nullptr;
        cout << "Liste créée (vide) ✅" << endl;
    }

    // ajouter un élément au début de la liste
    void ajouterDebut(int val)
    {
        // créer un nouvel élément
        Element *nouveau = new Element;
        nouveau->valeur = val;   // on met la valeur
        nouveau->suivant = tete; // il pointe vers l’ancien premier
        tete = nouveau;          // il devient la nouvelle tête
        cout << "Ajout de " << val << " au début ✅" << endl;
    }

    // supprimer le premier élément
    void supprimerDebut()
    {
        if (tete == nullptr)
        { // si la liste est vide
            cout << "Liste vide, rien à supprimer ❌" << endl;
            return;
        }
        Element *temp = tete; // on garde l’adresse du premier élément
        tete = tete->suivant; // on passe au suivant
        cout << "Suppression de " << temp->valeur << " ✅" << endl;
        delete temp; // on libère l’ancien premier élément
    }

    // afficher la liste
    void afficher()
    {
        if (tete == nullptr)
        {
            cout << "Liste vide ❌" << endl;
            return;
        }

        cout << "Contenu de la liste : ";
        Element *courant = tete;
        while (courant != nullptr)
        {
            cout << courant->valeur << " ";
            courant = courant->suivant;
        }
        cout << endl;
    }

    // Destructeur : libère toute la mémoire quand la liste est détruite
    ~Liste()
    {
        Element *courant = tete;
        while (courant != nullptr)
        {
            Element *temp = courant;
            courant = courant->suivant;
            delete temp;
        }
        cout << "Mémoire libérée, liste détruite 🗑" << endl;
    }
};
int main()
{
    Liste maListe; // création d'une liste vide

    maListe.ajouterDebut(10);
    maListe.ajouterDebut(20);
    maListe.ajouterDebut(30);

    maListe.afficher(); // affiche : 30 20 10

    maListe.supprimerDebut();
    maListe.afficher(); // affiche : 20 10

    return 0;
}

//--------------------------------------------------exercice 4:-------------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;
class Client
{
private:
    int id;
    string nom;
    string prenom;

public:
    Client() : id(0), nom(""), prenom("")
    {
        cout << "Client par défaut créé." << endl;
    }

    // --- Constructeur avec paramètres ---
    Client(int id, string nom, string prenom)
        : id(id), nom(nom), prenom(prenom)
    {
        cout << "Client " << prenom << " " << nom << " créé." << endl;
    }

    // --- Constructeur de copie ---
    Client(const Client &autre)
        : id(autre.id), nom(autre.nom), prenom(autre.prenom)
    {
        cout << "Copie du client " << prenom << " " << nom << " effectuée." << endl;
    }

    // --- Destructeur ---
    ~Client()
    {
        cout << "Destruction du client " << prenom << " " << nom << endl;
    }

    // --- Méthode d'affichage ---
    void afficher() const
    {
        cout << "Client #" << id << " : " << prenom << " " << nom << endl;
    }
};
class Compte
{
private:
    int numero;           // Numéro du compte
    float solde;          // Solde du compte
    Client *client;       // Pointeur vers un client associé
    static int nbComptes; // Variable statique pour compter les comptes existants

public:
    // --- Constructeur par défaut ---
    Compte() : numero(0), solde(0.0), client(nullptr)
    {
        nbComptes++; // on augmente le nombre de comptes
        cout << "Compte par défaut créé. Total comptes = " << nbComptes << endl;
    }

    // --- Constructeur avec paramètres ---
    Compte(int numero, float solde, const Client &c)
        : numero(numero), solde(solde)
    {
        // On crée une copie dynamique du client
        client = new Client(c);
        nbComptes++;
        cout << "Compte #" << numero << " créé pour ";
        client->afficher();
        cout << "Total comptes = " << nbComptes << endl;
    }

    // --- Constructeur de copie ---
    Compte(const Compte &autre)
        : numero(autre.numero), solde(autre.solde)
    {
        // Copie profonde : on crée un nouveau client dynamique
        client = new Client(*autre.client);
        nbComptes++;
        cout << "Compte #" << numero << " copié. Total comptes = " << nbComptes << endl;
    }

    // --- Destructeur ---
    ~Compte()
    {
        cout << "Destruction du compte #" << numero << endl;
        delete client; // libère la mémoire du client
        nbComptes--;   // on diminue le nombre total
        cout << "Compte détruit. Total comptes = " << nbComptes << endl;
    }

    // --- Méthode d'affichage ---
    void afficher() const
    {
        cout << "---- Informations du compte ----" << endl;
        cout << "Numéro : " << numero << endl;
        cout << "Solde : " << solde << " €" << endl;
        if (client)
            client->afficher();
        else
            cout << "Aucun client associé." << endl;
        cout << "--------------------------------" << endl;
    }

    // --- Méthode statique pour afficher le nombre total de comptes ---
    static void afficherNbComptes()
    {
        cout << "Nombre total de comptes existants : " << nbComptes << endl;
    }

    // --- Accesseurs pour modifier ou lire le solde ---
    float getSolde() const { return solde; }
    void setSolde(float nouveauSolde) { solde = nouveauSolde; }
};

// Initialisation du membre statique
int Compte::nbComptes = 0;
// Fonction globale qui calcule le nouveau solde après application des intérêts
inline float calculInteret(float solde, float taux)
{
    return solde + (solde * taux / 100);
}
int main()
{
    cout << "=== Début du programme de gestion bancaire ===" << endl;

    // Création de clients
    Client c1(1, "Dupont", "Jean");
    Client c2(2, "Durand", "Marie");

    // Création de comptes
    Compte compte1(1001, 1500.0, c1);
    Compte compte2(1002, 2500.0, c2);

    // Affichage du nombre total de comptes
    Compte::afficherNbComptes();

    // Copie d’un compte
    Compte compte3 = compte1; // constructeur de copie
    Compte::afficherNbComptes();

    // Affichage des informations
    compte1.afficher();
    compte3.afficher();

    // Application d’intérêts
    cout << "\n--- Application des intérêts ---" << endl;
    float nouveauSolde = calculInteret(compte1.getSolde(), 5.0); // 5% d’intérêt
    compte1.setSolde(nouveauSolde);
    compte1.afficher();

    // Destruction de comptes (automatique à la fin du bloc)
    cout << "\n--- Fin du programme ---" << endl;
    Compte::afficherNbComptes();

    return 0;
}
