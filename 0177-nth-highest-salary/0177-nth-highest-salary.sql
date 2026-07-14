CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      SELECT 
      CASE
              WHEN COUNT(*) = N THEN MIN(salary)
              ELSE NULL
          END from (
        select distinct salary from Employee order by salary desc limit N
      )as temp
  );
END