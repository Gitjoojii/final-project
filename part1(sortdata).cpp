#include <iostream>
#include <string>

using namespace std;

class sortDataClass {
    private:
    int *data;      //private data array
    int dataSize, maxNum;   //size of data and maximum number

    public:     //method to randomize the data.
    void randomize() {
        for (int i=0; i<dataSize; i++)
        data[i] = rand() % maxNum;
    }
    //constructor with parameter for array size.
    sortDataClass(int s, string dataset, int m) {
        dataSize = s;
        maxNum = m;
        //create data array with size s.
        data = new int[dataSize];
        if (dataset == "inorder")
            //generate in-order data starting from 0.
            for (int i=0; i<dataSize; i++) data[i] = i;
        else if (dataset == "reverseorder")
            //generate reverse data starting frm maximum.
            for (int i=0; i<dataSize; i++) data[i] = maxNum-i-1;
        else if (dataset =="random")
            //generate random data using module maximum.
            randomize();
        else
            //error
            cout << "Error";
    }

    //method to print the data array.
    void printData() {
        for (int i=0; i<dataSize; i++)
        cout << data[i] << endl;
    }
};

int main() {
    
    int dataSize = 50;
    int maxNum = 100;


    //declare and in-order object and print it.
    cout << "In-order data set."  << endl;
    sortDataClass inorder(dataSize, "inorder", maxNum);
    inorder.printData();
    cout << endl << endl << endl << endl;

    //declare and reverse object and print it.
    cout << "Reverse-order data set." << endl;
    sortDataClass reverse(dataSize, "reverseorder", maxNum);
    reverse.printData();
    cout << endl << endl << endl << endl;

    //declare  and random order object and print it.
    cout << "Random order data set." << endl;
    sortDataClass random(dataSize, "random" , maxNum);
    random.printData();

    return 0;
}