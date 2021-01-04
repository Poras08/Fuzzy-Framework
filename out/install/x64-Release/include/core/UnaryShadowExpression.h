#ifndef FUZZY_UNARYSHADOWEXPRESSION_H
#define FUZZY_UNARYSHADOWEXPRESSION_H

#include "UnaryExpression.h"
#include "Expression.h"

namespace core {

    template<class T>
    class UnaryShadowExpression : public UnaryExpression<T> {

    public:
        UnaryShadowExpression();
        UnaryShadowExpression(UnaryExpression<T>*);
        ~UnaryShadowExpression();
        void setTarget(UnaryExpression<T>*);
        virtual T evaluate(const Expression<T>*) const;

    private:
        UnaryExpression<T> *target;

    };

    template<class T>
    UnaryShadowExpression<T>::UnaryShadowExpression() : target(nullptr) {}

    template<class T>
    UnaryShadowExpression<T>::UnaryShadowExpression(UnaryExpression<T>* ue) : target(ue) {}

    template<class T>
    UnaryShadowExpression<T>::~UnaryShadowExpression() {
        delete target;
    }

    template<class T>
    void UnaryShadowExpression<T>::setTarget(UnaryExpression<T> *ue) {
        target = ue;
    }

    template<class T>
    T UnaryShadowExpression<T>::evaluate(const core::Expression<T> *e) const {
        if(target != nullptr)
            return target->evaluate(e);
    }

}

#endif //FUZZY_UNARYSHADOWEXPRESSION_H
