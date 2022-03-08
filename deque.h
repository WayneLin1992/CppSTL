#ifndef DEQUE_
#define DEQUE_

using namespace std;

template<typename T>
class ListNode{
private:
    T val;
    ListNode* next;
    template<typename U>friend class dequeClass;
public:
    ListNode(const T& data){
        val = data;
        next = nullptr;
        cout << " constructor listnode " << endl;
    }
    ~ListNode(){}
};

template<typename T>
class dequeClass{
private:
    ListNode<T>* head;
    ListNode<T>* tail;
    int _size;
public:
    dequeClass(): head{nullptr}, tail{nullptr}, _size{0}{
        cout << "default constructor" << endl;
    }
    ~dequeClass(){
        if(!empty())
            pop_front();
        cout << "deconstructor" << endl;
    }
    void push_front(T data){
        ListNode<T>* ptr = new ListNode(data);
        if(head){
            ptr->next = head;
            head = ptr;
        }else{
            tail = ptr;
            head = ptr;
        }
        _size++;
    }
    void push_back(T data){
        ListNode<T>* ptr = new ListNode(data);
        if(tail){
            tail->next = ptr;
            tail = ptr;
        }else{
            tail = ptr;
            head = ptr;
        }
        _size++;
    }
    void pop_back(){
        ListNode<T>* ptr = head;
        ListNode<T>*  ptrt = tail;
        if(tail){
            _size--;
            for(int i = 0; i < (_size - 1); i++)
                ptr = ptr->next;
            delete ptrt;
            tail = ptr;
            ptr->next = nullptr;
        }else{
            cout << "it's empty" << endl;
        }
    }
    void pop_front(){
        ListNode<T>* ptr = head->next;
        if(head){
            _size--;
            delete head;
            head = ptr;
        }else{
            cout << "it's empty" << endl;
        }
    }
    int size(){
        return _size;
    }
    bool empty(){
        return _size == 0;
    }
    T front(){
        return head->val;
    }
    T back(){
        return tail->val;
    }
    T at(int i){
        ListNode<T>* ptr = head;
        i--;
        for(; i >0; i--){
            ptr = ptr->next;
        }
        return ptr->val;
    }
    
    void show(){
        ListNode<T>* ptr = head;
        cout << "{ ";
        while(ptr){
            if(ptr == tail)
                cout << ptr->val;
            else
                cout << ptr->val << " ";
            ptr = ptr->next;
        }
        cout << " }" << endl;
    }
};

#endif //DEQUE_