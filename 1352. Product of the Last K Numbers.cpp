class ProductOfNumbers {
private:
    int arr[40000];
    int size;

public:
    ProductOfNumbers() {
        size = 0;
    }

    void add(int num) {
        arr[size] = num;
        size++;
    }

    int getProduct(int k) {
        int product = 1;

        for (int i = size - k; i < size; i++) {
            product = product * arr[i];
        }

        return product;
    }
};
