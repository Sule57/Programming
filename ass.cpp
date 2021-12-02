#include <iostream>

using namespace std;

class Vector {
    private:
        int vectorDimension;
        float* data;
    public:
        Vector(int dimension = 2, float initial = 0){
            vectorDimension = dimension;
            data = new float[dimension];
            for (int i = 0; i < vectorDimension; i++) {
                data[i] = initial;
            }
        }

        ~Vector() {
            delete data;
            cout <<endl << "Memory cleaned!" << endl;
        }

        void setValue(float value, int index) {
            data[index]=value;
        }
        float getValue (int index) {
            return data[index];
        }
        float& operator[] (int index) const {
            if (index >= vectorDimension) {
                cout << "Error, index too massive!";
                }
            return data[index];
        }
        Vector(const Vector &copyConstruct) {
            vectorDimension = copyConstruct.vectorDimension;
            data = new float[vectorDimension];
            for (int i = 0; i<vectorDimension; i++) {
                data[i] = copyConstruct.data[i];
            }
        }
        Vector& operator=(const Vector& replace) {
            vectorDimension = replace.vectorDimension;
            for (int i = 0; i < vectorDimension; i++) {
                data[i] = replace.data[i];
            }
            return *this;
        }
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



int main() {
    Vector v1(2,1);
    Vector v2(3,5);
    Vector v3;
    cout<< v1[0]<<endl;
    v1=v2;
    v1[2] = 3;
    cout << v3;
}