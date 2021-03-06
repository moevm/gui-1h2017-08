#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_campaign.h"
#include "ui_generatelevel.h"
#include "ui_menu.h"
#include <QMediaPlayer>
#include <QDir>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->GameFiels->hide();

    this->setGeometry(100,100,1000,600);

    initParameters();

  /*  QMediaPlayer  *player = new QMediaPlayer();
    player->setMedia(QUrl::fromLocalFile("/sound/theme.mp3"));
    player->setVolume(50);
    player->play();
    */
}
void MainWindow::initParameters()
{
    menuForm = new MenuForm(ui->centralWidget);
    menuForm->move(this->size().width()/2 - menuForm->size().width()/2, this->size().height()/2 - menuForm->size().height()/2 );
    menuForm->ui->continueGame->hide();
    QObject::connect(menuForm->ui->exit, SIGNAL(pressed()), this, SLOT(close()));
    QObject::connect(menuForm->ui->campaign, SIGNAL(pressed()), this, SLOT(openLevelSelector()));
    QObject::connect(menuForm->ui->gameWithSetting, SIGNAL(pressed()), this, SLOT(startGameWithSettings()));
    QObject::connect(menuForm->ui->continueGame, SIGNAL(pressed()), this, SLOT(continueCampaign()));

    cForm = new CampaignForm(ui->centralWidget);
    cForm->move(this->size().width()/2 - cForm->size().width()/2, this->size().height()/2 - cForm->size().height()/2 );
    QObject::connect(cForm->ui->cancel, SIGNAL(pressed()), this, SLOT(openMenu()));
    QObject::connect(this, SIGNAL(startLevel(int)), this->ui->GameFiels, SLOT(startCampaign(int)));
    QObject::connect(cForm->ui->level1, SIGNAL(pressed()), this, SLOT(startLevel1()));
    QObject::connect(cForm->ui->level2, SIGNAL(pressed()), this, SLOT(startLevel2()));
    QObject::connect(cForm->ui->level3, SIGNAL(pressed()), this, SLOT(startLevel3()));
    QObject::connect(cForm->ui->level4, SIGNAL(pressed()), this, SLOT(startLevel4()));
    QObject::connect(cForm->ui->level5, SIGNAL(pressed()), this, SLOT(startLevel5()));
    QObject::connect(cForm->ui->level6, SIGNAL(pressed()), this, SLOT(startLevel6()));
    QObject::connect(cForm->ui->level7, SIGNAL(pressed()), this, SLOT(startLevel7()));
    QObject::connect(cForm->ui->level8, SIGNAL(pressed()), this, SLOT(startLevel8()));
    QObject::connect(cForm->ui->level9, SIGNAL(pressed()), this, SLOT(startLevel9()));
    QObject::connect(cForm->ui->level10, SIGNAL(pressed()), this, SLOT(startLevel10()));
    cForm->hide();


    generateForm = new GenerateForm(ui->centralWidget);
    generateForm->move(this->size().width()/2 - generateForm->size().width()/2, this->size().height()/2 - generateForm->size().height()/2 );
    QObject::connect(generateForm->ui->cancel, SIGNAL(pressed()), this, SLOT(openMenu()));
    QObject::connect(generateForm->ui->generateLevel, SIGNAL(pressed()), this, SLOT(generatorStart()));
    QObject::connect(this, SIGNAL(generateLevel(int,int)), this->ui->GameFiels, SLOT(generateLevel(int,int)));

    QObject::connect(this->ui->GameFiels, SIGNAL(keyEscapePressed()), this, SLOT(openMenu()));
    generateForm->hide();

    ui->GameFiels->hide();

    //cForm->hide();

}

