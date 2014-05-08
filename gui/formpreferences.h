#ifndef FORMPREFERENCES_H
#define FORMPREFERENCES_H

#include <QWidget>
#include "data/preferences.h"

namespace Ui {
class FormPreferences;
}

class FormPreferences : public QWidget
{
    Q_OBJECT

public:
    explicit FormPreferences(Preferences *pref, QWidget *parent = 0);
    ~FormPreferences();

private slots:
    void on_pbBrowse_clicked();

    void on_pbSave_clicked();

private:
    Preferences *pref;

    Ui::FormPreferences *ui;


    void fillForm();
};

#endif // FORMPREFERENCES_H
