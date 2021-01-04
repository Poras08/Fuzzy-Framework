//
// Created by benja on 2/18/2020.
//

#ifndef FUZZY_NARYEXPRESSION_H
#define FUZZY_NARYEXPRESSION_H

#include "Expression.h"
#include <vector>

namespace core {

    template<class T>
    class NaryExpression {

    public:
        virtual T evaluate(const std::vector<Expression<T>*>) const = 0;

    };

}

#endif //FUZZY_NARYEXPRESSION_H
