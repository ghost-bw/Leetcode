# Write your MySQL query statement below
select e.employee_id from Employees e
left join Employees f on e.manager_id=f.employee_id
where f.employee_id is null and e.salary<30000 and e.manager_id is not null
order by employee_id ;