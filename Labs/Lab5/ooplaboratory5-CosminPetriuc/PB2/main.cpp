#include <iostream>
#include "Teste.cpp"

int main()
{
    std::cout << "Douzo yoroshiku onegai shimasu!" << std::endl;
    CharacterTest::runTests();
    WizardTest::runTests();
    KnightTest::runTests();
    return 0;
}
