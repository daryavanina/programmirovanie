#include <iostream>
int main()
{
    int t=1;//количество наборов
    std::cin>>t;
    int n,x,count=0;//раунды,колво контестов
    int m[201];//массив занятых мест
    int vs=-1;//индекс 0, который больше x
    /*for(int i=0;i<=200;i++){//заполнение массива
        m[i]=0;
    }*/
    for(int j=0;j<t;j++){
        count=0;
        std::cin>>n>>x;
        int a[n];
        for(int i=0;i<=200;i++){//заполнение массива
        m[i]=0;
    }
        for(int i=0;i<n;i++){
            std::cin>>a[i];//ввод занятых мест
            m[a[i]-1]=1;
        }
        for(int i=0;i<=200;i++){
            if(m[i]==0){
                count+=1;//подсчёт количества 0 в m
            }
            if(count==x){
                vs=i+1;//индекс 0, который по счёту x
            }
            //std:: cout<<m[i]<<" ";
            }
        if(count>=x){
            std::cout<<vs<<"\n";
        }
        else{
            std::cout<<n<<"\n";
        }
        //n*x колво 0 которые можно занять
        //нужно найти 0, который по счёту = x
        //ответ: индекс 0, который по счёту x
        //std::cout<<"\nnull - "<<count<<"\n";
        //std::cout<<"answer - "<<vs;
    }
    return 0;
}
