#include "notification.h"

notification::notification()
{

}
void notification::notifAjouterMateriels()
{
// Crée une icône pour la barre d'état système
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    // Définit une icône
    notifyIcon->setIcon(QIcon());
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des Materiels","Nouveau Materiel est ajoutée ",QSystemTrayIcon::Information,15000);
}

void notification::notifModifierMateriels(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    //notifyIcon->setIcon(QIcon("C:/Users/victo/OneDrive/Bureau/me/dali.jpeg"));
    notifyIcon->show();
    // Affiche un message d'information avec une durée d'affichage de 15 secondes
    notifyIcon->showMessage("Gestion des Materiels","Nouveau Materiel est modifiée",QSystemTrayIcon::Information,15000);
}


void notification::notifSupprimerMatereils(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    //notifyIcon->setIcon(QIcon());
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des Materiels","Nouveau Materiel est supprimée",QSystemTrayIcon::Information,15000);
}

/*
void notification::notif_failed(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    //notifyIcon->setIcon(QIcon());
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des Materiels","Action Failed",QSystemTrayIcon::Critical,15000);
}*/
