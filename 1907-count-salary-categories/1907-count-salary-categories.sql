# Write your MySQL query statement below
with m as (select category,count(*) as accounts_count from (select account_id, case when income<20000 then "Low Salary" when income>50000 then "High Salary" else "Average Salary" end as category from Accounts)as t group by category) 

select "Low Salary" as category, coalesce((select accounts_count from m where category='Low Salary'),0) as accounts_count
union
select "Average Salary" as category, coalesce((select accounts_count from m where category='Average Salary'),0) as accounts_count
union
select "High Salary" as category, coalesce((select accounts_count from m where category='High Salary'),0) as accounts_count
