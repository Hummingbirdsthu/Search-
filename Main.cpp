#include "header.h"


void sort(int b) {
    switch (b){
    case 1:
        selection_sort(a,n);
        break;
    case 2:
        insertion_sort(a,n);
        break;
    case 3:
        binary_insertion_sort(a,n);
        break;
    case 4:
        bubble_sort(a, n);
        break;
    case 5:
        shaker_sort(a,n);
        break;
    case 6:
        shell_sort(a,n);
        break;
    case 7:
        heap_sort(a,n);
        break;
    case 8:
        merge_sort(a,0,n-1);
        break;
    case 9:
        quick_sort(a,0,n);
        break;
    case 10:
        counting_sort(a,n);
        break;
    case 11:
        radix_sort(a,n);
        break;
    case 12:
        flash_sort(a,n);
        break;
    default: break;
    }
}


void write_file(double duration, string algorithm, string state, string size, int *a) {
    string filename = algorithm + "_" + state + "_" + size + ".txt";
    ofstream ofs(filename);
    if (!ofs) return 1;
    for (int i = 0; i <n; i++) ofs << a[i] <<' ';
    ofs <<"\n\nAlgorithm: "<<algorithm<<" Sort\n";
    ofs <<"State: "<<state<<endl;
    ofs <<"Size: "<<size<<endl;
    ofs<<"Time: "<<duration;
    ofs.close();
}

int main(){
    int n[5] = {1000, 3000, 10000, 30000, 100000};
    string size[5] = {"1000", "3000", "10000", "30000", "100000"};
    string state[3] = {"Random", "Revrse", "Sorted"};
    string algorithm[12] = {"Selection", "Insertion", "Binary Insertion", "Bubble", "Shaker", "Shell", "Heap", "Merge", "Quick", "Counting", "Radix", "Flash"};

    ofstream csv(filename,std::ios_base::app);
    if (!filename) return 0;
    csv<<"The running time of sorting algorithms\n";
    csv<<"Input State,Input Size"<<algorithm[0]<<","<<algorithm[1]<<","<<algorithm[2]<<","<<algorithm[3]<<","<<algorithm[4]<<","<<algorithm[5]<<","<<algorithm[6]<<","<<algorithm[7]<<","<<algorithm[8]<<","<<algorithm[9]<<","<<algorithm[10]<<","<<algorithm[11]<<endl;
    
    for (int i = 0; i < 3; i++){
        csv<<state[i];
        for (int j = 0; j < 5; j++){
            csv<<","<<n[j];
            //tạo mang có tình trạng state và kích thước size
            int *a = new int[n[j]];
            a = Create_Array(state[i], n[j]);
            for (int z = 0; z < 12; z++) {
                int *b= new int[n[j]];
                for (int k = 0; k < n[j]; k++) b[k] = a[k];

                clock_t start, end;
                double duration;
                start = clock();

                sort(z+1);

                end = clock();
                duration = ((double) (end - start)) / CLOCKS_PER_SEC;
                //lưu kết quả sort xuống file
                write_file(duration, algorithm[z], state[i], size[j], b);
                //lưu kết quả thời gian xuống file
                csv<<","<<duration;
                delete[] b;
            }
            csv<<endl;
            delete[] a;
        }
    }
    csv.close();
}