#include <iostream>
#include <memory>
using namespace std;

unique_ptr<int> createPointer() {
    unique_ptr<int> ptr = make_unique<int>(100);
    cout << "[createPointer] Created value: " << *ptr << endl;
    return std::move(ptr); 
}

void consumePointer(unique_ptr<int> ptr) {
    if (ptr) {
        cout << "[consumePointer] Consumed value: " << *ptr << endl;
    } else {
        cout << "[consumePointer] Received null pointer!" << endl;
    }
}

int main() {
    unique_ptr<int> myPtr = createPointer();
    
    consumePointer(std::move(myPtr));

    //chalange
    cout<<"myptr : "<<*myPtr<<endl;

    return 0;
}
