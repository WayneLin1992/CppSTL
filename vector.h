#ifndef VECTORCLASS_
#define VECTORCLASS_

using namespace std; 
template<typename T>
class vectorClass{
private:
    unsigned int _size;
    unsigned int _capacity;
    T* arr;
public:
    vectorClass(): _size{0}, _capacity{8}, arr{new T[_capacity]}{
        cout << "default constructor" << endl;
    }
    vectorClass(unsigned int s, T data): _size{s}, _capacity{s > 8 ? 2*s : 8}, arr{new T[_capacity]}{
        cout << "constructor from s and data" << endl;
        for(unsigned int i = 0; i < _size; i++)
            arr[i] = data;
    }
    vectorClass(std::initializer_list<T> lst) : _size{(unsigned int)lst.size()}{
        cout << "initalizer lst" <<endl;
        _capacity = (lst.size()*2 > 8) ? lst.size()*2:8;
        arr = new T[_capacity];
        if(lst.size() > 0 )
            std::copy( lst.begin(), lst.end(), arr);
    }
    vectorClass(vectorClass&v) :_size{v._size}, _capacity{v._capacity}, arr(new T[_capacity]){
        cout << "copy constructor" <<endl;
        for(unsigned int i = 0; i < v._size; i++){
            arr[i] = v.arr[i];
        }
    }
    ~vectorClass(){
        delete [] arr;
        cout << "default deconnstructor" << endl;
    }
    void push_back(T data);
    void pop_back();
    void show();
    bool empty();
    unsigned int size();
    unsigned int max_size();
    void sort();
    void rsort();
    T begin();
    T end();
    void emplace(unsigned int p, T data);
    vectorClass& operator=(const vectorClass& v);
};

template<typename T>
void vectorClass<T>::push_back(T data){
    if(_size + 1 >= _capacity){
        T* tmp = new T[2 *_capacity];
        for (unsigned int i = 0; i <= _size; i++){
            tmp[i] = arr[i];
        }
        delete [] arr;
        _capacity = 2 * _capacity;
        arr  = tmp;
    }
    arr[_size] = data;
    _size ++;
}
template<typename T>
void vectorClass<T>::pop_back(){
    if(_size == 0){
        cout << "it's empty" << endl;
    }else{
        arr[_size] = 0;
        _size--;
    }
}
template<typename T>
void vectorClass<T>::show(){
    cout << "{ " ;
    for(unsigned int i = 0; i < _size; i++){
        cout << arr[i] << " ";
    }
    cout << "} " <<endl;
}
template<typename T>
bool vectorClass<T>::empty(){
    return _size == 0;
}
template<typename T>
unsigned int vectorClass<T>::size(){
    return _size;
}
template<typename T>
unsigned int vectorClass<T>::max_size(){
    return _capacity;
}
template<typename T>
void  vectorClass<T>::sort(){
    T* a = arr;
    unsigned int n = _size;
    for (unsigned int i = 0; i < n - 1; i++)
        for (unsigned int  j = n - 1; i < j; j--)
            if (a[j] < a[j - 1])
              swap(a[j], a[j - 1]);
}
template<typename T>
void vectorClass<T>::rsort(){
    T* a = arr;
    unsigned int n = _size;
    for (unsigned int i = 0; i < n - 1; i++)
        for (unsigned int  j = n - 1; i < j; j--)
            if (a[j] > a[j - 1])
              swap(a[j], a[j - 1]);
}
template<typename T>
T vectorClass<T>::begin(){
    return arr[0];
}
template<typename T>
T vectorClass<T>::end(){
    return arr[_size - 1];
}
template<typename T>
void vectorClass<T>::emplace(unsigned int p, T data){
    if(p < _size && (_size + 1) < _capacity ){
        T* tmp = new T[_capacity];
        unsigned int i = 0;
        for(; i < p; i++){
            tmp[i] = arr[i];
        }
        tmp[p] = data;
        for(; i < _size; i++){
            tmp[i+1] = arr[i];
        }
        delete [] arr;
        arr = tmp;
        _size++;
    }else if(p < _size && (_size + 1) >= _capacity){
        T* tmp = new T[2 * _capacity];
        unsigned int i = 0;
        for(; i < p; i++){
            tmp[i] = arr[i];
        }
        tmp[p] = data;
        for(; i < _size; i++){
            tmp[i+1] = arr[i];
        }
        delete [] arr;
        arr = tmp;
        _capacity *= 2;
        _size++;
    }else if(p > _size && (_size + 1) < _capacity){
        arr[p] = data;
        _size++;
    }else{
        T* tmp = new T[2 * p];
        unsigned int i = 0;
        for(; i < _size; i++){
            tmp[i] = arr[i];
        }
        tmp[p] = data;
        delete [] arr;
        arr = tmp;
        _capacity = 2 * p;
        _size = p + 1;
    }
}
template<typename T>
vectorClass<T>& vectorClass<T>::operator=(const vectorClass<T>& v){
        cout << "copy constructor " << endl;
        vectorClass tmp {v};
        std::swap(arr, tmp.arr);
        _size = tmp.size();
        _capacity = tmp.max_size();
        return *this;
    }

#endif //VECTORCLASS_