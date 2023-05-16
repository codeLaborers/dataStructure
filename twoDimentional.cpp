// template<class T>
// void make2dArray(T ** &x, int numberOfRows, int numberOfColumns){
//     x = new T * [numberOfRows];
//     for(int i = 0; i < numberOfRows; ++i){
//         x[i] = new T [numberOfColumns];
//     }
// }

// template<class T>
// void delete2dArray(T ** &x, int numberOfRows){
//     for(int i = 0; i < numberOfRows; ++i){
//         delete [] x[i];
//     }
//     delete [] x;
//     x = NULL;
// }



template<class T>
void make2dArray(T ** &x, int numberOfRows, int numberOfColumns){
    x = new T * [numberOfRows];
    for(int i = 0; i < numberOfRows; ++i){
        x[i] = new T [numberOfColumns];
    }
}

template<class T>
void delete2dArray(T ** &x, int numberOfRows){
    for(int i = 0; i < numberOfRows; ++i){
        delete [] x[i];
    }
    delete [] x;
    x = NULL;
}



















