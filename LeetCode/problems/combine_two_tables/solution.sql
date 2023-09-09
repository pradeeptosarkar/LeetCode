# Write your MySQL query statement below

SELECT firstName, lastName, city, state from Person left join Address on Person.personID = Address.personId