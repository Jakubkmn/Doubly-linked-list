#ifndef RING_H_
#define RING_H_
#include <iostream>
using namespace std;

template<typename Key, typename Info>
class Ring;
template<typename Key, typename Info>
void split_pos(const Ring<Key, Info>& ring, int start_pos, bool direct, Ring<Key, Info>& ring1, int len1, bool direct1, Ring<Key, Info>& ring2, int len2, bool direct2);
template<typename Key, typename Info>
void split_pos(const Ring<Key, Info>& ring, int start_pos, bool direct, Ring<Key, Info>& ring1, int len1, bool direct1, Ring<Key, Info>& ring2, int len2, bool direct2);

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

            friend ostream& operator<<(ostrean& out, const Node& s)
            {
                out << s.key << " " << s.info;
                return out;
            }
        };
        Node* Any;
    public:
    //opis metod w gicie
        template<typename K, typename I>
        class iterator
        {
            Node* curr;
        public:
            iterator(Node* src)
            {
                curr = src;
            } 

            iterator()
            {
                curr = nullptr;
            }

            iterator(const iterator& src)
            {
                curr = src.curr;
            }

            ~iterator()
            {
            }

            iterator& operator++()
            {
                goNext();
                return *this;
            }

            iterator& operator--()
            {
                goPrev();
                return *this;
            }

            iterator operator=(const iterator& s)
            {}

            iterator operator+(int d)
            {}

            iterator operator-(int d)
            {
            }

            bool operator==(const iterator& s)
            {
                return curr == s.curr;
            }

            bool operator!=(const iterator& s)
            {
                return curr != s.curr
            }

            Node& operator*()
            {
                return *curr;
            }

            Node* operator->()
            {
                return curr;
            }

            friend ostrean& operator<<(ostrean& o, const iterator& it)
            {
                o << *it
                return o;
            }

            bool iter_valid()
            {
                if(curr)
                return true;
                else 
                return false;
            }

            void goNext()
            {
                curr = curr->next;
            }

            

            void goPrev()
            {
                curr = curr->prev;
            }

        };
        typedef iterator<Key, Info> Iterator;
        typedef iterator<const Key, const Info> Const_Iterator;

        Iterator begin()
        {
            return Iterator(Any);
        }

        Iterator end()
        {
            return Iterator(Any);
        }

        Iterator last()
        {
            if(!Any)
            return Iterator(nullptr);
            else
            return Iterator(Any->Prev);
        }

        Const_Iterator const_begin() const 
        {
            return Const_Iterator(Any);
        }

        Const_Iterator const_end() const
        {
            return Const_Iterator(Any);
        }

        Const_Iterator const_last() const
        {
            if(!Any) 
            return Const_Iterator(nullptr);
            
            return Const_Iterator(Any->prev);
        }

        Ring() : Any(nullptr)
        {

        }

        ~Ring()
        {
            clear();
        }

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
        }

        void insert(Const_Iterator& s)
        {
            if(!s.iter_valid())
            throw std::domain_error;
            insert(s->key, s->info);
        }

        void insert(const Key& NewK, const Info& NewI)
        {
            Node* NewNode = new Node(NewK, NewI);

            if(!Any)
            {
                NewNode->next = NewNode;
                NewNode->prev = NewNode;
                Any = NewNode;
            }
            else
            {
                NewNode->next = Any->next;
                NewNode->next->prev = NewNode;
                NewNOde->prev = Any;
                Any->next = NewNode;
                Any = NewNode;
            }
        }

        void removeAll()
        {
            while(Any)
            remove();
        }

        void remove()
        {
            if(Any->next == Any)
            delete Any;
            Any = nullptr;
        }

        bool is_empty() const
        {
            if(!Any) return true;
            return false;
        }
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
        }
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
            
        }
    friend void split_pos<Key, Info>(const Ring<Key, Info>& ring, int start_pos, bool direct, Ring<Key, Info>& ring1, int len1, bool direct1, Ring<Key, Info>& ring2, int len2, bool direct2);
    friend void split_key<Key, Info>(const Ring<Key, Info>& ring, const Key& start_key,int start_occ, bool direct, Ring<Key, Info>& ring1, int len1, bool direct1, Ring<Key, Info>& ring2, int len2, bool direct2);
};

template<typename Key, typename Info>
void split_pos(const Ring<Key, Info>& ring, int start_pos, bool direct, Ring<Key, Info>& ring1, int len1, bool direct1, Ring<Key, Info>& ring2, int len2, bool direct2)
{
    typename Ring<Key, Info>::Const_Iterator iter1;
    typename Ring<Key, Info>::Const_Iterator iter2;
    int c = 0;
    while(c < count &&)
    {
        int oc = 0;
        if(direct1 == true)
        {
            iter1 = ring.const_begin();
            while(oc < len1 &&)
            {
                ring1.insert(iter1);
                iter1++;
                oc++;
            }
        }
        else
        {
            iter1 = ring.const_last();
            while(oc < len1 &&)
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
            while(oc < len2 &&)
            {
                ring2.insert(iter2);
                iter2++;
                oc++;
            }
        }
        else 
        {
            iter2 = ring.const_last();
            whiel(oc < len2 &&)
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
void split_key(const Ring<Key, Info>& ring, const Key& start_key,int start_occ, bool direct, Ring<Key, Info>& ring1, int len1, bool direct1, Ring<Key, Info>& ring2, int len2, bool direct2)
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