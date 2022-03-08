#ifndef PAIRCLASS_
#define PAIRCLASS_

using namespace std;
template<typename T, typename U>
class pairClass{
public:
    T first;
    U second;
    pairClass(){}
    pairClass(T f, U s){
        first = f;
        second = s;
    }
    pairClass(const pairClass &v){
        cout << "copy constructor" << endl;
        first = v.first;
        second = v.second;
    }
    ~pairClass(){}
    pairClass& operator=(const pairClass& v ){
        cout << "copy constructor1" << endl;
        first = v.first;
        second = v.second;
        return *this;
    }
    pairClass<T, U>& swap_pairClass(pairClass<T, U>& v){
        T tmp;
        tmp = v.first;
        v.first = this->first;
        this->first = tmp;
        U tmp1;
        tmp1 = v.second;
        v.second = this->second;
        this->second = tmp1;
        return *this;
    }
    bool operator== (const pairClass pr){
        cout << " == " << endl;
        return ((first == pr.first) && (second == pr.second));
    }
    bool operator!= (const pairClass pr){
        cout << " != " << endl;
        return ((first != pr.first) && (second != pr.second));
    }
};

template<typename T, typename U>
pairClass<T, U> make_pairClass(T f, U s ){
    pairClass<T, U>p1;
    p1.first = f;
    p1.second = s;
    return p1;
}

#endif //PAIRCLASS_