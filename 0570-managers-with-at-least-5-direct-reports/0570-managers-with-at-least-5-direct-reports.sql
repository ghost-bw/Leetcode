 select name from (
    select  e1.name , count(*) as countemp from  Employee e1
    join Employee e2 on e1.id=e2.managerId
    group by e1.id,e1.name
 ) as temp
 where countemp>=5
;
