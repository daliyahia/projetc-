#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QSystemTrayIcon>
#include<QString>

class notification
{
public:
    notification();
    void notifAjouterMateriels();
    void notifSupprimerMatereils();
    void notifModifierMateriels();
    //void notif_failed();

};

#endif // NOTIFICATION_H
