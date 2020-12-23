/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-12-23 19:28:48
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
typedef struct {
} OrderedStream;

OrderedStream* orderedStreamCreate(int n) {
}

char** orderedStreamInsert(OrderedStream* obj, int id, char* value, int* retSize) {
}

void orderedStreamFree(OrderedStream* obj) {
}

/**
 * Your OrderedStream struct will be instantiated and called as such:
 * OrderedStream* obj = orderedStreamCreate(n);
 * char ** param_1 = orderedStreamInsert(obj, id, value, retSize);

 * orderedStreamFree(obj);
*/
