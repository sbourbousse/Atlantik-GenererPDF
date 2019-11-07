#ifndef PDF_H
#define PDF_H

#include <QString>
#include <QTextDocument>
#include "passerelle.h"

class PDF
{

private:
    QString contenuDuDocument;

public:
    PDF(QString nomDocument);

    void ecrireTexte(QString leTexte);
    void chargerImage(QString chemin);
    void fermer();
};

#endif // PDF_H
