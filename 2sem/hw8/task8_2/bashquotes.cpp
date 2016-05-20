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

    connect(webView, SIGNAL(loadFinished(bool)), this, SLOT(loadQuotes()));
    connect(ui->next, SIGNAL(clicked()), this, SLOT(nextQuote()));
    connect(ui->load, SIGNAL(clicked()), this, SLOT(reloadQuotes()));
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
        quoteIterator = --quotesBlocks.end();
        nextQuote();
        ui->next->setEnabled(true);
    }
}


void BashQuotes::nextQuote()
{
    QString textOfQuote;
    do
    {
        quoteIterator++;
        if (quoteIterator == quotesBlocks.end())
        {
            quoteIterator = quotesBlocks.begin();
        }
        textOfQuote = quoteIterator->findFirst("div[class=text]").toPlainText();
    }
    while (textOfQuote.isEmpty());

    ui->quote->clear();
    ui->quote->insertPlainText(textOfQuote);
    ui->rating->setText(quoteIterator->findFirst("span[class=rating-o]").toPlainText());
}


void BashQuotes::reloadQuotes()
{
    int i = quotesBlocks.indexOf(*quoteIterator);
    webView->reload();
    quotesBlocks = webView->page()->mainFrame()->findAllElements("div[class=quote]").toList();
    quoteIterator = quotesBlocks.begin();
    quoteIterator += (i % quotesBlocks.size());
    ui->rating->setText(quoteIterator->findFirst("span[class=rating-o]").toPlainText());
}