void MainWindow::resizeEvent(QResizeEvent *resize)
{
    cForm->move(this->size().width()/2 - cForm->size().width()/2, this->size().height()/2 - cForm->size().height()/2 );
    menuForm->move(this->size().width()/2 - menuForm->size().width()/2, this->size().height()/2 - menuForm->size().height()/2 );
    generateForm->move(this->size().width()/2 - generateForm->size().width()/2, this->size().height()/2 - generateForm->size().height()/2 );
}


MainWindow::~MainWindow()
{
    delete ui;
    delete cForm;
    delete generateForm;
    delete menuForm;
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key() == Qt::Key_Escape  )
    {
        if(this->ui->GameFiels->isVisible())
        {
            this->menuForm->ui->continueGame->show();
            emit openMenu();
        }
        else if (this->gameStarted)
        {
            this->continueCampaign();
        }
    }
}

void MainWindow::startCampaign()
{
    this->gameStarted = true;
    emit this->ui->GameFiels->startCampaign(1);
}

void MainWindow::continueCampaign()
{
    this->menuForm->hide();
    cForm->hide();
    generateForm->hide();
    this->ui->GameFiels->continueCampaign();
}

void MainWindow::startGameWithSettings()
{
    this->menuForm->hide();
    this->generateForm->show();
}

void MainWindow::openMenu()
{
    cForm->hide();
    generateForm->hide();
    ui->GameFiels->hide();

    menuForm->show();
}

void MainWindow::openLevelSelector()
{
    menuForm->hide();
    cForm->show();
}
void MainWindow::generatorStart()
{
    generateForm->hide();
    this->gameStarted = true;
    emit generateLevel(generateForm->ui->width->value()%2 != 0? generateForm->ui->width->value(): generateForm->ui->width->value()+1,
                       generateForm->ui->higth->value()%2 != 0? generateForm->ui->higth->value(): generateForm->ui->higth->value()+1);
}

void MainWindow::startLevel1()
{
    cForm->hide();
    this->gameStarted = true;
    this->ui->GameFiels->show();
    emit startLevel(1);
}
void MainWindow::startLevel2()
{
    cForm->hide();
    this->gameStarted = true;
    this->ui->GameFiels->show();
    emit startLevel(2);
}
void MainWindow::startLevel3()
{
    cForm->hide();
    this->gameStarted = true;
    this->ui->GameFiels->show();
    emit startLevel(3);
}
void MainWindow::startLevel4()
{
    cForm->hide();
    this->gameStarted = true;
    this->ui->GameFiels->show();
    emit startLevel(4);
}
void MainWindow::startLevel5()
{
    cForm->hide();
    this->gameStarted = true;
    this->ui->GameFiels->show();
    emit startLevel(5);
}
void MainWindow::startLevel6()
{
    cForm->hide();
    this->gameStarted = true;
    this->ui->GameFiels->show();
    emit startLevel(6);
}
void MainWindow::startLevel7()
{
    cForm->hide();
    this->gameStarted = true;
    this->ui->GameFiels->show();
    emit startLevel(7);
}
void MainWindow::startLevel8()
{
    cForm->hide();
    this->gameStarted = true;
    this->ui->GameFiels->show();
    emit startLevel(8);
}
void MainWindow::startLevel9()
{
    cForm->hide();
    this->gameStarted = true;
    this->ui->GameFiels->show();
    emit startLevel(9);
}
void MainWindow::startLevel10()
{
    cForm->hide();
    this->gameStarted = true;
    this->ui->GameFiels->show();
    emit startLevel(10);
}

void MainWindow::levelFinished(int n)
{
    if(n == 1)
    {
        this->cForm->ui->level1->setStyleSheet("background-color: rgb(255,255,0);");
        this->cForm->ui->level1->update();
    }else
    if(n == 2)
    {
        this->cForm->ui->level2->setStyleSheet("background-color: rgb(255,255,0);");
        this->cForm->ui->level2->update();
    }
    if(n == 3)
    {
        this->cForm->ui->level3->setStyleSheet("background-color: rgb(255,255,0);");
        this->cForm->ui->level3->update();
    }
}
