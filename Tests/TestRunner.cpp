#include "TestSimpleLogger.h"

Tests::ITest *test = nullptr;


int main(int argc, char const *argv[])
{
    test = new Logger::Tests::SimpleLogger;

    test->RunTests();
    
    delete test;
    return 0;
}
