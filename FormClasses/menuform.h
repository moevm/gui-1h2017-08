#ifndef MENUFORM_H
#define MENUFORM_H

#include <QWidget>

namespace Ui {
class MenuForm;
}

class MenuForm: public QWidget
{
    Q_OBJECT
public:
    explicit MenuForm(QWidget *parent = 0);
    ~MenuForm();
    Ui::MenuForm *ui;

signals:

public slots:
};

#endif // MENUFORM_H
