#ifndef FUZZY_NARYSHADOWEXPRESSION_H
#define FUZZY_NARYSHADOWEXPRESSION_H

#include "NaryExpression.h"
#include "Expression.h"
#include <vector>

namespace core {

	template<class T>
	class NaryShadowExpression : public NaryExpression<T> {

		private:
			NaryExpression<T>* target;

		public:
			NaryShadowExpression();
			NaryShadowExpression(NaryExpression<T>* op);
			~NaryShadowExpression();
			void setTarget(NaryExpression<T>* op);
			virtual T evaluate(const std::vector<Expression<T>*> operands) const;

	};

	template<class T>
	NaryShadowExpression<T>::NaryShadowExpression() : target(nullptr) {}

	template<class T>
	NaryShadowExpression<T>::NaryShadowExpression(NaryExpression<T>* op) : target(op) {}

	template<class T>
	NaryShadowExpression<T>::~NaryShadowExpression() {
		delete target;
	}

	template<class T>
	void NaryShadowExpression<T>::setTarget(NaryExpression<T>* op) {
		target = op;
	}

	template<class T>
	T NaryShadowExpression<T>::evaluate(const std::vector<Expression<T>*> operands) const {
		if (target != nullptr) 
			return target->evaluate(operands);
	}

}

#endif // !FUZZY_NARYSHADOWEXPRESSION_H
