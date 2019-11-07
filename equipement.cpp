#include "equipement.h"
#include <QString>

Equipement::Equipement(int unId, QString unLib)
{
    idEquip=unId;
    libEquip=unLib;
}

QString Equipement::versChaine()
{
   return libEquip;
}
