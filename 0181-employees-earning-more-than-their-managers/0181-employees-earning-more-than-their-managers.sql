# Write your MySQL query statement below

select e.name as Employee from Employee as e INNER JOIN Employee as e2 ON e.managerId=e2.id Where e.salary>e2.salary ;


