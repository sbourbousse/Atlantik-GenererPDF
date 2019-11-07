#ifndef PASSERELLE_H
#define PASSERELLE_H
#include <vector>
#include <QDebug>
#include "equipement.h"
#include "bateauvoyageur.h"
#include "jeuenregistrement.h"

class Passerelle
{
public:
    static std::vector<Equipement> chargerLesEquipements(QString unIdBateau);
    static std::vector<BateauVoyageur> chargerLesBateauxVoyageurs();
};

#endif // PASSERELLE_H
