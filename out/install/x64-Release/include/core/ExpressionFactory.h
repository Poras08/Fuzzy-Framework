#ifndef FUZZY_EXPRESSIONFACTORY_H
#define FUZZY_EXPRESSIONFACTORY_H

#include <set>

#include "Expression.h"
#include "UnaryExpression.h"
#include "BinaryExpression.h"
#include "NaryExpression.h"
#include "UnaryExpressionModel.h"
#include "BinaryExpressionModel.h"
#include "NaryExpressionModel.h"

namespace core {

    template<class T>
    class ExpressionFactory {

    public:
        ExpressionFactory();
        Expression<T>* hold(Expression<T>*);
        void clear();
        Expression<T>* newUnary(UnaryExpression<T>*, Expression<T>*);
        Expression<T>* newBinary(BinaryExpression<T>*, Expression<T>*, Expression<T>*);
        Expression<T>* ExpressionFactory<T>::newNary(NaryExpression<T>* op, std::vector<Expression<T>*> operands);

    private:
        std::set<Expression<T>*> memory;

    };

    template<class T>
    ExpressionFactory<T>::ExpressionFactory() : memory(std::set<Expression<T>*>()) {}

    template<class T>
    Expression<T>* ExpressionFactory<T>::hold(Expression<T> *e) {
        memory.insert(e);
        return e;
    }

    template<class T>
    void ExpressionFactory<T>::clear() {
        memory.clear();
    }

    template<class T>
    Expression<T>* ExpressionFactory<T>::newUnary(core::UnaryExpression<T> *op, core::Expression<T> *e) {
        return hold(new UnaryExpressionModel<T>(op,e));
    }

    template<class T>
    Expression<T>* ExpressionFactory<T>::newBinary(BinaryExpression<T> *op, Expression<T> *l, Expression<T> *r) {
        return hold(new BinaryExpressionModel<T>(op,l,r));
    }

    template<class T>
    Expression<T>* ExpressionFactory<T>::newNary(NaryExpression<T> *op, std::vector<Expression<T>*> operands) {
        return hold(new NaryExpressionModel<T>(op,operands));
    }

}

#endif //FUZZY_EXPRESSIONFACTORY_H
