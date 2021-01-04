//
// Created by Busra on 29/01/2020.
//

#ifndef FUZZY_VALUEMODEL_H
#define FUZZY_VALUEMODEL_H

#include "Expression.h"

namespace core {

    template<class T>
    class ValueModel : public Expression<T> {
    public:
        ValueModel();
        ValueModel(const T&);
        virtual ~ValueModel(){};
        T evaluate() const;
        void setValue(const T&);

    private:
        T value;
    };

    template<class T>
    T ValueModel<T>::evaluate() const {
        return value;
    }

    template<class T>
    void ValueModel<T>::setValue(const T &v) {
        this->value = v;
    }

    template<class T>
    ValueModel<T>::ValueModel() : value(T()){}

    template<class T>
    ValueModel<T>::ValueModel(const T& v) : value(v) {}

}
#endif //FUZZY_VALUEMODEL_H
