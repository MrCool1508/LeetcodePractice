/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-13 14:22:51
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
#include <linearList.h>
//线性表的基本操作——初始化与销毁
Status List_Init(SqListPtr L) {
}
void List_Destory(SqListPtr L) {
}
void List_Clear(SqListPtr L) {
}
//线性表的基本操作——引用型
bool List_Empty(SqListPtr L) {
}    //是否为空
int List_Size(SqListPtr L) {
}    //求线性表的元素个数/长度
Status List_Retrival(SqListPtr L, int pos, ElemType *elem) {
}    //从线性表pos的位置取出数据放入*elem指针
Status List_Locate(SqListPtr L, ElemType elem, int *pos) {
}    //从线性表定位elem的值并返回pos的位置
Status List_Prior(SqListPtr L, int pos, ElemType *elem) {
}    //在线性表L中找到pos元素的直接前驱
Status List_Next(SqListPtr L, int pos, ElemType *elem) {
}    //在线性表L中找到pos元素的直接后驱
//线性表的基本操作——加工型
Status List_Insert(SqListPtr L, int pos, ElemType elem) {
}    //在线性表pos的位置插入elem元素
Status List_Delete(SqListPtr L, int pos) {
}    //在线性表L中，删除pos位置的元素
Status List_Add(SqListPtr L, int pos, int val) {
}    //在线性表L中，pos的元素增加val
/* example1：合并线性表
 * 问题：集合A和B分别表示两个线性表，分别用LA、LB表示，求A∪B用线性表LA表示
 * 算法设计：从LB中逐一取出，判断元素是否在LA中，若不在则插入到LA中
 * 细化算法：
 *     -逐一：遍历LB，需要知道LB元素个数（List_Size）
 *     -取出：遍历LB，将pos位置的元素取出（List_Retrival）
 * 算法性能分析：
 *     -设A的长度为m，B的长度为n
 *     -最好：B为A前面部分元素：1+2+...+n=(n+1)*n/2
 *     -最坏：A∩B为空：m+(m+1)+...+(m+n-1)=n*m+(n-1)*n/2
 *     由上，应该选数据元素个数少的表作为B。
 * */

Status ListCombine(SqListPtr A, SqListPtr B) {
    ElemType elemB;                       //用于存放B中取出的元素
    Status   status;                      //代码状态
    int      pos;                         //用于存放单个A∩B的元素位置
    int      B_ListLen = List_Size(B);    //用于存放B的元素个数

    for (int i = 1; i <= B_ListLen; i++) {
        // 1、依次从B中取出第i个元素
        List_Retrival(B, i, &elemB);
        // 2、判断elem是否在A中
        status = List_Locate(A, elemB, &pos);
        // 3、不存在，则将elem插入到LA的第一个位置
        if (status != success) {
            status = List_Insert(A, 1, elemB);
            if (status != success) break;    //插入失败退出
        } else
            List_Add(A, pos, 1);    // A表中的pos所在的数据加1
    }
    return status;
}
