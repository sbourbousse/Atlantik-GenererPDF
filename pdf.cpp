#include "pdf.h"
#include <QPrinter>
#include "bateauvoyageur.h"
#include <vector>

PDF::PDF(QString nomDocument)
{
    //Nouvelle instance de QPrinter + parametrage
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(nomDocument+".pdf");

    //Creer le document PDF Vierge "nomDocument"
    QTextDocument *leDocument = new QTextDocument;

    //Entetes de la page au format HTML
    contenuDuDocument = "<html><head><meta charset=\"utf8\"><style type=\"text/css\" media=\"print\" >.representation{page-break-inside:avoid;page-break-after:auto;page-break-before:auto;}</head><body>";

    //Je récupère tout les bateaux voyageurs
    std::vector<BateauVoyageur> mesBateaux = Passerelle::chargerLesBateauxVoyageurs();

    //Je renvoie l'image et les information de chaque bateau à ma page au format HTML
    for(int i = 0 ; i<mesBateaux.size() ; i++)
    {

        contenuDuDocument+="<div class=\"representation\"><div>";
        chargerImage(mesBateaux[i].getImageBatVoy());
        contenuDuDocument+="</div>";
        ecrireTexte(mesBateaux[i].versChaine());
        contenuDuDocument+="</div>";
    }

    //Fin de la page au format HTML
    contenuDuDocument +="</body></html>";

    //qDebug()<<contenuDuDocument;

    //J'ajoute mon contenue HTML a mon document
    leDocument->setHtml(contenuDuDocument);

    //Je donne un format à la page et je l'exporte (dossier Debug par défaut)
    leDocument->setPageSize(printer.pageRect().size());
    leDocument->print(&printer);

    delete leDocument;
}

void PDF::ecrireTexte(QString leTexte)
{
    contenuDuDocument += leTexte;
}

void PDF::chargerImage(QString chemin)
{
    contenuDuDocument += "<center><img height=\"150\" width=\"350\" src=\""+chemin+"\"></center>";
}
