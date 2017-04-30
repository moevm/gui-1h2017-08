#include "campaignform.h"
#include "ui_campaign.h"

CampaignForm::CampaignForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CampaignForm)
{
    ui->setupUi(this);

}
CampaignForm::~CampaignForm()
{
    delete ui;
}
