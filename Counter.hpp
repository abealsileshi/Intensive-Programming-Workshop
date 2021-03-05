/*
CSCI 3010 - Spring 2021
HW2 - Unit Testing
Abeal Sileshi
*/
#include<iostream>
#include<string>
#include<vector>
#include<iterator>
#include<map>
#include<stdexcept>
#include<set>

template <class T>
class Counter{
    public:
        Counter(); //initialize an empty Counter <T>
        Counter(std::vector<T> vals); // Initialize a Counter<t>

        int Count(); // access the total of all counts so far
        int Count(const T key); // access the count associated with any object T, even for values of T that have not been counted
        int Count(const T min , const T max); //access the total of all counts for objects T given a certain range (an inclusive minimum T and an exclusive maximum T element)

        void Remove(T key); //remove the object T from the Counter

        void Increment(T key); //increment the count of an object T by one
        void Increment(T key, int n); //increment the count of an object T by n

        void Decrement(T key); //decrement the count of an object T by one 1
        void Decrement(T key, int n);

        T MostCommon(); //get the most commonly occurring object of type T (the object with the highest count) If the Counter is empty, this method should throw a domain error
        std::vector<T> MostCommon(int n); //get the n most commonly occurring objects of type T. If the Counter is empty, this method should return a vector of size 0.

        T LeastCommon(); //get the least commonly occurring object of type T (the object with the highest count) If the Counter is empty, this method should throw a domain error
        std::vector<T> LeastCommon(int n); //get the n least commonly occurring objects of type T get the n most commonly occurring objects of type T. If the Counter is empty, this method should return a vector of size 0.

        std::map<T, double> Normalized(); //access normalized weights for all objects of type T seen so far
        
        std::set<T> Keys(); //access the set of all keys in the Counter
        std::vector<int> Values(); //access the collection of all values in the Counter
        
        template <class U>
        friend std::ostream& operator<<(std::ostream& os, const Counter<U> &b); //overload the << operator for Counter<T>
    private:
        std::map<T, int> map; //unsigned integer because
};

//initialize an empty Counter <T>
template <class T>
Counter<T>:: Counter(){ //declares empty map
} 

template <class T>
Counter<T>:: Counter(std::vector<T> vals){   
    typename std::map<T, int>::iterator itr;

    for(int i = 0; i < vals.size(); i++){
        itr = map.find(vals[i]);
        if(itr != map.end()){ //if the key already exists
            map.at(vals[i])++;
        }
       else{
            map.insert(std::pair<T, int>(vals[i], 1));
        }  
    }
}

template <class T>
int Counter<T>:: Count(){ //counts all elements in the map
    int totalCount = 0;
    typename std::map<T, int>::iterator itr; 
    for(itr = map.begin(); itr != map.end(); ++itr){  
        totalCount += itr->second; //itr->second holds the count of the element
    }
    return totalCount;
}

template<class T>
int Counter<T>:: Count(const T key) // access the count associated with any object T, even for values of T that have not been counted
{
    typename std::map<T, int>::iterator itr;
    itr = map.find(key); 
    return itr->second;
} 

template<class T>
int Counter<T>:: Count(const T min, const T max){
    int totalCount = 0;
    T temp;
    typename std::map<T, int>::iterator itr;
    for(itr = map.begin(); itr != map.end(); ++itr){  
        temp = itr->first;
        if(temp >= min && temp < max){
            totalCount += itr->second; //itr->second holds the count of the element
        }
    }
    return totalCount;  
}

template <class T>
void Counter<T>:: Remove(T key){
    if(!map.empty()){
        map.erase(key);
    }
}

template <class T>
void Counter<T>:: Increment(T key){
    //access the counts
    typename std::map<T, int>::iterator it;
    it = map.find(key);
    //if(it != map.end()){
        it->second++;
    //}
}

template <typename T>
void Counter<T>:: Increment(T key, int n){
    typename std::map<T, int>::iterator it;
    it = map.find(key);
    //if(it != map.end()){
        it->second += n;
    //}
}

template <typename T>
void Counter<T>:: Decrement(T key){
    typename std::map<T, int>::iterator it;
    it = map.find(key);
    //int temp = it->second;
    //if(temp > 0){ //we don't want to decrement into negative values
        it->second--;
    //}  
}

template <typename T>
void Counter<T>:: Decrement(T key, int n){
    typename std::map<T, int>::iterator it;
    it = map.find(key);
    //if(it != map.end()){
        it->second -= n;
    //}
}

