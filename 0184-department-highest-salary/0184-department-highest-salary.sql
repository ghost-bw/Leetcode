# Write your MySQL query statement below
-- select d.name as Department,e.name as Employee,e.salary as Salary from Employee e
-- join Department d on e.departmentId =d.id
-- where salary=(
--     select max(e2.salary) from Employee e2
--     where e2.departmentId=e.departmentId
-- );
select Department,Employee,Salary from (
    select d.name as Department,e.name as Employee,e.salary 
    ,dense_rank() over(partition by d.name order by salary desc ) as rnk from Employee e
    join Department d on e.departmentId =d.id ) as temp
where rnk=1;