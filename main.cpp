#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Source/Application.cpp"

int main() {

    // Comentar a opção que não queremos

    // 1 -> Rodar o código
    Application() ;
    return 0;

    // 2 -> Rodar os testes
    //testing::InitGoogleTest();
    //return RUN_ALL_TESTS();

}
