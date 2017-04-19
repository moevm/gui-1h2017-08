#include "levelsetting.h"
#include "ui_levelsetting.h"

LevelSetting::LevelSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LevelSetting)
{
    ui->setupUi(this);
}

LevelSetting::~LevelSetting()
{
    delete ui;
}

void LevelSetting::generatorStart()
{
    emit generateLevel(ui->width->value(),ui->higth->value());
    close();
}
