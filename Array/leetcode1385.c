/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-26 23:52:34
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d) {
    int res  = 0;
    int flag = 0;
    for (int i = 0; i < arr1Size; i++) {
        for (int j = 0; j < arr2Size; j++) {
            flag = (abs(arr1[i] - arr2[j]) > d) ? 1 : 0;
            if (flag == 0) {
                break;
            }
        }
        if (flag) {
            res++;
            flag = 0;
        }
    }
    return res;
}
