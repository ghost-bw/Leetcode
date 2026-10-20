-- # Write your MySQL query statement below
-- SELECT 
--     DATE_FORMAT(trans_date, '%Y-%m') AS month,
--     country,
--     COUNT(*) AS trans_count,
--     SUM(state = 'approved') AS approved_count,
--     SUM(amount) AS trans_total_amount,
--     SUM(IF(state = 'approved', amount, 0)) AS approved_total_amount
-- FROM Transactions
-- GROUP BY 
--     DATE_FORMAT(trans_date, '%Y-%m'),
--     country;









select date_format(trans_date,'%Y-%m') as month,country,
count(*) as trans_count,sum(case
    when state='approved' then 1
    else 0 end) as approved_count ,sum(amount) as trans_total_amount ,
    sum(case
        when state='approved' then amount
        else 0 end) as approved_total_amount 
from Transactions
group by country,month