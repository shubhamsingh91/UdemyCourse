#ifndef INTARRAY_H
#define INTARRAY_H
#include <cassert>
#include <algorithm> // for std::copy_n
#include <iostream>
#include <initializer_list> // for std::initializer_list
using namespace std;

class IntArray
{
    private:
        int length;
        int *data;
    
    public:
        IntArray() = default;
        IntArray(int l):length{l}{
            assert(length > 0);
            if (length>0)
                data = new int[length]{};
        }
        
        IntArray(const IntArray& a): IntArray(a.getlength()){
            std::copy_n(a.data,length,data);
        }

        IntArray(std::initializer_list<int> list):IntArray(static_cast<int>(list.size())) {
            int cnt{0};
            for (auto element : list) {
                data[cnt] = element;
                cnt++;
            }
            
        }

          ~IntArray()
        {
            delete[] data;
            // we don't need to set m_data to null or m_length to 0 here, since the object will be destroyed immediately after this function anyway
        }

        void erase()
        {
            delete[] data;

            // We need to make sure we set m_data to nullptr here, otherwise it will
            // be left pointing at deallocated memory!
            data = nullptr;
            length = 0;
        }
        int& operator[](const int& i) {
            assert(i>= 0 && i<length);
            return data[i];
        }
        int getlength() const {
            return length;
        }
        
        void reallocate(int newlength) {
            erase();

            if (newlength <= 0)
               return;
            
            data = new int[newlength];
            length = newlength;
        }


        // resize resizes the array.  Any existing elements will be kept.  This function operates slowly.
        void resize(int newLength)
    {
        // if the array is already the right length, we're done
        if (newLength == length)
            return;

        // If we are resizing to an empty array, do that and return
        if (newLength <= 0)
        {
            erase();
            return;
        }

        // Now we can assume newLength is at least 1 element.  This algorithm
        // works as follows: First we are going to allocate a new array.  Then we
        // are going to copy elements from the existing array to the new array.
        // Once that is done, we can destroy the old array, and make m_data
        // point to the new array.

        // First we have to allocate a new array
        int* data1{ new int[newLength] };

        // Then we have to figure out how many elements to copy from the existing
        // array to the new array.  We want to copy as many elements as there are
        // in the smaller of the two arrays.
        if (length > 0)
        {
            int elementsToCopy{ (newLength > length) ? length : newLength };
            std::copy_n(data, elementsToCopy, data1); // copy the elements
        }

        // Now we can delete the old array because we don't need it any more
        delete[] data;

        // And use the new array instead!  Note that this simply makes m_data point
        // to the same address as the new array we dynamically allocated.  Because
        // data was dynamically allocated, it won't be destroyed when it goes out of scope.
        data = data1;
        length = newLength;
    }

        void print(){
            for (int i = 0; i<length; i++){
                std::cout << data[i] << ",";
            }
            std::cout << std::endl;
        }

        IntArray& operator=(const IntArray& a)
        {
            // Self-assignment check
            if (&a == this)
                return *this;

            // Set the size of the new array appropriately
            reallocate(a.getlength());
            std::copy_n(a.data, length, data); // copy the elements

            return *this;
        }

        IntArray& operator=(std::initializer_list<int> list){
            reallocate(list.size());
            
            int cnt{0};
            for (auto element : list) {
                data[cnt] = element;
                cnt++;
            }
            return *this;
        }

        void insertBefore(int value, int index)
        {
            // Sanity check our index value
            assert(index >= 0 && index <= length);

            // First create a new array one element larger than the old array
            int* data1{ new int[length+1] };

            // Copy all of the elements up to the index
            std::copy_n(data, index, data1);

            // Insert our new element into the new array
            data1[index] = value;

            // Copy all of the values after the inserted element
            std::copy_n(data + index, length - index, data1 + index + 1);

            // Finally, delete the old array, and use the new array instead
            delete[] data;
            data = data1;
            ++length;
        }

        void remove(int index)
        {
            // Sanity check our index value
            assert(index >= 0 && index < length);

            // If this is the last remaining element in the array, set the array to empty and bail out
            if (length == 1)
            {
                erase();
                return;
            }

            // First create a new array one element smaller than the old array
            int* data1{ new int[length-1] };

            // Copy all of the elements up to the index
            std::copy_n(data, index, data1);

            // Copy all of the values after the removed element
            std::copy_n(data + index + 1, length - index - 1, data1 + index);

            // Finally, delete the old array, and use the new array instead
            delete[] data;
            data = data1;
            --length;
        }
            // A couple of additional functions just for convenience
        void insertAtBeginning(int value) { insertBefore(value, 0); }
        void insertAtEnd(int value) { insertBefore(value, length); }

};

#endif