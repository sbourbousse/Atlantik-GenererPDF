#include "pdf.h"
#include <QPrinter>
#include "bateauvoyageur.h"
#include <vector>

PDF::PDF(QString nomDocument)
{
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(nomDocument+".pdf");

    //Creer le document PDF Vierge "nomDocument"
    QTextDocument *leDocument = new QTextDocument;

    contenuDuDocument = "<html><head><meta charset=\"utf8\"><style type=\"text/css\" media=\"print\" >.representation{page-break-inside:avoid;page-break-after:auto;page-break-before:auto;}</head><body>";



    std::vector<BateauVoyageur> mesBateaux = Passerelle::chargerLesBateauxVoyageurs();



    for(int i = 0 ; i<mesBateaux.size() ; i++)
    {

        contenuDuDocument+="<div class=\"representation\"><div>";
        chargerImage(mesBateaux[i].getImageBatVoy());
        contenuDuDocument+="</div>";
        ecrireTexte(mesBateaux[i].versChaine());
        contenuDuDocument+="</div>";
    }

    contenuDuDocument +="</body></html>";

    qDebug()<<contenuDuDocument;
    leDocument->setHtml(contenuDuDocument);

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
