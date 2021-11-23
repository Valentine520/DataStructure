////
//// Created by 龙舌兰 on 2021/9/24.
////
//
//#include <stdio.h>
//#include <stdlib.h>
//void Hanoi(int n,char x, char y,char z);//轴心的变化
//int main(void){
//    Hanoi(3,'x','y','z');
//    return 0;
//}
//void Hanoi(int n,char x,char y,char z){
//    static int num1=0;
//    num1++;
//    int num2=0;
//    num2++;
////    printf("num1:%d num2:%d\n",num1,num2);
//    if(n==1){
//        printf("%c to %c\n",x,z);
//    }
//    else{
//        //把n-1 借助 z 移到 y
//        Hanoi(n-1,x,z,y);
//        //把n 直接移到 z
//        printf("%c to %c\n",x,z);//从当前主塔直接移动到目标塔
//        //把n-1从y移到z上 借助x
//        Hanoi(n-1,y,x,z);
//    }
//}
//
