#include <iostream>
#include "../core/ValueModel.h"
#include "Operator.h"

void test_AndMin() {
    int v1 = 1;
    int v2 = 2;
    core::ValueModel<int> *vm1 = new core::ValueModel<int>(v1);
    core::ValueModel<int> *vm2 = new core::ValueModel<int>(v2);
    fuzzy::AndMin<int> op;

    int res = op.evaluate(vm1,vm2);
    int expected = vm1->evaluate();

    if(res == expected) {
        std::cout << "AndMin operator OK" << std::endl;
    } else {
        std::cout << "AndMin operator FAIL" << std::endl;
    }
}

void test_AndMult() {
    int v1 = 1;
    int v2 = 2;
    core::ValueModel<int> *vm1 = new core::ValueModel<int>(v1);
    core::ValueModel<int> *vm2 = new core::ValueModel<int>(v2);
    fuzzy::AndMult<int> op;

    int res = op.evaluate(vm1,vm2);
    int expected = vm1->evaluate() * vm2->evaluate();

    if(res == expected) {
        std::cout << "AndMult operator OK" << std::endl;
    } else {
        std::cout << "AndMult operator FAILED" << std::endl;
    }
}

void test_OrMax() {
    int v1 = 1;
    int v2 = 2;
    core::ValueModel<int> *vm1 = new core::ValueModel<int>(v1);
    core::ValueModel<int> *vm2 = new core::ValueModel<int>(v2);
    fuzzy::OrMax<int> op;

    int res = op.evaluate(vm1,vm2);
    int expected = vm2->evaluate();

    if(res == expected) {
        std::cout << "OrMax operator OK" << std::endl;
    } else {
        std::cout << "OrMax operator FAILED" << std::endl;
    }
}

void test_OrPlus() {
    int v1 = 1;
    int v2 = 2;
    core::ValueModel<int> *vm1 = new core::ValueModel<int>(v1);
    core::ValueModel<int> *vm2 = new core::ValueModel<int>(v2);
    fuzzy::OrPlus<int> op;

    int res = op.evaluate(vm1,vm2);
    int expected = vm1->evaluate()+vm2->evaluate();

    if(res == expected) {
        std::cout << "OrPlus operator OK" << std::endl;
    } else {
        std::cout << "OrPlus operator FAILED" << std::endl;
    }
}

void test_ThenMin() {
    int v1 = 1;
    int v2 = 2;
    core::ValueModel<int> *vm1 = new core::ValueModel<int>(v1);
    core::ValueModel<int> *vm2 = new core::ValueModel<int>(v2);
    fuzzy::ThenMin<int> op;

    int res = op.evaluate(vm1,vm2);
    int expected = vm1->evaluate();

    if(res == expected) {
        std::cout << "ThenMin operator OK" << std::endl;
    } else {
        std::cout << "ThenMin operator FAIL" << std::endl;
    }
}

void test_ThenMult() {
    int v1 = 1;
    int v2 = 2;
    core::ValueModel<int> *vm1 = new core::ValueModel<int>(v1);
    core::ValueModel<int> *vm2 = new core::ValueModel<int>(v2);
    fuzzy::ThenMult<int> op;

    int res = op.evaluate(vm1,vm2);
    int expected = vm1->evaluate() * vm2->evaluate();

    if(res == expected) {
        std::cout << "ThenMult operator OK" << std::endl;
    } else {
        std::cout << "ThenMult operator FAILED" << std::endl;
    }
}

void test_AggMax() {
    int v1 = 1;
    int v2 = 2;
    core::ValueModel<int> *vm1 = new core::ValueModel<int>(v1);
    core::ValueModel<int> *vm2 = new core::ValueModel<int>(v2);
    fuzzy::AggMax<int> op;

    int res = op.evaluate(vm1,vm2);
    int expected = vm2->evaluate();

    if(res == expected) {
        std::cout << "AggMax operator OK" << std::endl;
    } else {
        std::cout << "AggMax operator FAILED" << std::endl;
    }
}

void test_AggPlus() {
    int v1 = 1;
    int v2 = 2;
    core::ValueModel<int> *vm1 = new core::ValueModel<int>(v1);
    core::ValueModel<int> *vm2 = new core::ValueModel<int>(v2);
    fuzzy::AggPlus<int> op;

    int res = op.evaluate(vm1,vm2);
    int expected = vm1->evaluate()+vm2->evaluate();

    if(res == expected) {
        std::cout << "AggPlus operator OK" << std::endl;
    } else {
        std::cout << "AggPlus operator FAILED" << std::endl;
    }
}

void test_NotMinus1() {
    int v = 5;
    core::ValueModel<int> *vm = new core::ValueModel<int>(v);
    fuzzy::NotMinus1<int> op;

    int res = op.evaluate(vm);
    int expected = -4;

    if(res == expected) {
        std::cout << "NotMinus1 operator OK" << std::endl;
    } else {
        std::cout << "NotMinus1 operator FAILED" << std::endl;
    }
}

