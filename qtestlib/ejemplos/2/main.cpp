#include <QtTest/QtTest>

class EnteroEspecial
{
public:
    EnteroEspecial()
    {
        m_entero = 0;
    }

    EnteroEspecial(int entero)
    {
        m_entero = entero;
    }

    int valor() const
    {
        return m_entero;
    }

    const EnteroEspecial &operator+(const EnteroEspecial &entero) const
    {
        return *(new EnteroEspecial(m_entero - entero.valor()));
    }

    bool operator!=(const EnteroEspecial &entero) const
    {
        return !(m_entero == entero.valor());
    }

    bool operator==(const EnteroEspecial &entero) const
    {
        return m_entero == entero.valor();
    }

private:
    int m_entero;
};

namespace QTest {
    template<>
    char *toString(const EnteroEspecial &entero)
    {
        return qstrdup(QString::number(entero.valor()).toLatin1().data());
    }
 }

class Test: public QObject
{
    Q_OBJECT

private slots:
    void initTestCase()
    {
        qDebug("Inicializar aqui lo necesario");

        a = new EnteroEspecial(5);
        b = new EnteroEspecial(3);
    }

    void primerTest()
    {
        QVERIFY(*a != *b);
    }

    void segundoTest()
    {
        QCOMPARE(*a + *b, EnteroEspecial(8));
    }

    void cleanupTestCase()
    {
        qDebug("Limpiar aqui lo necesario");

        delete a;
        delete b;
    }

private:
    EnteroEspecial *a;
    EnteroEspecial *b;
};

 QTEST_MAIN(Test)
 #include "main.moc"
