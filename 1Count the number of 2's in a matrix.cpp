#include <iostream>

int count_num_of_twos(int n, int m, int ** mat) {
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==2){
                count++;
            }
        }
    }
    return count;
}


// Preparation code. Don't modify anything under this line!
int** create_matrix(int n, int m) {
    int **mat;

    mat = new int*[n];
    for(int i=0; i<n; i++) {
        mat[i] = new int[m];
        for(int j=0; j<m; j++) {
            std::cin >> mat[i][j];
        }
    }

    return mat;
}

void decreate_mat(int n, int **mat) {
    for(int i=0; i<n; i++) {
        delete[] mat[i];
    }
    delete[] mat;
}

void print_array(int n, int *arr) {
    std::cout << "[";
    for(int i=0; i<n-1; i++) {
        std::cout << arr[i] << ",";
    }
    std::cout << arr[n-1] << "]";
}

void print_mat(int n, int m, int **mat) {
    std::cout << "[ ";
    for(int i=0; i<n-1; i++) {
        if(i!=0) { std::cout << "  "; }
        print_array(m, mat[i]);
        std::cout << "," << std::endl;
    }
    std::cout << "  ";
    print_array(m, mat[n-1]);
    std::cout << " ]" << std::endl;
}

int main() {
    int n, m;
    int **mat;

    std::cin >> n >> m;
    mat = create_matrix(n, m);

    std::cout << "Original matrix:" << std::endl;
    print_mat(n, m, mat);
    std::cout << std::endl;

    int twos = count_num_of_twos(n, m, mat);

    std::cout << "Total number of twos in matrix: " << twos << std::endl;

    decreate_mat(n, mat);

    return 0;
}
