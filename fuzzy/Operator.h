//
// Created by Busra on 28/01/2020.
//

#ifndef FUZZY_OPERATOR_H
#define FUZZY_OPERATOR_H

#include "core/UnaryExpression.h"
#include "core/BinaryExpression.h"
#include "core/NaryExpression.h"
#include "core/Expression.h"
#include "core/ValueModel.h"
#include <vector>

namespace fuzzy{

    template<class T>
    class Evaluator {
        public:
            typedef std::pair<std::vector<T>, std::vector<T>> Shape;
            static Shape* buildShape(const core::Expression<T>* l, const core::Expression<T> *r, const T *begin, const T *end, const T *step);
            static std::ostream& printShape(std::ostream& out, const Shape *shape);
    };

    template<class T>
    typename Evaluator<T>::Shape* Evaluator<T>::buildShape(const core::Expression<T> *l, const core::Expression<T> *r, const T *begin,
                                const T *end, const T *step) {
        core::ValueModel<T> *x = (core::ValueModel<T>*)r;
        core::UnaryExpression<T> *f = (core::UnaryExpression<T>*)l;

        std::vector<T> xVector, yVector;
        for(T i = *begin; i < *end; i+=*step) {
            x->setValue(i);
            T y = f->evaluate(x);

            xVector.push_back(x->evaluate());
            yVector.push_back(y);
        }
        return new Shape(xVector,yVector);
    }

    template<class T>
    std::ostream& Evaluator<T>::printShape(std::ostream& os, const Shape* s) {
        os << '[';
        typename std::vector<T>::const_iterator it = s->first.begin();
        for (; it != s->first.end(); ++it)
            os << *it << ", ";
        os << ']';
        os << std::endl;
        os << '[';
        it = s->second.begin();
        for (; it != s->second.end(); ++it)
            os << *it << ", ";
        os << ']';
        return os;
    }

    template<class T>
    class And : public core::BinaryExpression<T>{};

    template<class T>
    class Or : public core::BinaryExpression<T>{};

    template<class T>
    class Then : public core::BinaryExpression<T>{};

    template<class T>
    class Agg : public core::BinaryExpression<T>{};

    template<class T>
    class Not : public core::UnaryExpression<T>{};

    template<class T>
    class Lukasiewicz : public Then<T>{
    public:
        T evaluate(const core::Expression<T> *l, const core::Expression<T> *r) const;

    };

    template<class T>
    class DienesRischer : public Then<T>{
        public:
            T evaluate(const core::Expression<T> *l, const core::Expression<T> *r) const;

    };

    template<class T>
    class Godel : public Then<T>{
        public:
            T evaluate(const core::Expression<T> *l, const core::Expression<T> *r) const;
    };

    template<class T>
            class Zadeh : public Then<T>{
                public:
                    T evaluate(const core::Expression<T> *l, const core::Expression<T> *r) const;

            };


    template<class T>
    class MamdaniDefuzz : public core::BinaryExpression<T> {

        private:
            T begin, end, step;

        public:
            MamdaniDefuzz(const T _begin, const T _end, const T _step);
            T evaluate(const core::Expression<T> *l, const core::Expression<T> *r) const;
            T virtual defuzz(const typename Evaluator<T>::Shape *shape) const = 0;
    };

    template<class T>
    class COGDefuzz : public MamdaniDefuzz<T> {
        public:
            COGDefuzz(const T _begin, const T _end, const T _step);
            T virtual defuzz(const typename Evaluator<T>::Shape *shape) const;
    };

    template<class T>
            class BOADefuzz : public MamdaniDefuzz<T> {
            public:
                BOADefuzz(const T _begin, const T _end, const T _step);
                T virtual defuzz(const typename Evaluator<T>::Shape *shape) const;


            };
    template<class T>
    class LOMDefuzz : public MamdaniDefuzz<T> {
    public:
        LOMDefuzz(const T _begin, const T _end, const T _step);
        T virtual defuzz(const typename Evaluator<T>::Shape *shape) const;
    };

    template<class T>
    class FOMDefuzz : public MamdaniDefuzz<T> {
    public:
        FOMDefuzz(const T _begin, const T _end, const T _step);
        T virtual defuzz(const typename Evaluator<T>::Shape *shape) const;
    };

