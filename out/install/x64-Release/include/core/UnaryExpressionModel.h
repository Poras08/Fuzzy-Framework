#ifndef FUZZY_UNARYEXPRESSIONMODEL_H
#define FUZZY_UNARYEXPRESSIONMODEL_H

#include "UnaryExpression.h"
#include "Expression.h"

namespace core {

    template<class T>
    class UnaryExpressionModel : public UnaryExpression<T>, public Expression<T> {

    public:
        UnaryExpressionModel(UnaryExpression<T>*, Expression<T>*);
        ~UnaryExpressionModel();
        virtual T evaluate() const;
        virtual T evaluate(const Expression<T>*) const;

    private:
        UnaryExpression<T> *UE_operator;
        Expression<T> *UE_operand;

    };

    template<class T>
    UnaryExpressionModel<T>::UnaryExpressionModel(UnaryExpression<T> *_UE_operator, Expression<T> *_UE_operand) : UE_operator(_UE_operator), UE_operand(_UE_operand) {}

    template<class T>
    UnaryExpressionModel<T>::~UnaryExpressionModel() {
        delete UE_operator;
        delete UE_operand;
    }

    template<class T>
    T UnaryExpressionModel<T>::evaluate() const {
        if(UE_operand != nullptr) return evaluate(UE_operand);
    }

    template<class T>
    T UnaryExpressionModel<T>::evaluate(const Expression<T> *o) const {
        if(UE_operator != nullptr) return UE_operator->evaluate(o);
    }

}

#endif //FUZZY_UNARYEXPRESSIONMODEL_H
