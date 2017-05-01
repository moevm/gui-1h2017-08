#include "generateform.h"
#include "ui_generatelevel.h"

GenerateForm::GenerateForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GenerateForm)
{
    ui->setupUi(this);

}
GenerateForm::~GenerateForm()
{
    delete ui;
}