template <typename T>
T Counter<T>:: MostCommon()
{
    if(map.size() == 0){
        throw std::invalid_argument( "The counter class is empty" );
    }
    T temp;
    typename std::map<T, int>::iterator itr;
    typename std::map<T, int>::iterator maxVal;
    maxVal = map.begin();

    for(itr = map.begin(); itr != map.end(); ++itr){  
        temp = itr->second;
        if(temp > maxVal->second){
            maxVal = itr;
        }
    }
    T val = maxVal->first;
    return val;
} //get the most commonly occurring object of type T (the object with the highest count) If the Counter is empty, this method should throw a domain error

template <typename T>
std::vector<T> Counter<T>:: MostCommon(int n) //get the n most commonly occurring objects of type T. If the Counter is empty, this method should return a vector of size 0.
{
    std::vector<T> vec;
    std::vector<std::pair<int, T>> sorted_list;
    typename std::map<T, int>::iterator itr;
    itr=map.begin();

    
    // sort(sorted_list.begin(), sorted_list.end(), std::greater<int>()); //then we sort the counts in descending order

    // while(sorted_list.size() != n){ //taking out all counts that aren't in top n counts
    //     sorted_list.pop_back();
    // }
    return vec;
}

template <typename T>
T Counter<T>:: LeastCommon(){
      if(map.size() == 0){
        throw std::invalid_argument( "The counter class is empty" );
    }
    T temp;
    typename std::map<T, int>::iterator itr;
    typename std::map<T, int>::iterator minVal;
    minVal = map.begin();

    for(itr = map.begin(); itr != map.end(); ++itr){  
        temp = itr->second;
        if(temp < minVal->second){
            minVal = itr;
        }
    }
    return minVal->first;
}

template <typename T>
std::vector<T> Counter<T>:: LeastCommon(int n)
{
    std::vector<T> temp;
    return temp;
}

template <typename T> //empty map, and then go through and do inserts 
std::map<T, double> Counter<T>:: Normalized(){
    std::map<T, double> normalized_map=std::map<T, double>();
    typename std::map<T, int>::iterator itr;
    typename std::map<T, double>::iterator it;

    for(itr = map.begin(); itr != map.end(); itr++){
        normalized_map.insert(std::pair<T, double>(itr->first, itr->second));
    }
    int total;
    total = this->Count();
    for(it = normalized_map.begin(); it != normalized_map.end(); ++it){  
            it->second = it->second/total;
    }
    // for(it = normalized_map.begin(); it != normalized_map.end(); ++it){  
    //         std::cout << it->first <<  " : " << it->second << ", "; 
    // }
    // std::cout << std::endl;
    return normalized_map;
}    

template <typename T>
std::set<T> Counter<T>:: Keys(){
    std::set<T> temp;

    return temp;
}

template <typename T>
std::vector<int> Counter<T>:: Values(){
    std::vector<int> vec;
    return vec;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Counter<T> &n) { 
    //typename std::map<U, unsigned int>::iterator itr = n.map.begin();
    os << "{";
    int index = 0;
    for(auto itr = n.map.begin(); itr != n.map.end(); ++itr)
    { 
        if(index == n.map.size() - 1){
            os << itr->first <<  ": " << itr->second; 
        }
        else{
            os << itr->first <<  ": " << itr->second << ", "; 
        }
        index++;
    }
        os << "}" << std::endl;
    return os; 
}


//std::sort 
//make a new data structure
// template <typename T>
// std::vector<T> Counter<T>:: MostCommon(int n) //get the n most commonly occurring objects of type T. If the Counter is empty, this method should return a vector of size 0.
// {
//     std::vector<T> vec;
//     if(map.size() == 0){ //if counter is empty than we shall return a vector of size zero
//         return vec;
//     }
//     typename std::map<T, unsigned int>map2;
//     map2 = map;
//     typename std::map<T, unsigned int>::iterator itr, maxItr;
//     maxItr = map2.begin();
//     for(itr = map2.begin(); itr != map2.end(); ++itr){  //first we store all elements of map into a vector
//         if(itr->second > maxItr->second){
//             maxItr = itr;
//             vec.push_back(maxItr->first); 
//             map2.erase(maxItr);
//         }
          
//     }

//     std::vector<T> vec2;
//     for(int i = 0; i < vec.size(); i++){
//        itr = map.find(vec[i]);
//         vec2.push_back(itr->first);
//     }
//     std::cout << "Final vector" << std::endl;
//     for(int i = 0; i < vec.size(); i++){
//         std::cout << vec2[i] << std::endl;
//     }
//     return vec;
// }