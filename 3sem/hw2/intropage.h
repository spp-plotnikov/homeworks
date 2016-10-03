#pragma once

#include <QWizardPage>

namespace Ui {
class IntroPage;
}

class IntroPage : public QWizardPage
{
    Q_OBJECT

public:
    explicit IntroPage(QWidget *parent = 0);
    ~IntroPage();

private:
    Ui::IntroPage *ui;
};
