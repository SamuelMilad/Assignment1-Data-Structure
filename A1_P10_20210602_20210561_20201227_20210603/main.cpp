#include <iostream>
using namespace std;
template<class T>
struct node
{
    T data;
    node<T> *next;
};
template<class T>
class List {
private:
    node<T>* head,*last;
public:
    List()
    {
        head= nullptr;
        last= new node<T>;
       // dummy= new node<T>;
    }

    List(T value, int initial_size){
        node<T> *new_node=new node<T>;
        new_node->data=value;
        new_node->next=nullptr;
        head=new_node;
        last=new_node;
        new_node=nullptr;
        for(int i=0;i<initial_size-1;++i){
            node<T> *new_node=new node<T>;
            new_node->data=value;
            new_node->next=nullptr;
            last->next=new_node;
            last=new_node;
        }
    }
    int size()
    {
        int count=0;
        node<T>* new_node=new node<T>;
        new_node=head;
        //node<T> *new_node=new node<T>;
        while(new_node!= nullptr)
        {
            new_node=new_node->next;
            count++;
        }
        return count;
    }

    void push_back(T value)
    {
        node<T> *new_node=new node<T>;
        new_node->data=value;
        new_node->next=nullptr;
        if(head==nullptr)
        {
            head=new_node;
            last=new_node;
            new_node=nullptr;
        }
        else
        {
            last->next=new_node;
            last=new_node;
        }
    }

     List<T>& operator = (List<T> another_list){
         if( this == &another_list )
             return *this;
         iterator it =another_list.begin( );
         this->push_back(*it);
         do{
             ++it;
             this->push_back(*it);
         }while(it != another_list.end());
         return *this;
     }
          //inner class
    class iterator {
    public:
        node<T> *node_iterator,*head_iterator;

    public:
        iterator()
        {
            node_iterator= NULL;
            head_iterator= NULL;
        }
        iterator(node<T> *n,node<T> *h){
            node_iterator=n;
            head_iterator=h;
        }
        void operator ++ ()
        {
            if(node_iterator->next== nullptr)
                cout<<"currently pointing is after the last element";
            else node_iterator=node_iterator->next;
        }
        /*void operator -- (){

        }*/
        T & operator * ()
        {
           return node_iterator->data;
        }
        bool operator == (const iterator & i) const
        {
           if (node_iterator == i.node_iterator)
            return true;
           else
               return false;
        }
        bool operator != (const iterator & i) const
        {
            if (node_iterator != i.node_iterator)
                return true;
            else
                return false;
        }

    };
    void insert(T value, int position)
    {
        node <T> *new_node=new node<T>;
        node <T> *current_node=new node<T>;
        node <T> *previous_node=new node<T>;
        current_node=head;
        for(int i=0;i<position;i++)
        {
            previous_node=current_node;
            current_node=current_node->next;
        }
        new_node->next=current_node;
        previous_node->next=new_node;
        new_node->data=value;
    }



     iterator erase(iterator position) {
        node<T> *delete_node = position.node_iterator->next;
        position.node_iterator->next = position.node_iterator->next->next;
        if (delete_node == last)
            last = position.node_iterator;
        delete delete_node;
        return position;
    }

    void erase(int position) {
        node<T> *current=new node<T>;
        node<T> *previous=new node<T>;
        current=head;
        for(int i=1;i<position;i++)
        {
            previous=current;
            current=current->next;
        }
        previous->next=current->next;
    }


    iterator begin()
    {
        return iterator(head,head);
    }
    iterator end()
    {
        return iterator(last,head);
    }
    ~List()
    {
        delete head;
        delete last;
    }
    void display()
    {
        node<T> *new_node=new node<T>;
        new_node=head;
        while(new_node!=nullptr)
        {
            cout<<new_node->data<<" ";
            new_node=new_node->next;
        }
        cout<<endl;
    }


};

int main() {

        List<int> _list(4,3);
    _list.push_back(7);
    _list.push_back(8);
    _list.push_back(9);
        cout<<_list.size()<<endl;
    _list.display();
    _list.insert(5,3);
    _list.display();
    _list.erase(2);
    _list.display();

    List<int>:: iterator it = _list.begin();
    cout<<*it <<"\t" ;
    ++it;
    cout<<*it<< endl;
    _list.erase(it);
    _list.display();

    List<int> _list2;
    _list2 = _list;
    cout<<"deep copy list1 into list2"<<endl;
    _list2.display();

    return 0;
}
