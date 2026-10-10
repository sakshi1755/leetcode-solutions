# Write your MySQL query statement below
select case
when (id=(select count(*) from Seat) and id%2=1) then id
when id%2=0 then id-1
when id%2=1 then id+1
end as id, student from Seat order by id;