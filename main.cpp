#include <QApplication>
#include <QtWebEngineWidgets>
#include <QHBoxLayout>
#include <QWidget>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget window;
    window.resize(800,600);
    QHBoxLayout layout(&window);
    QWebEngineView view;
    QTextEdit tEdit;
    QRect rect = window.rect();
    QRect leftRect = rect, rightRect = rect;
    leftRect.setWidth(rect.width()/2);
    rightRect.setWidth(rect.width()/2);
    rightRect.setLeft(leftRect.x() + leftRect.width());
    tEdit.setBaseSize(leftRect.width(), leftRect.height());
    tEdit.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    view.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout.addWidget(&tEdit);
    layout.addWidget(&view);
    QObject::connect(&tEdit, &QTextEdit::textChanged, [&view, &tEdit]{
        view.setHtml(tEdit.toPlainText());
    } );
    window.show();
    return a.exec();
}
