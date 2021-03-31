/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2021-03-31 22:26:06
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */

select Email from Person group by Email having count(Email) > 1;
