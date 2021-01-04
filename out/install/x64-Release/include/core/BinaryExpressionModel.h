#ifndef FUZZY_BINARYEXPRESSIONMODEL_H
#define FUZZY_BINARYEXPRESSIONMODEL_H

#include "BinaryExpression.h"
#include "Expression.h"

namespace core {
    template<class T>
    class BinaryExpressionModel : public BinaryExpression<T>, public Expression<T> {

    public:
        BinaryExpressionModel(BinaryExpression<T>*,Expression<T>*,Expression<T>*);
        ~BinaryExpressionModel();
        virtual T evaluate() const;
        virtual T evaluate(const Expression<T>*, const Expression<T>*) const;
        BinaryExpression<T>* getOperator() const;

    private:
        BinaryExpression<T> *BE_operator;
        Expression<T> *left, *right;

    };

    template<class T>
    BinaryExpressionModel<T>::BinaryExpressionModel(core::BinaryExpression<T> *_BE_operator, core::Expression<T> *_left,
                                                    core::Expression<T> *_right) : BE_operator(_BE_operator), left(_left), right(_right) {}

    template<class T>
    BinaryExpressionModel<T>::~BinaryExpressionModel() {
        delete BE_operator;
        delete left;
        delete right;
    }

    template<class T>
    T BinaryExpressionModel<T>::evaluate() const {
        if(left != nullptr && right != nullptr) return evaluate(left,right);
    }

    template<class T>
    T BinaryExpressionModel<T>::evaluate(const Expression<T> *_left, const Expression<T> *_right) const {
        if(BE_operator != nullptr) return BE_operator->evaluate(_left,_right);
    }

    template<class T>
    BinaryExpression<T>* BinaryExpressionModel<T>::getOperator() const {
        return BE_operator;
    }
}

#endif //FUZZY_BINARYEXPRESSIONMODEL_H
