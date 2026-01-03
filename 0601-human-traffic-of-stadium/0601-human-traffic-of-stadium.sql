# Write your MySQL query statement below
with t as (select id , visit_date, people , id - ROW_NUMBER() OVER (ORDER BY id) as grp from Stadium where people>=100) 

select id,visit_date,people from t where grp in (select grp from t group by grp having count(*)>=3)order by visit_date;