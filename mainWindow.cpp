#include <QtWidgets>

#include "mainWindow.h"

Q_DECLARE_METATYPE(QFontComboBox::FontFilter)

MainWindow::MainWindow()
{



    QSize availableSize = qApp->desktop()->availableGeometry().size();
    int width = availableSize.width();
    int height = availableSize.height();
    width *= 0.8;
    height *= 0.8;

	resize(width,height);
	createMenu();
	createHorizontalGroupBox();
    createGridGroupBox();


	QVBoxLayout *mainLayout = new QVBoxLayout;
	
	mainLayout->setMenuBar(menuBar);
	
	mainLayout->addWidget(horizontalGroupBox);
	mainLayout->addWidget(gridGroupBox);

	setLayout(mainLayout);
	setWindowTitle(tr("MAssEffects"));
}

void MainWindow::createMenu()
{
    menuBar = new QMenuBar;

    fileMenu = new QMenu(tr("&File"), this);
    exitAction = fileMenu->addAction(tr("E&xit"));
    menuBar->addMenu(fileMenu);

    connect(exitAction, SIGNAL(triggered()), this, SLOT(accept()));
}

void MainWindow::createHorizontalGroupBox()
{
    horizontalGroupBox = new QGroupBox(tr("Horizontal layout"));
    horizontalGroupBox->setMaximumHeight(100);
    QHBoxLayout *layout = new QHBoxLayout;

    for (int i = 0; i < NumButtons; ++i) {
        buttons[i] = new QPushButton(tr("Button %1").arg(i + 1));
        layout->addWidget(buttons[i]);
    }
    horizontalGroupBox->setLayout(layout);
}

void MainWindow::createGridGroupBox()
{
    gridGroupBox = new QGroupBox(tr("Grid layout"));
    gridGroupBox->setMaximumWidth(350);

    QGridLayout *layout = new QGridLayout;

    for (int i = 0; i < NumGridRows; ++i) {
        labels[i] = new QLabel(tr("Line %1:").arg(i + 1));
        lineEdits[i] = new QLineEdit;
        layout->addWidget(labels[i], i + 1, 0);
        layout->addWidget(lineEdits[i], i + 1, 1);
    }
    layout->setColumnStretch(1, 10);
    layout->setColumnStretch(2, 20);
    gridGroupBox->setLayout(layout);
}
/*
MainWindow::MainWindow()
{
	QMenu *fileMenu = menuBar()->addMenu(tr("menu1"));
    //fileMenu->addAction(tr("Quit"), this, &QWidget::close);
    QMenu *helpMenu = menuBar()->addMenu(tr("menu2"));
    //helpMenu->addAction(tr("Show Font Info"), this, &MainWindow::showInfo);
    //helpMenu->addAction(tr("About &Qt"), qApp, &QApplication::aboutQt);

    QWidget *centralWidget = new QWidget;
    QLabel *filterLabel = new QLabel(tr("Filter:"));
    
    filterCombo = new QComboBox;
    
    filterCombo->addItem("lol");
    filterCombo->addItem("lol2");
    filterCombo->addItem("lol3");
    filterCombo->setCurrentIndex(0);
    connect(filterCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),this, &MainWindow::filterChanged);

    FractalWidget	*tmp = new FractalWidget;


	QHBoxLayout *controlsLayout = new QHBoxLayout;
	controlsLayout->addWidget(filterLabel);
	controlsLayout->addWidget(filterCombo, 1);

	controlsLayout->addWidget(tmp);	

	QVBoxLayout *centralLayout = new QVBoxLayout;
	centralLayout->addLayout(controlsLayout);
	centralWidget->setLayout(centralLayout);
	setCentralWidget(centralWidget);
    setWindowTitle(tr("Character Map"));
}
*/

/*
void MainWindow::filterChanged(int f)
{
    const QFontComboBox::FontFilter filter = filterCombo->itemData(f).value<QFontComboBox::FontFilter>();
    std::cout << "clicked on:" << f << std::endl;
}*/