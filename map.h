#ifndef MAPCLASS_
#define MAPCLASS_

using namespace std;

template<typename T, typename U>
class pairClass{
    
public:
    pairClass(T f, U s){
        cout << "constructor pair" << endl;
        key = f;
        element = s;
        next = nullptr;
    }
    ~pairClass(){}
private:
    T key;
    U element;
    pairClass<T, U>* next;
    template<typename X, typename Y>friend class mapClass;
};
template<typename T, typename U>
class mapClass{
private:
        pairClass<T,U>* head; //act pointer to pairClass
        pairClass<T,U>* tail;
        int _size;
public:
    mapClass(): head{nullptr}, tail{nullptr}, _size(0){
        cout << "map constructor" << endl;
    }
    ~mapClass(){}
    void insert_pair(pairClass<T, U> v){
        if(tail){
            pairClass<T, U>* ptr = tail;
            ptr->next = &v;
            tail = &v;
        }else{
            tail = &v;
            head = &v;
        }
        _size++;
    }
    U find(T keyw){
        pairClass<T, U>* ptr = head;
        while(ptr){
            if(ptr->key == keyw){
                return ptr->element;
            }
            ptr = ptr->next;
        }
        return tail->element;
    }
    void show(){
        pairClass<T, U>* ptr = head;
        cout << "key " << "element" << endl;
        while(ptr){
            cout << ptr->key << " " << ptr->element << endl;
            ptr = ptr->next;
        }
    }
    int size(){
        return _size;
    }
    U begin(){
        return tail->element;
    }
    U end(){
        return head->element;
    }
    bool empty(){
        return head == nullptr;
    }
    void erase(T keyw){
        pairClass<T, U>* ptr = head;
        pairClass<T, U>* prev;
        while(ptr){
            if(ptr->key == keyw){
                    prev->next = ptr->next;
            }
            prev = ptr;
            ptr = ptr->next;
        }
    }
};


#endif //MAPCLASS_