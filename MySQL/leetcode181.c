/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-10-20 15:32:13
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
#Write your MySQL query statement below
--方法一-- SELECT a.Name AS Employee-- FROM-- Employee AS a, --Employee AS b-- WHERE a.ManagerId = b.Id-- AND a.Salary > b.Salary;
--方法二 select a.Name as Employee from employee a where salary > (select salary from employee where Id = a.ManagerId);
