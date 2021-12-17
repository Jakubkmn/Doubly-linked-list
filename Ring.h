#ifndef RING_H_
#define RING_H_
#include <iostream>
using namespace std;

template<typename Key, typename Info>
class Ring;
template<typename Key, typename Info>
void split_pos(const Ring<Key, Info>& ring, int start_pos, bool direct, int count, Ring<Key, Info>& ring1, int len1, bool direct1, Ring<Key, Info>& ring2, int len2, bool direct2);
template<typename Key, typename Info>
void split_key(const Ring<Key, Info>& ring, const Key& start_key,int start_occ, bool direct, int count, Ring<Key, Info>& ring1, int len1, bool direct1, Ring<Key, Info>& ring2, int len2, bool direct2);
template <typename Key, typename Info>
class Ring { //doubly linked list with iterator
    private:
        struct Node {
            Key key;
            Info info;
            Node* next;
            Node* prev;

            Node()
            {
            };

            Node(const Key& ExistKey, const Info& ExistInfo) : key(ExistKey), info(ExistInfo), next(nullptr), prev(nullptr)
            {
            };

            Node(const Key& ExistKey, const Info& ExistInfo, Node* ExistNext, Node* ExistPrev) : key(ExistKey), info(ExistInfo), next(ExistNext), prev(ExistPrev)
            {
            };

            friend ostream& operator<<(ostream& out, const Node& s)
            {
                out << s.key << " " << s.info;
                return out;
            };
        };
        Node* Any;
    public:
    //opis metod w gicie
        template<typename K, typename I>
        class iterator
        {
            Node* itr;
        public:
            iterator(Node* s)
            {
                itr = s;
            };

            iterator()
            {
                itr = nullptr;
            };

            iterator(const iterator& s)
            {
                itr = s.itr;
            };

            ~iterator()
            {
            };

            iterator& operator++() //pre inc
            {
                goNext();
                return *this;
            };

            iterator operator++(int) //post inc
            {
                iterator before = *this;
                goNext();
                return before;
            };

            iterator& operator--() //pre dec
            {
                goPrev();
                return *this;
            };

            iterator operator--(int) //post dec
            {
                iterator before = *this;
                goPrev();
                return before;
            };

            iterator& operator=(const iterator& s)
            {
                itr = s.itr;
                return *this;
            };

            iterator operator+(int d)
            {};

            iterator operator-(int d)
            {
            };

            bool operator==(const iterator& s)
            {
                return itr == s.itr;
            };

            bool operator!=(const iterator& s)
            {
                return itr != s.itr;
            };

            Node& operator*() const
            {
                return *itr;
            };

            Node* operator->()
            {
                return itr;
            };

            friend ostream& operator<<(ostream& o, const iterator& it)
            {
                o << *it;
                return o;
            };

            bool iter_valid()
            {
                if(itr)
                return true;
                else 
                return false;
            };

            void goNext()
            {
                itr = itr->next;
            };

            void goPrev()
            {
                itr = itr->prev;
            };

            void goNext(int n)
            {
                for(int i = 0; i < n; i++)
                goNext();
            };

            void goPrev(int n)
            {
                for(int i = 0; i < n; i++)
                goPrev();
            };

        };
        typedef iterator<Key, Info> Iterator;
        typedef iterator<const Key, const Info> Const_Iterator;

        Iterator begin()
        {
            return Iterator(Any);
        };

        Iterator end()
        {
            return Iterator(Any);
        };

        Iterator last()
        {
            if(!Any)
            return Iterator(nullptr);
            else
            return Iterator(Any->prev);
        };

        Const_Iterator const_begin() const 
        {
            return Const_Iterator(Any);
        };

        Const_Iterator const_end() const
        {
            return Const_Iterator(Any);
        };

        Const_Iterator const_last() const
        {
            if(!Any) 
            return Const_Iterator(nullptr);
            else
            return Const_Iterator(Any->prev);
        };

        Ring() : Any(nullptr)
        {
        };

        ~Ring()
        {
            removeAll();
        };

        Ring(const Ring<Key, Info>& s)
        {
            Any = nullptr;
            if(!s.is_empty())
            {
              Const_Iterator it = s.const_begin();
                do
                {
                    insert(it);
                    it++;
                } while (it != s.const_end());
            }
        };

        void insert(Const_Iterator& s)
        {
           
            if(!s.iter_valid())
            throw std::domain_error("Error");
            insert(s->key, s->info);
        
            /*Node* tmp = new Node;
            if(s.itr == Any->prev)
            {
                s.itr->prev = tmp;
            }
            s.itr->prev = tmp;
            tmp->prev->next=tmp;*/
        };

