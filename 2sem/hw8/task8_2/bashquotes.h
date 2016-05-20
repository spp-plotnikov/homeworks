#pragma once

#include <QMainWindow>
#include <QWebElement>
#include <QWebFrame>
#include <QWebView>


namespace Ui {
class BashQuotes;
}

class BashQuotes : public QMainWindow
{
    Q_OBJECT

public:
    explicit BashQuotes(QWidget *parent = 0);
    ~BashQuotes();

private slots:
    void nextQuote();
    void loadQuotes();
    void reloadQuotes();
//    void rateUp();
//    void rateDown();
//    void rateBayan();

private:
    Ui::BashQuotes *ui;

    QWebView *webView = new QWebView();
    QList<QWebElement> quotesBlocks;
    QList<QWebElement>::iterator quoteIterator;
};
