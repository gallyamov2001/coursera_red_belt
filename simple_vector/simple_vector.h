#pragma once

#include <cstdlib>
#include <algorithm>

using namespace std;

template <typename T>
class SimpleVector {
public:
    SimpleVector(){
        data = nullptr;
        end_ = data;
        size_is = 0;
        capa_is = 0;
    }
    explicit SimpleVector(size_t size){
        end_ = data + size;
        size_is = size;
        capa_is = size_is;
        data = new T[capa_is];
        end_ = data + size_is;

    }
    ~SimpleVector(){
        if (data != nullptr) {
            delete[] data;
        }
        capa_is = 0;
        size_is = 0;
    }

    T& operator[](size_t index){
        return data[index];
    }

    T* begin() { return data; }
    T* end() { return end_; }

    const T* begin() const { return data; }
    const T* end() const { return end_; }

    size_t Size() const{
        return size_is;
    }
    size_t Capacity() const{
        return capa_is;
    }
    void PushBack(const T& value){
        if (Size() >= Capacity()) {
            if(capa_is != 0) {
                capa_is *= 2;
            }
            else {
                capa_is = 1;
            }

            T* ptr = new T[capa_is];

            for(size_t i=0; i < size_is ; i++) {
                ptr[i]=data[i];
            }
            delete[] data;
            data = ptr;
            data[size_is++] = value;
            end_ = data + size_is;
        }
        else {
            data[size_is++] = value;
            end_ = data + size_is;
        }
    }

private:
    T* data;
    T* end_;
    size_t size_is;
    size_t capa_is;
};
