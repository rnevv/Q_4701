#include <iostream>

using std::cout;
using std::endl;
using std::cin;

template <typename T>
class BoundCheckArray{
    private:
        T *arr;
        int arrlen;
    public:
        BoundCheckArray(int len) : arrlen(len){
            arr = new T[len];
        }
        ~BoundCheckArray(){
            delete []arr;
        }
        T& operator[](int idx){
            if(idx < 0 || idx > arrlen){
                cout<<"Array index out of bound exception"<<endl;
                exit(1);
            }

            return arr[idx];
        }
        T operator[](int idx) const{
            if(idx < 0 || idx > arrlen){
                cout<<"Array index out of bound exception"<<endl;
                exit(1);
            }

            return arr[idx];
        }
        int GetArrLen() const{
            return arrlen;
        }
};

class DataManagement{
    private:
        int temp_sum;
        int data1, data2;
        BoundCheckArray<int> *p_arr;   
    public:
        DataManagement(BoundCheckArray<int> *arr_address) : p_arr(arr_address), temp_sum(2147483647), data1(0), data2(0){
            //empty
        }
        void InitIntrray(){
            for(int i = 0; i < p_arr->GetArrLen(); i++){
                cin>>(*p_arr)[i];
            }
        }
        void Calculation(){
            for(int i = 0; i < p_arr->GetArrLen() - 1; i++){
                for(int n = i + 1; n < p_arr->GetArrLen(); n++){
                    int temp = (*p_arr)[i] + (*p_arr)[n];
                    if (temp < 0 && temp * (-1) < temp_sum){
                        temp_sum = temp;
                        data1 = (*p_arr)[i];
                        data2 = (*p_arr)[n];
                    }else if(temp >= 0 && temp < temp_sum){
                        temp_sum = temp;
                        data1 = (*p_arr)[i];
                        data2 = (*p_arr)[n];
                    }
                }
            }
            if(data1 > data2){
                Swap(&data1, &data2);
            }    
        }   
        void Swap(int *a, int * b){
            int temp;
            temp = *a;
            *a = *b;
            *b = temp;
        }
        void ShowData() const{
            cout<<data1<<' '<<data2<<endl;
        }
};

int main(void){
    int solution_num;
    cin>>solution_num;

    BoundCheckArray<int> solution(solution_num);
    DataManagement managedata(&solution);

    managedata.InitIntrray();
    managedata.Calculation();
    managedata.ShowData();
    return 0;
}