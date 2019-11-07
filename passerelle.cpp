#include "passerelle.h"


std::vector<Equipement> Passerelle::chargerLesEquipements(QString unIdBateau)
{
    std::vector<Equipement> equipementsDuBateau;

    JeuEnregistrement recupererEquipement("select equipement.numeroEquipement, libelleEquipement from equipement natural join posseder where bateauId="+unIdBateau);


    while(!recupererEquipement.fin())
    {
        equipementsDuBateau.push_back(Equipement(recupererEquipement.getValeur("numeroEquipement").toInt(),recupererEquipement.getValeur("libelleEquipement").toString()));
        recupererEquipement.suivant();


    }

    recupererEquipement.fermer();

    return equipementsDuBateau;
}

std::vector<BateauVoyageur> Passerelle::chargerLesBateauxVoyageurs()
{
    std::vector<BateauVoyageur> toutLesBateauxVoyageurs;

    JeuEnregistrement recupererBateau("select bateauId,bateauNom,bateauLongueur,bateauLargeur,bateauVitesse,bateauImage from bateau where bateauType='v'");


    while(!recupererBateau.fin())
    {
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
