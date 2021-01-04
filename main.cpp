#include <iostream>

#include "fuzzy/Operator.h"
#include "fuzzy/FuzzyFactory.h"
#include "core/Expression.h"
#include "core/ValueModel.h"
#include "core/BinaryShadowExpression.h"
#include <iostream>

int main() {
    fuzzy::NotMinus1<float> opNot;
    fuzzy::AndMin<float> opAnd;
    fuzzy::OrMax<float> opOr;
    fuzzy::ThenMin<float> opThen;
    //fuzzy::SugenoThen<float> opThen;
    //fuzzy::COGDefuzz<float> opDefuzz(0, 25, 0.1);
    //fuzzy::BOADefuzz<float> opDefuzz(0,25,0.1);
    //fuzzy::MOMDefuzz<float> opDefuzz(0,25,0.1);
    //fuzzy::LOMDefuzz<float> opDefuzz(0,25,0.1);
    fuzzy::FOMDefuzz<float> opDefuzz(0,25,0.1);
    fuzzy::AggMax<float> opAgg;
    fuzzy::SugenoDefuzz<float> opSugenoDefuzz;

    //opConclusion.setCoeff(list);
    //SugenoThen<float> opSugenoThen(0);

    //fuzzy expession factory
    fuzzy::FuzzyFactory<float> f(&opAnd, &opOr, &opThen,&opAgg, &opDefuzz, &opNot,&opSugenoDefuzz);

    //membership function
//    fuzzy::IsGaussian<float> poor(0,1.3);
//    fuzzy::IsGaussian<float> good(5, 1.3);
//    fuzzy::IsGaussian<float> excellent(10, 1.3);
//    fuzzy::IsRamp<float> rancid(1, 4, IsRamp<float>::dir::Down);
//    fuzzy::IsRamp<float> delicious(6, 9, IsRamp<float>::dir::Up);

    fuzzy::IsLeftTrapezium<float> rancid(1, 4);
    fuzzy::IsRightTrapezium<float> delicious(6, 9);

    fuzzy::IsTriangle<float> poor(-5,0,5);
    fuzzy::IsTriangle<float> good(0,5,10);
    fuzzy::IsTriangle<float> excellent(5,10,15);

    fuzzy::IsTriangle<float> cheap(0,5,10);
    fuzzy::IsTriangle<float> average(10,15,20);
    fuzzy::IsTriangle<float> generous(20,25,30);

    //values
    core::ValueModel<float> service(8);
    core::ValueModel<float> food(8);
    core::ValueModel<float> tips;


    core::Expression<float> *r = f.newAgg(
            f.newAgg(
                    f.newThen(
                            f.newOr(
                                    f.newIs(&poor, &service),
                                    f.newIs(&rancid, &food)
                            ),
                            f.newIs(&cheap, &tips)),
                    f.newThen(
                            f.newIs(&good, &service),
                            f.newIs(&average, &tips))),
            f.newThen(
                    f.newOr(
                            f.newIs(&excellent, &service),
                            f.newIs(&delicious, &food)
                    ),
                    f.newIs(&generous, &tips)));

    
    //defuzzification
    core::Expression<float> *system = f.newMamdaniDefuzz(r,&tips);

    std::vector<float> v1;
    v1.push_back(1);
    v1.push_back(1);
    v1.push_back(0);
    fuzzy::SugenoConclusion<float>* sc1 = new fuzzy::SugenoConclusion<float>(v1);

    std::vector<float> v2;
    v2.push_back(1);
    v2.push_back(1);
    v2.push_back(0);
    fuzzy::SugenoConclusion<float>* sc2 = new fuzzy::SugenoConclusion<float>(v2);

    std::vector<float> v3;
    v3.push_back(1);
    v3.push_back(1);
    v3.push_back(0);
    fuzzy::SugenoConclusion<float>* sc3 = new fuzzy::SugenoConclusion<float>(v3);

    std::vector<core::Expression<float>*> ops1;
    ops1.push_back(f.newIs(&poor, &service));
    ops1.push_back(f.newIs(&rancid, &food));

    std::vector<core::Expression<float>*> ops2;
    ops2.push_back(f.newIs(&good, &service));
    ops2.push_back(f.newIs(new fuzzy::IsTriangle<float>(0,0,0), &food));

    std::vector<core::Expression<float>*> ops3;
    ops3.push_back(f.newIs(&excellent, &service));
    ops3.push_back(f.newIs(&delicious, &food));

    core::Expression<float> *t1 = f.newThen(
        f.newOr(
           ops1[0],
           ops1[1]
        ),
        f.newSugenoConclusion(
            sc1,
            ops1
        )
    );

    core::Expression<float>* t2 = f.newThen(
        f.newOr(
            ops2[0],
            ops2[1]
        ),
        f.newSugenoConclusion(
            sc2,
            ops2
        )
    );

    core::Expression<float>* t3 = f.newThen(
        f.newOr(
            ops3[0],
            ops3[1]
        ),
        f.newSugenoConclusion(
            sc3,
            ops3
        )
    );
    
    std::vector<core::Expression<float>*> defuzzOperands;
    defuzzOperands.push_back(t1);
    defuzzOperands.push_back(t2);
    defuzzOperands.push_back(t3);

    //core::Expression<float>* system = f.newSugenoDefuzz(defuzzOperands);

    //apply input
    float s;
    while(true)
    {
        std::cout << "service : ";std::cin >> s;
        service.setValue(s);
        std::cout << "tips -> " << system->evaluate() << std::endl;
    }
    return 0;
}
