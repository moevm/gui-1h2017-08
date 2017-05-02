#ifndef CAMPAINGNFORM_H
#define CAMPAINGNFORM_H

#include <QWidget>

namespace Ui {
class CampaignForm;
}

class CampaignForm : public QWidget
{
    Q_OBJECT
public:
    explicit CampaignForm(QWidget *parent = 0);
    ~CampaignForm();


    Ui::CampaignForm *ui;
signals:

public slots:
  //  void resizeEvent(QResizeEvent * event);
};

#endif // CAMPAINGNFORM_H