    template<class T>
    class MOMDefuzz : public MamdaniDefuzz<T> {
    public:
        MOMDefuzz(const T _begin, const T _end, const T _step);
        T virtual defuzz(const typename Evaluator<T>::Shape *shape) const;
    };



    template<class T>
    class SugenoConclusion : public core::NaryExpression<T> {
        private:
            std::vector<T> coeff;

        public:
            SugenoConclusion(std::vector<T>);
            T evaluate(const std::vector<core::Expression<T>*>) const;
    };

    template<class T>
    SugenoConclusion<T>::SugenoConclusion(std::vector<T> _coeff) : coeff(_coeff) {}

    template<class T>
    T SugenoConclusion<T>::evaluate(const std::vector<core::Expression<T>*> operands) const {
        int lenOperands = operands.size();
        int lenCoeff = coeff.size();
        T result(0);
        if (lenOperands == lenCoeff - 1) {
            int i = 0;
            for (i = 0; i < lenOperands; i++) {
                result += operands[i]->evaluate() * coeff[i];
            }
            result += coeff[i];
        }
        return result;
    }

    template<class T>
    class Is : public core::UnaryExpression<T>{};

    template<class T>
    class AndMin : public And<T>{
    public:
        virtual T evaluate(const core::Expression<T>* left, const core::Expression<T>* right) const;
    };

    template<class T>
    class AndMult : public And<T>{
    public:
        virtual T evaluate(const core::Expression<T>* left, const core::Expression<T>* right) const;
    };

    template<class T>
    class OrMax : public Or<T>{
    public:
        virtual T evaluate(const core::Expression<T>* left, const core::Expression<T>* right) const;
    };

    template<class T>
    class OrPlus : public Or<T>{
    public:
        virtual T evaluate(const core::Expression<T>* left, const core::Expression<T>* right) const;
    };

    template<class T>
    class ThenMin : public Then<T>{
    public:
        virtual T evaluate(const core::Expression<T>* left, const core::Expression<T>* right) const;
    };

    template<class T>
    class ThenMult : public Then<T>{
    public:
        virtual T evaluate(const core::Expression<T>* left, const core::Expression<T>* right) const;
    };

    template<class T>
    class SugenoThen : public Then<T>{
        private:
            mutable T _premiseValue;

        public:
            SugenoThen();
            virtual T evaluate(const core::Expression<T>* left, const core::Expression<T>* right) const;
            T premiseValue() const;

    };

    template<class T>
    SugenoThen<T>::SugenoThen() : _premiseValue(0) {}

    template<class T>
    T SugenoThen<T>::evaluate(const core::Expression<T>* left, const core::Expression<T>* right) const {
        _premiseValue = left->evaluate();
        return _premiseValue * right->evaluate();
    }

    template<class T>
    T SugenoThen<T>::premiseValue() const {
        return _premiseValue;
    }

    template<class T>
    class SugenoDefuzz : public core::NaryExpression<T> {

        public:
            virtual T evaluate(const std::vector<core::Expression<T>*> operands) const;
    };

    template<class T>
    T SugenoDefuzz<T>::evaluate(const std::vector<core::Expression<T>*> operands) const {
        T num(0);
        T den(0);
        for (core::Expression<T>* then : operands) {
            core::BinaryExpressionModel<T>* bThen = (core::BinaryExpressionModel<T>*) then;
            SugenoThen<T>* sThen = (SugenoThen<T>*) bThen->getOperator();
            num += bThen->evaluate();
            den += sThen->premiseValue();
        }
        return num / den;
    }

    template<class T>
    class AggMax : public Agg<T>{
    public:
        virtual T evaluate(const core::Expression<T>* left, const core::Expression<T>* right) const;
    };

    template<class T>
    class AggPlus : public Agg<T>{
    public:
        virtual T evaluate(const core::Expression<T>* left, const core::Expression<T>* right) const;
    };


    template<class T>
    class NotMinus1 : public Not<T> {
    public:
        virtual T evaluate(const core::Expression<T>*) const;
    };

    template<class T>
    class IsTriangle : public Is<T> {

    public:
        IsTriangle(T _min, T _mid, T _max);
        virtual T evaluate(const core::Expression<T>*) const;

