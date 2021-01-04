#include <iostream>
#include "UnaryExpressionModel.h"
#include "BinaryExpressionModel.h"
#include "ValueModel.h"
#include "../fuzzy/Operator.h"


void test_UnaryExpressionModel() {
    float v = 5;
    core::ValueModel<float> *vm = new core::ValueModel<float>(v);
    fuzzy::NotMinus1<float> op;

    core::UnaryExpressionModel<float> uem(&op, vm);

    float expected = -4;
    float eval = uem.evaluate();

    if(eval == expected) {
        std::cout << "UnaryExpressionModel OK" << std::endl;
    } else {
        std::cout << "UnaryExpressionModel FAILED" << std::endl;
    }

}

void test_BinaryExpressionModel() {
    float v1 = 5;
    float v2 = 10;
    core::ValueModel<float> *vm1 = new core::ValueModel<float>(v1);
    core::ValueModel<float> *vm2 = new core::ValueModel<float>(v2);
    fuzzy::AndMin<float> op;

    core::BinaryExpressionModel<float> bem(&op,vm1, vm2);

    float expected = 5;
    float eval = bem.evaluate();

    if(eval == expected) {
        std::cout << "BinaryExpressionModel OK" << std::endl;
    } else {
        std::cout << "BinaryExpressionModel FAILED" << std::endl;
    }
}

int main() {
    test_UnaryExpressionModel();
    test_BinaryExpressionModel();
    return 0;
}