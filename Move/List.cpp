#include <functional>
#include <iostream>

using namespace std;

template <class T> class List {
public:
    virtual int getSize() = 0;                          
    virtual bool isEmpty() = 0;
    virtual void clear() = 0;
    virtual List<T>* clone() = 0;
    virtual List<T>* makeEmptyList() = 0;

    virtual void insert(const T& val, int idx) = 0;
    virtual void remove(int idx) = 0;
    virtual int findIdx(const T& val) = 0;
    virtual T* findVal(const T& val) = 0;
    virtual T& operator[](int idx) = 0;

    // virtual void traverse() = 0;
    virtual void traverse(function<void(T&)>);

    virtual void concatenate(List<T>*) = 0;
    virtual List<T>* split(int idx) = 0;
    virtual void reverse() = 0;
};

#define ARRY_LIST_BLOCK = 16

template <class T> class ArrayList : public List<T> {
protected:
    T* pD;
    int cap, nE;

public:
    ArrayList() : cap(0), nE(0), pD(nullptr) {}
    ArrayList(ArrayList<T>& a) : cap(a.cap), nE(a.nE), pD(new T[a.cap]) {
        for (T* p = pD, *p0rg = a.pD, *pE = a.pD + nE; p0rg != pE; ) {
            *p++ = move(*p0rg++);
        }
    }
    ~ArrayList() { clear(); }

    void resize(int N) {
        int newCap;
        T* pND = new T[N];
        for (T* p = pND, *p0 = pD, *pDE = nE < N ? (pD + nE) : (pD + N);
            p0 != pDE;) {
            *p++ = move(*p0++);
        }

        delete[] pD;
        pD = pND;
        cap = newCap;
        nE = nE > N ? N : nE;
    }

    int getSize() { return nE; };

    bool isEmpty() { return !nE; };

    void clear() {
        if (pD) {
            delete[] pD, nE = cap = 0;
        }
    }

    List<T>* clone() {
        // TODO
        return new ArrayList(*this);
    };

    List<T>* makeEmptyList() { return new ArrayList<T>; };

    void insert(const T& val, int idx) = 0;

    void remove(int idx) = 0;

    int findIdx(const T& val) = 0;

    T* findVal(const T& val) = 0;

    T& operator[](int idx) = 0;

    //  void traverse() = 0;
    void traverse(function<void(T&)>);

    void concatenate(List<T>*) = 0;

    List<T>* split(int idx) = 0;

    void reverse() = 0;
};