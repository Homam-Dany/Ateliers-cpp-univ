/*
//----------------------------------------Exercice 1:--------------------------------------------------------------
#include <iostream>
#include<string>
#include<vector>
using namespace std;
class base_Ressource{
    protected:
    int id;
    string titre;
    string auteur;
    int annee ;
    public:
    base_Ressource(int i,string t,string a , int an)
    {
        id = i;
        titre = t;
        auteur = a ;
        annee = an ;
    }
    virtual void afficherInfo() const // virtuel c'est pour utiliser ce champs la dans les classes derives
    {
        cout << "ID : " << id << endl;
        cout << "Titre : " << titre << endl;
        cout << "Auteur : " << auteur << endl;
        cout << "Annee : " << annee << endl;
    }
    virtual void telecharger() const
    {
        cout << "Telechargement des ressources...." << endl ;
    }
     bool operator==(const base_Ressource& r) const {
        return id == r.id;
    }
    int getId()
    {
        return id ;
    }
    int getAnnee()
    {
        return annee;
    }
    string getTitre()
    {
        return titre;
    }
    string getAuteur()
    {
        return auteur;
    }
};
class Telechargeable{
    public:
    void telecharger()
    {
        cout << " telechargement ......" << endl ;
    }
    void afficherMessage()
    {
        cout << " cette ressource est telechargeable " << endl;
    }
};
class Livre : public base_Ressource , public Telechargeable
{
    private:
    int nbPages;
    public:
    Livre(int i , string t , string a , int an , int nb):base_Ressource(i,t,a,an)
    {
        nbPages = nb ;
    }
    void afficherInfo() const override
    {
        cout << "Livre" << endl;
        base_Ressource::afficherInfo();
        cout << " nombre de page:" << nbPages << endl;
    };
    void telecharger() const override
    {
        cout << " telechargement de livre " << titre << "......" << endl;
    }
};
class Magazine : public base_Ressource , public Telechargeable
{
    private:
    int numero ;
    public:
    Magazine(int i , string t , string a , int an , int num): base_Ressource (i,t,a,an)
    {
        numero = num ;
    }
    void afficherInfo() const override
    {
        cout << "Magazine" << endl;
        base_Ressource::afficherInfo();
        cout << " Numero:" << numero << endl;
    };
    void telecharger() const override
    {
        cout << " telechargement du magazine " << titre << "......" << endl;
    }
};
class video : public base_Ressource , public Telechargeable
{
    private:
    int duree ;
    public:
    video(int i , string t , string a , int an , int dur): base_Ressource (i,t,a,an)
    {
        duree = dur ;
    }
    void afficherInfo() const override
    {
        cout << "video" << endl;
        base_Ressource::afficherInfo();
        cout << " Duree:" << duree << endl;
    };
    void telecharger() const override
    {
        cout << " telechargement du video " << titre << "......" << endl;
    }
};
class Mediatheque {
    private:
    vector<base_Ressource*> ressource;
    public:
    void ajouterRessource(base_Ressource* r)
    {
        ressource.push_back(r);
    }
    void afficherRessource() const // affichage pour tous
    {
        cout << "listes des ressources est :"<<endl;
        for (auto r:ressource)
        r->afficherInfo(); // polymorphisme
    }
    void rechercher(const string& titre) const {
        cout << "Recherche par titre : " << titre << endl;
        for (auto r : ressource)
            if (r->getTitre() == titre)
                r->afficherInfo();
    }
    void rechercher(int annee) const {
        cout << "Recherche par année : " << annee << endl;
        for (auto r : ressource)
            if (r->getAnnee() == annee)
                r->afficherInfo();
    }
    void rechercher(const string& auteur, int annee) const {
        cout << "Recherche par auteur + année : " << auteur << ", " << annee << endl;
        for (auto r : ressource)
            if (r->getAuteur() == auteur && r->getAnnee() == annee)
                r->afficherInfo();
    }
};
int main() {
    // Création d'objets de chaque type
    Livre l1(1, "Les Misérables", "Victor Hugo", 1862, 1488);
    Livre l2(2, "Le Petit Prince", "Antoine de Saint-Exupéry", 1943, 96);
    Magazine m1(3, "Science & Vie", "Collectif", 2023, 128);
    video v1(4, "Inception", "Christopher Nolan", 2010, 148);

    // Affichage des informations
    l1.afficherInfo();
    m1.afficherInfo();
    v1.afficherInfo();

    // Téléchargement (plusieurs versions)
    cout << "\n--- Test de téléchargement ---" << endl;
    l1.telecharger();                  // version Livre
    l1.Telechargeable::telecharger();  // version Telechargeable
    l1.base_Ressource::telecharger();       // version Ressource

    // Comparaison entre deux ressources
    cout << "\n--- Comparaison ---" << endl;
    if (l1 == l2)
        cout << "Les deux livres ont le même ID." << endl;
    else
        cout << "Les deux livres sont différents." << endl;

    // Création d'une médiathèque et ajout des ressources
    Mediatheque med;
    med.ajouterRessource(&l1);
    med.ajouterRessource(&l2);
    med.ajouterRessource(&m1);
    med.ajouterRessource(&v1);

    // Affichage complet
    med.afficherRessource();
    //Recherche
    med.rechercher("Inception");
    med.rechercher(2023);
    med.rechercher("Victor Hugo", 1862);

    return 0;
}

*/



