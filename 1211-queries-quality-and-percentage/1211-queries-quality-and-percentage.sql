# Write your MySQL query statement below
-- with poor as(
--     select query_name,count(*) as cnt from Queries 
--     where rating<3
--     group by query_name
-- )
-- select query_name,round(avg(rating/position),2) as quality,
-- coalesce(round(((select cnt from poor where poor.query_name=Queries.query_name )/count(*)*100),2),0) as poor_query_percentage 
-- from Queries 
-- group by query_name
with poor as(
    select query_name,count(*) as cnt from Queries
    where rating<3
    group by query_name
)
select query_name,round(sum(rating/position)/count(*),2) as quality,
coalesce(round((select cnt from poor where poor.query_name=Queries.query_name)/count(*)*100,2),0) as
poor_query_percentage from Queries
group by query_name
