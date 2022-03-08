#ifndef QUEUECLASS_
#define QUEUECLASS_

using namespace std;
template<typename T>
class ListNode{
public:
    ListNode(const T& data) : val{data}, next{nullptr}{
        cout << " constructor listnode " << endl;
    }
    ~ListNode(){}
private:
    T val;
    ListNode<T>* next;
    template<typename U>friend class queueClass;
};
template<typename T>
class queueClass {    
public:
    queueClass(){
        this->head = nullptr;
        this->tail = nullptr;
        cout << "default constructor" << endl;
    }
    ~queueClass(){
        if(!empty())
            pop();
        cout << "deconstructor" << endl;
    }
    void push(const T& data){
        ListNode<T> *ls = new ListNode<T>(data);
        if(tail){
            tail->next = ls;
            tail = ls;
        }else{
            tail = ls;
            head = ls;
        }
    }
    void pop(){
        if(head){
            ListNode<T>* ls = head;
            head = ls->next;
            ls->next = nullptr;
            delete ls;
            if(!head)
                tail = nullptr;
        }
    }
    bool empty(){
        return head == nullptr;
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
    void sort();
    int size();
    T front();
    T back();
protected:
    ListNode<T>* head;
    ListNode<T>* tail;
};
template<typename T>
void queueClass<T>::sort(){
    int size = 0;
    ListNode<T>* cur = head;
    ListNode<T>* ptr = head;
    T tmp;
    size = queueClass::size();
    
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - i - 1 ; j++){
            int k = j;
            ptr = head;
            for(; k > 0; k--){
                ptr = ptr->next;
            }
            cur = ptr;
            if(cur->val > cur->next->val){
                tmp = cur->next->val;
                cur->next->val = cur->val;
                cur->val = tmp;
            }
        }
    }
}
template<typename T>
int queueClass<T>::size(){
    ListNode<T>* ptr = head;
    int size = 0;
    while(ptr){
        ptr = ptr->next;
        size++;
    }
    return size;
}
template<typename T>
T queueClass<T>::front(){
    return head->val;
}
template<typename T>
T queueClass<T>::back(){
    return tail->val;
}

#endif //QUEUECLASS_