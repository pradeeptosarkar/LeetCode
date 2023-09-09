# Write your MySQL query statement below

select *, 
IF(x + y > z AND x + z > y AND y + z > x, 'Yes', 'No') 
as triangle 
from triangle;