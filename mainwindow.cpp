#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::MainWindow),
    m_status(""),
    m_aboutBox(new aboutBox())
{
    m_ui->setupUi(this);
    statusBar()->addWidget(&m_status);
    //Connect
    connect(m_ui->actionRun,SIGNAL(triggered()),this,SLOT(runClicked()));
    connect(m_ui->actionPause,SIGNAL(triggered()),this,SLOT(pauseClicked()));
    connect(m_ui->actionClear_4,SIGNAL(triggered()),this,SLOT(clearClicked()));
    connect(m_ui->actionNew,SIGNAL(triggered()),this,SLOT(newClicked()));
    connect(m_ui->actionOpen,SIGNAL(triggered()),this,SLOT(openClicked()));
    connect(m_ui->actionSave,SIGNAL(triggered()),this,SLOT(saveClicked()));
    connect(m_ui->actionQuit,SIGNAL(triggered()),this,SLOT(quitClicked()));
    connect(m_ui->actionReset_Universe,SIGNAL(triggered()),this,SLOT(resetUniverseClicked()));
    connect(m_ui->actionReset_Timer,SIGNAL(triggered()),this,SLOT(resetTimerClicked()));
    connect(m_ui->universe_spinBox,SIGNAL(valueChanged(int)),this,SLOT(universeSizeChanged(int)));
    connect(m_ui->universe_slider,SIGNAL(valueChanged(int)),this,SLOT(universeSizeChanged(int)));
    connect(m_ui->timer_SpinBox,SIGNAL(valueChanged(int)),this,SLOT(timerChanged(int)));
    connect(m_ui->timer_slider,SIGNAL(valueChanged(int)),this,SLOT(timerChanged(int)));
    connect(m_ui->actionHide_parameters,SIGNAL(toggled(bool)),this,SLOT(hideParameters(bool)));
    connect(m_ui->actionHide_data,SIGNAL(toggled(bool)),this,SLOT(hideData(bool)));
    connect(m_ui->actionHide_toolbar,SIGNAL(toggled(bool)),this,SLOT(hideToolbar(bool)));
    connect(m_ui->actionMaximized,SIGNAL(triggered()),this,SLOT(maximizedClicked()));
    connect(m_ui->actionNormal,SIGNAL(triggered()),this,SLOT(normalClicked()));
    connect(m_ui->actionFull_Screen,SIGNAL(triggered()),this,SLOT(fullscreenClicked()));
    connect(m_ui->actionAbout,SIGNAL(triggered()),this,SLOT(aboutGolClicked()));
    connect(m_ui->actionParameters_2,SIGNAL(triggered()),this,SLOT(parametersClicked()));
    connect(m_ui->actionHelp,SIGNAL(triggered()),this,SLOT(helpClicked()));
    connect(m_ui->actionReset_Color,SIGNAL(triggered()),this,SLOT(resetColorClicked()));
}

MainWindow::~MainWindow()
{
    delete m_ui;
}

void MainWindow::closeEvent(QCloseEvent* e)
{
    Q_UNUSED(e);
    emit quitClickedSignal();
}

/*****************************
 *   public GUI Features
 * ***************************/
void MainWindow::displayGame(GameWidget *game)
{
    m_ui->game_layout->addWidget(game);
}

void MainWindow::status(QString text)
{
    m_status.setText(text);
}

/*****************************
 *   private GUI Features
 * ***************************/
void MainWindow::maximizedClicked()
{
    this->showMaximized();
    m_ui->actionNormal->setEnabled(true);
    m_ui->statusBar->showMessage("Window is in maximized",1000);
}

void MainWindow::fullscreenClicked()
{
    this->showFullScreen();
    m_ui->actionNormal->setEnabled(true);
    m_ui->statusBar->showMessage("Window is in fullscreen",1000);
}

void MainWindow::normalClicked()
{
    this->showNormal();
    m_ui->actionNormal->setEnabled(false);
    m_ui->statusBar->showMessage("Window is in normal",1000);
}


void MainWindow::resizeEvent( QResizeEvent *e )
{
    Q_UNUSED(e);
    m_ui->actionMaximized->setEnabled(!this->isMaximized());
    m_ui->actionFull_Screen->setEnabled(!this->isFullScreen());
}

void MainWindow::hideToolbar(bool hide)
{
    m_ui->mainToolBar->setHidden(hide);
}

void MainWindow::hideParameters(bool hide)
{
    m_ui->groupBox_params->setHidden(hide);
}

