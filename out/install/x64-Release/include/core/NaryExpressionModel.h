//
// Created by benja on 2/18/2020.
//

#ifndef FUZZY_NARYEXPRESSIONMODEL_H
#define FUZZY_NARYEXPRESSIONMODEL_H

#include "NaryExpression.h"
#include "Expression.h"

#include <vector>

namespace core {

    template<class T>
    class NaryExpressionModel : public NaryExpression<T>, public Expression<T> {

    public:
        NaryExpressionModel(NaryExpression<T>*, std::vector<Expression<T>*>);
        ~NaryExpressionModel();
        virtual T evaluate() const;
        virtual T evaluate(const std::vector<Expression<T>*>) const;

    private:
        NaryExpression<T>* NE_operator;
        std::vector<Expression<T>*> operands;

    };

    template<class T>
    NaryExpressionModel<T>::NaryExpressionModel(core::NaryExpression<T> *_NE_operator, std::vector<Expression<T>*> _operands) : NE_operator(_NE_operator), operands(_operands) {}

    template<class T>
    NaryExpressionModel<T>::~NaryExpressionModel() {
        delete NE_operator;
        delete[] operands;
    }

    template<class T>
    T NaryExpressionModel<T>::evaluate() const {
        return evaluate(operands);
    }

    template<class T>
    T NaryExpressionModel<T>::evaluate(const std::vector<Expression<T>*> ops) const {
        if(NE_operator != nullptr)
            return NE_operator->evaluate(ops);
    }

}

#endif //FUZZY_NARYEXPRESSIONMODEL_H