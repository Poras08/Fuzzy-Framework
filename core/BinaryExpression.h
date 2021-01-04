//
// Created by Busra on 28/01/2020.
//

#ifndef FUZZY_BINARYEXPRESSION_H
#define FUZZY_BINARYEXPRESSION_H

#include "Expression.h"

namespace core {

    template<class T>
    class BinaryExpression {

    public :
        virtual T evaluate(const Expression<T>* left, const Expression<T>* right) const =0;

    };

}


#endif //FUZZY_BINARYEXPRESSION_H
