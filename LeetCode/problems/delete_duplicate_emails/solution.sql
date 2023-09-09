# Write your MySQL query statement below

delete p2 from Person as p1 inner join Person as p2 where p1.id<p2.id and p1.email=p2.email;