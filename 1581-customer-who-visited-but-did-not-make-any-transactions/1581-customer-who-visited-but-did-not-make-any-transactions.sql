select v.customer_id , count(*) as count_no_trans 
from Visits v left join transactions t on v.visit_id =t.visit_id 
where t.transaction_id  is null GROUP BY v.customer_id;;