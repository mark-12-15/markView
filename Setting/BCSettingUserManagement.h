#ifndef BCSETTINGUSERMANAGEMENT_H
#define BCSETTINGUSERMANAGEMENT_H

#include <QDialog>

namespace Ui {
class BCSettingUserManagement;
}

class BCSettingUserManagement : public QDialog
{
    Q_OBJECT

public:
    explicit BCSettingUserManagement(QWidget *parent = 0);
    ~BCSettingUserManagement();

private:
    Ui::BCSettingUserManagement *ui;
};

#endif // BCSETTINGUSERMANAGEMENT_H
