#include "passerelle.h"


std::vector<Equipement> Passerelle::chargerLesEquipements(QString unIdBateau)
{
    //Nouveau vecteur vide des equipements du bateau
    std::vector<Equipement> equipementsDuBateau;

    //Requete qui récupère tout les éauipements d'un bateau rentrée en paramètres
    JeuEnregistrement recupererEquipement("select equipement.numeroEquipement, libelleEquipement from equipement natural join posseder where bateauId="+unIdBateau);


    //Tant que le requete renvoie des lignes
    while(!recupererEquipement.fin())
    {
        //J'ajoute à mon vecteur un equipement
        equipementsDuBateau.push_back(Equipement(recupererEquipement.getValeur("numeroEquipement").toInt(),recupererEquipement.getValeur("libelleEquipement").toString()));



        recupererEquipement.suivant();
    }

    recupererEquipement.fermer();

    return equipementsDuBateau;
}

std::vector<BateauVoyageur> Passerelle::chargerLesBateauxVoyageurs()
{
    //Nouveau vecteur vide bateau voyageur
    std::vector<BateauVoyageur> toutLesBateauxVoyageurs;

    //Requete qui récupère tout les bateau voyageurs
    JeuEnregistrement recupererBateau("select bateauId,bateauNom,bateauLongueur,bateauLargeur,bateauVitesse,bateauImage from bateau where bateauType='v'");

    //Tant que la requête renvoie des lignes
    while(!recupererBateau.fin())
    {
        //J'ajoute le bateau à mon vecteur de bateaux
        toutLesBateauxVoyageurs.push_back(BateauVoyageur(recupererBateau.getValeur("bateauId").toInt(),
                                                                         recupererBateau.getValeur("bateauNom").toString(),
                                                                         recupererBateau.getValeur("bateauLongueur").toFloat(),
                                                                         recupererBateau.getValeur("bateauLargeur").toFloat(),
                                                                         recupererBateau.getValeur("bateauVitesse").toInt(),
                                                                         recupererBateau.getValeur("bateauImage").toString(),
                                                                         chargerLesEquipements(recupererBateau.getValeur("bateauId").toString())
                                                                         )
                                          );

        recupererBateau.suivant();
    }

    recupererBateau.fermer();
    return toutLesBateauxVoyageurs;
}
