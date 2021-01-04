#ifndef FUZZY_BINARYSHADOWEXPRESSION_H
#define FUZZY_BINARYSHADOWEXPRESSION_H

#include "BinaryExpression.h"
#include "Expression.h"

namespace core {

    template<class T>
    class BinaryShadowExpression : public BinaryExpression<T> {

    public:
        BinaryShadowExpression();
        BinaryShadowExpression(BinaryExpression<T>*);
        ~BinaryShadowExpression();
        void setTarget(BinaryExpression<T>*);
        virtual T evaluate(const Expression<T>*, const Expression<T>*) const;

    private:
        BinaryExpression<T> *target;

    };

    template<class T>
    BinaryShadowExpression<T>::BinaryShadowExpression() : target(nullptr) {}

    template<class T>
    BinaryShadowExpression<T>::BinaryShadowExpression(BinaryExpression<T> *be) : target(be) {}

    template<class T>
    BinaryShadowExpression<T>::~BinaryShadowExpression() {
        delete target;
    }

    template<class T>
    void BinaryShadowExpression<T>::setTarget(BinaryExpression<T> *be) {
        target = be;
    }

    template<class T>
    T BinaryShadowExpression<T>::evaluate(const core::Expression<T> *l, const core::Expression<T> *r) const {
        if(target != nullptr)
            return target->evaluate(l,r);
    }

}

#endif //FUZZY_BINARYSHADOWEXPRESSION_H