void MainWindow::hideData(bool hide)
{
    m_ui->groupBox_data->setHidden(hide);
}

void MainWindow::aboutGolClicked(){
   //new aboutBox();
    m_aboutBox.hide();
    m_aboutBox.show();
}

void MainWindow::helpClicked(){
    QMessageBox helpBox;
    QPushButton *md_button = helpBox.addButton(tr("Open MarkDown"), QMessageBox::ActionRole);
    helpBox.addButton(QMessageBox::Close);

    helpBox.setWindowTitle("Help !");
    helpBox.setWindowIcon(QPixmap(":/assets/vb_black_bg_border_512.png"));
    helpBox.setText("<html><head/><body><p><span style=' font-weight:600;'>Introduction</span></p><p>The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970.</p><p><br/></p><p>The game is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input. One interacts with the Game of Life by creating an initial configuration and observing how it evolves, or, for advanced players, by creating patterns with particular properties. </p><p><br/></p><p><span style=' font-weight:600;'>Rules (default game mode)</span></p><p>    Any live cell with fewer than two live neighbors dies, as if by underpopulation.</p><p>    Any live cell with two or three live neighbors lives on to the next generation.</p><p>    Any live cell with more than three live neighbors dies, as if by overpopulation.</p><p>    Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.</p><p><br/></p><p><span style=' font-weight:600;'>Controls</span></p><p>- Right click : to fill a cell</p><p>- Left click : to unfill a cell</p><p><br/></p><p><span style=' color:#00aa7f;'>To more details please check the MarkDown file</span><br/></p></body></html>");
    helpBox.exec();

    if (helpBox.clickedButton() == md_button) {
        // open MD
        QDesktopServices::openUrl(QUrl("https://gitlab.com/Kyross/game_of_life/blob/master/help.md"));
    }
}

/***************************
 *      SLOTS
 * **************************/
void MainWindow::runClicked()
{
    emit runClickedSignal();
}

void MainWindow::pauseClicked()
{
    emit pauseClickedSignal();
}

void MainWindow::clearClicked()
{
    emit clearClickedSignal();
}

void MainWindow::newClicked()
{
    emit newClickedSignal();
}

void MainWindow::openClicked()
{
    emit openClickedSignal();
}

void MainWindow::saveClicked()
{
    emit saveClickedSignal();
}

void MainWindow::quitClicked()
{
   emit quitClickedSignal();
}

void MainWindow::resetTimerClicked()
{
    emit resetTimerClickedSignal();
}

void MainWindow::resetColorClicked()
{
    emit resetColorClickedSignal();
}

void MainWindow::resetUniverseClicked()
{
    emit resetUniverseClickedSignal();
}

void MainWindow::setParamsEnable(bool e, bool r)
{
    Q_UNUSED(r);
    m_ui->universe_spinBox->setEnabled(e);
    m_ui->universe_slider->setEnabled(e);
}

void MainWindow::universeSizeChanged(int size)
{
    if(size!=m_ui->universe_spinBox->value() || size!=m_ui->universe_slider->value()){
        m_ui->universe_spinBox->setValue(size);
        m_ui->universe_slider->setValue(size);
        emit universeSizeChangedSignal(size);
    }
}

void MainWindow::timerChanged(int t)
{
    if(t!=m_ui->timer_SpinBox->value() || t!=m_ui->timer_slider->value()){
        m_ui->timer_SpinBox->setValue(t);
        m_ui->timer_slider->setValue(t);
        emit timerChangedSignal(t);
    }
}

void MainWindow::parametersClicked()
{
    emit parametersClickedSignal();
}

//Setter
void MainWindow::setRunPause(bool e,bool r)
{
    m_ui->actionRun->setEnabled(!e && !r);
    m_ui->actionPause->setEnabled(!e && r);
    m_ui->actionClear_4->setEnabled(!e);
    m_ui->actionReset_Universe->setEnabled(e);
    if(!e) m_ui->actionNew->setEnabled(!e);
}

void MainWindow::initRange(int min_u,int max_u, int min_t, int max_t)
{
    m_ui->universe_spinBox->setRange(min_u,max_u);
    m_ui->universe_slider->setRange(min_u,max_u);
    m_ui->timer_SpinBox->setRange(min_t,max_t);
    m_ui->timer_slider->setRange(min_t,max_t);
}

void MainWindow::setDataCellAlive(int c)
{
    m_ui->label_cellAlive->setText(QString::number(c));
}

void MainWindow::setDataGenerations(int c)
{
    m_ui->label_cellGenerations->setText(QString::number(c));
}
