#ifndef BATEAUVOYAGEUR_H
#define BATEAUVOYAGEUR_H

#include "bateau.h"
#include "equipement.h"
#include <QString>
#include <vector>

class BateauVoyageur: public Bateau
{
private:
    int vitesseBatVoy;
    QString imageBatVoy;
    std::vector<Equipement> listeEquipement;

public:
    BateauVoyageur(int unId, QString unNom, float uneLongueur, float uneLargeur, int uneVitesse, QString uneImage, std::vector<Equipement> collectionEquipement);
    QString versChaine();
    QString getImageBatVoy();
};

#endif // BATEAUVOYAGEUR_H
