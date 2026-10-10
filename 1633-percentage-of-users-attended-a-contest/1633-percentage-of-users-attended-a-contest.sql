# Write your MySQL query statement below
select r.contest_id,ROUND(COUNT(r.user_id) * 100.0 / (SELECT COUNT(*) FROM Users), 2) as percentage
from Users u
join Register r on u.user_id=r.user_id
group by r.contest_id
order by percentage DESC, r.contest_id ASC;