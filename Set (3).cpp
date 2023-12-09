// File name: A3_SheetPb4_20220242.cpp
// Purpose: set class which take distinct elements and sort them
// Author(s): Fatma ibrahim hamed mabrouk
// ID(s): 20220242
// Section: 19
// Date: 9 / 12 / 2023
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;
template < class T >
class set {
private:
    vector < T > container ;
public:
    void insert(T val) ;
    void remove(T val) ;
    int size() ;
    bool Find (T val) ;
    void print() ;
    T* DynamicArray() const ;
};
template<class T>
void set <T> :: insert(T val){
    auto it = std::find(container.begin(), container.end(),val) ;
    if(it == container.end()) {
        container.push_back(val) ;
    }
    sort(container.begin() , container.end()) ;
}

template<class T>
void set<T> ::remove(T val) {
   auto it = std::find(container.begin(), container.end(),val) ;
   if(it != container.end()){
       container.erase(it) ;
   }
}
template<class T>
int set<T> ::size() {
    return container.size() ;
}
template <class T>
bool set<T> ::Find(T val) {
    auto it = std::find(container.begin(), container.end(),val) ;
    if(it != container.end()){
        return true ;
    }
    return false ;
}
template<class T>
void set<T> ::print() {
    for(auto element : container){
        cout <<  element << ' ' ;
    }
    cout << endl;
}
template<class T>
T* set<T> ::DynamicArray() const {
    T* newArray = new T[container.size()] ;
    for(size_t i = 0 ; i < container.size() ; ++i){
        newArray[i] = container[i] ;
    }
    return newArray ;
}
class Rectangle{
private:
    float Length ;
    float Width ;
public:
    Rectangle(){
        Length = 0 , Width = 0 ;
    }
    Rectangle(float l , float w) : Length(l) , Width(w) {

    }
    float GetRectangleArea() const{
        return Length * Width ;
    }
    bool operator==(const Rectangle &R){
        if(R.Length == this->Length and R.Width == this->Width)
            return true ;
        return false ;
    }
    bool operator!=(const Rectangle &R){
        if(R.Length != this->Length || R.Width != this->Width)
            return true ;
        return false ;
    }
    friend ostream& operator<<(ostream& out, const Rectangle& R) {
        out << R.Length << " " << R.Width << endl;
        return out;
    }
    bool operator <(const Rectangle &R){
        return this->GetRectangleArea() <  R.GetRectangleArea() ;
    }
    bool operator<=(const Rectangle &R)  {
        return this->GetRectangleArea() <= R.GetRectangleArea();
    }
};
int main() {
set<int> st ;
st.insert(5) ;
st.insert(5) ;
st.insert(2) ;
st.insert(2) ;
st.insert(5) ;
st.insert(7) ;
st.remove(7) ;
int *arr = st.DynamicArray() ;
for(size_t i = 0 ; i < st.size() ; ++i){
    cout << arr[i] << ' ' ;
}
cout << endl;
delete[] arr ;
st.print() ;
cout << st.size() << endl;
cout << st.Find(7) << endl;
Rectangle R(10 , 50) , r(50 , 60) , g(10 , 10) , j(5 , 8) , l(5 , 8);
set < Rectangle > x ;
x.insert(R) ;
    x.insert(r) ;
    x.insert(g) ;
    x.insert(j) ;
    x.insert(l) ;
    x.print() ;
    return 0;
}