void test_IsTriangle() {
    float v1 = 2;
    float v2 = 3;
    float v3 = 4;
    float v4 = 5;
    float v5 = 6;
    float v6 = 7;
    float v7 = 8;
    core::ValueModel<float> *vm1 = new core::ValueModel<float>(v1);
    core::ValueModel<float> *vm2 = new core::ValueModel<float>(v2);
    core::ValueModel<float> *vm3 = new core::ValueModel<float>(v3);
    core::ValueModel<float> *vm4 = new core::ValueModel<float>(v4);
    core::ValueModel<float> *vm5 = new core::ValueModel<float>(v5);
    core::ValueModel<float> *vm6 = new core::ValueModel<float>(v6);
    core::ValueModel<float> *vm7 = new core::ValueModel<float>(v7);

    float min = 3;
    float mid = 5;
    float max = 7;
    fuzzy::IsTriangle<float> op(min,mid,max);

    float expected1 = 0;
    float expected2 = 0;
    float expected3 = 0.5;
    float expected4 = 1;
    float expected5 = 0.5;
    float expected6 = 0;
    float expected7 = 0;

    float eval1 = op.evaluate(vm1);
    float eval2 = op.evaluate(vm2);
    float eval3 = op.evaluate(vm3);
    float eval4 = op.evaluate(vm4);
    float eval5 = op.evaluate(vm5);
    float eval6 = op.evaluate(vm6);
    float eval7 = op.evaluate(vm7);

    if(eval1 == expected1 && eval2 == expected2 && eval3 == expected3
        && eval4 == expected4 && eval5 == expected5 &&
        eval6 == expected6 && eval7 == expected7) {
        std::cout << "IsTriangle operator OK" << std::endl;
    } else {
        std::cout << "IsTriangle operator FAILED" << std::endl;
    }

}

void test_IsTrapezium() {
    float v1 = 3;
    float v2 = 3.5;
    float v3 = 4.5;
    float v4 = 5.5;
    float v5 = 6;
    core::ValueModel<float> *vm1 = new core::ValueModel<float>(v1);
    core::ValueModel<float> *vm2 = new core::ValueModel<float>(v2);
    core::ValueModel<float> *vm3 = new core::ValueModel<float>(v3);
    core::ValueModel<float> *vm4 = new core::ValueModel<float>(v4);
    core::ValueModel<float> *vm5 = new core::ValueModel<float>(v5);

    float min = 3;
    float start = 4;
    float end = 5;
    float max = 6;
    fuzzy::IsTrapezium<float> op(min,start,end,max);

    float expected1 = 0;
    float expected2 = 0.5;
    float expected3 = 1;
    float expected4 = 0.5;
    float expected5 = 0;

    float eval1 = op.evaluate(vm1);
    float eval2 = op.evaluate(vm2);
    float eval3 = op.evaluate(vm3);
    float eval4 = op.evaluate(vm4);
    float eval5 = op.evaluate(vm5);

    if(eval1 == expected1 && eval2 == expected2 && eval3 == expected3
        && eval4 == expected4 && eval5 == expected5) {
        std::cout << "IsTrapezium operator OK" << std::endl;
    } else {
        std::cout << "IsTrapezium operator FAILED" << std::endl;
    }

}

void test_IsLeftTrapezium() {
    float v1 = 5;
    float v2 = 5.5;
    float v3 = 6;
    core::ValueModel<float> *vm1 = new core::ValueModel<float>(v1);
    core::ValueModel<float> *vm2 = new core::ValueModel<float>(v2);
    core::ValueModel<float> *vm3 = new core::ValueModel<float>(v3);

    float start = 5;
    float end = 6;
    fuzzy::IsLeftTrapezium<float> op(start,end);

    float expected1 = 1;
    float expected2 = 0.5;
    float expected3 = 0;

    float eval1 = op.evaluate(vm1);
    float eval2 = op.evaluate(vm2);
    float eval3 = op.evaluate(vm3);

    if(eval1 == expected1 && eval2 == expected2 && eval3 == expected3) {
        std::cout << "IsLeftTrapezium operator OK" << std::endl;
    } else {
        std::cout << "IsLeftTrapezium operator FAILED" << std::endl;
    }
}

void test_IsRightTrapezium() {
    float v1 = 5;
    float v2 = 5.5;
    float v3 = 6;
    core::ValueModel<float> *vm1 = new core::ValueModel<float>(v1);
    core::ValueModel<float> *vm2 = new core::ValueModel<float>(v2);
    core::ValueModel<float> *vm3 = new core::ValueModel<float>(v3);

    float start = 5;
    float end = 6;
    fuzzy::IsRightTrapezium<float> op(start,end);

    float expected1 = 0;
    float expected2 = 0.5;
    float expected3 = 1;

    float eval1 = op.evaluate(vm1);
    float eval2 = op.evaluate(vm2);
    float eval3 = op.evaluate(vm3);

    if(eval1 == expected1 && eval2 == expected2 && eval3 == expected3) {
        std::cout << "IsRightTrapezium operator OK" << std::endl;
    } else {
        std::cout << "IsRightTrapezium operator FAILED" << std::endl;
    }

}

int main() {
    test_AndMin();
    test_AndMult();
    test_OrMax();
    test_OrPlus();
    test_ThenMin();
    test_ThenMult();
    test_AggMax();
    test_AggPlus();
    test_NotMinus1();
    test_IsTriangle();
    test_IsTrapezium();
    test_IsLeftTrapezium();
    return 0;
}