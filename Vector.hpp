using namespace cop4530;

template <typename T>
Vector<T>::Vector(){
    theSize = 0;
    theCapacity = 0;
    array = NULL;
}

template <typename T>
Vector<T>::Vector(const Vector &rhs){
    array = NULL;
    operator=(rhs);
}

template <typename T>
Vector<T>::Vector(int num, const T& val){	    //might need to chage
    theSize = num;
    theCapacity = num;
    array = new T[theCapacity];
    for(int i = 0; i < num; ++i){
	array[i] = val;
    }	
}

template <typename T>
Vector<T>::Vector(const_iterator start, const_iterator end){
//not sure what this constructor requires
    int i = 0;
    theSize = 0;
    theCapacity = 0;
    array = NULL;

    for(const T* Titr= start; Titr != end; Titr++){
	push_back(*Titr);
    }
}

template <typename T>
Vector<T>::~Vector(){
    delete [] array;
}

template <typename T>
const Vector<T>& Vector <T>::operator = (const Vector &rhs){	//possible 1 off error in here
    
    if(*this != rhs){
	delete [] array;
	theSize = rhs.size();
	theCapacity = rhs.theCapacity;

	array = new T[theCapacity];
	for(int i = 0; i < size(); i++){
	    array[i] = rhs.array[i];
	}
    }
    return *this;
}

template <typename T>
T& Vector<T>::operator[](int index){
    return array[index];
}

template <typename T>
const T& Vector<T>::operator[](int index) const{
    return array[index];
}

template <typename T>
T& Vector<T>::at(int loc){
    return array[loc];
}

template <typename T>
const T& Vector<T>::at(int loc) const{
    return array[loc];
}


template <typename T>
T& Vector<T>::front(){
    return size() == 0;
}
template <typename T>
const T& Vector<T>::front() const{
    return size() == 0;
}

template <typename T>
T& Vector<T>::back(){
    return &array[size()];		//refer to the non-const version
}

template <typename T>
const T& Vector<T>::back() const{
    //needs to return the last element in the vector
    return &array[size()];		//copied iterator end, possibly different, consider *T or just T;
}

template <typename T>
int Vector<T>::size() const{
    return theSize;
}

template <typename T>
int Vector<T>::capacity() const{
    return theCapacity;
}

template <typename T>
bool Vector<T>::empty() const{
    return size() == 0;
}

template <typename T>
void Vector<T>::clear(){
    theSize = 0;
    delete [] array;
    array = new T [theCapacity];
}

template <typename T>
void Vector<T>::push_back(const T& val){
    if(theSize == theCapacity)
	reserve(2 * theCapacity + 1);
    array[theSize++] = val;
}

template <typename T>
void Vector<T>::pop_back(){
    theSize--;
}

template <typename T>
void Vector<T>::resize(int num, T val){
    if(num > theCapacity)
	reserve(num * 2 + 1);
    theSize = num;
}

template <typename T>
void Vector<T>::reserve(int size){
    if(size < theSize)
	return;
    T *oldArray = array;		    //Ts = new T[theCapacity]

    array = new T[size];
    for(int i = 0; i < theSize; i ++){
	array[i] = oldArray[i];
    }
    theCapacity = size;

    delete [] oldArray;

}

template <typename T>
void Vector<T>::print(std::ostream& os, char ocf) const{
    for(int i = 0; i < theSize; i++){
	os << array[i] << ocf;
    }
}

template <typename T>
T* Vector<T>::begin(){
    return &array[0];
}

template <typename T>
const T* Vector<T>::begin() const{
    return &array[0];
}

template <typename T>
T* Vector<T>::end(){
    return &array[size()];
}

template <typename T>
const T* Vector<T>::end() const{
    return &array[size()];
}

template <typename T>
T* Vector<T>::insert(iterator itr, const T& val){
    T temp1; 
    T temp2 = val;
    for(iterator i = itr; i < end(); i++){
	temp1 = *i;
	*i = temp2;
	temp2 =  temp1;
    }
    theSize++;
    return itr;
}

template <typename T>
T* Vector<T>::erase(iterator itr){
    theSize--;
    for(itr; itr != end(); itr++){
	*itr = *(itr + 1);
    }
    return itr;
}

template <typename T>
T* Vector<T>::erase(iterator start, iterator end){
//for loop that traverses from back to front 
//uses pop_back
    Vector<T>::iterator flag = end;
    for(iterator itr = start; itr != end; itr++){
	*start = *end;
	start++;
    }
    return flag;
}

template <typename T>
bool operator==(const Vector<T> &lhs, const Vector<T> &rhs){
    if(lhs.size() == rhs.size()){
	for(int i = 0; i < lhs.size(); i++){
    	    if(lhs[i] != rhs[i])
		return false;
	}
    }
    return true;
}

template <typename T>
bool operator !=(const Vector<T> & lhs, const Vector<T> & rhs){
    return !(lhs == rhs);
}

template <typename T>
std::ostream& operator << (std::ostream &os, const Vector<T> &v){
    v.print(os);
    return os;
}













