#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QtNetwork>
#include "bashquotes.h"
#include "ui_bashquotes.h"

BashQuotes::BashQuotes(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BashQuotes)
{
    ui->setupUi(this);
    setFixedSize(420, 370);

    ui->increaseRating->setIcon(QIcon(":new/prefix1/images/plus.png"));
    ui->decreaseRating->setIcon(QIcon(":new/prefix1/images/minus.png"));
    ui->bayan->setIcon(QIcon(":new/prefix1/images/bayan2.png"));
    ui->load->setIcon(QIcon(":new/prefix1/images/reload2.png"));
    ui->next->setIcon(QIcon(":new/prefix1/images/next1.png"));
    statusBar()->showMessage("© Sasha Plotnikov Production, Ltd.");

    webView->load(QUrl("http://bash.im/"));

    connect(ui->next, SIGNAL(clicked()), this, SLOT(nextQuote()));
    connect(ui->load, SIGNAL(clicked()), this, SLOT(reloadQuotes()));
    connect(webView, SIGNAL(loadFinished(bool)), this, SLOT(loadQuotes()));
    connect(ui->increaseRating, SIGNAL(clicked()), this, SLOT(rateUp()));
    connect(ui->decreaseRating, SIGNAL(clicked()), this, SLOT(rateDown()));
    connect(ui->bayan, SIGNAL(clicked()), this, SLOT(rateBayan()));
}

BashQuotes::~BashQuotes()
{
    delete webView;
    delete ui;
}


//----------------------------------------------------------


void BashQuotes::loadQuotes()
{
    if (!ui->next->isEnabled())
    {
        quotesBlocks = webView->page()->mainFrame()->findAllElements("div[class=quote]").toList();
        nextQuote();
        makeEnabled();
    }
}


void BashQuotes::nextQuote()
{
    makeEnabled();

    QString textOfQuote;
    do
    {
        quoteIterator++;
        if (quoteIterator == quotesBlocks.size())
        {
            quoteIterator = 0;
        }
        textOfQuote = quotesBlocks[quoteIterator].findFirst("div[class=text]").toPlainText();
    }
    while (textOfQuote.isEmpty());

    ui->quote->clear();
    ui->quote->insertPlainText(textOfQuote);
    ui->rating->setText(quotesBlocks[quoteIterator].findFirst("span[class=rating-o]").toPlainText());
}


void BashQuotes::reloadQuotes()
{
    ui->next->setEnabled(false);
    ui->load->setEnabled(false);
    quoteIterator--;
    webView->reload();
}


void BashQuotes::rateUp()
{
    if (!ui->decreaseRating->isEnabled())
        return;

    QString addressOfQuote = quotesBlocks[quoteIterator].findFirst("a[class=up]").attribute("href");
    QNetworkAccessManager manager;
    manager.get(QNetworkRequest(QUrl("http://bash.im" + addressOfQuote)));

    updateRating(1);
    ui->bayan->setEnabled(false);
    ui->decreaseRating->setEnabled(false);
}


void BashQuotes::rateDown()
{
    if (!ui->bayan->isEnabled())
        return;

    QString addressOfQuote = quotesBlocks[quoteIterator].findFirst("a[class=down]").attribute("href");
    QNetworkAccessManager manager;
    manager.get(QNetworkRequest(QUrl("bash.im" + addressOfQuote)));

    updateRating(-1);
    ui->bayan->setEnabled(false);
    ui->increaseRating->setEnabled(false);
}


void BashQuotes::rateBayan()
{
    if (!ui->decreaseRating->isEnabled())
        return;

    QString addressOfQuote = quotesBlocks[quoteIterator].findFirst("a[class=bayan]").attribute("href");
    QNetworkAccessManager manager;
    manager.get(QNetworkRequest(QUrl("bash.im" + addressOfQuote)));

    ui->increaseRating->setEnabled(false);
    ui->decreaseRating->setEnabled(false);
}


//----------------------------------------------------------


void BashQuotes::makeEnabled()
{
    ui->next->setEnabled(true);
    ui->load->setEnabled(true);
    ui->increaseRating->setEnabled(true);
    ui->decreaseRating->setEnabled(true);
    ui->bayan->setEnabled(true);
}


void BashQuotes::updateRating(const int shift)
{
    int currentValue = ui->rating->text().toInt();
    currentValue += shift;
    ui->rating->setText(QString::number(currentValue));
}
