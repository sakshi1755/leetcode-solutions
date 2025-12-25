# Write your MySQL query statement below
select p.firstName, p.LastName, a.city,a.state FROM Person as p LEFT JOIN Address as a ON p.personId=a.PersonId;