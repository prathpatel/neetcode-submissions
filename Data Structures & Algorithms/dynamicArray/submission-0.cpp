class DynamicArray {
private:
    int capacity;
    int length;
    int* arr;

public:
    DynamicArray(int capacity) {
        this->capacity = capacity;
        this->length = 0;
        this->arr = new int[capacity];
    }

    int get(int i) {
        if(i < length) {
            return arr[i];
        }
        return -1;
    }

    void set(int i, int n) {
        if(i < length) {
            arr[i] = n;
        }
    }

    void pushback(int n) {
        if(length==capacity) {
            resize();
        }
        arr[length++] = n;
    }

    int popback() {
        if (length > 0) {
            length--;
        }
        return arr[length];
    }

    void resize() {
        capacity = 2 * capacity;
        int *newArr = new int[capacity];
        for(int i=0; i<length; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

    int getSize() {
        return length;
    }

    int getCapacity() {
        return capacity;
    }
};
