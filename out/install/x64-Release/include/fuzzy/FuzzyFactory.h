//
// Created by benja on 2/17/2020.
//

#ifndef FUZZY_FUZZYFACTORY_H
#define FUZZY_FUZZYFACTORY_H

#include "core/ExpressionFactory.h"
#include "core/BinaryShadowExpression.h"
#include "core/UnaryShadowExpression.h"
#include "core/NaryShadowExpression.h"
#include "core/Expression.h"
#include "Operator.h"

#include <vector>

namespace fuzzy {

    template<class T>
    class FuzzyFactory : public core::ExpressionFactory<T> {

    public:
        FuzzyFactory<T>();
        FuzzyFactory<T>(And<T>*, Or<T>*, Then<T>*, Agg<T>*, MamdaniDefuzz<T>*, Not<T>*, SugenoDefuzz<T>*);

        core::Expression<T>* newAnd(core::Expression<T>*, core::Expression<T>*);
        core::Expression<T>* newOr(core::Expression<T>*, core::Expression<T>*);
        core::Expression<T>* newThen(core::Expression<T>*, core::Expression<T>*);
        core::Expression<T>* newAgg(core::Expression<T>*, core::Expression<T>*);
        core::Expression<T>* newMamdaniDefuzz(core::Expression<T>*, core::Expression<T>*);
        core::Expression<T>* newSugenoDefuzz(std::vector<core::Expression<T>*>);
        core::Expression<T>* newNot(core::Expression<T>*);
        core::Expression<T>* newIs(Is<T>*, core::Expression<T>*);
        core::Expression<T>* newSugenoConclusion(SugenoConclusion<T>*, std::vector<core::Expression<T>*>);

        void changeAnd(And<T>*);
        void changeOr(Or<T>*);
        void changeThen(Then<T>*);
        void changeAgg(Agg<T>*);
        void changeMamdaniDefuzz(MamdaniDefuzz<T>*);
        void changeNot(Not<T>*);
        void changeSugenoDefuzz(SugenoDefuzz<T>*);

    private:
        core::UnaryShadowExpression<T> *use_not;
        core::BinaryShadowExpression<T> *bse_and, *bse_or, *bse_then, *bse_agg, *bse_mamdaniDefuzz;
        core::NaryShadowExpression<T> *nse_sugenoDefuzz, *nse_sugenoConclusion;

    };

    template<class T>
    FuzzyFactory<T>::FuzzyFactory(And<T> *newAnd, Or<T> *newOr, Then<T> *newThen, Agg<T> *newAgg, MamdaniDefuzz<T> *newDefuzz, 
                                  Not<T> *newNot, SugenoDefuzz<T> *newSugenoDefuzz) :
                                  bse_and(new core::BinaryShadowExpression<T>(newAnd)),
                                  bse_or(new core::BinaryShadowExpression<T>(newOr)),
                                  bse_then(new core::BinaryShadowExpression<T>(newThen)),
                                  bse_agg(new core::BinaryShadowExpression<T>(newAgg)),
                                  bse_mamdaniDefuzz(new core::BinaryShadowExpression<T>(newDefuzz)),
                                  use_not(new core::UnaryShadowExpression<T>(newNot)), 
                                  nse_sugenoDefuzz(new core::NaryShadowExpression<T>(newSugenoDefuzz)) {}

    template<class T>
    core::Expression<T>* FuzzyFactory<T>::newAnd(core::Expression<T>* l, core::Expression<T>* r) {
        return newBinary(bse_and,l,r);
    }

    template<class T>
    core::Expression<T>* FuzzyFactory<T>::newOr(core::Expression<T>* l, core::Expression<T>* r) {
        return newBinary(bse_or,l,r);
    }

    template<class T>
    core::Expression<T>* FuzzyFactory<T>::newThen(core::Expression<T>* l, core::Expression<T>* r) {
        return newBinary(bse_then,l,r);
    }

    template<class T>
    core::Expression<T>* FuzzyFactory<T>::newAgg(core::Expression<T>* l, core::Expression<T>* r) {
        return newBinary(bse_agg,l,r);
    }

    template<class T>
    core::Expression<T>* FuzzyFactory<T>::newMamdaniDefuzz(core::Expression<T>* l, core::Expression<T>* r) {
        return newBinary(bse_mamdaniDefuzz,l,r);
    }

    template<class T>
    core::Expression<T>* FuzzyFactory<T>::newSugenoDefuzz(std::vector<core::Expression<T>*> operands) {
        return newNary(nse_sugenoDefuzz, operands);
    }

    template<class T>
    core::Expression<T>* FuzzyFactory<T>::newNot(core::Expression<T>* e) {
        return newUnary(use_not,e);
    }

    template<class T>
    core::Expression<T>* FuzzyFactory<T>::newIs(Is<T> *is, core::Expression<T> *e) {
        return newUnary(is,e);
    }

    template<class T>
    core::Expression<T>* FuzzyFactory<T>::newSugenoConclusion(SugenoConclusion<T>* nse_sugenoConclusion, std::vector<core::Expression<T>*> operands) {
        return newNary(nse_sugenoConclusion, operands);
    }

    template<class T>
    void FuzzyFactory<T>::changeAnd(And<T>* newAnd) {
        bse_and->setTarget(newAnd);
    }

    template<class T>
    void FuzzyFactory<T>::changeOr(Or<T>* newOr) {
        bse_or->setTarget(newOr);
    }

    template<class T>
    void FuzzyFactory<T>::changeThen(Then<T>* newThen) {
        bse_then->setTarget(newThen);
    }

    template<class T>
    void FuzzyFactory<T>::changeAgg(Agg<T>* newAgg) {
        bse_agg->setTarget(newAgg);
    }


    template<class T>
    void FuzzyFactory<T>::changeMamdaniDefuzz(MamdaniDefuzz<T>* newDefuzz) {
        bse_mamdaniDefuzz->setTarget(newDefuzz);
    }


    template<class T>
    void FuzzyFactory<T>::changeNot(Not<T>* newNot) {
        use_not->setTarget(newNot);
    }

    template<class T>
    void FuzzyFactory<T>::changeSugenoDefuzz(SugenoDefuzz<T>* newSugenoDefuzz) {
        nse_sugenoDeffuz->setTarget(newSugenoDefuzz);
    }

}

#endif //FUZZY_FUZZYFACTORY_H
