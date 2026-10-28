-- SELECT 
--     c.category,
--     COALESCE(t.accounts_count, 0) AS accounts_count
-- FROM (
--     SELECT 'Low Salary' AS category
--     UNION ALL
--     SELECT 'Average Salary'
--     UNION ALL
--     SELECT 'High Salary'
-- ) c
-- LEFT JOIN (
--     SELECT 
--         CASE
--             WHEN income < 20000 THEN 'Low Salary'
--             WHEN income <= 50000 THEN 'Average Salary'
--             ELSE 'High Salary'
--         END AS category,
--         COUNT(*) AS accounts_count
--     FROM Accounts
--     GROUP BY category
-- ) t
-- ON c.category = t.category;
SELECT 'Low Salary' AS category,
       SUM(CASE WHEN income < 20000 THEN 1 ELSE 0 END) AS accounts_count
FROM Accounts

UNION ALL

SELECT 'Average Salary',
       SUM(CASE WHEN income BETWEEN 20000 AND 50000 THEN 1 ELSE 0 END)
FROM Accounts

UNION ALL

SELECT 'High Salary',
       SUM(CASE WHEN income > 50000 THEN 1 ELSE 0 END)
FROM Accounts;