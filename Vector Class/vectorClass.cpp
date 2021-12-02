#include <iostream>

using namespace std;
/**
 * @brief a class Vector containing a dynamically allocated array and operator overloads necessary for it to function cleanly
 * 
 */
class Vector {
    private:
        /**
         * @brief Declaring the necessary variable and array
         */
        int vectorDimension;
        float* data;
    public:
        /**
         * @brief Construct a new Vector object
         * 
         * @param dimension sets the dimension of the array, in case it is left empty it will be set by default to 2
         * @param initial sets the initialisation value, inc ase it is left empty it will be set by default to 0
         */
        Vector(int dimension = 2, float initial = 0){
            vectorDimension = dimension;
            data = new float[dimension];
            for (int i = 0; i < vectorDimension; i++) {
                data[i] = initial;
            }
        }
        /**
         * @brief Destroy the Vector object to clean memory after the program has finished running
         */
        ~Vector() {
            delete data;
        }
        /**
         * @brief Set the value at a certain index (unnecessary after overloading the operators, but the assignment says it has to be here so...)
         * 
         * @param value The value being set
         * @param index The index to which the value is being set
         */
        void setValue(float value, int index) {
            data[index]=value;
        }
        /**
         * @brief Get the value at a certain index
         * 
         * @param index the index from which we want to get the value
         * @return the value at given index
         */
        float getValue (int index) {
            return data[index];
        }

        /**
         * @brief Overloads the [] operator to access the values at a certain index ex. v1[3], gives the value at index 3 of the object v1
         * 
         * @param index The given index from which we are taking/setting the value
         * @return Value at the given index
         */
        float& operator[] (int index) const {
            if (index >= vectorDimension) {
                cout << "Error, index too massive!";
                }
            return data[index];
        }
        /**
         * @brief Construct a new copy vector, used to copy from one vector to another
         * 
         * @param copyConstruct the new vector used to copy from one to another vector
         */
        Vector(const Vector &copyConstruct) {
            vectorDimension = copyConstruct.vectorDimension;
            data = new float[vectorDimension];
            for (int i = 0; i<vectorDimension; i++) {
                data[i] = copyConstruct.data[i];
            }
        }
        /**
         * @brief Overloading the "=" operator to use the copy constructor
         * 
         * @param replace replaces one vector with the given one (ex. v1 = v2, will copy the size and info from v2 into v1)
         * @return Returns the newly copied vector
         */
        Vector& operator=(const Vector& replace) {
            vectorDimension = replace.vectorDimension;
            for (int i = 0; i < vectorDimension; i++) {
                data[i] = replace.data[i];
            }
            return *this;
        }
        /**
         * @brief Overloads the operator "<<" so there's a certain syntax when printing Vector objects.
         * 
         * @param print The name used for ostream (yes I stole it from python)
         * @param v1 The reference to the vector being printed
         * @return everything we have written into print
         */
        friend ostream& operator<<(ostream& print, const Vector& v1) {
            print << "(";
            for (int i = 0; i < v1.vectorDimension; i++) {
                if (i != (v1.vectorDimension-1)) {
                    print << v1.data[i] << ", ";
                }
                else {
                    print << v1.data[i] << ")";
                }
            }
            return print;
        }

};

//TESTING ENVIRONMENT//

int main() {
    Vector v1(2,1);
    Vector v2(3,5);
    Vector v3;
    cout << v1 << endl;
    v1 = v2;
    cout << v1 << endl << v2 << endl << v3 << endl;
}