#include "basetopbar.h"

BaseTopBar::BaseTopBar(const QString& title, QWidget* parent)
    : QWidget(parent), _menubar(new QMenuBar(this)), _title(new QLabel(this)),
      _verticalLayout(new QVBoxLayout), _horizontalLayout(new QHBoxLayout) {
    setupLayout();

    setupMenuBar();
    setupLabel(title);

    setLayout(_verticalLayout);
}

BaseTopBar::~BaseTopBar() {
    delete _horizontalLayout;
    delete _verticalLayout;
    delete _title;
    delete _menubar;
}

QString BaseTopBar::title() const {
    return _title->text();
}

void BaseTopBar::setTitle(const QString& title) {
    _title->setText("<h1>" + title + "</h1>");
}

void BaseTopBar::setupLayout() {
    _verticalLayout->addWidget(_menubar);
    _verticalLayout->addLayout(_horizontalLayout);
    _horizontalLayout->addWidget(_title);
    _verticalLayout->setAlignment(Qt::AlignLeft);
}

void BaseTopBar::setupMenuBar() {
    QMenu* file = _menubar->addMenu("File");
    QAction* exit = file->addAction("Exit");
    exit->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_W));
    QAction* addVehicle = file->addAction("Add vehicle");
    addVehicle->setShortcut(QKeySequence::New);
    QAction* addCity = file->addAction("Add city");
    addCity->setShortcut(QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_N));

    connect(exit, &QAction::triggered, this, &BaseTopBar::closeSignal);
    connect(addCity, &QAction::triggered, this, &BaseTopBar::showAddCityWizard);
    connect(addVehicle, &QAction::triggered, this, &BaseTopBar::showAddVehicleWizard);

}

void BaseTopBar::setupLabel(const QString &title) {
    _title->setText("<h1>" + title + "</h1>");
    _title->setTextFormat(Qt::RichText);
}
