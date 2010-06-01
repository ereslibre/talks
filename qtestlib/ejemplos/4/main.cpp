#include <QtTest/QtTest>
#include <QtTest/QSignalSpy>
#include <QtGui/QLineEdit>

class Test: public QObject
{
    Q_OBJECT

private slots:
    void test()
    {
        QLineEdit lineEdit;

        QSignalSpy espia(&lineEdit, SIGNAL(textChanged(QString)));

        QTest::keyClicks(&lineEdit, "Aditel iParty X");
        QCOMPARE(lineEdit.text(), QString("Aditel iParty X"));

        QVERIFY(espia.count() == 15);
    }
};

 QTEST_MAIN(Test)
 #include "main.moc"
