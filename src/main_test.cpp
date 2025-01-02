#include <QCoreApplication>
#include <QTest>
#include "../tests/test_square.h"
#include "../tests/test_boundry.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    int status = 0;

    //run test_square
    {
        TestSquare testSquare;
        status |= QTest::qExec(&testSquare, argc, argv);
    }

    //run test_boundary
    {
        TestBoundary testBoundary;
        status |= QTest::qExec(&testBoundary, argc, argv);
    }

    return status;
}