    private:
        T min,mid,max;
    };

    template<class T>
    class IsTrapezium : public Is<T> {

    public:
        IsTrapezium(T _min, T _start, T _end, T _max);
        virtual T evaluate(const core::Expression<T>*) const;

    private:
        T min, start, end, max;
    };

    template<class T>
    class IsLeftTrapezium : public Is<T> {

    public:
        IsLeftTrapezium(T _start, T _end);
        virtual T evaluate(const core::Expression<T>*) const;

    private:
        T start, end;

    };

    template<class T>
    class IsRightTrapezium : public Is<T> {

    public:
        IsRightTrapezium(T _start, T _end);
        virtual T evaluate(const core::Expression<T>*) const;

    private:
        T start, end;
    };
    
    template<class T>
    class IsGaussian : public Is<T> {

    public:
        IsGaussian(T _mean,T _stddev);
        virtual T evaluate(const core::Expression<T>*) const;

    private:
        T mean,std_dev;
    };

    template <class T>
    class IsRectangle : public Is<T>{

    public :
        IsRectangle(T _start,T _end);
        virtual T evaluate(const core::Expression<T>*) const;
    };

    template <class T>
    class IsSigmoid : public Is<T>{

    public :
        IsSigmoid(T _pente, T _inflection);
        virtual T evaluate(const core::Expression<T>*)const;

    private:
        T  pente, inflection;
    };

    template <class T>
    class IsBell : public Is<T>{

    public:
        IsBell(T _min,T _mid, T _center);
        virtual T evaluate(const core::Expression<T>*)const;

    private:
        T min,mid,center;
    };
    

    template<class T>
    T AndMin<T>::evaluate(const core::Expression<T>* left, const core::Expression<T>* right) const{
        T leftEval = left->evaluate();
        T rightEval = right->evaluate();
        return (leftEval<rightEval) ? leftEval : rightEval;
    }

    template<class T>
    T AndMult<T>::evaluate(const core::Expression<T>* left, const core::Expression<T>* right) const{
        T leftEval = left->evaluate();
        T rightEval = right->evaluate();
        return (leftEval*rightEval);
    }

    template<class T>
    T OrMax<T>::evaluate(const core::Expression<T>* left, const core::Expression<T>* right) const{
        T leftEval = left->evaluate();
        T rightEval = right->evaluate();
        return (leftEval>rightEval) ? leftEval : rightEval;
    }

    template<class T>
    T OrPlus<T>::evaluate(const core::Expression<T>* left, const core::Expression<T>* right) const{
        T leftEval = left->evaluate();
        T rightEval = right->evaluate();
        return(leftEval+rightEval);
    }

    template<class T>
    T ThenMin<T>::evaluate(const core::Expression<T>* left, const core::Expression<T>* right) const{
        T leftEval = left->evaluate();
        T rightEval = right->evaluate();
        return (leftEval<rightEval) ? leftEval : rightEval;
    }

    template<class T>
    T ThenMult<T>::evaluate(const core::Expression<T>* left, const core::Expression<T>* right) const{
        T leftEval = left->evaluate();
        T rightEval = right->evaluate();
        return (leftEval*rightEval);
    }

    template<class T>
    T AggMax<T>::evaluate(const core::Expression<T>* left, const core::Expression<T>* right) const{
        T leftEval = left->evaluate();
        T rightEval = right->evaluate();
        return (leftEval>rightEval) ? leftEval : rightEval;
    }

    template<class T>
    T AggPlus<T>::evaluate(const core::Expression<T>* left, const core::Expression<T>* right) const{
        T leftEval = left->evaluate();
        T rightEval = right->evaluate();
        return(leftEval+rightEval);
    }

    template<class T>
    T Lukasiewicz<T>::evaluate(const core::Expression<T> *left, const core::Expression<T> *right) const {
        T leftEval = left->evaluate();
        T rightEval = right->evaluate();

        return (rightEval<leftEval) ? (1 - leftEval + rightEval) : 1;
    }

    template<class T>
    T DienesRischer<T>::evaluate(const core::Expression<T> *left, const core::Expression<T> *right) const{
        T leftEval = left->evaluate();
        T rightEval = right->evaluate();

        return (rightEval>1-leftEval)? rightEval : 1 - leftEval;
    }

