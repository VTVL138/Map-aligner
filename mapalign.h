#ifndef MAPALIGN
#define MAPALIGN


#include <vector>
#include <map>
#include <set>

#include <typeinfo>


template <typename T1, typename T2,typename My_Compare = std::less<T1> >
class map_aligner{


public:


void add(std::map<T1,T2,My_Compare> &m){
    data.push_back(&m);
}

map_aligner& operator+=( std::map<T1,T2,My_Compare> &m){//?????

    data.push_back(&m);
    return *this;
}

//////////////////////////////////////////////////////

 

void align(){
    
    std::set<T1> unique_keys;
    for(unsigned int i=0; i<data.size();i++){
        for (typename std::map<T1, T2>::iterator it = data[i]->begin(); it != data[i]->end(); it++ ){ // typename to decide if its a type or a value
            unique_keys.insert(it->first);
        }
    }

    std::vector<T1> unique_keys_vec;

    //for (const auto &it: unique_keys) {
    for (typename std::set<T1>::const_iterator it = unique_keys.begin(); it != unique_keys.end(); ++it) {
        unique_keys_vec.push_back(*it);
    }

 

    //[] operator does the thing
    for(unsigned int i=0; i<data.size(); i++){
        for(unsigned int j=0;j<unique_keys_vec.size();j++){
            (*data[i])[unique_keys_vec[j]];
            }
        }
    }


void set_filler(int max){
    
    std::set<T1> unique_keys;
    for(unsigned int i=0; i<data.size();i++){
        for (typename std::map<T1, T2>::iterator it = data[i]->begin(); it != data[i]->end(); it++ ){
            unique_keys.insert(it->first);
        }
    }
    
    std::vector<T1> unique_keys_vec;

//    for (const auto &it: unique_keys) {
     for (typename std::set<T1>::const_iterator it = unique_keys.begin(); it != unique_keys.end(); ++it) {
        unique_keys_vec.push_back(*it);
    }



    //[] operator does the thing, set the default constructed value of type
    for(unsigned int i=0; i<data.size(); i++){
        for(unsigned int j=0;j<unique_keys_vec.size();j++){
            (*data[i])[unique_keys_vec[j]]=max;
            }
        }
    }

 

void erase(T1 parameter_key){
//    if (!std::is_same<T1,T2>::value){
    if (typeid(T1)!=typeid(T2)){
		std::cout<<"alma\n" ;
    	for(unsigned int i=0; i<data.size();i++){
            (*data[i]).erase (parameter_key);  
        }
    }else{
        for(unsigned int i=0; i<data.size();i++){
            (*data[i]).erase (parameter_key);  
        }
        for(unsigned int i=0; i<data.size();i++){
            for (typename std::map<T1, T2>::iterator it = data[i]->begin(); it != data[i]->end(); it++ ){
                if (it->second == parameter_key){
                    (*data[i]).erase (it->first);
                }
            }
        }
        
        }
    }

int count(){
    int counter = 0;
    std::set<T1> unique_keys;
    for(unsigned int i=0; i<data.size();i++){
        for (typename std::map<T1, T2>::iterator it = data[i]->begin(); it != data[i]->end(); it++ ){
            unique_keys.insert(it->first);
        }
    }
    
    std::vector<T1> unique_keys_vec;    

    for(unsigned int i=0;i<data.size();i++){
        
        if ((*data[i]).size() != unique_keys_vec.size()){
            counter++;
        }
    }
    return counter;
}

private:
std::vector<std::map<T1,T2,My_Compare> *> data;

};
////////////////////////////////////////////////////
////////////////////////////////////////////////////

#endif
