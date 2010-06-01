#include <QtTest/QtTest>

class MiPrimerTest: public QObject
{
    Q_OBJECT

private slots:
    void initTestCase()
    {
        qDebug("Inicializar aqui lo necesario");
    }

    void primerTest()
    {
        qDebug("Primer test llamado");
    }

    void segundoTest()
    {
        qDebug("Segundo test llamado");
    }

    void cleanupTestCase()
    {
        qDebug("Limpiar aqui lo necesario");
    }
};

 QTEST_MAIN(MiPrimerTest)
 #include "main.moc"
