# Write your MySQL query statement below

select Customer.name as 'name'
from Customer
where Customer.referee_id!=2 or referee_id is null;