        /*void insertFront(const Key& NewK, const Info& NewI)
        {
            if(!s.iter_valid())
            throw std::domain_error("Error");
            Iterator s.it = begin();
            insert(s.it, s->key, s->info);
        };*/

        void insert(const Key& NewK, const Info& NewI)
        {
            Node* NewNode = new Node(NewK, NewI);
            //NewNode->key = NewK;
            //NewNode->info = NewI;
           if(!Any)
            {
                Any = NewNode;
                NewNode->next = NewNode;
                NewNode->prev = NewNode;
                //Any = NewNode;
            }
            else
            {
                NewNode->next = Any;
                Any->prev->next = NewNode;
                NewNode->prev = Any->prev;
                Any->prev = NewNode;
                Any = NewNode;
                /*NewNode->next = Any->next;
                NewNode->next->prev = NewNode;
                NewNode->prev = Any;
                Any->next = NewNode;
                Any = NewNode;
                */
            }
        };

        void removeAll()
        {
            while(Any)
            remove();
        };

        void remove()
        {
            if(Any->next == Any)
            {
            delete Any;
            Any = nullptr;
            }
            else
            {
                Node* pre = Any->prev;
                Node* suc = Any->next;
                pre->next = suc;
                suc->prev = pre;
                delete Any;
                Any = suc;
            }
        };

        bool is_empty() const
        {
            if(!Any) return true;
            return false;
        };
        int amount() const
        {
            if(!Any)
            return 0;
            int i = 0;
            Const_Iterator it = const_begin();
            do
            {
                ++it;
                i++;
            } while (it != const_last());
            return i + 1;
        };
        void print()
        {
            if(is_empty())
            throw std::domain_error("Ring is empty");

            auto it = const_begin();

            do
            {
                cout << it << endl;
                ++it;
            } while (it != const_end());
            
        };
    friend void split_pos<Key, Info>(const Ring<Key, Info>&, int, bool, int, Ring<Key, Info>&, int, bool, Ring<Key, Info>&, int, bool);
    friend void split_key<Key, Info>(const Ring<Key, Info>&, const Key&, int, bool, int, Ring<Key, Info>&, int, bool, Ring<Key, Info>&, int, bool);
};

template<typename Key, typename Info>
void split_pos(const Ring<Key, Info>& ring, int start_pos, bool direct, int count, Ring<Key, Info>& ring1, int len1, bool direct1, Ring<Key, Info>& ring2, int len2, bool direct2)
{
    ring.const_begin() = start_pos;
    typename Ring<Key, Info>::Const_Iterator iter1;
    typename Ring<Key, Info>::Const_Iterator iter2;
    int c = 0;
    while(c < count)
    {
        int oc = 0;
        if(direct1 == true)
        {
            iter1 = ring.const_begin();
            while(oc < len1 && iter1 != nullptr)
            {
                ring1.insert(iter1);
                iter1++;
                oc++;
            }
        }
        else
        {
            iter1 = ring.const_last();
            while(oc < len1 && iter1 != nullptr)
            {
                ring1.insert(iter1);
                iter1++;
                oc++;
            }
        }
        c++;

        if(direct2 == true)
        {
            iter2 = ring.const_begin();
            while(oc < len2 && iter2 != nullptr)
            {
                ring2.insert(iter2);
                iter2++;
                oc++;
            }
        }
        else 
        {
            iter2 = ring.const_last();
            while(oc < len2 && iter2 != nullptr)
            {
                ring2.insert(iter2);
                iter2++;
                oc++;
            }
        }
    }
}
//ring={1,}{2,}{3,}{4,}{5,}
//start_pos=1, direct=true, count=4
//len1=2, direct1=true
//len2=1, direct2=false jak true to zgodnie ze wskazówkami zegara 
//
//ring1={2,}{3,}{5,}{1,}{3,}{4,}{1,}{2,}
//ring2={5,}{2,}{4,}


template<typename Key, typename Info>
void split_key(const Ring<Key, Info>& ring, const Key& start_key,int start_occ, bool direct, int count, Ring<Key, Info>& ring1, int len1, bool direct1, Ring<Key, Info>& ring2, int len2, bool direct2)
{
//ring={1,}{2,}{3,}{4,}{5,}
//start_key=2, start_occ=100, direct=true, count=4
//len1=2, direct1=true
//len2=1, direct2=false 
//
//ring1={2,}{3,}{5,}{1,}{3,}{4,}{1,}{2,}
//ring2={5,}{2,}{4,}
}
#endif