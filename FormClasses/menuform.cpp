#include "menuform.h"
#include "ui_menu.h"

MenuForm::MenuForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuForm)
{
    ui->setupUi(this);

}
MenuForm::~MenuForm()
{
    delete ui;
}
