#include <cassert>

#pragma once

#ifndef VECTOR_H
#define VECTOR_H
template<class T>
class VECTOR{

    public:

        VECTOR(int _m){
            arr = new T[_m];
            m = _m;
            n = 0;
            Initialize();
        }

        VECTOR(){
            arr = new T[1];
            m = 1;
            n = 0;
            Initialize();
        }

        void Resize(int _m){
            T* new_arr = new T[_m];

            for(int i = 0; i < _m; ++i) new_arr[i] = i < m ? arr[i] : (T){};

            delete[] arr;
            arr = new_arr;
            m = _m;
        }

        void Append(T _app){
            if(!(n < m-1)) Resize(m * 2);
            

            
            arr[n] = _app;
            n++;
        }

        

        T pop(){
            //std::cout << "pop called" << std::endl;
            assert(n > -1);
            T result = arr[0];
            for(int i = 0; i < n; ++i){
                arr[i] = arr[i+1];
            }
            n--;
            return result;
        }

        bool Empty(){return n <= 0;}

        int Get_Length(){ return n;}

        T& operator[](int b){
            assert(b > -1 && b < m);
            return arr[b];
        }

        friend std::ostream& operator<<(std::ostream& os, VECTOR<T>& obj){
            for(int i = 0; i < obj.Get_Length(); ++i){
                os << "Element " << i << ": " << *obj[i] << std::endl;
            }
            return os;
        }

    private:

        int m; //capacity of array
        int n; //size of array
        T* arr;

        //sets all indices to the 0 equivalent of T
        void Initialize(){ for(int i = 0; i < m; ++i) arr[i] = (T){}; }
};

#endif