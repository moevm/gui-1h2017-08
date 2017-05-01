#ifndef GENERATEFORM_H
#define GENERATEFORM_H

#include <QWidget>

namespace Ui {
class GenerateForm;
}

class GenerateForm : public QWidget
{
    Q_OBJECT
public:
    explicit GenerateForm(QWidget *parent = 0);
    ~GenerateForm();

    Ui::GenerateForm *ui;
signals:

public slots:
};

#endif // GENERATEFORM_H
