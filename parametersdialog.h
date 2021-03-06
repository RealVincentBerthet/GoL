#ifndef PARAMETERSDIALOG_H
#define PARAMETERSDIALOG_H

#include "ui_parametersdialog.h"
#include <QDialog>
#include <QString>
#include <QColorDialog>
#include <QDebug>

namespace Ui {
class ParametersDialog;
}

class ParametersDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ParametersDialog(QWidget *parent = nullptr);
    ~ParametersDialog();
     void initRange(int,int,int,int);
signals:
    void universeSizeChangedSignal(int);
    void timerChangedSignal(int);
    void loadDemoSignal(QString);
    void randomizeModeSignal(int);
    void modeSignal(bool,bool,bool,int,int,int,int);
    void colorSignal();
    void resetModeClickedSignal();
    void resetTimerClickedSignal();
    void resetUniverseClickedSignal();
    void resetColorClickedSignal();
    void resetParametersClickedSignal();
    void clearClickedSignal();

public slots:
    void universeSizeChanged(int size);
    void timerChanged(int time);
    void loadDemo();
    void randomizeMode();
    void colorClicked();
    void setParamsEnable(bool,bool);
    void resetModeClicked();
    void modeChanged();
    void resetTimerClicked();
    void resetUniverseClicked();
    void resetColorClicked();
    void resetParametersClicked();
    void clearClicked();
    //Getter
    bool isBornChecked();
    bool isStaseChecked();
    bool isDeadChecked();
    int getBornMin();
    int getBornMax();
    int getStaseMin();
    int getStaseMax();

    //Setter
    void setBornChecked(bool);
    void setStaseChecked(bool);
    void setDeadChecked(bool);
    void setBornMin(int);
    void setBornMax(int);
    void setStaseMin(int);
    void setStaseMax(int);
    void setColor(QColor,QColor);
    void setMode(bool,bool,bool,int,int,int,int);
private:
    Ui::ParametersDialog *m_ui;

};

#endif // PARAMETERSDIALOG_H
