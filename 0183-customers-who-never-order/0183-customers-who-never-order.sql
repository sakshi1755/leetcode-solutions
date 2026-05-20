# Write your MySQL query statement below
select name  as Customers from (select c.name , o.id  from Customers as c LEFT JOIN Orders as o on c.id=o.customerId  )as I where id is null