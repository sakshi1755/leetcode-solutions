# Write your MySQL query statement below
select person_name from (select person_name,sum(weight) over(order by turn) as running from Queue )t where running<=1000 order by running desc limit 1 ;