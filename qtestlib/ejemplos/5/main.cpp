#include <QtTest/QtTest>
#include <QtTest/QTestEventList>
#include <QtGui/QLineEdit>

class Test: public QObject
{
    Q_OBJECT

private slots:
    void test()
    {
        Qt::Key keys[15] = { Qt::Key_A, Qt::Key_D,     Qt::Key_I,     Qt::Key_T,
                             Qt::Key_E, Qt::Key_L,     Qt::Key_Space, Qt::Key_I,
                             Qt::Key_P, Qt::Key_A,     Qt::Key_R,     Qt::Key_T,
                             Qt::Key_Y, Qt::Key_Space, Qt::Key_X };

        QTestEventList eventList;
        for (int i = 0; i < 15; i++)
        {
            eventList.addKeyClick(keys[i]);
        }

        QLineEdit lineEdit;
        eventList.simulate(&lineEdit);
        QCOMPARE(lineEdit.text(), QString("aditel iparty x"));
    }
};

 QTEST_MAIN(Test)
 #include "main.moc"
