#ifndef INTCOUNTERTEMPLATE_H_INCLUDED
#define INTCOUNTERTEMPLATE_H_INCLUDED

template<class T>
class IntCounter {
private :
    T * ptr = nullptr;
    T * counter = nullptr;
    void add_reference ();
    void remove_reference ();
    void freeMemory ();
    void redirectPointers (T* newPtr, T* newCounter);
    void redirectPointers ( const IntCounter& rhs);
public :
    IntCounter() = default ;
    IntCounter( T * newPtr);
    IntCounter( const IntCounter& rhs);
    IntCounter& operator=( const IntCounter& rhs);
    ~IntCounter();
    T get_count () const ;
    T get_value () const ;
};


#endif // INTCOUNTERTEMPLATE_H_INCLUDED
