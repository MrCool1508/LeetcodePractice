/*
 * @file: 文件名
 * @author: hzy
 * @version: V1.0.0
 * @date: 2020-11-02 17:22:25
 * @brief: 模块目的、功能
 * @History:
 * <author><date><version><brief>
 */
#Write your MySQL query statement             below
SELECT Name AS Customers FROM Customers WHERE Customers.Id NOT IN(SELECT CustomerId FROM Orders);
