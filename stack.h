#ifndef STACKCLASS_
#define STACKCLASS_

using namespace std;
template<typename T>
class ListNode{
private:
    T val;
    ListNode* next;
    template<typename U>friend class stackClass;
public:
    ListNode(const T& data){
        val = data;
        next = nullptr;
        cout << " constructor listnode " << endl;
    }
    ~ListNode(){}
};

template<typename T>
class stackClass{
private:
    ListNode<T>* bottom;
    ListNode<T>* top;
    int _size;
public:
    stackClass(): bottom{nullptr}, top{nullptr}, _size{0}{}
    ~stackClass(){
            if(!empty())
                pop();
            cout << "deconstructor" << endl;
    }
   void push(T data){
        ListNode<T> *ls = new ListNode<T>(data);
        if(top){
            top->next = ls;
            top = ls;
        }else{
            top = ls;
            bottom = ls;
        }
        _size++;
    }
    void pop(){
        if(top && top != bottom){
            ListNode<T>* lt = top;
            ListNode<T> *prev = bottom;
            int size = _size;
            for(int i = 0; i < (size - 1); i++)
                prev = prev->next;
            prev->next = nullptr;
            top  = prev;
            delete lt;
            _size--;
        }else if(top && top == bottom){
            ListNode<T>* lt = top;
            delete lt;
            top = nullptr;
            bottom = nullptr;
            _size--;
        }else if(!top){
            cout << "it is empty stack"<< endl;
        }
    }
    T topper(){
        return top->val;
    }
    int size(){
        return _size;
    }
    bool empty(){
        return top == nullptr;
    }
};

#endif //STACKCLASS_