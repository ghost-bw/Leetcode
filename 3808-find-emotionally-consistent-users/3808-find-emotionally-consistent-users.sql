# Write your MySQL query statement below
with temp as (
    select user_id,count(*) as cnt
    from reactions
    group by user_id
    having count(content_id)>=5
)
select r.user_id,r.reaction as dominant_reaction, round(count(*)/MAX(t.cnt),2) as reaction_ratio
from reactions r
join temp t on t.user_id=r.user_id
group by r.user_id,r.reaction
having count(*)/MAX(t.cnt) >=0.6
order by reaction_ratio desc;

