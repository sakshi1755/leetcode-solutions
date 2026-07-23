# Write your MySQL query statement below
select name, bonus  from (select e.name as name , b.bonus as bonus from Employee e Left join Bonus b on e.empId=b.empId)t where bonus<1000 or bonus is null