    template<class T>
    T Godel<T>::evaluate(const core::Expression<T> *left, const core::Expression<T> *right) const {
        T leftEval = left->evaluate();
        T rightEval = right->evaluate();

        return (leftEval<rightEval)? 1 : rightEval;
    }

    template<class T>
    T Zadeh<T>::evaluate(const core::Expression<T> *left, const core::Expression<T> *right) const {
        T leftEval = left->evaluate();
        T rightEval = right->evaluate();

        return (leftEval<0.5 || (rightEval+leftEval)<1)? 1 - leftEval : (leftEval<rightEval)? leftEval : rightEval;
    }
    template<class T>
    T NotMinus1<T>::evaluate(const core::Expression<T> *e) const {
        T eval = e->evaluate();
        return 1 - eval;
    }

    template<class T>
    IsTriangle<T>::IsTriangle(T _min, T _mid, T _max) : min(_min), mid(_mid), max(_max) {}

    template<class T>
    T IsTriangle<T>::evaluate(const core::Expression<T> *e) const {
        T eval = e->evaluate();
        if(eval <= min || eval >= max) return T();
        else if(eval > min && eval <= mid) return (1/(mid - min) * eval) - (min / (mid - min ));
        else if(eval > mid && eval < max) return (1/(mid - max) * eval) - (max / (mid - max));
    }

    template<class T>
    IsTrapezium<T>::IsTrapezium(T _min, T _start, T _end, T _max) : min(_min), start(_start), end(_end), max(_max) {}

    template<class T>
    T IsTrapezium<T>::evaluate(const core::Expression<T> *e) const {
        T eval = e->evaluate();
        if(eval <= min || eval >= max) return T();
        else if(eval > min && eval < start) return (1/(start - min) * eval) - (min / (start - min ));
        else if(eval >= start && eval <= end) return T(1);
        else if(eval > end && eval < max) return (1/(end - max) * eval) - (max / (end - max));
    }

    template<class T>
    IsLeftTrapezium<T>::IsLeftTrapezium(T _start, T _end) : start(_start), end(_end) {}

    template<class T>
    T IsLeftTrapezium<T>::evaluate(const core::Expression<T> *e) const {
        T eval = e->evaluate();
        if(eval <= start) return T(1);
        else if(eval > start && eval < end) return (1/(start - end) * eval) - (end / (start - end));
        else return T();
    }

    template<class T>
    IsRightTrapezium<T>::IsRightTrapezium(T _start, T _end) : start(_start), end(_end) {}

    template<class T>
    T IsRightTrapezium<T>::evaluate(const core::Expression<T> *e) const {
        T eval = e->evaluate();
        if(eval <= start) return T();
        else if(eval > start && eval < end) return (1/(end - start) * eval) - (start / (end - start ));
        else return T(1);
    }
    
    template <class T>
    IsGaussian<T>::IsGaussian (T _mean, T _stdDev) :mean(_mean), stdDev(_stdDev) {}

    template <class T>
    T IsGaussian<T>:: evaluate(const core::Expression<T>* e) const
    {
        T eval = e->evaluate();
        return exp(-pow((eval - mean), 2) / (2 * pow(stdDev, 2)));
    }

    template <class T>
    IsRectangle<T>::IsRectangle(T _start, T _end): start(_start), end(_end){}

    template <class T>
    T IsRectangle<T>:: evaluate(const core::Expression<T>* e)const
    {
        T eval = e->evaluate();
        if (eval >= start && eval <= end)
            return 1;
        return 0;
    }

    template <class T>
    IsSigmoid<T>::IsSigmoid(T _pente, T _inflection):pente(_pente), inflection(_inflection) {}

    template <class T>
    T IsSigmoid<T>:: evaluate(const core::Expression<T>* e)const
    {
        T eval = e->evaluate();
        return (1 / (1 + exp(-pente * (eval - inflection))));
    }

    template <class T>
    IsBell<T>::IsBell(T _min, T _mid, T _center):min(_min),mid(_mid),center(_center){}

    template <class T>
    T IsBell<T>:: evaluate(const core::Expression<T>* e)const
    {
        T eval=e->evaluate();
        return 1/(1+(pow((abs((eval-center)/min)),(2*mid))));
    }

