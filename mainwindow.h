#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>

#include "FormClasses/campaignform.h"
#include "FormClasses/menuform.h"
#include "FormClasses/generateform.h"

namespace Ui {
class MainWindow;
class CampaignForm;
class GenerateForm;
class MenuForm;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool gameStarted = false;

private:
    Ui::MainWindow *ui;
    CampaignForm *cForm;
    MenuForm *menuForm;
    GenerateForm *generateForm;

    Ui::GenerateForm *ui_generateLevel;
    Ui::MenuForm *ui_menu;
    void keyPressEvent(QKeyEvent  * ev);
    void initParameters();
    void resizeEvent(QResizeEvent * resize);

signals:
    void generateLevel(int, int);
    void startLevel(int);
public slots:
    void startCampaign();
    void continueCampaign();
    void startGameWithSettings();
    void openMenu();
    void openLevelSelector();
    void generatorStart();
    void startLevel1();
    void startLevel2();
    void startLevel3();
    void startLevel4();
    void startLevel5();
    void startLevel6();
    void startLevel7();
    void startLevel8();
    void startLevel9();
    void startLevel10();
    void levelFinished(int);
};

#endif // MAINWINDOW_H
