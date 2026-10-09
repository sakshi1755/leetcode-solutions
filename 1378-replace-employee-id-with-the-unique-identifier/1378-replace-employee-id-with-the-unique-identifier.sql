# Write your MySQL query statement below
select u.unique_id, e.name from Employees as e Left join EmployeeUNI u on e.id=u.id;