    template<class T>
    MamdaniDefuzz<T>::MamdaniDefuzz(const T _begin, const T _end, const T _step) : begin(_begin), end(_end), step(_step) {}

    template<class T>
    T MamdaniDefuzz<T>::evaluate(const core::Expression<T> *l, const core::Expression<T> *r) const {
        return this->defuzz(Evaluator<T>::buildShape(l,r,&begin,&end,&step));
    }

    template<class T>
    COGDefuzz<T>::COGDefuzz(const T _begin, const T _end, const T _step) : MamdaniDefuzz<T>(_begin, _end, _step) {}

    template<class T>
    T COGDefuzz<T>::defuzz(const typename Evaluator<T>::Shape *shape) const {
        std::vector<T> fi = shape->first;
        std::vector<T> se = shape->second;
        float den = 0, num = 0, count = 0;
        for (T val : se) {
            den += val;
            num += val * fi[count];
            count++;
        }
        return num / den;
    }

    template<class T>
    BOADefuzz<T>::BOADefuzz(const T _begin, const T _end, const T _step) : MamdaniDefuzz(_begin, _end, _step) {}

    template<class T>
    T BOADefuzz<T>::defuzz(const typename Evaluator<T>::Shape *shape) const {
        std::vector<T> fi = shape->first;
        std::vector<T> se = shape->second;
        float den = 0, num = 0;


        for(int k = 0; k < fi.size(); k++){
            T zoneGauche = 0;
            T zoneDroite = 0;

            for(int i = 0; i <= k; i++ ){
                zoneGauche += se[i]*step;
            }
            for(int j = fi.size()-1; j>=k; j--){
                zoneDroite += se[j]*step;
            }
            if(zoneGauche==zoneDroite){
                return fi[k];
            }
            else if(zoneGauche>=zoneDroite){
                return (fi[k]+fi[k-1])/2;
            }

        }
    }

    template<class T>
    LOMDefuzz<T>::LOMDefuzz(const T _begin, const T _end, const T _step) : MamdaniDefuzz<T>(_begin, _end, _step) {}

    template<class T>
    T LOMDefuzz<T>::defuzz(const typename Evaluator<T>::Shape *shape) const {
        std::vector<T> fi = shape->first;
        std::vector<T> se = shape->second;
        float val_maxima = se[0], x_maxima = fi[0];
        for (unsigned int i =0; i < fi.size();i++ ) {
            if(se[i]>= val_maxima){
                x_maxima = fi[i];
                val_maxima = se[i];
            }

        }
        return x_maxima;
    }

    template<class T>
    FOMDefuzz<T>::FOMDefuzz(const T _begin, const T _end, const T _step) : MamdaniDefuzz<T>(_begin, _end, _step) {}

    template<class T>
    T FOMDefuzz<T>::defuzz(const typename Evaluator<T>::Shape *shape) const {
        std::vector<T> fi = shape->first;
        std::vector<T> se = shape->second;
        float val_maxima = se[0], x_maxima = fi[0];
        for (unsigned int i =0; i < fi.size();i++ ) {
            if(se[i]> val_maxima){
                x_maxima = fi[i];
                val_maxima = se[i];
            }

        }
        return x_maxima;
    }

    template<class T>
    MOMDefuzz<T>::MOMDefuzz(const T _begin, const T _end, const T _step) : MamdaniDefuzz<T>(_begin, _end, _step) {}

    template<class T>
    T MOMDefuzz<T>::defuzz(const typename Evaluator<T>::Shape *shape) const {
        std::vector<T> fi = shape->first;
        std::vector<T> se = shape->second;
        float val_maxima1 = se[0], x_maxima1 = fi[0];
        float val_maxima2 = se[0], x_maxima2 = fi[0];
        for (unsigned int i =0; i < fi.size();i++ ) {
            if(se[i]>= val_maxima1){
                x_maxima1 = fi[i];
                val_maxima1 = se[i];
            }
            if(se[i]> val_maxima2){
                x_maxima2 = fi[i];
                val_maxima2 = se[i];
            }
        }
        return (x_maxima1+x_maxima2)/2;
    }

}
#endif //FUZZY_OPERATOR_H
