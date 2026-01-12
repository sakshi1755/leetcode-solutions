# Write your MySQL query statement below
select(select distinct salary from employee order by salary DESC LIMIT 1 OFFSET 1) as SecondHighestSalary ;