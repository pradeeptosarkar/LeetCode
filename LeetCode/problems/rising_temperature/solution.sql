# Write your MySQL query statement below

select weather.id as 'id'
from weather
join weather as w
on DATEDIFF(weather.recordDate, w.recordDate)=1
and weather.temperature > w.temperature
;