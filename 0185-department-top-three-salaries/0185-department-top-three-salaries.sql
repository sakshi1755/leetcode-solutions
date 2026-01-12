WITH t AS (
    SELECT d.name AS Department, e.name AS Employee, e.salary AS Salary
    FROM Employee e
    JOIN Department d ON e.departmentId = d.id
)
SELECT Department, Employee, Salary
FROM t
WHERE (
    SELECT COUNT(DISTINCT t2.Salary)
    FROM t AS t2
    WHERE t2.Department = t.Department
      AND t2.Salary > t.Salary
) < 3;
