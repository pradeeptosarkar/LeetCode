# Write your MySQL query statement below

select s.name 
from salesperson s left join 

(select o.sales_id from orders o inner join company c on o.com_id=c.com_id where c.name='RED') tbl 

on s.sales_id=tbl.sales_id 
where tbl.sales_id is null