// -----------------------------------Exercice 2:----------------------------------------------------

#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;
class client
{
    public:
    string nom;
    string CIN;
    int id;
    client(const string& nom_ , const string& CIN_ , int id_)
    {
        nom = nom_;
        CIN = CIN_;
        id = id_;
    }
};
class compteBancaire
{
    private:
    int numero ;
    double solde;
    string codeSecret;
    client* proprietaire;
    public:
    compteBancaire(int num , double sol , const string& code , client* prop)
    {
        numero = num;
        solde = sol;
        codeSecret = code;
        proprietaire = prop;
    }
    void deposer (double montant)
    {
        if (montant > 0){
            solde+=montant;
            cout<<"depot de " << montant <<"effectuer sur compte" << numero << "nouveau solde:" << solde << endl;
        }
        else{
            cout << "montant invalide" ;
        }
    }
    void afficherInfosPubliques() const
    {
        cout << "compte #" << numero 
             << "|proprietaire:" << proprietaire->nom
             <<"| solde :" << fixed << setprecision(2)<< solde<< endl;
    }
    friend class AgentBanque;
    friend class Banque;
};
class AgentBanque
{
    private:
    string nomAgent;
    public:
    AgentBanque(const string& nom)
    {
        nomAgent = nom;
    }
    bool retirer (compteBancaire& compte , const string& codeFournit , double montant)
    {
        if (codeFournit!=compte.codeSecret){
            cout << "code sec incorrect" ;
            return false;
        }
        if (montant <= 0) {
            cout << "Montant invalide";
            return false;
        }
        if (montant > compte.solde) {
            cout << "Solde insuffisant";
            return false;
        }
        compte.solde -= montant;
        cout << "Retrait de " << montant << "effectuer par l'agent " << nomAgent
             << "sur compte " << compte.numero<< "nouveau solde :"<< compte.solde << endl;

    }
     bool transferer(compteBancaire& from, const string& codeFrom, compteBancaire& to, double montant) {
        if (codeFrom != from.codeSecret) {
            cout << "Code secret incorrect pour le compte source. Transfert refuse.\n";
            return false;
        }
        if (montant <= 0) {
            cout << "Montant invalide.\n";
            return false;
        }
        if (montant > from.solde) {
            cout << "Solde insuffisant sur le compte source.\n";
            return false;
        }
        from.solde -= montant;
        to.solde += montant;
        cout << "Transfert de " << montant << " effectué par l'agent " << nomAgent
             << " depuis compte " << from.numero << " vers compte " << to.numero << ".\n";
        cout << "Nouveau solde (source): " << from.solde << " | (dest): " << to.solde << endl;
        return true;
    }

    string getNomAgent() const { return nomAgent; }
};
class Banque {
private:
    string nomBanque;
    vector<compteBancaire*> comptes;

public:
    Banque(const string& nom) : nomBanque(nom) {}

    void ajouterCompte(compteBancaire* compte) {
        comptes.push_back(compte);
    }
    void afficherTousComptes() const {
        cout << "---- Comptes (informations publiques) ----\n";
        for (auto c : comptes) c->afficherInfosPubliques();
        cout << "------------------------------------------\n";
    }
    void rapportAudit() const {
        cout << "==== Rapport d'audit interne de la banque: " << nomBanque << " ====\n";
        for (auto c : comptes) {
            cout << "Compte #" << c->numero
                 << " | Proprietaire: " << c->proprietaire->nom
                 << " | CIN: " << c->proprietaire->CIN
                 << " | Solde: " << fixed << setprecision(2) << c->solde
                 << " | CodeSecret: " << c->codeSecret << "\n";
        }
        cout << "====================================================\n";
    }
};

int main() {
    // Création de quelques clients
    client c1("Ali", "CIN12345", 1);
    client c2("Sara", "CIN54321", 2);

    // Création des comptes (numéro, solde initial, code secret, propriétaire)
    compteBancaire compte1(1001, 500.0, "codeAli", &c1);
    compteBancaire compte2(2002, 1000.0, "codeSara", &c2);

    // Création de la banque et ajout des comptes
    Banque banque("BanqueDemo");
    banque.ajouterCompte(&compte1);
    banque.ajouterCompte(&compte2);

    // Création d'un agent autorisé
    AgentBanque agent("Ahmed");

    // Afficher états publics
    banque.afficherTousComptes();

    // Dépôt (n'a pas besoin d'agent)
    compte1.deposer(200.0);

    // Tentative de retrait avec mauvais code
    agent.retirer(compte1, "mauvaisCode", 100.0);

    // Retrait avec le bon code
    agent.retirer(compte1, "codeAli", 100.0);

    // Transfert de compte2 vers compte1 (avec vérification du code du compte source)
    agent.transferer(compte2, "codeSara", compte1, 150.0);

    // Afficher état public après opérations
    banque.afficherTousComptes();

    // Rapport d'audit (affiche aussi les codes secrets — réservé à la banque/interne)
    banque.rapportAudit();

    return 0;

};
       
