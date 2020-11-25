/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-13 14:23:03
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */

#ifndef _LINEARLIST_H_
#define _LINEARLIST_H_
#include <stdbool.h>
/*
success:成功
fail：失败
fatal：内存分配错误失败
range_error：连续空间访问越界
*/
enum Status { success, fail, fatal, range_error };
//线性表的基本操作——初始化与销毁
Status List_Init(SqListPtr L);
void   List_Destory(SqListPtr L);
void   List_Clear(SqListPtr L);
//线性表的基本操作——引用型
bool   List_Empty(SqListPtr L);                                //是否为空
int    List_Size(SqListPtr L);                                 //求线性表的元素个数/长度
Status List_Retrival(SqListPtr L, int pos, ElemType *elem);    //从线性表pos的位置取出数据放入*elem指针
Status List_Locate(SqListPtr L, ElemType elem, int *pos);      //从线性表定位elem的值并返回pos的位置
Status List_Prior(SqListPtr L, int pos, ElemType *elem);       //在线性表L中找到pos元素的直接前驱
Status List_Next(SqListPtr L, int pos, ElemType *elem);        //在线性表L中找到pos元素的直接后驱
//线性表的基本操作——加工型
Status List_Insert(SqListPtr L, int pos, ElemType elem);    //在线性表pos的位置插入elem元素
Status List_Delete(SqListPtr L, int pos);                   //在线性表L中，删除pos位置的元素
Status List_Add(SqListPtr L, int pos, int val);             //在线性表L中，pos的元素增加val
//线性表的基本操作测试函数
// Test_CreateList( );           //基本操作：List_Init\List_Insert\List_Print
// Test_ClearList( );            //基本操作：Test_CreateList\List_Print\List_Empty\List_Clear\List_Print
// Test_RetrivalPriorNext( );    //基本操作：Test_CreateList\List_Print\List_Retrival\List_Prior\List_Next
// Test_Locate( );               //基本操作：Test_CreateList\List_Print\List_Locate
// Test_Length( );               //基本操作：Test_CreateList\List_Print\List_size
#endif
