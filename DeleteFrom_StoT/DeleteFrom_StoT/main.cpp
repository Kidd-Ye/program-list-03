//
//  main.cpp
//  DeleteFrom_StoT
//
//  Created by kidd on 2018/9/7.
//  Copyright © 2018年 Kidd. All rights reserved.
//从有序顺序表中删除其值在给定值S与T之间的所有数，S<T,如果S或T不合理或者表为空则退出。

#include <iostream>
#define LIST_SIZE 10
typedef struct List{
    int data[LIST_SIZE];
    int length;
} SqList;

void PrintList(SqList list){
    for (int i = 0; i<list.length; i++) {
        printf("%d ", list.data[i]);
    }
    printf("\n");
}

void DeleteFrom_StoT(int s, int t, SqList &list){
    int s_pos = 0, t_pos = 0;
    if (s < t && list.length > 1) {
        for (int i = 0; i < list.length; i++) {
            if (list.data[i] == s) {
                s_pos = i;
            }
        }
        for (int i = list.length-1; i >= 0; i--) {
            if (list.data[i] == t) {
                t_pos = i;
            }
        }
        for (int i = t_pos + 1, j = s_pos; i < list.length; i++, j++) {
            list.data[j] = list.data[i];
        }
        list.length = list.length- (t_pos - s_pos + 1);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    SqList list;
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    for (int i = 0; i < 10; i++) {
        list.data[i] = arr[i];
    }
    list.length = 10;
    PrintList(list);
    
    DeleteFrom_StoT(3, 6, list);
    PrintList(list);
    printf("操作化的表长度为:%d\n", list.length);
    return 0;
}
