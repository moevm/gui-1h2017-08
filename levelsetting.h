#ifndef LEVELSETTING_H
#define LEVELSETTING_H

#include <QDialog>

namespace Ui {
class LevelSetting;
}

class LevelSetting : public QDialog
{
    Q_OBJECT

public:
    explicit LevelSetting(QWidget *parent = 0);
    ~LevelSetting();

private:
    Ui::LevelSetting *ui;
signals:
    void generateLevel(int, int);
    void cansel();
private slots:
    void generatorStart();

};

#endif // LEVELSETTING_H
