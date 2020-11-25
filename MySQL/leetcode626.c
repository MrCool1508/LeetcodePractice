/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-31 13:54:58
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
SELECT* FROM seat;
update seat as a, seat as b set a.student = b.student where a.id = (b.id + 1);
