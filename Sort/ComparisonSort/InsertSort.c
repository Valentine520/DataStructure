//
// Created by 龙舌兰 on 2021/10/19.
//

//
// Created by 龙舌兰 on 2021/10/18.
//

//The detail implementation of insertsort

void InsertSort(int *array,int size){
    //从1开始 默认第0号元素已经在其中
    //查找其插入的位置
    for(int i=1;i<size;i++){
        int temp=array[i];
        int flag=0;
        for(int j=i-1;j>=0;j--){
            if(temp<array[j]){
                array[j+1]=array[j];//移动数组元素
            }
            else{
                array[j+1]=temp;
                flag=1;
                break;
            }
        }
        if(flag==0){
            array[0]=temp;//表明需要插在头部
        }
    }
}
