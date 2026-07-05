class DynamicArray {
private:
    int* arr;
    int size;
    int capacity;

public:

    DynamicArray(int capacity) {
        this->capacity = capacity;
        size = 0;
        arr = new int[capacity];
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if(size == capacity){
            resize();
        }

        arr[size] = n;
        size++;
    }

    int popback() {
        int val = arr[size - 1];
        size --;
        return val;
    }

    void resize() {
        capacity *= 2;

        int* newArr = new int[capacity];

        for(int i = 0; i < size ; i++){
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};