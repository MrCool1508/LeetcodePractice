/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-11-03 12:00:20
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */

double average(int* salary, int salarySize) {
    double res = 0;

    int minSalary = salary[0];
    int maxSalary = salary[0];

    for (int i = 0; i < salarySize; i++) {
        res += salary[i];
        minSalary = (minSalary > salary[i]) ? salary[i] : minSalary;
        maxSalary = (maxSalary < salary[i]) ? salary[i] : maxSalary;
    }
    res = res - minSalary - maxSalary;
    res /= (salarySize - 2);

    return res;
}
