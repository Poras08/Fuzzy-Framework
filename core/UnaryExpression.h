//
// Created by Busra on 28/01/2020.
//

#ifndef FUZZY_UNARYEXPRESSION_H
#define FUZZY_UNARYEXPRESSION_H

#include "Expression.h"

namespace core{

    template<class T>
    class UnaryExpression{

    public:
        virtual T evaluate(const Expression<T>* e) const = 0;

    };

}
#endif //FUZZY_UNARYEXPRESSION_H
