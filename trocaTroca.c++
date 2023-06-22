#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main(int argc, char const *argv[]) {
    
    cout << "Hello" << endl;

    vector<int> numeros(20);

    for (int i = 0; i < numeros.size(); i++) {
        numeros[i] = i * 3;
    }
    for (int i = 0; i < numeros.size(); i++) {
        cout << numeros[i] << endl;
    }
    
    cout << numeros[3] << endl;
    
    return 0;
}
