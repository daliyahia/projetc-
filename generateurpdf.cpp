#include "generateurpdf.h"
#include <QMessageBox>
void GenerateurPDF::genererPDF(QSqlQueryModel* model, const QString& nomFichierPDF) {
    QPdfWriter writer(nomFichierPDF);
    QPainter painter(&writer);

    // Configurer la mise en page
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setRenderHint(QPainter::TextAntialiasing, true);

    // Créer une table pour afficher les données
    int rowCount = model->rowCount();
    int columnCount = model->columnCount();
    int cellWidth = 1996;
    int cellHeight = 400;
    int margin = 10;

    // Dessiner les en-têtes avec bordures
    for (int i = 0; i < columnCount; ++i) {
        // Dessiner le rectangle (bordure)
        painter.drawRect(margin + i * cellWidth, margin, cellWidth, cellHeight);
        // Dessiner le texte à l'intérieur du rectangle
        painter.drawText(margin + i * cellWidth, margin, cellWidth, cellHeight, Qt::AlignCenter, model->headerData(i, Qt::Horizontal).toString().toUtf8());
    }

    // Dessiner les données avec bordures
    for (int row = 0; row < rowCount; ++row) {
        for (int col = 0; col < columnCount; ++col) {
            // Dessiner le rectangle (bordure)
            painter.drawRect(margin + col * cellWidth, margin + (row + 1) * cellHeight, cellWidth, cellHeight);
            // Dessiner le texte à l'intérieur du rectangle
            painter.drawText(margin + col * cellWidth, margin + (row + 1) * cellHeight, cellWidth, cellHeight, Qt::AlignCenter, model->data(model->index(row, col)).toString().toUtf8());
        }
    }

    // Dessiner le rectangle et le texte pour "Fin du document" avec bordure
    painter.drawRect(margin, margin + (rowCount + 1) * cellHeight, columnCount * cellWidth, cellHeight);
    painter.drawText(margin, margin + (rowCount + 1) * cellHeight, columnCount * cellWidth, cellHeight, Qt::AlignCenter, "Fin du document");

    QMessageBox::information(nullptr, "PDF créé", "Le fichier PDF a été créé avec succès !");
}
